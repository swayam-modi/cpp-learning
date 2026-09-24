# Object-Oriented Programming in C++

> **Source:** Stroustrup – *A Tour of C++* & *The C++ Programming Language* | Modern C++ (C++11/14/17/20)

---

## 1. Classes & Objects

### What is a Class?

A class is a **blueprint** that bundles data (member variables) and behavior (member functions) into one unit. Unlike Java, a C++ class definition **must end with a semicolon**.

```cpp
class Student {
public:
    std::string name;   // Member variable (field)
    int age;            // Member variable

    void display() {    // Member function (method)
        std::cout << name << " - " << age << "\n";
    }
};  // <-- semicolon required in C++!
```

### What is an Object?

An object is an **instance** of a class — it can live on the **stack** (automatic) or the **heap** (dynamic).

```cpp
// Stack-allocated (preferred in C++ — automatic lifetime)
Student s1;
s1.name = "Swayam";
s1.age  = 20;
s1.display();

// Heap-allocated (manual lifetime — use smart pointers!)
Student* s2 = new Student();   // raw pointer — avoid if possible
s2->name = "Swayam";           // -> dereferences + accesses member
delete s2;                     // MUST free manually!

// Modern C++ — heap + automatic cleanup
#include <memory>
auto s3 = std::make_unique<Student>();
s3->name = "Swayam";
// No delete needed — destroyed when s3 goes out of scope
```

### Stack vs Heap (C++ vs Java)

| Feature      | C++ Stack Object  | C++ Heap (raw ptr) | Java Object              |
| ------------ | ----------------- | ------------------- | ------------------------ |
| Syntax       | `Student s;`      | `new Student()`     | `new Student()`          |
| Memory       | Stack             | Heap                | Heap                     |
| Lifetime     | Automatic (RAII)  | Manual (`delete`)   | Garbage Collected        |
| Access       | `.` operator      | `->` operator       | `.` operator             |
| Preferred    | ✅ Yes            | ❌ Use smart ptrs   | ✅ Only option           |

### Object Creation Breakdown

```
// Stack:             Student s1("Swayam", 20);
//                       │
//                       └── Constructor called automatically
//                           Object lives in current scope's stack frame
//                           Destroyed automatically when scope ends ✅

// Heap (modern):     auto s2 = std::make_unique<Student>("Swayam", 20);
//                       │
//                       └── Heap-allocated, but unique_ptr owns it
//                           Destroyed automatically when unique_ptr goes out of scope ✅
```

### Copying Objects

```cpp
Student a;
a.name = "Alice";

Student b = a;       // VALUE copy — b is a completely separate object!
b.name = "Bob";
std::cout << a.name; // "Alice" ← a is NOT changed (unlike Java references!)
```

> **Key Difference from Java:** In C++, object assignment **copies by value** by default. Java copies **references** (both point to the same heap object).

---

## 2. The `this` Pointer

In C++, `this` is a **pointer** (not a reference like in Java) to the current object. It's implicitly available in all non-static member functions.

### Uses

```cpp
class Person {
    std::string name;
    int age;

public:
    // 1. Disambiguate member from parameter (same name)
    Person(std::string name, int age) {
        this->name = name;   // this->name = member, name = parameter
        this->age  = age;
    }

    // 2. Return current object (enables method chaining)
    Person& setName(std::string name) {
        this->name = name;
        return *this;         // Dereference this pointer to return object
    }

    // 3. Pass current object as argument
    void registerSelf() {
        Registry::add(this);  // Pass pointer to self
    }
};

// Method chaining with *this
Person p;
p.setName("Alice").setAge(25).display();  // Fluent interface
```

> ⚠️ `this` is a **pointer** in C++, so use `this->member` or `(*this).member`. In Java, `this.member` is a reference.

### `this` Pointer Type

| Context              | `this` type      |
| -------------------- | ---------------- |
| Regular method       | `ClassName*`     |
| `const` method       | `const ClassName*` |
| Rvalue-ref method    | `ClassName&&`    |

---

## 3. The `const` Keyword (Analog to Java's `final`)

C++ uses `const` where Java uses `final`. It's far more powerful — it applies to variables, pointers, references, and member functions.

### const Variables

