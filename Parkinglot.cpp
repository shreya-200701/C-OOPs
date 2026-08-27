#include<iostream>
#include<limits>
#include<vector>
#include<ctime>
#include<memory>
using namespace std;

// enum class = scoped enum. Values must be written as VechileSize::small etc.
// Prevents name collisions and gives "size" a real, type-checked identity
// instead of being a bare int.
enum class VechileSize{ small, medium, large };

class Vechile{
protected:
    VechileSize vechilesize;
    int lisenceplate;
    time_t entrytime;
    time_t exittime;
public:
    // Only plate + size are needed now — entry time is stamped automatically
    // the moment the object is created, not typed in by the user.
    Vechile(int plate, VechileSize size){
        lisenceplate = plate;
        vechilesize = size;
        entrytime = time(nullptr);
    }

    int getplate() const { return lisenceplate; }

    void setexit(){
        exittime = time(nullptr);
    }

    virtual int calculatefee() const = 0;
    virtual VechileSize getsize() const = 0;
    virtual ~Vechile(){
        // Uncomment while testing to visually confirm cleanup is happening:
        // cout << "Destroying vehicle with plate " << lisenceplate << "\n";
    }
};

class Bike : public Vechile{
    int price = 20;
public:
    Bike(int plate) : Vechile(plate, VechileSize::small) {}

    int calculatefee() const override{
        double seconds = difftime(exittime, entrytime);
        int hours = static_cast<int>(seconds / 3600);
        if(hours < 1) hours = 1;   // minimum 1-hour charge
        return price * hours;
    }
    VechileSize getsize() const override{
        return vechilesize;
    }
};

class Car : public Vechile{
    int price = 100;
public:
    Car(int plate) : Vechile(plate, VechileSize::medium) {}

    int calculatefee() const override{
        double seconds = difftime(exittime, entrytime);
        int hours = static_cast<int>(seconds / 3600);
        if(hours < 1) hours = 1;
        return price * hours;
    }
    VechileSize getsize() const override{
        return vechilesize;
    }
};

class Truck : public Vechile{
    int price = 200;
public:
    Truck(int plate) : Vechile(plate, VechileSize::large) {}

    int calculatefee() const override{
        double seconds = difftime(exittime, entrytime);
        int hours = static_cast<int>(seconds / 3600);
        if(hours < 1) hours = 1;
        return price * hours;
    }
    VechileSize getsize() const override{
        return vechilesize;
    }
};

class Parkingspot{
    int spotID;
    VechileSize Vechilesize;
    bool availability_status;
    Vechile* has_a_vechile;   // non-owning — Parkingspot never deletes this
public:
    Parkingspot(int ID, VechileSize size){
        spotID = ID;
        Vechilesize = size;
        availability_status = true;
        has_a_vechile = nullptr;
    }

    bool ParkVechile(Vechile* V){
        if(!availability_status) return false;
        if(V->getsize() != Vechilesize) return false;
        availability_status = false;
        has_a_vechile = V;
        return true;
    }

    friend class Parkingspotmanager;
};

class Parkingspotmanager{
    vector<Parkingspot> spots;
    vector<unique_ptr<Vechile>> parkedvechiles;   // manager OWNS the vehicles
public:
    Parkingspotmanager(int numsmall, int nummedium, int numlarge){
        int id = 0;
        for(int i = 0; i < numsmall; i++)
            spots.emplace_back(id++, VechileSize::small);
        for(int i = 0; i < nummedium; i++)
            spots.emplace_back(id++, VechileSize::medium);
        for(int i = 0; i < numlarge; i++)
            spots.emplace_back(id++, VechileSize::large);

        parkedvechiles.resize(spots.size());
        // Note: spots.size() is used everywhere below instead of a separate
        // "n" member — storing a duplicate count is how they get out of sync.
    }

    bool parkvechile(unique_ptr<Vechile> v){
        for(size_t i = 0; i < spots.size(); i++){
            if(spots[i].ParkVechile(v.get())){
                parkedvechiles[i] = move(v);
                return true;
            }
        }
        return false;   // v still owns the vehicle here -> auto-cleaned up, no leak
    }

    bool removevechile(int plateID){
        for(size_t i = 0; i < spots.size(); i++){
            if(parkedvechiles[i] != nullptr && parkedvechiles[i]->getplate() == plateID){
                parkedvechiles[i]->setexit();
                int money = parkedvechiles[i]->calculatefee();
                cout << "Money to be paid: " << money << "\n";

                parkedvechiles[i] = nullptr;        // frees the Vechile via unique_ptr
                spots[i].has_a_vechile = nullptr;   // spot no longer dangles
                spots[i].availability_status = true;
                return true;
            }
        }
        return false;
    }

    void displaystatus(){
        for(size_t i = 0; i < spots.size(); i++){
            cout << "Spot " << i << ": ";
            if(parkedvechiles[i])
                cout << "Occupied by plate " << parkedvechiles[i]->getplate();
            else
                cout << "Empty";
            cout << "\n";
        }
    }
};

int main(){
    Parkingspotmanager manager(2, 2, 1); // 2 small, 2 medium, 1 large
    int choice;

    while(true){
        cout << "\n======= PARKING LOT MANAGEMENT SYSTEM =======\n";
        cout << "1. Park a vehicle\n";
        cout << "2. Unpark/Checkout\n";
        cout << "3. Display parking lot occupancy\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";

        cin >> choice;
        if(cin.fail()){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input - please enter a number between 1 and 4.\n";
            continue;
        }

        if(choice == 1){
            int type, plate;
            cout << "Vehicle type (1-Bike, 2-Car, 3-Truck): ";
            cin >> type;
            if(cin.fail() || type < 1 || type > 3){
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid vehicle type.\n";
                continue;
            }

            cout << "License plate (number): ";
            cin >> plate;
            if(cin.fail()){
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid plate number.\n";
                continue;
            }

            unique_ptr<Vechile> v;
            if(type == 1)      v = make_unique<Bike>(plate);
            else if(type == 2) v = make_unique<Car>(plate);
            else                v = make_unique<Truck>(plate);

            if(manager.parkvechile(move(v)))
                cout << "Vehicle parked successfully.\n";
            else
                cout << "No available spot for this vehicle size.\n";
        }
        else if(choice == 2){
            int plate;
            cout << "License plate to remove: ";
            cin >> plate;
            if(cin.fail()){
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid plate number.\n";
                continue;
            }

            if(manager.removevechile(plate))
                cout << "Vehicle removed.\n";
            else
                cout << "No vehicle found with that plate.\n";
        }
        else if(choice == 3){
            manager.displaystatus();
        }
        else if(choice == 4){
            cout << "Exiting. Cleaning up...\n";
            break;
        }
        else{
            cout << "Please choose a number between 1 and 4.\n";
        }
    }
    return 0;
}