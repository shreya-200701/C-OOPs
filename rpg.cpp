#include<iostream>
#include<limits>
#include<memory>
#include<vector>
using namespace std;

class Character{
protected:
    string name;
    float Health;
    int attackpower;   // max power this character can put into a single attack
    int stamina;
    int maxStamina;

public:
    Character(string name, float health, int attackpower, int maxStamina)
        : name(name), Health(health), attackpower(attackpower),
          stamina(maxStamina), maxStamina(maxStamina) {}

    string getName() const { return name; }
    float getHealth() const { return Health; }
    int getStamina() const { return stamina; }
    int getMaxAttackPower() const { return attackpower; }
    bool isAlive() const { return Health > 0; }

    void regenStamina(int amount){
        stamina += amount;
        if(stamina > maxStamina) stamina = maxStamina;
    }

    void takeDamage(int amount){
        Health -= amount;
        if(Health < 0) Health = 0;
        cout << name << " took " << amount << " damage. (" << Health << " HP left)\n";
        if(!isAlive()) cout << name << " is defeated!\n";
    }

    // chosenPower = how much of their attack power the player wants to spend this turn
    virtual void attack(Character& target, int chosenPower) = 0;
    virtual ~Character() = default;
};

class Warrior : public Character{
public:
    Warrior(string name, float health)
        : Character(name, health, /*attackpower=*/50, /*maxStamina=*/100) {}

    void attack(Character& target, int chosenPower) override{
        if(chosenPower > attackpower){
            cout << name << " can't attack that hard (max power: " << attackpower << ")\n";
            return;
        }
        if(chosenPower > stamina){
            cout << name << " doesn't have enough stamina (" << stamina << " left)\n";
            return;
        }
        stamina -= chosenPower;
        cout << name << " swings a heavy blow at " << target.getName()
             << " using " << chosenPower << " power!\n";
        target.takeDamage(chosenPower);
    }
};

class Blackwoman : public Character{
public:
    Blackwoman(string name, float health)
        : Character(name, health, /*attackpower=*/35, /*maxStamina=*/150) {}

    void attack(Character& target, int chosenPower) override{
        if(chosenPower > attackpower){
            cout << name << " can't attack that hard (max power: " << attackpower << ")\n";
            return;
        }
        if(chosenPower > stamina){
            cout << name << " doesn't have enough stamina (" << stamina << " left)\n";
            return;
        }
        stamina -= chosenPower;
        cout << name << " strikes fast at " << target.getName()
             << " using " << chosenPower << " power!\n";
        target.takeDamage(chosenPower);
    }
};

int main(){
    unique_ptr<Character> p1 = make_unique<Warrior>("Conan", 200);
    unique_ptr<Character> p2 = make_unique<Blackwoman>("Nakia", 180);

    Character* attacker = p1.get();
    Character* defender = p2.get();

    int choice;
    while(p1->isAlive() && p2->isAlive()){
        cout << "\n--- " << attacker->getName() << "'s turn ---\n";
        cout << attacker->getName() << ": HP " << attacker->getHealth()
             << " | Stamina " << attacker->getStamina()
             << " | Max power " << attacker->getMaxAttackPower() << "\n";
        cout << defender->getName() << ": HP " << defender->getHealth() << "\n";

        cout << "Choose attack power to use (0 to skip): ";
        cin >> choice;
        if(cin.fail()){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input, turn skipped.\n";
            choice = 0;
        }

        if(choice > 0)
            attacker->attack(*defender, choice);
        else
            cout << attacker->getName() << " holds back this turn.\n";

        attacker->regenStamina(10); // simple flat regen per turn

        swap(attacker, defender);   // switch turns
    }

    cout << "\n=== Battle Over ===\n";
    if(p1->isAlive()) cout << p1->getName() << " wins!\n";
    else if(p2->isAlive()) cout << p2->getName() << " wins!\n";
    else cout << "Both fighters are down!\n";

    return 0;
}