```cpp
const int MAX = 100;     // Constant — value can't change
// MAX = 200;            // ❌ Compile error

const Student s;         // Object itself is const
// s.name = "X";         // ❌ Can't modify const object's members
```

> `const` on an object prevents modification of **all its members** — stricter than Java's `final` on a reference.

### const Pointers (No Java equivalent)

```cpp
int x = 10, y = 20;

const int* p1 = &x;    // Pointer-to-const: can't change *p1, CAN change p1
// *p1 = 20;           // ❌ Can't modify value
p1 = &y;               // ✅ Can change what p1 points to

int* const p2 = &x;    // Const-pointer: CAN change *p2, can't change p2
*p2 = 20;              // ✅ Can modify value
// p2 = &y;            // ❌ Can't change pointer itself

const int* const p3 = &x;  // Both const: can't change either
```

### const Member Functions

```cpp
class Circle {
    double radius;
public:
    // const method — promises NOT to modify the object
    double area() const {
        return 3.14 * radius * radius;   // can read members
        // radius = 0;                   // ❌ Can't modify in const method
    }

    void setRadius(double r) {           // Non-const method — can modify
        radius = r;
    }
};

const Circle c;
c.area();      // ✅ Can call const method on const object
// c.setRadius(5);  // ❌ Can't call non-const method on const object
```

### Summary

| Applied To              | Effect                                    | Java Equivalent |
| ----------------------- | ----------------------------------------- | --------------- |
| Primitive variable      | Value cannot change (constant)            | `final int`     |
| Object variable         | Entire object is immutable                | No direct equiv |
| Pointer (low)           | Pointed-to value cannot change            | No direct equiv |
| Pointer (high)          | Pointer address cannot change             | `final` ref     |
| Member function         | Method cannot modify object state         | No direct equiv |

---

## 4. Object Cleanup — Destructors (Analog to Java's `finalize()`)

In C++, the **destructor** is called deterministically when an object's lifetime ends — NOT by a garbage collector. This is the foundation of **RAII** (Resource Acquisition Is Initialization).

```cpp
class Resource {
    int* data;
public:
    Resource() {
        data = new int[100];                    // Acquire resource
        std::cout << "Resource acquired\n";
    }

    ~Resource() {                               // Destructor — called automatically!
        delete[] data;                          // Release resource
        std::cout << "Resource released\n";
    }
};

{
    Resource r;         // Constructor called
    // ... use r ...
}                       // ← Destructor called HERE automatically (scope ends)
```

> ✅ Unlike Java's `finalize()` (deprecated, non-deterministic), C++ destructors run **immediately and predictably** when the object goes out of scope.

### RAII Pattern

```cpp
// Bad (Java style): manual resource management
FILE* f = fopen("file.txt", "r");
// ... use f ...
fclose(f);   // Must remember to call — easy to forget!

// Good (C++ RAII): resource tied to object lifetime
std::ifstream file("file.txt");   // Opens in constructor
// ... use file ...
// Closed automatically in destructor ← no manual cleanup needed!
```

### Rule of Three / Five / Zero

| Rule    | Applies When              | What to Define                                     |
| ------- | ------------------------- | -------------------------------------------------- |
| Zero    | No raw resource ownership | Nothing — compiler defaults are fine ✅            |
| Three   | Pre-C++11 manual resource | Destructor + Copy Constructor + Copy Assignment    |
| Five    | C++11+ move semantics     | Above + Move Constructor + Move Assignment         |

---

## 5. Constructors

A constructor **initializes** an object when it's created. Same name as class, no return type — same as Java.

### Types

```cpp
class Car {
    std::string model;
    int year;

public:
    // 1. Default Constructor
    Car() : model("Unknown"), year(2024) {}   // Member Initializer List (preferred!)

    // 2. Parameterized Constructor
    Car(std::string model, int year)
        : model(model), year(year) {}         // MIL avoids double-initialization

    // 3. Copy Constructor (compiler provides a default, but define if needed)
    Car(const Car& other)
        : model(other.model), year(other.year) {}

    // 4. Move Constructor (C++11) — transfers ownership instead of copying
    Car(Car&& other) noexcept
        : model(std::move(other.model)), year(other.year) {
        other.year = 0;
    }
};
```

### Member Initializer List (MIL)

The syntax `Constructor(int data) : data(data) {}` is called the **Member Initializer List**.
The colon `:` after the parameter list begins it, and each member is initialized as `member(value)`.

