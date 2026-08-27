# C-OOPs
# C++ OOP Projects

A collection of C++ Object-Oriented Programming projects created to learn and apply core OOP concepts through practical applications.

## 📁 Project Structure

C-OOPs/
├── parking-lot-system/
│   └── main.cpp
├── rpg-battle-system/
│   └── main.cpp
└── README.md

---

## 🚗 1. Parking Lot Management System

A console-based parking lot management system built using C++.

The system manages different types of vehicles and parking spots while demonstrating important Object-Oriented Programming concepts.

### Features

- Park a vehicle
- Unpark / checkout a vehicle
- Display parking lot occupancy
- Supports different vehicle types:
  - Bike
  - Car
  - Truck
- Supports different parking spot sizes:
  - Small
  - Medium
  - Large
- Automatically records vehicle entry time
- Calculates parking fees based on parking duration
- Validates user input
- Automatic memory management using smart pointers

### OOP Concepts Used

- Classes and Objects
- Encapsulation
- Inheritance
- Abstraction
- Runtime Polymorphism
- Pure Virtual Functions
- Virtual Functions
- Virtual Destructor
- Function Overriding
- `enum class`
- Friend Classes
- `unique_ptr`
- RAII
- Move Semantics
- STL `vector`
- Constructors and Destructors

### Class Hierarchy

    Vechile
       |
    +--+--+
    |  |  |
    Bike Car Truck

`Vechile` acts as the abstract base class, while `Bike`, `Car`, and `Truck` are derived classes.

---

## ⚔️ 2. RPG Battle System

A console-based turn-based RPG battle system designed to demonstrate inheritance, abstraction, and runtime polymorphism in C++.

### Features

- Turn-based combat
- Multiple character types
- Warrior character
- Blackwoman character
- Health management
- Stamina management
- Attack power system
- Stamina consumption
- Stamina regeneration
- Damage calculation
- Character defeat detection
- Input validation

### OOP Concepts Used

- Classes and Objects
- Encapsulation
- Inheritance
- Abstraction
- Runtime Polymorphism
- Abstract Classes
- Pure Virtual Functions
- Virtual Functions
- Function Overriding
- Virtual Destructor
- Smart Pointers (`unique_ptr`)
- RAII
- References
- STL

### Class Hierarchy

    Character
       |
    +--+--+
    |     |
    Warrior  Blackwoman

`Character` is an abstract base class with a pure virtual `attack()` function. The derived classes provide their own implementations of the attack behavior.

---

## 🧠 Concepts Practiced

| OOP Concept | Parking Lot | RPG Battle |
|-------------|:-----------:|:----------:|
| Classes & Objects | ✅ | ✅ |
| Encapsulation | ✅ | ✅ |
| Inheritance | ✅ | ✅ |
| Abstraction | ✅ | ✅ |
| Runtime Polymorphism | ✅ | ✅ |
| Abstract Classes | ✅ | ✅ |
| Pure Virtual Functions | ✅ | ✅ |
| Virtual Functions | ✅ | ✅ |
| Virtual Destructor | ✅ | ✅ |
| Function Overriding | ✅ | ✅ |
| `enum class` | ✅ | ❌ |
| Friend Class | ✅ | ❌ |
| `unique_ptr` | ✅ | ✅ |
| RAII | ✅ | ✅ |
| Move Semantics | ✅ | ❌ |
| STL `vector` | ✅ | ❌ |
| Constructors | ✅ | ✅ |
| References | ❌ | ✅ |

---

## 🛠️ Requirements

- C++14 or later
- GCC / MinGW
- Clang
- MSVC
- Any C++ compatible IDE

---

## ▶️ How to Run

### Clone the Repository

    git clone <your-repository-url>
    cd C-OOPs

### Run Parking Lot System

    cd parking-lot-system
    g++ -std=c++14 main.cpp -o parking
    ./parking

### Run RPG Battle System

    cd rpg-battle-system
    g++ -std=c++14 main.cpp -o rpg
    ./rpg

### Windows

Using MinGW:

    g++ -std=c++14 main.cpp -o parking.exe
    parking.exe

---

## 🎯 Learning Goals

The purpose of these projects is to understand OOP concepts by implementing them in practical systems.

The projects provide hands-on practice with:

- Classes and Objects
- Encapsulation
- Inheritance
- Abstraction
- Polymorphism
- Smart Pointers
- RAII
- Modern C++

---

## 📌 Projects

### Parking Lot System

Focuses on:

- Object relationships
- Inheritance
- Vehicle and parking spot management
- Runtime polymorphism
- Smart pointer based ownership
- Resource management

### RPG Battle System

Focuses on:

- Abstract classes
- Inheritance
- Runtime polymorphism
- Virtual functions
- Character behavior
- Smart pointer based object management

---

## 👨‍💻 Author

**Shreya Johari**

Built as part of learning and practicing C++ Object-Oriented Programming.

