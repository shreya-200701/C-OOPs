# C-OOPs
C++ OOP practice projects — parking lot system &amp; RPG battle system
<br>
🚗 1. Parking Lot Management System

A console-based parking lot management system that manages different types of vehicles and parking spots.
<br>
Features
Park vehicles in available parking spots
Support for:
🏍️ Bike
🚗 Car
🚚 Truck
Different parking spot sizes:
Small
Medium
Large
Automatically records vehicle entry time
Calculates parking fees based on parking duration
Unpark/checkout vehicles
Display current parking lot occupancy
Input validation for invalid user input
Automatic memory management using unique_ptr
OOP Concepts Used
Classes and Objects
Encapsulation
Inheritance
Runtime Polymorphism
Pure Virtual Functions
Abstract Classes
Virtual Destructor
Function Overriding
enum class
Composition
Friend Classes
Smart Pointers (unique_ptr)
RAII
Move Semantics (std::move)
Constructors
STL vector

The vehicle hierarchy uses an abstract Vechile base class with Bike, Car, and Truck derived classes. Each derived class provides its own implementation of fee calculation and vehicle size.

Example Hierarchy
                 Vechile
                /   |   \
               /    |    \
            Bike   Car   Truck

The parking manager owns the vehicles through:

vector<unique_ptr<Vechile>> parkedvechiles;

while parking spots maintain non-owning pointers to the vehicles.

⚔️ 2. RPG Battle System

A console-based RPG combat system demonstrating inheritance and runtime polymorphism.

Features
Multiple character classes
Warrior character with different attack characteristics
Blackwoman character with different attack characteristics
Health and stamina management
Configurable attack power
Stamina consumption per attack
Stamina regeneration
Damage calculation
Character defeat detection
Turn-based combat
Input validation
OOP Concepts Used
Classes and Objects
Inheritance
Runtime Polymorphism
Abstract Classes
Pure Virtual Functions
Virtual Functions
Function Overriding
Virtual Destructor
Encapsulation
Smart Pointers (unique_ptr)
RAII
References
STL

The Character class acts as an abstract base class, while Warrior and Blackwoman provide their own implementations of the virtual attack() function.

Example Hierarchy
              Character
              /       \
             /         \
        Warrior      Blackwoman

The game uses unique_ptr<Character> to manage the lifetime of derived character objects.

🧠 OOP Concepts Covered
Concept	Parking Lot	RPG Battle
Classes & Objects	✅	✅
Encapsulation	✅	✅
Inheritance	✅	✅
Runtime Polymorphism	✅	✅
Abstract Classes	✅	✅
Pure Virtual Functions	✅	✅
Virtual Destructor	✅	✅
Function Overriding	✅	✅
enum class	✅	—
Friend Class	✅	—
unique_ptr	✅	✅
RAII	✅	✅
std::move	✅	—
STL vector	✅	—
Constructors	✅	✅
References	—	✅
🛠️ Requirements
C++11 or later
A C++ compiler such as:
GCC
Clang
MSVC

The projects use modern C++ features such as unique_ptr and make_unique, so C++14 or later is recommended.

▶️ How to Run

Clone the repository:

git clone <your-repository-url>
cd C-OOPs
Parking Lot
cd parking-lot-system
g++ -std=c++14 main.cpp -o parking
./parking
RPG Battle
cd ../rpg-battle-system
g++ -std=c++14 main.cpp -o rpg
./rpg
🎯 Purpose

These projects were created to move beyond learning OOP concepts theoretically and apply them to real-world and interactive C++ applications.

The goal is to build a strong understanding of:

OOP Fundamentals
       ↓
Inheritance
       ↓
Polymorphism
       ↓
Abstract Classes
       ↓
Smart Pointers
       ↓
RAII & Memory Management
       ↓
Practical C++ Design
👩‍💻 Author

Shreya Johari

A collection of C++ OOP projects created for learning, practice, and building a stronger foundation in modern C++.