#### Body Assignment vs MIL — What's the Difference?

```cpp
class Node {
    int data;
    std::string label;
public:
    // ❌ Body Assignment — two steps for each member:
    //    1. Members are DEFAULT-initialized first (label = "", data = garbage)
    //    2. Then assigned inside the body
    Node(int data, std::string label) {
        this->data  = data;    // Assignment (not initialization)
        this->label = label;   // std::string constructed twice!
    }

    // ✅ Member Initializer List — one step, directly initialized:
    Node(int data, std::string label)
        : data(data), label(label) {}   // std::string constructed once ✅
};
```

#### Performance Comparison

| | Body Assignment | Member Initializer List |
|---|---|---|
| Steps for object member | Default-init → Assign (2 steps) | Direct-init (1 step) |
| Steps for primitive | Same (negligible) | Same (negligible) |
| Preferred for `std::string`, vectors, etc. | ❌ Wasteful | ✅ Efficient |

> For **primitives** (`int`, `double`, etc.) both work identically. For **class-type members** (like `std::string`), MIL avoids a redundant default construction.

#### When MIL is MANDATORY

```cpp
class Example {
    const int MAX;      // const member — can't assign after creation
    int& ref;           // reference — must be bound at init
    SubObject obj;      // class with no default constructor

public:
    // ONLY way to initialize these — body assignment won't compile!
    Example(int max, int& r, SubObject o)
        : MAX(max), ref(r), obj(o) {}
};
```

Three cases where MIL is **not optional**:
1. **`const` members** — value is fixed forever at init; can't assign later.
2. **Reference members** — references must be bound when created, never rebound.
3. **Members whose class has no default constructor** — there's no "default" to fall back to.

#### Initialization Order Warning ⚠️

Members are **always initialized in the order they are declared**, regardless of the order in the MIL:

```cpp
class Danger {
    int b;   // declared FIRST
    int a;   // declared SECOND
public:
    // ⚠️ UNDEFINED BEHAVIOR — b is initialized before a (declaration order!)
    //    but we wrote a(x) first in MIL — misleading!
    Danger(int x) : a(x), b(a) {}   // b = a is read BEFORE a is set!
};

class Safe {
    int a;   // declared first
    int b;   // declared second
public:
    Safe(int x) : a(x), b(a) {}   // ✅ a initialized first, then b = a
};
```

> **Rule:** Always write MIL entries in the **same order** as member declarations to avoid bugs.

#### Summary

```cpp
// Use MIL by default — clean, efficient, and required for const/refs
Node(int data, std::string label) : data(data), label(label) {}

// Use body only when logic is conditional
Node(int data, std::string label) {
    if (data < 0) this->data = 0;
    else          this->data = data;
    this->label = label;
}
```

### Constructor Rules

1. **Same name** as the class.
2. **No return type** — same as Java.
3. Called **automatically** when object is created (stack or `new`).
4. If you define **any** constructor, compiler **does NOT** provide a default.
5. Use `= default` to explicitly request compiler-generated versions.
6. Use `= delete` to disable (e.g., prevent copying).

```cpp
class Singleton {
public:
    Singleton(const Singleton&) = delete;             // Disable copy
    Singleton& operator=(const Singleton&) = delete;  // Disable copy-assign
    Singleton() = default;                            // Request compiler default
};
```

### Constructor Delegation (C++11 — Like Java's `this()`)

```cpp
class Config {
    std::string host;
    int port;

    Config(std::string host, int port) : host(host), port(port) {}

    // Delegating constructor — calls another constructor
    Config() : Config("localhost", 8080) {}   // Like Java's this("localhost", 8080)
    Config(int port) : Config("localhost", port) {}
};
```

---

## 6. Namespaces (Analog to Java Packages)

C++ uses **namespaces** instead of packages to organize code and avoid name collisions.

### Declaration

```cpp
namespace com::swayam::dsa {   // C++17 nested namespace shorthand

    class MyClass {
        // Defined in file: com/swayam/dsa/MyClass.h (convention only)
    };

}
```

### Using a Namespace

```cpp
#include <iostream>

// 1. Fully qualified name (always safe)
std::cout << "Hello\n";

// 2. using declaration — brings one name into scope
using std::cout;
cout << "Hello\n";

// 3. using directive — brings ALL names into scope (avoid in headers!)
using namespace std;    // ⚠️ Can cause name collisions — use sparingly

// 4. Namespace alias
namespace dsa = com::swayam::dsa;
dsa::MyClass obj;
```

### Common Standard Namespaces

| Namespace   | Purpose                              | Java Equivalent       |
| ----------- | ------------------------------------ | --------------------- |
| `std`       | All standard library (containers, IO)| `java.lang`, `java.util` |
| `std::chrono` | Time utilities                     | `java.time`           |
| `std::filesystem` | File system operations         | `java.nio.file`       |
| `std::this_thread` | Threading                     | `Thread`              |

---

## 7. The `static` Keyword

`static` members belong to the **class**, not any instance — same concept as Java.

### Static Member Variables

```cpp
class Counter {
public:
    static int count;   // Declaration — defined outside class
    std::string name;

    Counter(std::string name) : name(name) {
        count++;         // Shared across ALL instances
    }
};

// Definition outside class (required for static members pre-C++17)
int Counter::count = 0;

// Or in-class initialization (C++17 inline static)
class Counter2 {
    inline static int count = 0;   // C++17 — no external definition needed
};

Counter a("Alpha");   // count = 1
Counter b("Beta");    // count = 2
std::cout << Counter::count;   // Access via class name
```

### Static Member Functions

```cpp
class MathUtils {
public:
    static int add(int a, int b) {
        return a + b;
    }
};

MathUtils::add(3, 5);   // Called without creating an object (note :: not .)
```

**Rules for static methods:**

- ✅ Can access **static** variables and other **static** methods.
- ❌ Cannot access instance variables or instance methods.
- ❌ Cannot use `this` (no object context).

### Static Local Variables (No Java equivalent)

```cpp
void counter() {
    static int callCount = 0;   // Initialized ONCE, persists between calls!
    callCount++;
    std::cout << "Called " << callCount << " times\n";
}

counter();   // "Called 1 times"
counter();   // "Called 2 times"
counter();   // "Called 3 times"
```

### Comparison to Java

| Feature         | C++                        | Java                    |
| --------------- | -------------------------- | ----------------------- |
| Static variable | `static int x;` + external def | `static int x = 0;` |
| Static method   | `ClassName::method()`      | `ClassName.method()`    |
| Static block    | No direct equivalent       | `static { ... }`        |
| Static local    | Yes — persists across calls| Not possible            |

---

## 8. Inheritance

Inheritance allows a class to **acquire properties and behaviors** of another class — same goal as Java.

```cpp
class Animal {               // Base class (Superclass in Java)
public:
    std::string name;
    void eat() { std::cout << name << " eats\n"; }
};

class Dog : public Animal {  // Derived class (Subclass in Java)
public:
    void bark() { std::cout << name << " barks\n"; }
};

Dog d;
d.name = "Rex";
d.eat();     // Inherited from Animal ✅
d.bark();    // Own method ✅
```

### Inheritance Access Specifiers (C++ Only)

| Specifier         | public members become | protected members become | private members |
| ----------------- | --------------------- | ------------------------ | --------------- |
| `public` (normal) | public                | protected                | Inaccessible    |
| `protected`       | protected             | protected                | Inaccessible    |
| `private`         | private               | private                  | Inaccessible    |

> **Always use `public` inheritance** to model an "is-a" relationship (equivalent to Java's `extends`).

### Types of Inheritance

```
Single:      Multilevel:     Hierarchical:    Multiple (✅ Allowed in C++!):
  A               A               A                A    B
  |               |             / | \               \  /
  B               B            B  C  D               C
                  |
                  C
```

> ✅ **C++ supports multiple inheritance** directly (Java supports only multiple interface inheritance).

### The Analogs to Java's `super`

```cpp
class Vehicle {
protected:
    int speed;
public:
    Vehicle(int speed) : speed(speed) {}
    virtual void display() { std::cout << "Vehicle: " << speed << "\n"; }
};

class Car : public Vehicle {
    int ownSpeed = 200;
public:
    Car() : Vehicle(150) {}    // 1. Call base constructor (like super(150) in Java)

    void display() override {
        std::cout << Vehicle::speed << "\n";   // 2. Access base field via scope resolution
        Vehicle::display();                     // 3. Call base method (like super.display())
    }
};
```

### Constructor Execution Order

Same as Java — **top-down** (base class first):

```cpp
class A { public: A() { std::cout << "A\n"; } };
class B : public A { public: B() { std::cout << "B\n"; } };
class C : public B { public: C() { std::cout << "C\n"; } };

C obj;  // Output: A → B → C
```

> Compiler inserts the base constructor call automatically if not specified.

---

## 9. Polymorphism

Polymorphism means **"many forms"** — same as Java. C++ achieves it through function overloading and **virtual functions**.

### Compile-Time (Function Overloading)

Same as Java's method overloading:

```cpp
class Calculator {
public:
    int add(int a, int b)          { return a + b; }
    double add(double a, double b) { return a + b; }
    int add(int a, int b, int c)   { return a + b + c; }
};
```

### Runtime (Virtual Functions — The C++ Way)

In C++, you must **explicitly mark** methods as `virtual` to enable runtime polymorphism. Java does this by default for all non-final methods.

```cpp
class Shape {
public:
    virtual void draw() {    // virtual = can be overridden; dispatch at runtime
        std::cout << "Drawing shape\n";
    }
    virtual ~Shape() {}      // ALWAYS make destructor virtual in base classes!
};

class Circle : public Shape {
public:
    void draw() override {   // override = explicit override (like @Override in Java)
        std::cout << "Drawing circle\n";
    }
};

Shape* s = new Circle();    // Base pointer, derived object
s->draw();                  // "Drawing circle" ← Virtual dispatch!
delete s;                   // Calls Circle's destructor first (because virtual ~Shape)

// Modern C++ with smart pointer:
auto s2 = std::make_unique<Circle>();
s2->draw();   // Still uses virtual dispatch
```

### `virtual` vs Non-virtual

```cpp
class Base {
public:
    virtual void virtualMethod() { std::cout << "Base virtual\n"; }
    void nonVirtualMethod()       { std::cout << "Base non-virtual\n"; }
};

class Derived : public Base {
public:
    void virtualMethod() override { std::cout << "Derived virtual\n"; }
    void nonVirtualMethod()       { std::cout << "Derived non-virtual\n"; }
};

Base* ptr = new Derived();
ptr->virtualMethod();     // "Derived virtual"    ← Runtime dispatch ✅
ptr->nonVirtualMethod();  // "Base non-virtual"   ← Compile-time dispatch ❌
```

> ⚠️ In C++, only `virtual` functions use late binding. **Always** use `virtual` for functions you intend to override.

### Early vs Late Binding

| Aspect        | Early Binding (C++)            | Late Binding (C++)             |
| ------------- | ------------------------------ | ------------------------------ |
| When          | Compile time                   | Runtime                        |
| How           | Compiler resolves              | vtable (virtual dispatch table)|
| For           | Non-virtual, static functions  | `virtual` functions            |
| Also called   | Static dispatch                | Dynamic dispatch                |
| Java default  | Only `static`/`private`/`final`| All regular methods            |

### `override` and `final` Specifiers

```cpp
class Base {
    virtual void foo() {}
    virtual void bar() {}
};

class Derived : public Base {
    void foo() override {}   // ✅ Safe: compiler checks overriding is correct
    // void baz() override {}  ❌ Error: Base has no virtual baz()

    void bar() final {}      // No further subclass can override bar()
};

class MoreDerived : public Derived {
    // void bar() override {}  ❌ Error: bar() is final
};
```

---

## 10. Access Modifiers

C++ has the same three modifiers as Java, but **no package-level access**.

| Modifier      | Same Class | Derived Class | Everywhere Else |
| ------------- | ---------- | ------------- | --------------- |
| `private`     | ✅         | ❌            | ❌              |
| `protected`   | ✅         | ✅            | ❌              |
| `public`      | ✅         | ✅            | ✅              |

> **No `default`/package-private in C++.** Java's package-private has no direct equivalent.

### Class vs Struct Default Access

```cpp
class Foo {
    int x;    // private by default in class
public:
    int y;
};

struct Bar {
    int x;    // public by default in struct
};
```

> `class` and `struct` are almost identical in C++ — the only difference is default member access.

### Visibility Hierarchy

```
private → protected → public
  (most restrictive)    (least restrictive)
```

> **Best Practice:** Default to `private` fields with public getters/setters (**encapsulation**). Same as Java.

---

## 11. Abstraction

Abstraction hides implementation details. In C++, achieved through **abstract classes** (with pure virtual functions) — no separate `abstract` keyword needed.

### Abstract Classes (Pure Virtual Functions)

```cpp
class Shape {               // Abstract — has at least one pure virtual function
    std::string color;
public:
    // Pure virtual — no body, MUST be overridden (= 0 syntax)
    virtual double area() = 0;

    // Concrete method — has body, can be inherited as-is
    void display() {
        std::cout << "Color: " << color << "\n";
    }

    virtual ~Shape() = default;   // Always virtual destructor!
};

class Circle : public Shape {
    double radius;
public:
    Circle(double r) : radius(r) {}

    double area() override {   // MUST implement pure virtual
        return 3.14159 * radius * radius;
    }
};

// Shape s;        // ❌ Cannot instantiate abstract class (same as Java)
Circle c(5.0);    // ✅ Concrete class
Shape* s = &c;    // ✅ Pointer/reference to abstract type — polymorphism!
```

### Rules

1. **Cannot instantiate** a class with pure virtual functions: `Shape s;` → ❌
2. Can have **both pure virtual and concrete** methods.
3. Can have **constructors** (called by derived class).
4. Can have **member variables**.
5. If a class has **even one** `= 0` method, instantiation is forbidden.
6. Derived class **must implement all** pure virtual methods, or itself be abstract.

---

## 12. Interfaces in C++ (via Pure Abstract Classes)

C++ has no `interface` keyword. Interfaces are simulated using **pure abstract classes** — classes with *only* pure virtual functions and no data.

### Declaring an Interface

```cpp
class Drawable {              // "Interface" — pure abstract class
public:
    virtual void draw() = 0;
    virtual double getArea() = 0;
    virtual ~Drawable() = default;   // Always virtual destructor!
};
```

### Implementing an Interface

```cpp
class Circle : public Drawable {   // "implements" in Java
    double radius;
public:
    Circle(double r) : radius(r) {}

    void draw() override {
        std::cout << "Drawing circle\n";
    }

    double getArea() override {
        return 3.14159 * radius * radius;
    }
};
```

### Multiple Inheritance — The C++ Way (Multiple Interface)

```cpp
class Flyable {
public:
    virtual void fly() = 0;
    virtual ~Flyable() = default;
};

class Swimmable {
public:
    virtual void swim() = 0;
    virtual ~Swimmable() = default;
};

// C++ directly supports multiple inheritance (Java uses implements A, B)
class Duck : public Flyable, public Swimmable {
public:
    void fly()  override { std::cout << "Duck flies\n"; }
    void swim() override { std::cout << "Duck swims\n"; }
};
```

### Diamond Problem & Virtual Inheritance

C++ unique issue — multiple inheritance can cause ambiguity:

```cpp
class A { public: virtual void foo() {} };
class B : public A {};
class C : public A {};

// Without virtual inheritance — two copies of A!
class D : public B, public C {};   // ⚠️ Ambiguous: which A?

// With virtual inheritance — only one shared copy of A
class B2 : virtual public A {};
class C2 : virtual public A {};
class D2 : public B2, public C2 {};   // ✅ Unambiguous — one A
```

### Abstract Class vs "Interface" (Pure Abstract)

| Feature              | Abstract Class (C++)            | Pure Abstract / "Interface" (C++) |
| -------------------- | ------------------------------- | ---------------------------------- |
| Pure virtual methods | Some (has concrete methods too) | All methods are pure virtual       |
| Data members         | Yes                             | None (by convention)               |
| Constructor          | Yes                             | Only virtual destructor            |
| Multiple inheritance | Can be complex                  | Clean — no diamond issue typically |
| When to use          | "IS-A" with shared code         | "CAN-DO" contract                  |

---

## 13. Enumerations (Enums)

C++ provides two forms of enums — the classic C-style `enum` and the modern, type-safe **`enum class`** (C++11).

### Basic `enum` (C-style — avoid if possible)

```cpp
enum Day {
    MONDAY, TUESDAY, WEDNESDAY, THURSDAY, FRIDAY, SATURDAY, SUNDAY
};

Day today = MONDAY;
std::cout << today;            // Prints 0 (implicitly converts to int!)
```

> ⚠️ Old-style `enum` leaks names into the enclosing scope and implicitly converts to `int` — problematic.

### `enum class` — Scoped Enum (C++11 — Preferred)

```cpp
enum class Day {
    Monday, Tuesday, Wednesday, Thursday, Friday, Saturday, Sunday
};

Day today = Day::Monday;              // Must use scope resolution ::
std::cout << static_cast<int>(today); // Must explicitly cast to int

// Switch statement
switch (today) {
    case Day::Monday:
    case Day::Tuesday:
        std::cout << "Weekday\n";
        break;
    case Day::Saturday:
    case Day::Sunday:
        std::cout << "Weekend\n";
        break;
}
```

### Enum with Explicit Underlying Type

```cpp
enum class Status : uint8_t {  // Explicit underlying type (Java: no equivalent)
    OK      = 200,
    NotFound= 404,
    Error   = 500
};

Status s = Status::OK;
auto code = static_cast<uint8_t>(s);   // 200
```

### Enum Methods — C++ vs Java

| Feature                    | C++ `enum class`                   | Java `enum`                 |
| -------------------------- | ---------------------------------- | --------------------------- |
| Scoped names               | ✅ `Day::Monday`                   | ✅ `Day.MONDAY`             |
| Implicit int conversion    | ❌ Must `static_cast`              | ❌ Use `.ordinal()`         |
| Fields / methods           | ❌ Cannot add directly             | ✅ Can add                  |
| `values()` equivalent      | No built-in                        | `Day.values()`              |
| `ordinal()` equivalent     | `static_cast<int>(Day::Monday)` → 0| `Day.MONDAY.ordinal()` → 0  |
| `valueOf()` equivalent     | No built-in (use map)              | `Day.valueOf("MONDAY")`     |
| Underlying type control    | ✅ `enum class X : uint8_t`        | ❌ Always int internally    |
| Implements interface       | ❌                                 | ✅                          |

### Enum Rules

1. Prefer **`enum class`** over plain `enum` for type safety.
2. `enum class` names are **scoped** — no pollution of enclosing namespace.
3. **No implicit conversion** to `int` — use `static_cast`.
4. Can specify **underlying type** (e.g., `uint8_t`, `int32_t`).
5. Enums are **not objects** in C++ — cannot have methods or implement interfaces.

---

## 14. Four Pillars of OOP — Summary

| Pillar            | Definition                                 | C++ Mechanism                                          |
| ----------------- | ------------------------------------------ | ------------------------------------------------------ |
| **Encapsulation** | Binding data + methods, controlling access | `private` / `protected` members + public methods       |
| **Inheritance**   | Acquiring properties of parent class       | `: public Base`, base constructor via MIL              |
| **Polymorphism**  | One interface, multiple implementations    | `virtual` functions, function overloading, `override`  |
| **Abstraction**   | Hiding complexity, showing essentials      | Pure virtual (`= 0`), pure abstract classes as interfaces |

---

## 15. Key Takeaways

1. **Stack objects** have automatic lifetime (RAII); **heap objects** require `delete` or smart pointers.
2. `new` in C++ returns a raw pointer — prefer `std::make_unique` / `std::make_shared`.
3. `this` is a **pointer** in C++ (`this->member`), not a reference like in Java (`this.member`).
4. `const` replaces Java's `final` — applies to variables, pointers, references, and methods.
5. C++ destructors are **deterministic** — run immediately at end-of-scope (unlike Java's `finalize()`).
6. **Member Initializer Lists** (MIL) are preferred over assignment in constructor bodies.
7. Methods must be explicitly marked `virtual` for runtime polymorphism — Java does this by default.
8. Always declare destructor `virtual` in base classes to ensure correct cleanup via base pointer.
9. C++ supports **true multiple inheritance** for classes; Java allows multiple interface implementation.
10. Use `override` specifier to have the compiler verify you are actually overriding a virtual function.
11. Prefer **`enum class`** over plain `enum` for type safety and scoped names.
12. Use `= delete` to disable copy/move; `= default` to request compiler-generated implementations.
13. Abstract classes in C++ use **pure virtual functions** (`= 0`) — no `abstract` keyword.
14. **Static local variables** persist between function calls — a C++ feature with no Java equivalent.
