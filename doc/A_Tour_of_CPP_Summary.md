# A Tour of C++ (1st Edition) — Comprehensive Book Summary

> **Author:** Bjarne Stroustrup  
> **Topic:** Modern C++ (C++11 Standard) Overview & Best Practices  
> **Target Audience:** Experienced programmers seeking a fast-paced overview of modern C++ features, design philosophy, and standard library components.

---

## Table of Contents (Index)

- [Executive Summary & Core Design Philosophy](#executive-summary--core-design-philosophy)
- [Chapter-by-Chapter Breakdown](#chapter-by-chapter-breakdown)
  - [Chapter 1: The Basics](#chapter-1-the-basics)
    - [1.1–1.3 Programs & Hello, World!](#1113-programs--hello-world)
    - [1.4 Functions](#14-functions)
    - [1.5 Types, Variables, and Arithmetic](#15-types-variables-and-arithmetic)
    - [1.6 Scope & Lifetime](#16-scope--lifetime)
    - [1.7 Constants (`const` vs `constexpr`)](#17-constants-const-vs-constexpr)
    - [1.8 Pointers, Arrays, and References](#18-pointers-arrays-and-references)
    - [1.9 Tests & Control Structures](#19-tests--control-structures)
  - [Chapter 2: User-Defined Types](#chapter-2-user-defined-types)
    - [2.1–2.2 Structures (`struct`)](#2122-structures-struct)
    - [2.3 Classes (`class`)](#23-classes-class)
    - [2.4 Unions (`union`)](#24-unions-union)
    - [2.5 Enumerations (`enum` & `enum class`)](#25-enumerations-enum--enum-class)
  - [Chapter 3: Modularity](#chapter-3-modularity)
    - [3.1–3.2 Separate Compilation & Header Files](#3132-separate-compilation--header-files)
    - [3.3 Namespaces](#33-namespaces)
    - [3.4 Error Handling & Invariants](#34-error-handling--invariants)
  - [Chapter 4: Classes](#chapter-4-classes)
    - [4.1–4.2 Concrete Types & Container Initialization](#4142-concrete-types--container-initialization)
    - [4.3–4.5 Abstract Types, Class Hierarchies & Controls](#4345-abstract-types-class-hierarchies--controls)
    - [4.4 Virtual Functions](#44-virtual-functions)
    - [4.6 Copy and Move Semantics (The Rule of 5)](#46-copy-and-move-semantics-the-rule-of-5)
  - [Chapter 5: Templates](#chapter-5-templates)
    - [5.2 Parameterized Class Templates](#52-parameterized-class-templates)
    - [5.3 Function Templates](#53-function-templates)
    - [5.4 Concepts and Generic Programming](#54-concepts-and-generic-programming)
    - [5.5 Function Objects (Functors) & Lambdas](#55-function-objects-functors--lambdas)
    - [5.6 Variadic Templates](#56-variadic-templates)
    - [5.7 Aliases (`using`)](#57-aliases-using)
    - [5.8 Template Compilation Model](#58-template-compilation-model)
  - [Chapter 6: Library Overview](#chapter-6-library-overview)
  - [Chapter 7: Strings and Regular Expressions](#chapter-7-strings-and-regular-expressions)
    - [7.2 `std::string`](#72-stdstring)
    - [7.3 Regular Expressions (`std::regex`)](#73-regular-expressions-stdregex)
  - [Chapter 8: I/O Streams](#chapter-8-io-streams)
    - [8.1–8.3 Streams (`ostream` & `istream`)](#8183-streams-ostream--istream)
    - [8.4 Stream I/O State](#84-stream-io-state)
    - [8.5 User-Defined Type I/O](#85-user-defined-type-io)
    - [8.6 Stream Formatting & Manipulators](#86-stream-formatting--manipulators)
    - [8.7–8.8 File & String Streams](#8788-file--string-streams)
  - [Chapter 9: Containers](#chapter-9-containers)
    - [9.6 Container Overview & Operations](#96-container-overview--operations)
  - [Chapter 10: Algorithms](#chapter-10-algorithms)
    - [10.1–10.3 Iterators & Iterator Taxonomy](#101103-iterators--iterator-taxonomy)
    - [10.2 Use of Iterators in Practice](#102-use-of-iterators-in-practice)
    - [10.4 Stream Iterators](#104-stream-iterators)
    - [10.5 Predicates](#105-predicates)
    - [10.6 Algorithm Overview](#106-algorithm-overview)
    - [10.7 Container Member Algorithms](#107-container-member-algorithms)
  - [Chapter 11: Utilities](#chapter-11-utilities)
    - [11.2 Resource Management & Smart Pointers (C++11)](#112-resource-management--smart-pointers-c11)
    - [11.3 Specialized Containers & Utilities](#113-specialized-containers--utilities)
    - [11.4 Time (`std::chrono`)](#114-time-stdchrono)
    - [11.5 Function Adaptors (`std::function`, `bind`, `mem_fn`)](#115-function-adaptors-stdfunction-bind-mem_fn)
    - [11.6 Type Functions & Type Traits (`<type_traits>`)](#116-type-functions--type-traits-typetraits)
  - [Chapter 12: Numerics](#chapter-12-numerics)
    - [12.2–12.5 Mathematical, Complex & Random Number Utilities](#122125-mathematical-complex--random-number-utilities)
    - [12.6 Vector Arithmetic (`std::valarray`)](#126-vector-arithmetic-stdvalarray)
    - [12.7 `std::numeric_limits`](#127-stdnumeric_limits)
  - [Chapter 13: Concurrency](#chapter-13-concurrency)
    - [13.2 Tasks & Threads](#132-tasks--threads)
    - [13.3 Passing Arguments to Threads](#133-passing-arguments-to-threads)
    - [13.4 Returning Results from Threads](#134-returning-results-from-threads)
    - [13.5 Data Sharing & Synchronization (`std::mutex`, `std::lock_guard`)](#135-data-sharing--synchronization-stdmutex-stdlock_guard)
    - [13.6 Waiting for Events (`std::condition_variable`)](#136-waiting-for-events-stdcondition_variable)
    - [13.7 Communicating Tasks (`std::async`, `std::future`, `std::promise`)](#137-communicating-tasks-stdasync-stdfuture-stdpromise)
  - [Chapter 14: History and Compatibility](#chapter-14-history-and-compatibility)
    - [14.1 History & Standards Evolution](#141-history--standards-evolution)
    - [14.2 Key C++11 Language & Library Extensions Summary](#142-key-c11-language--library-extensions-summary)
    - [14.3 C vs C++ Compatibility](#143-c-vs-c-compatibility)
    - [14.4 Bibliography — Key References](#144-bibliography--key-references)
    - [14.5 Final Advice](#145-final-advice)
- [Bjarne Stroustrup's Core Advice & Best Practices Summary](#bjarne-stroustrups-core-advice--best-practices-summary)
- [Effective Modern C++ — Scott Meyers (C++11/14 Best Practices)](#effective-modern-c--scott-meyers-c1114-best-practices)
  - [Chapter 1: Deducing Types (Items 1–4)](#chapter-1-deducing-types-items-14)
    - [Item 1: Understand Template Type Deduction](#item-1-understand-template-type-deduction)
    - [Item 2: Understand `auto` Type Deduction](#item-2-understand-auto-type-deduction)
    - [Item 3: Understand `decltype`](#item-3-understand-decltype)
    - [Item 4: Know How to View Deduced Types](#item-4-know-how-to-view-deduced-types)
  - [Chapter 2: `auto` (Items 5–6)](#chapter-2-auto-items-56)
    - [Item 5: Prefer `auto` to Explicit Type Declarations](#item-5-prefer-auto-to-explicit-type-declarations)
    - [Item 6: Use the Explicitly Typed Initializer Idiom When `auto` Deduces Undesired Types](#item-6-use-the-explicitly-typed-initializer-idiom-when-auto-deduces-undesired-types)
  - [Chapter 3: Moving to Modern C++ (Items 7–17)](#chapter-3-moving-to-modern-c-items-717)
    - [Item 7: Distinguish Between `()` and `{}` When Creating Objects](#item-7-distinguish-between--and--when-creating-objects)
    - [Item 8: Prefer `nullptr` to `0` and `NULL`](#item-8-prefer-nullptr-to-0-and-null)
    - [Item 9: Prefer Alias Declarations to `typedef`s](#item-9-prefer-alias-declarations-to-typedefs)
    - [Item 10: Prefer Scoped `enum`s to Unscoped `enum`s](#item-10-prefer-scoped-enums-to-unscoped-enums)
    - [Item 11: Prefer Deleted Functions to Private Undefined Ones](#item-11-prefer-deleted-functions-to-private-undefined-ones)
    - [Item 12: Declare Overriding Functions `override`](#item-12-declare-overriding-functions-override)
    - [Item 13: Prefer `const_iterator`s to `iterator`s](#item-13-prefer-const_iterators-to-iterators)
    - [Item 14: Declare Functions `noexcept` If They Won't Emit Exceptions](#item-14-declare-functions-noexcept-if-they-wont-emit-exceptions)
    - [Item 15: Use `constexpr` Whenever Possible](#item-15-use-constexpr-whenever-possible)
    - [Item 16: Make `const` Member Functions Thread Safe](#item-16-make-const-member-functions-thread-safe)
    - [Item 17: Understand Special Member Function Generation](#item-17-understand-special-member-function-generation)
  - [Chapter 4: Smart Pointers (Items 18–22)](#chapter-4-smart-pointers-items-1822)
    - [Item 18: Use `std::unique_ptr` for Exclusive-Ownership Resource Management](#item-18-use-stdunique_ptr-for-exclusive-ownership-resource-management)
    - [Item 19: Use `std::shared_ptr` for Shared-Ownership Resource Management](#item-19-use-stdshared_ptr-for-shared-ownership-resource-management)
    - [Item 20: Use `std::weak_ptr` for `shared_ptr`-like Pointers That Can Dangle](#item-20-use-stdweak_ptr-for-shared_ptr-like-pointers-that-can-dangle)
    - [Item 21: Prefer `std::make_unique` and `std::make_shared` to Direct Use of `new`](#item-21-prefer-stdmake_unique-and-stdmake_shared-to-direct-use-of-new)
    - [Item 22: When Using the Pimpl Idiom, Define Special Member Functions in the Implementation File](#item-22-when-using-the-pimpl-idiom-define-special-member-functions-in-the-implementation-file)
  - [Chapter 5: Rvalue References, Move Semantics, and Perfect Forwarding (Items 23–30)](#chapter-5-rvalue-references-move-semantics-and-perfect-forwarding-items-2330)
    - [Item 23: Understand `std::move` and `std::forward`](#item-23-understand-stdmove-and-stdforward)
    - [Item 24: Distinguish Universal References from Rvalue References](#item-24-distinguish-universal-references-from-rvalue-references)
    - [Item 25: Use `std::move` on Rvalue References, `std::forward` on Universal References](#item-25-use-stdmove-on-rvalue-references-stdforward-on-universal-references)
    - [Item 26: Avoid Overloading on Universal References](#item-26-avoid-overloading-on-universal-references)
    - [Item 27: Familiarize Yourself with Alternatives to Overloading on Universal References](#item-27-familiarize-yourself-with-alternatives-to-overloading-on-universal-references)
    - [Item 28: Understand Reference Collapsing](#item-28-understand-reference-collapsing)
    - [Item 29: Assume That Move Operations Are Not Present, Not Cheap, and Not Used](#item-29-assume-that-move-operations-are-not-present-not-cheap-and-not-used)
    - [Item 30: Familiarize Yourself with Perfect Forwarding Failure Cases](#item-30-familiarize-yourself-with-perfect-forwarding-failure-cases)
  - [Chapter 6: Lambda Expressions (Items 31–34)](#chapter-6-lambda-expressions-items-3134)
    - [Item 31: Avoid Default Capture Modes](#item-31-avoid-default-capture-modes)
    - [Item 32: Use Init Capture to Move Objects into Closures](#item-32-use-init-capture-to-move-objects-into-closures)
    - [Item 33: Use `decltype` on `auto&&` Parameters to `std::forward` Them](#item-33-use-decltype-on-auto-parameters-to-stdforward-them)
    - [Item 34: Prefer Lambdas to `std::bind`](#item-34-prefer-lambdas-to-stdbind)
  - [Chapter 7: The Concurrency API (Items 35–40)](#chapter-7-the-concurrency-api-items-3540)
    - [Item 35: Prefer Task-Based Programming to Thread-Based](#item-35-prefer-task-based-programming-to-thread-based)
    - [Item 36: Specify `std::launch::async` If Asynchronicity Is Essential](#item-36-specify-stdlaunchasync-if-asynchronicity-is-essential)
    - [Item 37: Make `std::thread`s Unjoinable on All Paths](#item-37-make-stdthreads-unjoinable-on-all-paths)
    - [Item 38: Be Aware of Varying Thread Handle Destructor Behavior](#item-38-be-aware-of-varying-thread-handle-destructor-behavior)
    - [Item 39: Consider `void` Futures for One-Shot Event Communication](#item-39-consider-void-futures-for-one-shot-event-communication)
    - [Item 40: Use `std::atomic` for Concurrency, `volatile` for Special Memory](#item-40-use-stdatomic-for-concurrency-volatile-for-special-memory)
  - [Chapter 8: Tweaks (Items 41–42)](#chapter-8-tweaks-items-4142)
    - [Item 41: Consider Pass by Value for Copyable Parameters That Are Cheap to Move and Always Copied](#item-41-consider-pass-by-value-for-copyable-parameters-that-are-cheap-to-move-and-always-copied)
    - [Item 42: Consider Emplacement Instead of Insertion](#item-42-consider-emplacement-instead-of-insertion)

---

## Executive Summary & Core Design Philosophy

Bjarne Stroustrup's _A Tour of C++_ provides a complete high-level tour of the C++ programming language as modernized by the C++11 ISO standard. Rather than an exhaustive reference manual, the book conveys the **spirit and design principles** of idiomatic C++.

### Fundamental Design Guiding Principles of C++

1. **Direct Mapping to Hardware**: Basic language constructs (pointers, array indexing, fundamental types) map cleanly to CPU instructions and memory layout.
2. **Zero-Overhead Abstraction**: High-level abstractions (classes, templates, virtual functions, smart pointers) add no runtime cost compared to equivalent hand-crafted low-level C code. If you don't use a feature, you don't pay for it.
3. **Resource Acquisition Is Initialization (RAII)**: Object lifetimes manage resources (memory, file handles, locks). Constructors acquire resources, and destructors release them automatically when exiting scope.
4. **Static Type Safety**: Type checking occurs at compile time to eliminate runtime errors without performance overhead.
5. **Multi-Paradigm Support**: C++ seamlessly integrates procedural, object-oriented, functional, and generic programming styles.

---

## Chapter-by-Chapter Breakdown

---

### Chapter 1: The Basics

#### 1.1–1.3 Programs & Hello, World!

Every executable C++ program requires a single global `main()` function returning an integer status (`0` indicates success). Header files like `<iostream>` provide access to standard library input/output streams within the `std` namespace.

```cpp
#include <iostream>

int main() {
    std::cout << "Hello, World!\n"; // Standard output stream
    return 0;
}
```

#### 1.4 Functions

Functions express computations. C++ supports pass-by-value, pass-by-reference (`&`), pass-by-const-reference (`const &`), and pass-by-pointer (`*`). Function overloading allows multiple functions with the same name if parameter signatures differ.

#### 1.5 Types, Variables, and Arithmetic

- **Fundamental Types:** `bool`, `char`, `int`, `double`.
- **Uniform Initialization (C++11):** Using brace initialization `{}` prevents dangerous narrowing conversions (e.g. `int x{7.5};` triggers a compiler error, whereas `int x = 7.5;` silently truncates).
- **Type Deduction (`auto`):** The `auto` keyword instructs the compiler to deduce the variable type from its initializer.

```cpp
int a = 7;
double b{7.5};       // Brace initialization
auto c = true;       // Deduce bool
auto d = 3.14159;    // Deduce double
```

#### 1.6 Scope & Lifetime

Variables exist within scopes bounded by `{}` (Local, Class, Namespace, or Global). Local variables are automatically destroyed upon exiting their enclosing block.

#### 1.7 Constants (`const` vs `constexpr`)

- `const`: Promises that the value will not change after initialization. Evaluated at runtime or compile time.
- `constexpr`: Promises that the value can be evaluated at **compile time**. Functions marked `constexpr` can be executed by the compiler if given constant arguments.

```cpp
const int dmv = 17;                 // Named constant evaluated at runtime
constexpr double max_square = 1.414 * 1.414; // Evaluated at compile time

constexpr double square(double x) { return x * x; }
constexpr double sz = square(10);   // Calculated during compilation
```

#### 1.8 Pointers, Arrays, and References

- **Arrays:** Contiguous memory elements of fixed size (`char v[6];`).
- **Pointers:** Holds memory addresses (`char* p = &v[2];`). Indirection via `*p`.
- **`nullptr` (C++11):** Strongly-typed null pointer constant replacing literal `0` or macro `NULL`.
- **References:** An alias to an existing object (`int& r = x;`). Cannot be rebound or set to null.
- **Range-for loop:** Simplifies array/container iteration:

```cpp
int v[] = {0, 1, 2, 3, 4, 5};

for (auto x : v)        // Copy iteration
    std::cout << x << '\n';

for (auto& x : v)       // Reference iteration (allows modification)
    x *= 2;
```

#### 1.9 Tests & Control Structures

Standard control structures: `if`, `switch`, `while`, `for`.

---

### Chapter 2: User-Defined Types

C++ provides four primary forms of user-defined types: `struct`, `class`, `union`, and `enum`.

#### 2.1–2.2 Structures (`struct`)

A `struct` is an aggregate data structure where members are `public` by default.

```cpp
struct Vector {
    int sz;         // Number of elements
    double* elem;   // Pointer to elements
};

void vector_init(Vector& v, int s) {
    v.elem = new double[s]; // Allocate array on heap
    v.sz = s;
}
```

#### 2.3 Classes (`class`)

A `class` enforces encapsulation by separating the public interface from private implementation details (`private` by default).

```cpp
class Vector {
public:
    Vector(int s) : elem{new double[s]}, sz{s} {} // Constructor & initializer list
    ~Vector() { delete[] elem; }                  // Destructor (RAII)

    double& operator[](int i) { return elem[i]; } // Subscript operator
    int size() const { return sz; }               // Const member function

private:
    double* elem; // Pointer to memory
    int sz;       // Element count
};
```

#### 2.4 Unions (`union`)

A `union` is a structure where all members share the exact same memory address space. Only one member holds a value at any given time, saving memory in low-level code.

#### 2.5 Enumerations (`enum` & `enum class`)

C++11 introduced strongly-typed scoped enumerations (`enum class`), preventing implicit conversion to integers and scope pollution.

```cpp
enum class Color { red, blue, green };
enum class TrafficLight { green, yellow, red };

Color c = Color::red;
// int i = c; // ERROR: No implicit conversion to int!
```

---

### Chapter 3: Modularity

#### 3.1–3.2 Separate Compilation & Header Files

Code organization relies on header files (`.h` / `.hpp`) exposing declarations and interfaces, while implementation files (`.cpp`) contain definitions.

- Headers provide compilation independence and interface contracts.
- Modern C++ encourages keeping interface declarations clean and minimal.

#### 3.3 Namespaces

Namespaces prevent naming collisions across libraries:

```cpp
namespace MyLibrary {
    class Vector { /* ... */ };
    void compute();
}

MyLibrary::Vector v(10); // Fully qualified usage
```

#### 3.4 Error Handling & Invariants

- **Exceptions:** Separate error-detection from error-handling using `throw`, `try`, and `catch`.
- **Invariants:** Class constructors must establish class invariants (valid internal state). If an invariant cannot be established, throw an exception.
- **Static Assertions (`static_assert`):** Checked at compile time.

```cpp
Vector::Vector(int s) {
    if (s < 0)
        throw std::length_error{"Vector size cannot be negative"};
    elem = new double[s];
    sz = s;
}

static_assert(sizeof(int) >= 4, "Integers must be at least 32-bit");
```

---

### Chapter 4: Classes

#### 4.1–4.2 Concrete Types & Container Initialization

Concrete types behave just like built-in types (e.g. `Vector`, `Complex`).

- Allocated on stack or heap.
- Resource allocation in constructor, cleanup in destructor (**RAII**).
- **Initializer List Constructor (`std::initializer_list`):** Allows container initialization using brace lists (e.g., `Vector v = {1.2, 2.3, 3.4};`).

```cpp
Vector::Vector(std::initializer_list<double> lst)
    : elem{new double[lst.size()]}, sz{static_cast<int>(lst.size())} {
    std::copy(lst.begin(), lst.end(), elem);
}
```

#### 4.3–4.5 Abstract Types, Class Hierarchies & Controls

Abstract types define pure virtual interfaces (`= 0`) without exposing representation details.

```cpp
class Container {
public:
    virtual double& operator[](int) = 0; // Pure virtual function
    virtual int size() const = 0;
    virtual ~Container() {}             // Virtual destructor is REQUIRED!
};
```

Deriving concrete implementations from abstract interfaces enables runtime polymorphism:

```cpp
class VectorContainer : public Container {
public:
    VectorContainer(int s) : v(s) {}
    ~VectorContainer() override {} // Explicit override tag

    double& operator[](int i) override { return v[i]; }
    int size() const override { return v.size(); }

private:
    Vector v;
};
```

- **Hierarchy Controls (`final`):** Prevent further derivation of a class (`class Base final { ... };`) or overriding of a virtual function (`virtual void f() final;`).
- **Hierarchy Navigation (`dynamic_cast`):** Safely downcast interface pointers/references at runtime using RTTI. Returns `nullptr` if pointer cast fails, or throws `std::bad_cast` for reference cast:

```cpp
if (Shape* s = get_shape()) {
    if (Circle* c = dynamic_cast<Circle*>(s)) {
        // s points to a Circle
    }
}
```

#### 4.4 Virtual Functions

Virtual functions are the mechanism behind runtime polymorphism. When a class declares a `virtual` function, the compiler builds a **vtable** (virtual function table) — a per-class array of function pointers. Each object of the class stores a hidden pointer (the **vptr**) to its class's vtable.

**How dynamic dispatch works:**

```cpp
void use(Container& c) {
    const int sz = c.size();
    for (int i = 0; i != sz; ++i)
        std::cout << c[i] << '\n'; // Dispatch via vtable: calls the correct override
}

VectorContainer vc{10};
use(vc);           // Calls VectorContainer::operator[] at runtime
```

At the call site `c[i]`, the compiler does not know the concrete type of `c` — it follows the vptr to the vtable and calls whichever function pointer is stored there. This resolves at **runtime**, not compile time.

**Key rules for virtual functions:**

- A function is virtual in all classes derived from the class that first declares it `virtual`.
- Use `override` on derived-class overrides to get a compile-time check that the function signature matches.
- A class with at least one pure virtual function (`= 0`) is an **abstract class** — it cannot be instantiated directly.
- **Always declare the destructor `virtual`** in a polymorphic base class; otherwise `delete base_ptr` will only call the base destructor, leaking derived resources.

**Cost:** Virtual dispatch adds one pointer indirection per call and prevents inlining. For most designs this is negligible, but in hot inner loops on tiny objects it can matter.

#### 4.6 Copy and Move Semantics (The Rule of 5)

When a class manages resources (e.g. heap memory handles), default memberwise copy leads to dangling pointers and double-free errors. C++11 introduces **move semantics** to transfer ownership of resources without expensive deep copying.

| Special Member Function | Signature / Concept                                                   |
| :---------------------- | :-------------------------------------------------------------------- |
| **Destructor**          | `~Vector()` — Releases owned resources                                |
| **Copy Constructor**    | `Vector(const Vector& a)` — Deep copy allocation                      |
| **Copy Assignment**     | `Vector& operator=(const Vector& a)` — Deep copy reassignment         |
| **Move Constructor**    | `Vector(Vector&& a)` — Steal resource pointer from rvalue `a`         |
| **Move Assignment**     | `Vector& operator=(Vector&& a)` — Steal resource pointer, release old |

```cpp
// Move Constructor
Vector::Vector(Vector&& a) : elem{a.elem}, sz{a.sz} {
    a.elem = nullptr; // Leave source object in empty/valid state
    a.sz = 0;
}
```

Use `= default;` to request standard compiler-generated operations, or `= delete;` to suppress undesirable copying.

---

### Chapter 5: Templates

Templates enable generic programming by parameterizing types or values.

#### 5.2 Parameterized Class Templates

```cpp
template<typename T>
class Vector {
private:
    T* elem;
    int sz;
public:
    explicit Vector(int s);
    T& operator[](int i);
    int size() const { return sz; }
};
```

#### 5.3 Function Templates

```cpp
template<typename Sequence, typename Value>
Value sum(const Sequence& s, Value v) {
    for (const auto& x : s)
        v += x;
    return v;
}
```

#### 5.4 Concepts and Generic Programming

Generic programming focuses on designing and combining algorithms operating on abstract data types. In C++11, templates check requirements implicitly during instantiation.

- **Type Predicates & Requirements:** Template operations implicitly require types to satisfy specific concepts (e.g. supporting `+`, `==`, or iteration via `begin()`/`end()`).
- Stroustrup emphasizes specifying interface requirements clearly so template compile errors are caught early and meaningfully.

#### 5.5 Function Objects (Functors) & Lambdas

Function objects are classes overloading `operator()`, allowing objects to be invoked like functions while retaining internal state.
C++11 introduced **Lambdas** as concise, inline syntax for function objects:

```cpp
// Lambda expression capturing local environment by reference [&]
int val = 42;
auto print_if_greater = [&val](int x) {
    if (x > val) std::cout << x << '\n';
};
```

#### 5.6 Variadic Templates

Templates accepting a variable number of arbitrary type arguments:

```cpp
template<typename T>
void print(T head) {
    std::cout << head << '\n';
}

template<typename T, typename... Tail>
void print(T head, Tail... tail) {
    std::cout << head << ' ';
    print(tail...); // Recursive pack expansion
}
```

#### 5.7 Aliases (`using`)

Replaces `typedef` with clearer template-compatible syntax:

```cpp
template<typename Value>
using StringMap = std::map<std::string, Value>;

StringMap<int> myMap; // std::map<std::string, int>
```

#### 5.8 Template Compilation Model

- **Inclusion Model:** Unlike normal functions split into `.h` declarations and `.cpp` definitions, template declarations and definitions must both be included in header files so the compiler can instantiate them for concrete type parameters at compile time.
- Compile-time template instantiation occurs on demand when a template is used with specific type arguments.

---

### Chapter 6: Library Overview

The C++ Standard Library (`std`) is built upon standard components:

- Containers (`vector`, `list`, `map`, `unordered_map`)
- Algorithms (`sort`, `find_if`, `transform`, `copy`)
- I/O Streams (`cout`, `cin`, file streams, stringstreams)
- Utilities (`unique_ptr`, `shared_ptr`, `tuple`, `chrono`)
- Concurrency primitives (`thread`, `mutex`, `future`)

Standard library entities reside inside header files without `.h` extensions (e.g. `<vector>`, `<memory>`) within the `std` namespace.

---

### Chapter 7: Strings and Regular Expressions

#### 7.2 `std::string`

- Dynamic character sequence managing its own memory.
- Optimized with Short String Optimization (SSO) for small strings to avoid heap allocation.
- Supports operator overloading (`+`, `+=`, `==`, `<`).

#### 7.3 Regular Expressions (`std::regex`)

Pattern matching and textual search powered by standard regex support:

- `std::regex`: Compiled regex pattern object.
- `std::smatch`: Regex match results.
- `std::regex_search()` / `std::regex_match()` / `std::regex_replace()`.
- **Raw String Literals (C++11):** `R"(pattern)"` avoids double-backslash escaping.

```cpp
#include <regex>
#include <iostream>

void find_zip_codes() {
    std::string text = "ZIP codes: NY 10001, CA 90210";
    std::regex pattern{R"(\b[A-Z]{2}\s\d{5}\b)"}; // Raw string literal

    std::smatch matches;
    while (std::regex_search(text, matches, pattern)) {
        std::cout << "Found match: " << matches[0] << '\n';
        text = matches.suffix().str();
    }
}
```

---

### Chapter 8: I/O Streams

#### 8.1–8.3 Streams (`ostream` & `istream`)

Stream I/O provides type-safe, extensible formatting for input/output.

- Output (`std::cout << x`) converts binary data to text representation.
- Input (`std::cin >> x`) parses formatted input.

#### 8.4 Stream I/O State

Streams maintain state flags to track operation results:

- `good()`: Next operation may succeed.
- `fail()`: Format/conversion error occurred (can be cleared with `clear()`).
- `bad()`: Unrecoverable stream corruption.
- `eof()`: Reached end of file.
- Testing stream status directly in loops evaluates the stream state (e.g., `while (std::cin >> x)` checks if input extraction succeeded).

#### 8.5 User-Defined Type I/O

Streams are extended for custom types by overloading `operator<<` and `operator>>`:

```cpp
struct Entry {
    std::string name;
    int number;
};

std::ostream& operator<<(std::ostream& os, const Entry& e) {
    return os << "{\"" << e.name << "\", " << e.number << "}";
}
```

#### 8.6 Stream Formatting & Manipulators

`<iomanip>` provides stream manipulators for explicit output formatting:

- `std::setprecision(n)`: Sets floating-point precision.
- `std::setw(n)`: Sets output field width.
- `std::hex`, `std::dec`, `std::oct`: Integer radix bases.
- `std::fixed`, `std::scientific`: Floating-point notation.
- `std::boolalpha`: Prints `bool` values as `true`/`false`.

#### 8.7–8.8 File & String Streams

- `std::ifstream` / `std::ofstream`: RAII file reading and writing.
- `std::stringstream`: In-memory string formatting and conversion.

---

### Chapter 9: Containers

C++ Containers store collections of objects, managing memory automatically.

| Container              | Internal Structure | Access Time       | Insertion / Erasure       | Common Use Case                       |
| :--------------------- | :----------------- | :---------------- | :------------------------ | :------------------------------------ |
| `std::vector<T>`       | Contiguous array   | $O(1)$ random     | $O(N)$ middle, $O(1)$ end | **Default container** for performance |
| `std::list<T>`         | Doubly-linked list | $O(N)$ sequential | $O(1)$ anywhere           | Frequent middle insertion             |
| `std::forward_list<T>` | Singly-linked list | $O(N)$ sequential | $O(1)$ anywhere           | Low overhead singly linked list       |
| `std::map<K, V>`       | Red-Black Tree     | $O(\log N)$       | $O(\log N)$               | Sorted key-value lookup               |
| `std::unordered_map`   | Hash Table         | $O(1)$ average    | $O(1)$ average            | Fast key-value lookup                 |

#### 9.6 Container Overview & Operations

- **Element Requirements:** Elements stored in standard containers must be copy-constructible or move-constructible.
- **In-Place Construction (`emplace` / `emplace_back`):** Constructs objects directly inside container memory using forward arguments, avoiding copy/move overheads incurred by `push_back`.
- **Bounds Checking:** Subscripting `v[i]` is unchecked for maximum speed; `v.at(i)` performs explicit range checking, throwing `std::out_of_range` on error.
- **Capacity Management (`vector`):** `v.capacity()` indicates allocated storage before reallocation is required; `v.reserve(n)` preallocates memory for $n$ elements to avoid costly repeated reallocations.

> **Stroustrup's Rule of Thumb:** Use `std::vector` by default unless you have a specific, profiled reason not to. Contiguous memory allocation makes `vector` dramatically faster due to CPU cache locality.

---

### Chapter 10: Algorithms

The Standard Template Library (STL) decouples containers from algorithms using **Iterators**.

#### 10.1–10.3 Iterators & Iterator Taxonomy

Iterators act as generalized pointers operating on half-open ranges `[begin, end)`.

- **Input Iterator:** Read once, forward only (`*it`, `++it`).
- **Output Iterator:** Write once, forward only (`*it = v`, `++it`).
- **Forward Iterator:** Read/write multiple times, forward only (`*it`, `++it`).
- **Bidirectional Iterator:** Forward and backward traversal (`++it`, `--it`; e.g., `std::list`, `std::map`).
- **Random Access Iterator:** Arbitrary jump positioning (`it + n`, `it[n]`, `<`; e.g., `std::vector`, `std::array`).

```cpp
#include <algorithm>
#include <vector>

void example() {
    std::vector<int> v = {4, 1, 8, 3, 9};
    std::sort(v.begin(), v.end());          // Sort container range
    auto it = std::find(v.begin(), v.end(), 8); // Search element
}
```

#### 10.2 Use of Iterators in Practice

Every standard container exposes `begin()` and `end()` member functions that return iterators forming a **half-open range** `[begin, end)` — `begin` points to the first element, `end` points one past the last. An empty container satisfies `begin() == end()`.

**Inserter Iterators**

Standard algorithms write to output ranges via output iterators. Inserter adaptors let an algorithm _insert_ into a container rather than overwrite existing elements:

```cpp
#include <iterator>
#include <vector>
#include <algorithm>

std::vector<int> src = {3, 1, 4, 1, 5};
std::vector<int> dst;

// back_inserter calls push_back on every assignment
std::copy(src.begin(), src.end(), std::back_inserter(dst));

// front_inserter calls push_front (only for deque/list)
std::list<int> lst;
std::copy(src.begin(), src.end(), std::front_inserter(lst));

// inserter inserts at an arbitrary position
std::vector<int> mid;
std::copy(src.begin(), src.end(), std::inserter(mid, mid.begin()));
```

| Inserter                 | Calls              | Works with                          |
| ------------------------ | ------------------ | ----------------------------------- |
| `std::back_inserter(c)`  | `c.push_back(v)`   | `vector`, `deque`, `list`, `string` |
| `std::front_inserter(c)` | `c.push_front(v)`  | `deque`, `list`                     |
| `std::inserter(c, pos)`  | `c.insert(pos, v)` | All containers                      |

**Move Iterators**

`std::make_move_iterator` wraps an iterator so that dereferencing it yields an rvalue, enabling algorithms to **move** elements from a source range rather than copy them:

```cpp
std::vector<std::string> src = {"hello", "world"};
std::vector<std::string> dst;

// Moves strings out of src instead of copying
std::copy(std::make_move_iterator(src.begin()),
          std::make_move_iterator(src.end()),
          std::back_inserter(dst));
// src elements are now in a valid but unspecified (moved-from) state
```

This is especially valuable for containers of move-only types (e.g. `std::unique_ptr`) or to avoid expensive deep copies of large strings/containers.

**Reverse Iterators**

`rbegin()`/`rend()` yield bidirectional reverse iterators, allowing algorithms to process a range back-to-front without changing the algorithm itself:

```cpp
std::vector<int> v = {1, 2, 3, 4, 5};
// Print in reverse
for (auto it = v.rbegin(); it != v.rend(); ++it)
    std::cout << *it << ' '; // 5 4 3 2 1
```

#### 10.4 Stream Iterators

Iterators can bind directly to streams (`std::istream_iterator`, `std::ostream_iterator`), enabling stream processing with algorithms:

```cpp
// Copy unique sorted words from standard input to standard output
std::set<std::string> words{
    std::istream_iterator<std::string>{std::cin},
    std::istream_iterator<std::string>{}
};
std::copy(words.begin(), words.end(),
          std::ostream_iterator<std::string>{std::cout, "\n"});
```

#### 10.5 Predicates

Algorithms take function objects, pointers, or lambdas as **predicates** to customize evaluation:

- Unary Predicate: Takes one argument, returns `bool` (e.g. `find_if(v.begin(), v.end(), [](int x){ return x > 5; })`).
- Binary Predicate: Takes two arguments, returns `bool` (e.g. custom sorting comparators).

#### 10.6 Algorithm Overview

Standard library algorithms fall into distinct functional families:

- **Non-modifying:** `find`, `find_if`, `count`, `count_if`, `equal`, `mismatch`, `search`.
- **Modifying / Transforming:** `copy`, `move`, `transform`, `replace`, `unique`, `fill`, `generate`.
- **Sorting & Searching:** `sort`, `stable_sort`, `binary_search`, `lower_bound`, `upper_bound`.
- **Numeric Algorithms (`<numeric>`):** `accumulate`, `inner_product`, `partial_sum`, `adjacent_difference`, `iota`.

#### 10.7 Container Member Algorithms

Some containers provide their own member-function versions of algorithms that are **semantically or performance-wise different** from the generic `<algorithm>` versions. You should always prefer the member version when available.

**`std::list` and `std::forward_list`** — the canonical examples:

| Operation          | Generic `<algorithm>`                                                                  | Member function                                                          |
| ------------------ | -------------------------------------------------------------------------------------- | ------------------------------------------------------------------------ |
| Sort               | `std::sort(l.begin(), l.end())` — **won't compile** (requires random-access iterators) | `l.sort()` — O(N log N), stable, works with bidirectional iterators      |
| Remove duplicates  | `std::unique` only removes _consecutive_ duplicates and leaves garbage at the end      | `l.unique()` — removes consecutive duplicates _and_ erases them properly |
| Merge sorted lists | `std::merge` copies into a third range                                                 | `l.merge(other)` — splices nodes in O(N), no memory allocation           |
| Splice / relocate  | No generic equivalent                                                                  | `l.splice(pos, other)` — O(1) node relinking, no copy/move               |

```cpp
#include <list>
#include <algorithm>

std::list<int> a = {3, 1, 4, 1, 5, 9, 2, 6};
std::list<int> b = {1, 1, 2, 7};

// Must use member sort — std::sort requires random-access iterators
a.sort();                // {1, 1, 2, 3, 4, 5, 6, 9}
a.unique();              // {1, 2, 3, 4, 5, 6, 9} — removes consecutive duplicates

b.sort();                // {1, 1, 2, 7}
a.merge(b);              // a absorbs b's elements in sorted order; b becomes empty
                         // O(N) node relinking — no copies, no allocation

// splice: move one element from b into a at a given position
std::list<int> src = {10, 20, 30};
auto it = std::next(a.begin(), 2);
a.splice(it, src, src.begin()); // Moves 10 from src into a before 'it'
```

**`std::map` / `std::unordered_map`** — member lookup vs. generic algorithms:

- `map.find(key)` — O(log N), returns an iterator to the key-value pair or `end()`. Far faster than `std::find` (which would do a linear scan of pairs).
- `map.count(key)` — returns 0 or 1 for `map`; useful for existence checks without inserting.
- `map.lower_bound(key)` / `map.upper_bound(key)` — O(log N) range queries on the sorted tree, not available for `unordered_map`.

> **Rule:** When a container provides a member algorithm, use it. The generic algorithm either won't compile, gives worse complexity, or doesn't maintain container invariants (e.g., `std::remove` on a `list` doesn't actually erase nodes — `list::remove` does).

---

### Chapter 11: Utilities

#### 11.2 Resource Management & Smart Pointers (C++11)

Raw pointers create memory leak and double-free hazards. Smart pointers automate memory management via RAII ownership rules:

1. **`std::unique_ptr<T>`:** Exclusive ownership. Low/zero overhead. Cannot be copied, only moved.
2. **`std::shared_ptr<T>`:** Shared ownership powered by atomic reference counting.
3. **`std::weak_ptr<T>`:** Non-owning reference used to break circular `shared_ptr` dependency cycles.

```cpp
#include <memory>

struct Shape {};

void use_smart_pointers() {
    // Unique ownership
    auto p1 = std::make_unique<Shape>(); // C++14 helper / custom construct
    std::unique_ptr<Shape> p2 = std::move(p1); // Transfer ownership

    // Shared ownership
    auto s1 = std::make_shared<Shape>();
    auto s2 = s1; // Shared ownership count = 2
}
```

#### 11.3 Specialized Containers & Utilities

- `std::array<T, N>`: Fixed-size stack-allocated array maintaining STL container interface.
- `std::pair<T1, T2>` & `std::tuple<Types...>`: Heterogeneous fixed-size data structures.
- `std::bitset<N>`: Fixed-size sequence of bits with bitwise operator support.

#### 11.4 Time (`std::chrono`)

The `<chrono>` library provides type-safe, unit-correct time utilities organised around three concepts: **durations**, **clocks**, and **time points**.

**Durations**

A duration represents a span of time as a count of ticks at a known tick period:

```cpp
#include <chrono>
using namespace std::chrono;

auto t1 = 500ms;          // 500 milliseconds  (C++14 literals)
auto t2 = 2s;             // 2 seconds
auto t3 = 1h + 30min;     // 1 hour 30 minutes

// Explicit duration types
duration<long, std::milli> d1{250};   // 250 ms
duration<double>           d2{1.5};   // 1.5 seconds
```

Standard convenience aliases: `nanoseconds`, `microseconds`, `milliseconds`, `seconds`, `minutes`, `hours`.

**Clocks**

| Clock                   | Properties                                            | Use Case               |
| ----------------------- | ----------------------------------------------------- | ---------------------- |
| `system_clock`          | Wall-clock time; may go backward (NTP, DST)           | Timestamps, dates      |
| `steady_clock`          | Monotonic, never goes backward                        | Measuring elapsed time |
| `high_resolution_clock` | Highest available resolution (may alias either above) | Micro-benchmarks       |

**Time Points**

A `time_point` is a duration measured from a clock's **epoch**:

```cpp
// Snapshot the current moment
auto start = steady_clock::now();

// ... do work ...

auto end = steady_clock::now();
auto elapsed = duration_cast<milliseconds>(end - start);
std::cout << "Elapsed: " << elapsed.count() << " ms\n";
```

**Converting to calendar time (`system_clock` only):**

```cpp
auto now    = system_clock::now();
std::time_t t = system_clock::to_time_t(now);
std::cout << std::ctime(&t);   // Human-readable wall-clock time
```

**Sleeping:**

```cpp
#include <thread>
std::this_thread::sleep_for(200ms);
std::this_thread::sleep_until(steady_clock::now() + 1s);
```

> **Rule:** Always use `steady_clock` when measuring elapsed time — `system_clock` can jump backward due to clock adjustments.

#### 11.5 Function Adaptors (`std::function`, `bind`, `mem_fn`)

- **`std::function<R(Args...)>`:** Polymorphic, type-erased wrapper capable of storing any callable entity (lambda, functor, free function, member function pointer).
- **`std::bind` & `std::mem_fn`:** Bind specific arguments or adapt member functions to behave as standalone callables.

```cpp
#include <functional>

int add(int a, int b) { return a + b; }
std::function<int(int, int)> f = add; // Type-erased wrapper
```

#### 11.6 Type Functions & Type Traits (`<type_traits>`)

Compile-time type introspection and trait evaluation (`std::is_integral<T>::value`, `std::is_same<T, U>::value`).

- **`std::enable_if`:** Enables SFINAE (Substitution Failure Is Not An Error) conditional compilation of template functions based on type traits.

---

### Chapter 12: Numerics

#### 12.2–12.5 Mathematical, Complex & Random Number Utilities

- `<cmath>`: Standard mathematical functions (`sin`, `cos`, `pow`, `sqrt`).
- `<numeric>`: Numerical algorithms (`std::accumulate`, `std::inner_product`, `std::partial_sum`, `std::iota`).
- **`std::complex<T>`:** Representation of complex numbers supporting standard arithmetic and trigonometric operations.
- `<random>`: Replaces insecure `rand()` with engines (`std::mt19937`) and explicit statistical distributions (`std::uniform_int_distribution`, `std::normal_distribution`).

```cpp
#include <random>
#include <complex>

void numerics_demo() {
    std::complex<double> z{1.5, 2.0};
    auto z2 = std::sqrt(z);

    std::default_random_engine engine;
    std::uniform_int_distribution<int> dist{1, 6};
    int dice = dist(engine);
}
```

#### 12.6 Vector Arithmetic (`std::valarray`)

`<valarray>` provides `std::valarray<T>`, a numeric array designed for high-performance mathematical vector operations, elementwise arithmetic, and array slicing (`std::slice`).

#### 12.7 `std::numeric_limits`

Compile-time query of numerical type properties:

```cpp
constexpr auto max_int = std::numeric_limits<int>::max();
constexpr auto eps = std::numeric_limits<double>::epsilon();
```

---

### Chapter 13: Concurrency

C++11 introduced standard cross-platform multi-threading support `<thread>`.

#### 13.2 Tasks & Threads

```cpp
#include <thread>
#include <iostream>

void f() { std::cout << "Hello from thread!\n"; }

int main() {
    std::thread t{f}; // Start thread t running f()
    t.join();         // Wait for thread execution to finish
    return 0;
}
```

#### 13.3 Passing Arguments to Threads

Arguments passed to `std::thread` constructors are copied by default. To pass reference parameters, wrap arguments in `std::ref()` or `std::cref()`:

```cpp
void increment(int& val) { ++val; }
int x = 10;
std::thread t{increment, std::ref(x)}; // Explicit reference wrapper
t.join();
```

#### 13.4 Returning Results from Threads

The simplest way to get a result back from a thread is to pass a reference to a shared variable and synchronise access with a mutex — but this is error-prone. The cleaner, idiomatic approach uses `std::future` as the return channel.

**Pattern 1 — `std::promise` + `std::future` (manual)**

A `std::promise<T>` is the write end; its associated `std::future<T>` is the read end. The worker thread calls `promise.set_value()` (or `set_exception()`) and the caller blocks on `future.get()`:

```cpp
#include <future>
#include <thread>

void compute(std::promise<int> p, int x) {
    try {
        p.set_value(x * x);           // Deliver result
    } catch (...) {
        p.set_exception(std::current_exception()); // Propagate exception
    }
}

int main() {
    std::promise<int> prom;
    std::future<int>  fut = prom.get_future();

    std::thread t{compute, std::move(prom), 7};
    std::cout << fut.get() << '\n';   // Blocks until result is ready → 49
    t.join();
}
```

**Pattern 2 — `std::packaged_task` (wrap a callable)**

`std::packaged_task<F>` wraps any callable and automatically manages the promise/future pair:

```cpp
#include <future>
#include <thread>

int square(int x) { return x * x; }

int main() {
    std::packaged_task<int(int)> task{square};
    std::future<int> fut = task.get_future();

    std::thread t{std::move(task), 6}; // Run task on thread
    std::cout << fut.get() << '\n';    // → 36
    t.join();
}
```

**Comparison of result-return mechanisms:**

| Mechanism                      | Who creates thread | Exception propagated?     | Use case                    |
| ------------------------------ | ------------------ | ------------------------- | --------------------------- |
| `std::promise` + `std::future` | You                | Yes (via `set_exception`) | Fine-grained control        |
| `std::packaged_task`           | You                | Yes (automatically)       | Wrapping existing callables |
| `std::async` (§13.7)           | Runtime            | Yes (via `future::get`)   | Simplest high-level usage   |

> The fundamental difference between `promise`/`packaged_task` and `async` is **who manages the thread**. With `promise` and `packaged_task` you create and join threads explicitly; with `async` the runtime handles thread lifecycle.

#### 13.5 Data Sharing & Synchronization (`std::mutex`, `std::lock_guard`)

Prevent race conditions by locking shared data access:

```cpp
#include <mutex>

std::mutex mtx;
int shared_count = 0;

void safe_increment() {
    std::lock_guard<std::mutex> lock{mtx}; // RAII lock acquisition & release
    ++shared_count;
}
```

#### 13.6 Waiting for Events (`std::condition_variable`)

Thread synchronization mechanism allowing threads to sleep until notified of a state change:

```cpp
#include <mutex>
#include <condition_variable>

std::mutex mtx;
std::condition_variable cv;
bool ready = false;

void worker() {
    std::unique_lock<std::mutex> lock{mtx};
    cv.wait(lock, []{ return ready; }); // Wait until predicate is true
    // Process work...
}

void signal() {
    {
        std::lock_guard<std::mutex> lock{mtx};
        ready = true;
    }
    cv.notify_one(); // Wake waiting worker thread
}
```

#### 13.7 Communicating Tasks (`std::async`, `std::future`, `std::promise`)

Task-based concurrency abstracts thread management, returning values or exceptions asynchronously:

- **`std::async`:** High-level task launcher.
- **`std::future`:** Reader handle for an asynchronous result.
- **`std::promise`:** Writer handle to transmit a value/exception to a `future`.
- **`std::packaged_task`:** Wraps any callable target to allow asynchronous execution.

```cpp
#include <future>
#include <iostream>

int calculate_sum(int a, int b) { return a + b; }

void run_task() {
    // Launch task asynchronously
    std::future<int> res = std::async(calculate_sum, 20, 22);

    // Perform other work...

    std::cout << "Result: " << res.get() << '\n'; // Block until result is ready (42)
}
```

---

### Chapter 14: History and Compatibility

#### 14.1 History & Standards Evolution

- **1979:** C with Classes (Bjarne Stroustrup at Bell Labs).
- **1985:** C++ 1.0 release.
- **1998:** C++98 ISO Standard (First formal standardization).
- **2011:** **C++11 Standard** ("Modern C++") — Major language overhaul adding move semantics, auto, lambdas, smart pointers, threads, constexpr, and uniform initialization.

#### 14.2 Key C++11 Language & Library Extensions Summary

- Move semantics & rvalue references (`&&`)
- Type deduction (`auto`, `decltype`)
- Lambda expressions
- Smart pointers (`unique_ptr`, `shared_ptr`, `weak_ptr`)
- `constexpr` compile-time evaluation & `static_assert` static assertions
- Range-based `for` loops
- Scoped `enum class`
- Uniform brace initialization (`{}`) and `std::initializer_list`
- Delegating constructors & in-class member initializers
- Hierarchy controls (`override`, `final`)
- Control over special member functions (`= default`, `= delete`)
- Raw string literals (`R"(...)"`) & user-defined literals
- Concurrency library (`std::thread`, `std::async`, `std::mutex`, `std::condition_variable`)
- Standard type traits (`<type_traits>`) and tuple utilities (`std::tuple`)
- Thread-local storage duration (`thread_local`)

#### 14.3 C vs C++ Compatibility

C++ is almost a superset of C, but enforces **stricter static type checking**. C code using keywords reserved in C++ (like `class`, `new`, `template`) or performing implicit `void*` conversions will not compile in C++.

#### 14.4 Bibliography — Key References

Stroustrup points readers toward the following works for deeper study:

| Reference                                                                        | Description                                                                                                       |
| -------------------------------------------------------------------------------- | ----------------------------------------------------------------------------------------------------------------- |
| **TC++PL4** — _The C++ Programming Language (4th Ed.)_, Stroustrup               | The comprehensive reference; covers every feature of C++11 in full detail. The definitive companion to this tour. |
| **C++PL** — _The C++ Programming Language_, Stroustrup (earlier editions)        | Historical reference for C++98/03.                                                                                |
| **PPP** — _Programming: Principles and Practice Using C++ (2nd Ed.)_, Stroustrup | Introductory textbook for learners new to programming.                                                            |
| **D&E** — _The Design and Evolution of C++_, Stroustrup                          | Explains _why_ language decisions were made — invaluable for understanding C++ design rationale.                  |
| **ISO C++ Standard**                                                             | The formal language specification (`ISO/IEC 14882`).                                                              |
| _Effective C++_ / _More Effective C++_, Scott Meyers                             | Practical best-practice guides complementary to the Tour.                                                         |
| _The C++ Standard Library (2nd Ed.)_, Josuttis                                   | Comprehensive standard library reference.                                                                         |

#### 14.5 Final Advice

Stroustrup closes with a distilled set of guiding principles for programmers learning or working in modern C++:

1. **Learn the language from good books and tutorials** — do not rely solely on online snippets that may reflect outdated or non-idiomatic practices.
2. **Use the standard library** — before writing a data structure or algorithm from scratch, check whether it already exists in `<algorithm>`, `<numeric>`, `<memory>`, or a container header.
3. **Don't overuse the OOP paradigm** — not every problem needs a class hierarchy. Prefer concrete types and templates where appropriate.
4. **Avoid "C with classes"** — raw `new`/`delete`, raw arrays, and manual resource management are superseded by smart pointers, `std::vector`, and RAII wrappers.
5. **Express intent in code** — use `const`, `constexpr`, `override`, `final`, `= delete`, and `[[nodiscard]]` to communicate constraints directly to the compiler and to readers.
6. **Prefer compile-time checking** to runtime checking wherever possible — templates, `static_assert`, and `constexpr` push error detection to compile time.
7. **Keep it simple** — unnecessary complexity is a bug waiting to happen. Write the simplest code that is correct and efficient.

---

## Bjarne Stroustrup's Core Advice & Best Practices Summary

Across all chapters, Stroustrup highlights practical advice for writing modern, safe, clean C++ code:

1. **Prefer `constexpr` and `const`** over macro `#define` constants.
2. **Use brace initialization `{}`** to prevent unintended type truncation / narrowing.
3. **Manage resources using RAII**: Prefer smart pointers (`std::unique_ptr`) or container classes over raw `new`/`delete`.
4. **Use `std::vector` by default**: Benefit from contiguous memory cache efficiency.
5. **Pass large objects by `const &`** and return large resources by value (letting move semantics transfer ownership).
6. **Use `nullptr`** instead of `0` or `NULL`.
7. **Use `enum class`** over plain `enum` to prevent scope pollution and implicit type conversions.
8. **Catch exceptions by reference** (`catch (const std::exception& e)`).
9. **Always declare destructors as `virtual`** in abstract base classes.
10. **Prefer task-based concurrency (`std::async`)** over raw thread creation (`std::thread`).

---

## Effective Modern C++ — Scott Meyers (C++11/14 Best Practices)

> **Author:** Scott Meyers  
> **Topic:** How to use C++11 and C++14 correctly and effectively — 42 specific guidelines covering pitfalls, best practices, and the reasoning behind them.  
> **Relationship to the Tour:** While Stroustrup's Tour explains _what_ the features are, Meyers explains _how to use them correctly_. The two books are complementary.

---

### Chapter 1: Deducing Types (Items 1–4)

#### Item 1: Understand Template Type Deduction

When the compiler deduces `T` in `template<typename T> void f(ParamType param)`, the rules depend on the form of `ParamType`:

**Case 1 — `ParamType` is a pointer or non-universal reference (`T&`, `T*`, `const T&`)**

The reference/pointer part is stripped from the argument's type to deduce `T`, then `ParamType` is reapplied:

```cpp
template<typename T> void f(T& param);

int x = 27;
const int cx = x;
const int& rx = x;

f(x);   // T = int,       ParamType = int&
f(cx);  // T = const int, ParamType = const int&
f(rx);  // T = const int, ParamType = const int& (ref-ness ignored)
```

**Case 2 — `ParamType` is a universal reference (`T&&`)**

- If the argument is an lvalue of type `X`, T is deduced as `X&` (reference collapsing yields `X& &&` → `X&`).
- If the argument is an rvalue of type `X`, T is deduced as `X`.

```cpp
template<typename T> void f(T&& param);

f(x);            // x is lvalue  → T = int&,  ParamType = int&
f(std::move(x)); // rvalue       → T = int,   ParamType = int&&
```

**Case 3 — `ParamType` is by-value (`T`)**

Both reference-ness and top-level const/volatile are stripped:

```cpp
template<typename T> void f(T param);

f(cx);  // T = int (const stripped)
f(rx);  // T = int (const & both stripped)
```

**Array and function arguments:** Arrays decay to pointers in by-value deduction; pass-by-reference preserves the array type (allowing deduction of the size).

```cpp
template<typename T, std::size_t N>
constexpr std::size_t arraySize(T (&)[N]) noexcept { return N; }

int arr[7];
arraySize(arr); // → 7
```

---

#### Item 2: Understand `auto` Type Deduction

`auto` type deduction is **identical to template type deduction** with one exception: `auto` treats a braced initializer as `std::initializer_list<T>`, while template deduction fails for braced initializers.

```cpp
auto x1 = 27;    // int
auto x2(27);     // int
auto x3 = {27};  // std::initializer_list<int>
auto x4{27};     // std::initializer_list<int> (C++11); int (C++17)

// Template equivalent FAILS:
template<typename T> void f(T param);
f({1, 2, 3});    // ERROR: cannot deduce T from braced initializer
```

**In function return types and lambda parameters (C++14):** `auto` uses _template_ deduction rules, so returning `{1, 2, 3}` does not compile.

---

#### Item 3: Understand `decltype`

`decltype(expr)` returns the declared type of an expression **without stripping qualifiers or reference-ness**, unlike `auto`.

```cpp
int x = 0;
decltype(x)    // → int
decltype((x))  // → int& (parenthesised lvalue expression adds &!)
```

**Primary use — trailing return types in templates:**

```cpp
// C++11: deduce return type from expression
template<typename Container, typename Index>
auto authAndAccess(Container& c, Index i) -> decltype(c[i]) {
    return c[i]; // Returns reference if c[i] is a reference
}

// C++14: decltype(auto) preserves reference-ness
template<typename Container, typename Index>
decltype(auto) authAndAccess(Container& c, Index i) {
    return c[i];
}
```

**`decltype(auto)`** applies `decltype` rules to an `auto`-deduced expression — the most common use is preserving reference-ness in forwarding functions.

> **Gotcha:** `decltype((x))` is `int&`, not `int`. Wrapping a variable in extra parentheses changes the deduced type. Avoid `return (local_var);` with `decltype(auto)` — it returns a dangling reference.

---

#### Item 4: Know How to View Deduced Types

Three techniques, in increasing reliability:

1. **IDE tooltips** — hover over a variable; convenient but sometimes wrong for complex templates.
2. **Compiler error messages** — deliberately cause an error to force the compiler to print the type:

```cpp
template<typename T> class TD;  // Declared but not defined

TD<decltype(x)> xType;          // error: implicit instantiation of undefined template 'TD<int>'
                                 // → reveals T = int
```

3. **`typeid` + `std::type_info::name()`** — available at runtime but may produce mangled/simplified names; `const` and `&` are stripped:

```cpp
#include <typeinfo>
std::cout << typeid(x).name() << '\n'; // Platform-dependent ("i" for int on GCC)
```

4. **`boost::typeindex::type_id_with_cvr<T>()`** — most accurate; preserves `const`, `volatile`, and references (requires Boost):

```cpp
#include <boost/type_index.hpp>
using boost::typeindex::type_id_with_cvr;
std::cout << type_id_with_cvr<T>().pretty_name() << '\n';
```

---

### Chapter 2: `auto` (Items 5–6)

#### Item 5: Prefer `auto` to Explicit Type Declarations

`auto` avoids several classes of bugs:

**Uninitialized variables:** `auto` requires an initializer — `auto x;` is a compile error.

**Type mismatches causing silent inefficiency:**

```cpp
std::unordered_map<std::string, int> m;

// BAD: std::pair<const std::string, int> copied into pair<std::string, int>
for (const std::pair<std::string, int>& p : m) { ... }

// GOOD: exact type, no copy
for (const auto& p : m) { ... }
```

**Closure types:** Lambdas have unique unnamed types; `auto` is the only way to store them without `std::function` overhead:

```cpp
auto cmp = [](const int& a, const int& b) { return a < b; }; // Zero overhead
std::function<bool(const int&, const int&)> cmp2 = cmp;      // Heap alloc + indirect call
```

**Portability:** `std::vector<int>::size_type` is 32-bit on 32-bit platforms and 64-bit on 64-bit platforms. `auto sz = v.size()` is always correct; `unsigned sz = v.size()` silently truncates on 64-bit.

---

#### Item 6: Use the Explicitly Typed Initializer Idiom When `auto` Deduces Undesired Types

Some expressions return **proxy objects** — lightweight objects that represent something else. `auto` captures the proxy, not the underlying value.

**Classic example — `std::vector<bool>`:**

`std::vector<bool>` does not store actual `bool`s; it packs bits. `operator[]` returns `std::vector<bool>::reference`, a proxy object, not a `bool&`:

```cpp
std::vector<bool> features = {true, false, true};
auto highPriority = features[0]; // highPriority is a proxy, NOT bool!
                                  // Dangling after the vector is modified/destroyed
```

**Fix — explicitly typed initializer idiom:**

```cpp
auto highPriority = static_cast<bool>(features[0]); // Forces bool conversion immediately
```

Apply this pattern whenever `auto` captures a proxy type unintentionally. Other proxy types include `std::bitset::reference`, expression template results in Eigen/Blaze math libraries.

---

### Chapter 3: Moving to Modern C++ (Items 7–17)

#### Item 7: Distinguish Between `()` and `{}` When Creating Objects

C++11 introduced **uniform brace initialization** `{}` as a single syntax for all initialization contexts.

**What `{}` prevents:** narrowing conversions are compile errors:

```cpp
double d = 3.14;
int a{d};   // ERROR: narrowing conversion
int b(d);   // OK: silently truncates to 3
int c = d;  // OK: silently truncates to 3
```

**The `std::initializer_list` hijacking problem:**

If a class has a constructor taking `std::initializer_list`, `{}` syntax **strongly prefers** it over other constructors, even when the match is worse:

```cpp
std::vector<int> v1(10, 20); // 10 elements all equal to 20
std::vector<int> v2{10, 20}; // 2 elements: 10 and 20
```

This distinction is critical when writing template code that creates objects — `()` and `{}` can produce completely different results.

**Rule of thumb:**

- Prefer `{}` for general initialization (prevents narrowing, works everywhere).
- Use `()` when you explicitly need the non-`initializer_list` constructor.
- In templates, be aware of the difference and document which you intend.

---

#### Item 8: Prefer `nullptr` to `0` and `NULL`

`0` and `NULL` are integers (or integer-like macros), not pointer types. This causes ambiguity in overload resolution:

```cpp
void f(int);
void f(void*);

f(0);       // Calls f(int) — probably not intended
f(NULL);    // Implementation-defined; may call f(int) or be ambiguous
f(nullptr); // Calls f(void*) — unambiguous
```

`nullptr` has type `std::nullptr_t`, which implicitly converts to any pointer type but never to an integer. It also works correctly through templates where `0`/`NULL` would deduce as `int`.

---

#### Item 9: Prefer Alias Declarations to `typedef`s

Alias declarations (`using`) are equivalent to `typedef` but have two advantages:

**Readability for function pointer types:**

```cpp
typedef void (*FP)(int, const std::string&); // Harder to parse
using FP = void(*)(int, const std::string&); // Clear: FP is an alias for...
```

**Template aliases (impossible with `typedef`):**

```cpp
// typedef cannot be templated directly
template<typename T>
using MyAllocList = std::list<T, MyAllocator<T>>; // Alias template

MyAllocList<Widget> lw; // Clean usage
```

With `typedef` you need a struct wrapper (`typedef struct { typedef std::list<T, MyAllocator<T>> type; } MyAllocList;`) which requires `typename MyAllocList<T>::type` at use sites — verbose and error-prone.

---

#### Item 10: Prefer Scoped `enum`s to Unscoped `enum`s

| Feature                      | `enum` (unscoped)                  | `enum class` (scoped)      |
| ---------------------------- | ---------------------------------- | -------------------------- |
| Enumerator scope             | Leaks into enclosing scope         | Contained within enum name |
| Implicit conversion to `int` | Yes                                | No                         |
| Forward declaration          | Requires underlying type specified | Always allowed             |

```cpp
enum Color { black, white, red };   // black, white, red in global scope!
auto white = false;                  // ERROR: white already declared

enum class Color { black, white, red };
auto white = false;                  // OK: no conflict
Color c = Color::white;              // Must qualify
// int i = c;                        // ERROR: no implicit conversion
int i = static_cast<int>(c);        // OK: explicit
```

The one case where unscoped enums have an advantage: referencing `std::tuple` fields by name using `std::get<field>(tuple)` where implicit `int` conversion is convenient.

---

#### Item 11: Prefer Deleted Functions to Private Undefined Ones

The old C++98 idiom for preventing copying was to declare copy constructor/assignment `private` and not define them. The C++11 way is `= delete`:

```cpp
// C++98 way — error only at link time (or inside class/friend)
class Widget {
private:
    Widget(const Widget&);
    Widget& operator=(const Widget&);
};

// C++11 way — error at compile time, clearer intent
class Widget {
public:
    Widget(const Widget&) = delete;
    Widget& operator=(const Widget&) = delete;
};
```

**`= delete` works on any function**, not just special members. Use it to prevent undesired implicit conversions:

```cpp
bool isLucky(int);
bool isLucky(char)   = delete;  // Prevent char → int promotion
bool isLucky(double) = delete;  // Prevent double → int truncation
```

**`= delete` on template specializations** prevents instantiation of specific types:

```cpp
template<typename T> void processPointer(T* ptr);
template<> void processPointer<void>(void*)   = delete; // No void* allowed
template<> void processPointer<char>(char*)   = delete; // No char* allowed
```

---

#### Item 12: Declare Overriding Functions `override`

Virtual function overriding requires an exact signature match (name, parameter types, const-ness, reference qualifiers, return type). A mismatch silently creates a **new** virtual function instead of overriding:

```cpp
class Base {
public:
    virtual void f1() const;
    virtual void f2(int x);
};

class Derived : public Base {
public:
    virtual void f1();        // Doesn't override! (missing const) — compiles silently
    virtual void f2(unsigned x); // Doesn't override! (different param type)
};
```

Adding `override` turns these silent bugs into compile errors:

```cpp
class Derived : public Base {
public:
    virtual void f1() override;         // ERROR: no matching base function
    virtual void f2(unsigned x) override; // ERROR: no matching base function
};
```

**Reference qualifiers** (C++11) also participate in override matching:

```cpp
class Widget {
public:
    void doWork() &;   // Called only on lvalue Widgets
    void doWork() &&;  // Called only on rvalue Widgets
};
```

Always use `override` on intended overrides — it is free documentation and a safety net.

---

#### Item 13: Prefer `const_iterator`s to `iterator`s

Use `const_iterator` whenever you don't need to modify elements — it expresses intent and enables use in `const` contexts.

**C++11 adds `cbegin()`/`cend()`** member functions returning `const_iterator`:

```cpp
std::vector<int> v = {1, 2, 3, 4, 5};

auto it = std::find(v.cbegin(), v.cend(), 3); // const_iterator
v.insert(it, 99); // insert accepts const_iterator in C++11
```

In generic code, prefer non-member `std::cbegin()`/`std::cend()` (C++14) over member functions — they work with arrays and containers equally:

```cpp
template<typename C, typename V>
void findAndInsert(C& container, const V& target, const V& value) {
    auto it = std::find(std::cbegin(container), std::cend(container), target);
    container.insert(it, value);
}
```

---

#### Item 14: Declare Functions `noexcept` If They Won't Emit Exceptions

`noexcept` is part of a function's **interface**, not just an optimisation hint. If a `noexcept` function throws, `std::terminate` is called immediately (no stack unwinding).

**Performance implication — move vs copy in containers:**

`std::vector::push_back` and similar operations need to provide a **strong exception guarantee**: if reallocation fails, the original data must be intact. The implementation uses:

- **Move** if the move constructor is `noexcept` (safe — partial move cannot throw and leave broken state)
- **Copy** otherwise (safe fallback)

```cpp
class Widget {
public:
    Widget(Widget&&) noexcept;            // noexcept → vector will move
    Widget& operator=(Widget&&) noexcept; // noexcept → move assignment optimised
};
```

Without `noexcept` on move operations, standard containers silently fall back to copying — potentially catastrophic for performance.

**Other contexts where `noexcept` is critical:** `swap`, destructors (implicitly `noexcept` in C++11), `operator delete`.

> Functions that can genuinely never throw should be declared `noexcept` — but never lie. Adding `noexcept` to a function that can throw is worse than omitting it.

---

#### Item 15: Use `constexpr` Whenever Possible

`constexpr` **objects** are const and initialized with compile-time constant values — they can appear in contexts requiring compile-time constants (array sizes, template arguments, `static_assert`).

`constexpr` **functions** may be evaluated at compile time _or_ runtime depending on context:

```cpp
constexpr int pow(int base, int exp) noexcept {
    // C++14: full statement body allowed
    int result = 1;
    for (int i = 0; i < exp; ++i) result *= base;
    return result;
}

constexpr auto numConds = 5;
std::array<int, pow(3, numConds)> results; // Compile-time: array size known

int base = 3, exp = 10;
auto val = pow(base, exp); // Runtime: base/exp not constexpr
```

**C++11 restriction:** `constexpr` functions could only contain a single `return` statement. C++14 removed this restriction (loops, local variables, etc. are allowed).

`constexpr` is part of a function's interface — removing it later is a breaking change. Apply it wherever semantically correct.

---

#### Item 16: Make `const` Member Functions Thread Safe

A `const` member function conceptually does not modify the object, so callers assume concurrent calls are safe. But `mutable` members inside the class can break this:

```cpp
class Polynomial {
public:
    // Looks thread-safe — it's const!
    double computeRoots() const {
        if (!rootsAreValid) {
            // Compute expensive roots...
            rootVals = { ... };      // Modifies mutable member!
            rootsAreValid = true;
        }
        return rootVals;
    }
private:
    mutable bool rootsAreValid = false;
    mutable std::vector<double> rootVals;
};
```

Two concurrent calls to `computeRoots()` have a data race on `rootsAreValid`. **Fix with `std::mutex`:**

```cpp
class Polynomial {
public:
    double computeRoots() const {
        std::lock_guard<std::mutex> g(m); // RAII lock
        if (!rootsAreValid) {
            rootVals = { ... };
            rootsAreValid = true;
        }
        return rootVals;
    }
private:
    mutable std::mutex m;
    mutable bool rootsAreValid = false;
    mutable std::vector<double> rootVals;
};
```

For a single value, `std::atomic` is cheaper than a mutex:

```cpp
class Point {
public:
    double distanceFromOrigin() const noexcept {
        ++callCount;            // Atomic increment — no mutex needed
        return std::sqrt(x*x + y*y);
    }
private:
    mutable std::atomic<unsigned> callCount{0};
    double x, y;
};
```

> `std::atomic` is appropriate for a single variable; use `std::mutex` when multiple variables must be updated atomically together.

---

#### Item 17: Understand Special Member Function Generation

The compiler auto-generates six special member functions under specific conditions. The rules are subtle:

| Special Member       | Auto-Generated When                                   |
| -------------------- | ----------------------------------------------------- |
| Default constructor  | No user-declared constructors                         |
| Destructor           | Always (unless user-declared); implicitly `noexcept`  |
| Copy constructor     | No user-declared move operations                      |
| Copy assignment      | No user-declared move operations                      |
| **Move constructor** | No user-declared copy ops, move assign, or destructor |
| **Move assignment**  | No user-declared copy ops, move ctor, or destructor   |

**Key interactions (the "Rule of 5" extended):**

- Declaring a **destructor** suppresses auto-generation of move operations (copy operations are still generated but deprecated).
- Declaring a **move constructor or move assignment** suppresses auto-generation of the other move operation _and_ deletes the copy operations.
- Declaring **copy constructor or copy assignment** suppresses auto-generation of move operations.

```cpp
class Widget {
public:
    ~Widget();             // User destructor → move ops NOT generated
                           // Copy ops still generated (but deprecated behavior)
    // To restore move ops explicitly:
    Widget(Widget&&) = default;
    Widget& operator=(Widget&&) = default;
    // And to be safe, explicitly define copies too:
    Widget(const Widget&) = default;
    Widget& operator=(const Widget&) = default;
};
```

> The **Rule of Five**: if you declare _any_ of destructor, copy ctor, copy assign, move ctor, move assign — declare all five explicitly (`= default` or custom). This avoids the generation-suppression interactions silently degrading performance (falling back to copies instead of moves).

---

### Chapter 4: Smart Pointers (Items 18–22)

#### Item 18: Use `std::unique_ptr` for Exclusive-Ownership Resource Management

`std::unique_ptr` owns its resource exclusively. It has **zero overhead** compared to a raw pointer when using the default deleter. It is move-only (not copyable).

**Custom deleters:** When the resource requires special cleanup, provide a custom deleter:

```cpp
auto delInvmt = [](Investment* pInvestment) {  // Lambda deleter
    makeLogEntry(pInvestment);
    delete pInvestment;
};

std::unique_ptr<Investment, decltype(delInvmt)> pInv(nullptr, delInvmt);
```

**Size impact:** A `unique_ptr` with a lambda deleter is still the same size as a raw pointer. A `unique_ptr` with a function pointer deleter grows to two pointer sizes. Stateless lambdas (no captures) add no size.

**Converting to `shared_ptr`:** `unique_ptr` implicitly converts to `shared_ptr`, making it the right factory return type:

```cpp
std::unique_ptr<Shape> makeShape(ShapeType type) {
    // ...
    return std::make_unique<Circle>(radius); // Caller can move into shared_ptr
}
```

---

#### Item 19: Use `std::shared_ptr` for Shared-Ownership Resource Management

`shared_ptr` uses atomic reference counting via a **control block** (heap-allocated alongside or separately from the managed object). When the count reaches zero, the destructor runs.

**Size:** A `shared_ptr` is two pointer sizes — one to the managed object, one to the control block.

**Rules for control blocks:**

- `std::make_shared` creates object + control block in a single allocation (more efficient).
- Constructing a `shared_ptr` from a raw pointer creates a new control block — **never construct two `shared_ptr`s from the same raw pointer** (double-free):

```cpp
int* raw = new int(42);
std::shared_ptr<int> p1(raw);
std::shared_ptr<int> p2(raw); // DISASTER: two control blocks, double-free
```

**`enable_shared_from_this`:** Allows an object to safely get a `shared_ptr` to itself from within a member function:

```cpp
class Widget : public std::enable_shared_from_this<Widget> {
public:
    void process() {
        auto self = shared_from_this(); // Safe — uses existing control block
        processedWidgets.push_back(self);
    }
};
```

**Custom deleters:** Unlike `unique_ptr`, the deleter type is not part of the `shared_ptr` type — two `shared_ptr<Widget>` with different deleters are the same type.

---

#### Item 20: Use `std::weak_ptr` for `shared_ptr`-like Pointers That Can Dangle

`weak_ptr` is a non-owning observer of a `shared_ptr`-managed resource. It does not affect the reference count. Use `lock()` to get a `shared_ptr` — it returns `nullptr` if the resource has been destroyed:

```cpp
auto spw = std::make_shared<Widget>(); // ref count = 1
std::weak_ptr<Widget> wpw(spw);        // weak count = 1, ref count still 1

spw = nullptr;                         // ref count = 0 → Widget destroyed
                                        // weak count still 1 (control block lives)

auto sp = wpw.lock();  // Returns shared_ptr or nullptr
if (sp) { /* safe to use */ }
```

**Use cases:**

1. **Cache:** Store `weak_ptr` in a cache map; `lock()` before use, re-compute if expired.
2. **Observer pattern:** Observers hold `weak_ptr` to the subject — no ownership coupling.
3. **Breaking `shared_ptr` cycles:** In a parent↔child graph, parent holds `shared_ptr<Child>`, child holds `weak_ptr<Parent>` — prevents circular ownership leak.

---

#### Item 21: Prefer `std::make_unique` and `std::make_shared` to Direct Use of `new`

**Reason 1 — Exception safety:**

```cpp
// DANGEROUS: if Widget ctor throws after new but before shared_ptr ctor,
// or if computePriority() throws between the two evaluations, memory leaks
processWidget(std::shared_ptr<Widget>(new Widget), computePriority());

// SAFE: make_shared is a single expression — no interleaving possible
processWidget(std::make_shared<Widget>(), computePriority());
```

**Reason 2 — Performance (`make_shared` only):** `make_shared` allocates the object and control block in a **single heap allocation**. `shared_ptr(new T)` does two allocations.

**Reason 3 — No type repetition:**

```cpp
auto p = std::make_unique<Widget>(); // Type stated once
std::unique_ptr<Widget> p(new Widget); // Widget stated twice
```

**When `make_` functions are not usable:**

- Custom deleters (make functions don't support them).
- `std::initializer_list` construction: `make_shared<vector<int>>(10, 20)` calls `vector(10, 20)` (10 elements), not `vector{10, 20}` (2 elements). Use `new` directly in this case.
- For `shared_ptr` with very large objects where you want object memory freed before control block memory (make_shared keeps both alive until weak count hits zero).

---

#### Item 22: When Using the Pimpl Idiom, Define Special Member Functions in the Implementation File

The **Pimpl Idiom** (pointer-to-implementation) hides implementation details behind a forward-declared class, reducing compilation dependencies:

```cpp
// widget.h
class Widget {
public:
    Widget();
    ~Widget();                            // Must be declared
    Widget(Widget&&) noexcept;
    Widget& operator=(Widget&&) noexcept;
    Widget(const Widget&);
    Widget& operator=(const Widget&);
private:
    struct Impl;                          // Forward declaration
    std::unique_ptr<Impl> pImpl;          // unique_ptr to incomplete type
};
```

```cpp
// widget.cpp
#include "widget.h"
#include "gadget.h" // Only needed here, not in header

struct Widget::Impl {
    std::string name;
    Gadget g1, g2; // Full definition available here
};

Widget::Widget() : pImpl(std::make_unique<Impl>()) {}
Widget::~Widget() = default;  // MUST be defined here — Impl is complete here

Widget::Widget(Widget&&) noexcept = default;
Widget& Widget::operator=(Widget&&) noexcept = default;

Widget::Widget(const Widget& rhs) : pImpl(std::make_unique<Impl>(*rhs.pImpl)) {}
Widget& Widget::operator=(const Widget& rhs) { *pImpl = *rhs.pImpl; return *this; }
```

**Why the destructor must be in the `.cpp`:** `unique_ptr`'s destructor calls `delete` on the managed object, which requires the type to be complete. If `~Widget()` is defaulted in the header, `Impl` is incomplete at that point — compile error. Defining it in the `.cpp` where `Impl` is complete fixes it.

The same logic applies to move operations (they may call the destructor on the moved-from object).

---

### Chapter 5: Rvalue References, Move Semantics, and Perfect Forwarding (Items 23–30)

#### Item 23: Understand `std::move` and `std::forward`

**`std::move` does NOT move anything.** It is an unconditional cast to an rvalue reference — nothing more. The actual move happens in the move constructor or move assignment operator that receives the rvalue.

```cpp
std::string s1 = "hello";
std::string s2 = std::move(s1); // move() casts s1 to rvalue; string move-ctor does the move
// s1 is now in a valid but unspecified state
```

**`std::forward` is a conditional cast.** It casts to an rvalue only if the argument was initialised with an rvalue. This preserves the value category of the original argument through a forwarding layer:

```cpp
template<typename T>
void logAndProcess(T&& param) {
    log("calling process");
    process(std::forward<T>(param)); // Cast to rvalue iff T was deduced as non-reference
}
```

**Never use `std::move` on a `const` object:** the result is a `const` rvalue, which most move constructors cannot bind to (they take `T&&`, not `const T&&`) — the compiler silently falls back to copying.

---

#### Item 24: Distinguish Universal References from Rvalue References

`T&&` means two different things depending on context:

| Syntax                                   | Meaning                                            |
| ---------------------------------------- | -------------------------------------------------- |
| `void f(Widget&& param)`                 | Rvalue reference — binds only to rvalues           |
| `template<typename T> void f(T&& param)` | Universal reference — binds to lvalues AND rvalues |
| `auto&& var = expr`                      | Universal reference                                |

A universal reference requires **type deduction**. Without deduction, `&&` is just an rvalue reference:

```cpp
template<typename T>
void f(T&& param);         // Universal reference (T deduced)

template<typename T>
void f(std::vector<T>&&);  // Rvalue reference (T in vector, param not deduced directly)

Widget&& w = Widget();     // Rvalue reference (no deduction)
```

This distinction matters because universal references can bind to lvalues (and thus should be forwarded with `std::forward`, not cast with `std::move`).

---

#### Item 25: Use `std::move` on Rvalue References, `std::forward` on Universal References

Apply the correct cast depending on the reference type — mixing them causes subtle bugs:

```cpp
class Widget {
public:
    // Rvalue reference parameter → move unconditionally
    Widget(Widget&& rhs)
        : name(std::move(rhs.name)),     // CORRECT
          p(std::move(rhs.p)) {}

    // Universal reference parameter → forward conditionally
    template<typename T>
    void setName(T&& newName) {
        name = std::forward<T>(newName); // CORRECT: preserves lvalue/rvalue
    }
};
```

**Why not always `std::move` in a template?**

```cpp
template<typename T>
void setName(T&& newName) {
    name = std::move(newName); // WRONG if called with lvalue: silently moves from caller's object
}

std::string n = "Widget";
w.setName(n);  // n is now in moved-from state — caller's string destroyed!
```

**Returning local variables:** Use neither `move` nor `forward` on local variables being returned — the compiler applies **NRVO (Named Return Value Optimisation)** or implicit move automatically. Adding `std::move` can prevent NRVO:

```cpp
Widget makeWidget() {
    Widget w;
    return w;            // GOOD: NRVO or implicit move
    return std::move(w); // BAD: prevents NRVO, may be slower
}
```

---

#### Item 26: Avoid Overloading on Universal References

A universal reference function template will be instantiated to match almost any argument type — often beating non-template overloads in resolution:

```cpp
std::multiset<std::string> names;

template<typename T>
void logAndAdd(T&& name) {
    names.emplace(std::forward<T>(name));
}

void logAndAdd(int idx); // Overload for index lookup

short s = 5;
logAndAdd(s); // Calls TEMPLATE (short → int& is not exact; T=short is exact match)
              // Not the int overload — silent wrong behaviour
```

The template instantiation `logAndAdd<short&>` is a better match than `logAndAdd(int)` for a `short` argument. This leads to deeply confusing overload resolution and near-impossible-to-diagnose errors, especially with constructors.

**Rule:** Avoid overloading functions that take universal reference parameters.

---

#### Item 27: Familiarize Yourself with Alternatives to Overloading on Universal References

When you need the flexibility of universal references without the overload resolution hazards:

**Option 1 — Tag dispatch:** Add a dummy parameter to distinguish overloads at compile time without competing with the universal reference:

```cpp
template<typename T>
void logAndAddImpl(T&& name, std::false_type) { // Non-integral path
    names.emplace(std::forward<T>(name));
}

void logAndAddImpl(int idx, std::true_type) { // Integral path
    logAndAdd(nameFromIdx(idx));
}

template<typename T>
void logAndAdd(T&& name) {
    logAndAddImpl(std::forward<T>(name),
                  std::is_integral<std::remove_reference_t<T>>{});
}
```

**Option 2 — `std::enable_if` with SFINAE:** Constrain the template to only participate in overload resolution for specific types:

```cpp
template<typename T,
         typename = std::enable_if_t<!std::is_same_v<std::decay_t<T>, Widget>>>
explicit Widget(T&& n) : name(std::forward<T>(n)) {}
```

**Option 3 — `if constexpr` (C++17):** Single function body with compile-time branching — the cleanest modern approach:

```cpp
template<typename T>
void logAndAdd(T&& name) {
    if constexpr (std::is_integral_v<std::remove_reference_t<T>>) {
        logAndAdd(nameFromIdx(name)); // Integral branch
    } else {
        names.emplace(std::forward<T>(name)); // General branch
    }
}
```

---

#### Item 28: Understand Reference Collapsing

Reference collapsing is the compiler rule that resolves combinations of `&` and `&&`:

| Combination | Result |
| ----------- | ------ |
| `& &`       | `&`    |
| `& &&`      | `&`    |
| `&& &`      | `&`    |
| `&& &&`     | `&&`   |

**Rule: any lvalue reference in the combination produces an lvalue reference.**

This is the mechanic behind universal references. When `T&&` is instantiated with `T = int&`:
`int& &&` collapses to `int&` — an lvalue reference. When `T = int`: `int&&` stays `int&&`.

Reference collapsing occurs in four contexts:

1. Template instantiation (as above)
2. `auto` type deduction
3. `decltype` expressions
4. `typedef` / `using` aliases

This is also why `std::forward<T>(x)` works — `forward` is defined as:

```cpp
template<typename T>
T&& forward(std::remove_reference_t<T>& param) noexcept {
    return static_cast<T&&>(param);
}
```

When `T = int&`: `static_cast<int& &&>` collapses to `static_cast<int&>` — forwards as lvalue.  
When `T = int`: `static_cast<int&&>` — forwards as rvalue.

---

#### Item 29: Assume That Move Operations Are Not Present, Not Cheap, and Not Used

Move semantics are not universally fast. Three important cases where moves are not O(1):

**`std::array`:** Unlike `std::vector` (which moves by swapping an internal pointer), `std::array` stores elements directly in its object. Moving an `std::array<T, N>` moves all N elements — O(N):

```cpp
std::array<Widget, 100> a1;
auto a2 = std::move(a1); // Moves 100 Widgets — NOT O(1)
```

**Small String Optimisation (SSO):** `std::string` implementations store short strings (typically ≤15 chars) in an inline buffer within the string object — no heap allocation. Moving such a string must copy the inline buffer — O(N), not O(1).

**No `noexcept` guarantee:** Standard containers (e.g., `std::vector::push_back`) use copy instead of move if the move constructor is not `noexcept`. A missing `noexcept` silently disables move optimisation in containers.

**Conclusion:** In generic code, do not assume moves are cheap. In known concrete code (e.g., `std::vector<std::string>` with long strings), moves are fast.

---

#### Item 30: Familiarize Yourself with Perfect Forwarding Failure Cases

Perfect forwarding (`std::forward<T>(arg)`) fails when the compiler deduces a different type than intended, or deduction fails entirely:

**Case 1 — Braced initializers:**

```cpp
void f(const std::vector<int>& v);
f({1, 2, 3});              // OK: implicit conversion to vector<int>

template<typename T>
void fwd(T&& p) { f(std::forward<T>(p)); }
fwd({1, 2, 3});            // FAILS: cannot deduce T from braced initializer
```

Fix: assign to an `auto` variable first: `auto il = {1, 2, 3}; fwd(il);`

**Case 2 — `0` or `NULL` as null pointers:** Both deduce as `int`, not as a pointer type. Use `nullptr`.

**Case 3 — Integral `const static` data members without definitions:**

```cpp
class Widget {
    static const int MinVals = 28; // Declaration only — no definition
};
fwd(Widget::MinVals); // May fail: forwarding by reference requires an address (ODR-use)
```

Fix: provide a definition in the `.cpp` file: `const int Widget::MinVals;`

**Case 4 — Overloaded function names and function templates:**

```cpp
void process(int);
void process(int, int);

fwd(process);  // FAILS: which overload? Compiler cannot deduce
```

Fix: cast to the specific function pointer type: `fwd(static_cast<void(*)(int)>(process));`

**Case 5 — Bitfields:** Non-`const` references cannot bind to bitfields (they are not addressable). Pass a copy: `fwd(static_cast<uint32_t>(h.totalLength));`

---

### Chapter 6: Lambda Expressions (Items 31–34)

#### Item 31: Avoid Default Capture Modes

**`[&]` default capture by reference** risks dangling references when the closure outlives the local variables:

```cpp
void addDivisorFilter() {
    auto divisor = computeDivisor();
    filters.emplace_back(
        [&](int value) { return value % divisor == 0; } // divisor dangles after return!
    );
}
```

**`[=]` default capture by value** gives a false sense of safety:

1. Pointers are copied — the _pointed-to_ data can still dangle.
2. Inside member functions, `[=]` captures `this` (the pointer), not the member data directly:

```cpp
class Widget {
    int divisor;
public:
    void addFilter() const {
        filters.emplace_back(
            [=](int val) { return val % divisor == 0; } // Captures 'this', not divisor!
        );                                               // Dangles if Widget is destroyed
    }
};
```

Fix: capture explicitly by name, or in C++14 use init capture to copy the member:

```cpp
filters.emplace_back(
    [divisor = divisor](int val) { return val % divisor == 0; } // C++14 init capture
);
```

---

#### Item 32: Use Init Capture to Move Objects into Closures

C++11 lambdas cannot move-capture — only copy or reference capture. C++14 **init capture** (generalised lambda capture) solves this:

```cpp
auto pw = std::make_unique<Widget>();

// C++14: move pw into the closure
auto func = [pw = std::move(pw)]() {
    pw->doSomething();
};
// pw in outer scope is now null; closure owns the Widget
```

The syntax `[newName = expr]` creates a new closure member `newName` initialised from `expr`. The `expr` is evaluated in the outer scope; `newName` lives in the closure scope.

**C++11 workaround:** Use `std::bind` to emulate move capture:

```cpp
auto func = std::bind(
    [](const std::unique_ptr<Widget>& pw) { pw->doSomething(); },
    std::make_unique<Widget>()
);
```

---

#### Item 33: Use `decltype` on `auto&&` Parameters to `std::forward` Them

C++14 **generic lambdas** accept `auto` parameters — they are function templates under the hood. To perfectly forward such parameters, use `decltype` to recover the original type:

```cpp
// Generic lambda with perfect forwarding
auto f = [](auto&& param) {
    return someFunction(std::forward<decltype(param)>(param));
};
```

`decltype(param)` yields `T&` for lvalue arguments and `T&&` for rvalue arguments. When passed to `std::forward`, reference collapsing produces the correct cast in each case.

**Variadic generic lambdas (C++14):**

```cpp
auto f = [](auto&&... params) {
    return someFunction(std::forward<decltype(params)>(params)...);
};
```

---

#### Item 34: Prefer Lambdas to `std::bind`

Lambdas are almost always clearer, faster, and less error-prone than `std::bind`:

**Readability:**

```cpp
// std::bind — what does this do?
auto f = std::bind(setAlarm, std::bind(std::plus<>(), steady_clock::now(), 1h),
                   _1, 30s);

// Lambda — immediately clear
auto f = [](Sound s) {
    setAlarm(steady_clock::now() + 1h, s, 30s);
};
```

**Performance:** `std::bind` stores arguments as copies and dispatches through function pointers (no inlining). Lambdas are typically inlined by the compiler.

**Overload resolution:** `std::bind` cannot disambiguate overloaded function names without an explicit cast. Lambdas call the function directly.

**When `std::bind` is still warranted (C++11 only):**

- Move-capturing (before C++14 init capture)
- Polymorphic function objects where `auto` parameters aren't yet available

In C++14 and later, there is no use case where `std::bind` beats a lambda.

---

### Chapter 7: The Concurrency API (Items 35–40)

#### Item 35: Prefer Task-Based Programming to Thread-Based

Two ways to run `doAsyncWork` asynchronously:

```cpp
// Thread-based
std::thread t(doAsyncWork);

// Task-based
auto fut = std::async(doAsyncWork);
```

**Task-based advantages:**

- Access to the return value (or exception) via `fut.get()` — threads have no return mechanism.
- The runtime can optimize thread reuse via thread pools — `std::thread` always creates a new OS thread.
- No `join()`/`detach()` bookkeeping required.
- Exceptions propagate automatically through the future.

**`std::thread` is appropriate when** you need direct control over thread attributes (priority, affinity, stack size) that the standard concurrency API does not expose.

---

#### Item 36: Specify `std::launch::async` If Asynchronicity Is Essential

The default `std::async` policy is `std::launch::async | std::launch::deferred` — the runtime chooses whether to run the task on a new thread or defer it to run synchronously on the calling thread when the future is accessed.

**Problems with the default policy:**

```cpp
auto fut = std::async(f); // May run f now, or defer it — you don't know

// This loop may never terminate if f is deferred:
while (fut.wait_for(100ms) != std::future_status::ready) {
    doOtherWork();
}
```

**Fix:** Specify the policy explicitly:

```cpp
auto fut = std::async(std::launch::async, f); // Always runs on a new thread
```

Or write a wrapper that checks for deferred status:

```cpp
if (fut.wait_for(0s) == std::future_status::deferred) {
    fut.get(); // Run synchronously
} else {
    while (fut.wait_for(100ms) != std::future_status::ready)
        doOtherWork();
}
```

Use the default policy only when you truly don't care whether the task runs concurrently.

---

#### Item 37: Make `std::thread`s Unjoinable on All Paths

A `std::thread` is either **joinable** (has an associated running/runnable OS thread) or **unjoinable** (default-constructed, moved-from, joined, or detached). Destroying a joinable thread calls `std::terminate` — a fatal crash.

This makes exception-safe thread management difficult:

```cpp
void doWork() {
    std::thread t(threadFunc);
    // ... if this throws, t's destructor calls std::terminate!
    t.join();
}
```

**RAII wrapper (ThreadRAII):**

```cpp
class ThreadRAII {
public:
    enum class DtorAction { join, detach };

    ThreadRAII(std::thread&& t, DtorAction a)
        : action(a), t(std::move(t)) {}

    ~ThreadRAII() {
        if (t.joinable()) {
            if (action == DtorAction::join) t.join();
            else t.detach();
        }
    }

    std::thread& get() { return t; }

private:
    DtorAction action;
    std::thread t;
};
```

Use `DtorAction::join` to wait for completion; use `DtorAction::detach` when the thread must outlive the scope.

---

#### Item 38: Be Aware of Varying Thread Handle Destructor Behavior

A future's shared state lives in the heap, managed by the promise, future, and possibly a thread. Destructor behavior depends on **how the future was created**:

| Future source                                   | Destructor behavior                                   |
| ----------------------------------------------- | ----------------------------------------------------- |
| `std::async` with `launch::async` (last future) | **Blocks** until the task completes (implicit join)   |
| `std::packaged_task`                            | **Does not block** — simply destroys the shared state |
| `std::promise`                                  | **Does not block** — simply destroys the shared state |

```cpp
// This BLOCKS — implicit join on destruction:
{
    auto fut = std::async(std::launch::async, longRunningTask);
} // ← blocks here until longRunningTask finishes

// This does NOT block:
std::packaged_task<int()> pt(longRunningTask);
auto fut = pt.get_future();
std::thread t(std::move(pt));
t.detach();
// fut destructor: does not block
```

The blocking behavior of `async` futures can cause surprising latency if futures are stored in containers and destroyed together.

---

#### Item 39: Consider `void` Futures for One-Shot Event Communication

To signal between threads without shared state, `std::promise<void>` + `std::future<void>` provides a clean, flag-free mechanism:

```cpp
std::promise<void> p;

// Detecting task (sender): signals when event occurs
void detect() {
    // ... do setup work ...
    p.set_value();  // Signal the reacting task
}

// Reacting task (receiver): waits for signal
void react() {
    auto fut = p.get_future();
    fut.wait();     // Block until set_value() is called
    // ... respond to event ...
}
```

**Comparison with condition variables:**

| Method               | Spurious wakeups? | Lost signals?                  | Requires mutex? | One-shot?                    |
| -------------------- | ----------------- | ------------------------------ | --------------- | ---------------------------- |
| `condition_variable` | Yes (must loop)   | Yes (if signalled before wait) | Yes             | No                           |
| `void` future        | No                | No (state persists)            | No              | **Yes** (promise fires once) |

For one-shot notifications, `void` futures are simpler and safer. For recurring events, use `condition_variable`.

---

#### Item 40: Use `std::atomic` for Concurrency, `volatile` for Special Memory

These two keywords are frequently confused but address completely different concerns:

**`std::atomic`** provides **atomicity and memory ordering** for concurrent access — no mutex required for simple read/modify/write operations:

```cpp
#include <atomic>

std::atomic<int> ai(0);
ai = 10;           // Atomic store
++ai;              // Atomic increment (read-modify-write)
int x = ai;        // Atomic load

std::atomic<bool> flag(false);
flag.store(true, std::memory_order_release);
bool b = flag.load(std::memory_order_acquire);
```

Operations on `std::atomic` variables cannot be reordered past each other by the compiler or CPU (subject to the chosen memory order).

**`volatile`** tells the compiler that a variable's value can change **outside the program's control** (e.g., memory-mapped hardware registers, signal handlers). It prevents the compiler from caching the value in a register or eliminating redundant reads/writes:

```cpp
volatile int* const hw_register = reinterpret_cast<int*>(0x1234);
*hw_register = 0;  // Not optimised away — hardware may observe it
*hw_register = 1;  // Not merged with previous write
```

**`volatile` does NOT provide atomicity or thread safety.** On most platforms, reading a `volatile int` is not guaranteed to be atomic. For concurrent programming, `volatile` is the wrong tool.

|                              | `std::atomic`           | `volatile`                             |
| ---------------------------- | ----------------------- | -------------------------------------- |
| Prevents torn reads/writes   | Yes                     | No                                     |
| Prevents compiler reordering | Yes                     | Partially (read/write order preserved) |
| Prevents CPU reordering      | Yes (with memory order) | No                                     |
| Use case                     | Concurrent shared data  | Memory-mapped I/O, signal handlers     |

They can be combined — `volatile std::atomic<int>` — for hardware registers that are also accessed from multiple threads, but this is rare.

---

### Chapter 8: Tweaks (Items 41–42)

#### Item 41: Consider Pass by Value for Copyable Parameters That Are Cheap to Move and Always Copied

The classical advice is "pass by `const&`, return by value." But for parameters that are **always copied inside the function**, pass-by-value + move can be equally efficient and simpler:

```cpp
class Widget {
    std::string name;
public:
    // Option A — two overloads (optimal but verbose)
    void setName(const std::string& newName) { name = newName; }  // copy
    void setName(std::string&& newName)       { name = std::move(newName); } // move

    // Option B — pass by value (one function, same cost for the common cases)
    void setName(std::string newName) { name = std::move(newName); }
};
```

**Cost analysis for Option B:**

- Called with lvalue: one copy (to construct `newName`) + one move (into `name`) = copy + move
- Called with rvalue: one move (to construct `newName`) + one move (into `name`) = two moves

Option A costs: copy or move (one operation). Option B costs one extra move — acceptable for types where moves are cheap (strings, vectors).

**When pass-by-value is NOT appropriate:**

- Parameters that are not always copied (conditional copy wastes the construction).
- Move-only types — use a single rvalue reference overload.
- Base class parameters — pass-by-value causes **object slicing**.
- Types where moves are expensive (e.g., `std::array`, SSO strings).

---

#### Item 42: Consider Emplacement Instead of Insertion

`push_back` / `insert` take a constructed object and move/copy it into the container. `emplace_back` / `emplace` take **constructor arguments** and construct the object directly inside the container — avoiding the temporary:

```cpp
std::vector<std::string> vs;

vs.push_back("hello");          // Creates temporary std::string, then moves it in
vs.emplace_back("hello");       // Constructs std::string directly in the vector — no temporary
```

**`emplace` is superior when:**

- The value being added is not the same type as the container's element type (avoids implicit conversion temporary).
- The container won't reject the value (e.g., `set`/`map` won't insert duplicates — a temporary may be constructed and then discarded).
- The constructor is not `explicit` ... or `emplace` intentionally bypasses `explicit`:

```cpp
std::vector<std::regex> regexes;
regexes.push_back(nullptr);     // FAILS: regex(nullptr) is explicit — good protection
regexes.emplace_back(nullptr);  // COMPILES — bypasses explicit! Undefined behaviour at runtime
```

> **When `push_back`/`insert` may be preferable:**
>
> - With `explicit` constructors where you want the protection.
> - When you already have the object (no construction savings).
> - With resource-managing containers where exception safety matters — `push_back` provides a strong guarantee; `emplace_back` with multiple constructor args may not.

**Summary rule:** Prefer `emplace` over `insert`/`push_back` when constructing a new element from arguments, but be aware of the `explicit`-constructor bypass edge case.

---

## Effective Modern C++ — Quick Reference: All 42 Items

| #   | Item                                    | Key Takeaway                                                                   |
| --- | --------------------------------------- | ------------------------------------------------------------------------------ |
| 1   | Template type deduction                 | Three cases: ref/ptr, universal ref, by-value; arrays/functions decay          |
| 2   | `auto` type deduction                   | Same as templates; `{}` deduces `initializer_list`                             |
| 3   | `decltype`                              | Preserves cv-qualifiers and ref-ness; `(x)` adds `&`                           |
| 4   | View deduced types                      | Use compiler errors or `boost::typeindex` for accuracy                         |
| 5   | Prefer `auto`                           | Avoids uninitialised vars, type mismatches, lambda type erasure cost           |
| 6   | Explicitly typed initializer            | Use `static_cast` when `auto` captures proxy objects                           |
| 7   | `()` vs `{}`                            | `{}` prevents narrowing; `{}` prefers `initializer_list` ctors                 |
| 8   | `nullptr` over `0`/`NULL`               | Unambiguous pointer type; works through templates                              |
| 9   | Alias declarations                      | Cleaner than `typedef`; supports template aliases                              |
| 10  | Scoped `enum class`                     | No leakage, no implicit int conversion, always forward-declarable              |
| 11  | Deleted functions                       | Compile-time enforcement; works on any function                                |
| 12  | `override`                              | Compile-time check for correct signature match                                 |
| 13  | `const_iterator`                        | Use `cbegin()`/`cend()`; prefer non-member versions in templates               |
| 14  | `noexcept`                              | Required for move ops to be used by containers; part of interface              |
| 15  | `constexpr`                             | Compile-time or runtime; apply wherever semantically valid                     |
| 16  | Thread-safe `const`                     | Use `mutex` (multiple vars) or `atomic` (single var) for `mutable` members     |
| 17  | Special member generation               | Declaring one suppresses others; use Rule of Five explicitly                   |
| 18  | `unique_ptr`                            | Zero overhead; custom deleters; converts to `shared_ptr`                       |
| 19  | `shared_ptr`                            | Control block mechanics; never two from same raw pointer                       |
| 20  | `weak_ptr`                              | Caches, observers, cycle-breaking; use `lock()`                                |
| 21  | `make_unique`/`make_shared`             | Exception safety; single allocation; no type repetition                        |
| 22  | Pimpl idiom                             | Special members in `.cpp`; `unique_ptr` requires complete type at destructor   |
| 23  | `move` and `forward`                    | `move` = unconditional rvalue cast; `forward` = conditional                    |
| 24  | Universal vs rvalue refs                | `T&&` with deduction = universal; without = rvalue                             |
| 25  | `move` vs `forward` usage               | `move` on rvalue refs; `forward` on universal refs; neither on return locals   |
| 26  | Avoid overloading universal refs        | Template instantiation beats non-template overloads unexpectedly               |
| 27  | Alternatives to universal ref overloads | Tag dispatch; `enable_if`; `if constexpr`                                      |
| 28  | Reference collapsing                    | `& + anything = &`; `&& + && = &&`; powers `forward`                           |
| 29  | Move is not always cheap                | `array` O(N); SSO strings; missing `noexcept` disables moves in containers     |
| 30  | Perfect forwarding failures             | Braced inits; `0`/`NULL`; static members; overloads; bitfields                 |
| 31  | Avoid default captures                  | `[&]` dangles; `[=]` captures `this` pointer, not members                      |
| 32  | Init capture                            | Move objects into closures: `[x = std::move(x)]`                               |
| 33  | `decltype` in generic lambdas           | `std::forward<decltype(param)>(param)` for perfect forwarding                  |
| 34  | Lambdas over `std::bind`                | Clearer, faster (inlining), better overload resolution                         |
| 35  | Task-based over thread-based            | `async` provides return values, exception propagation, thread reuse            |
| 36  | `launch::async` when needed             | Default policy may silently defer; check or specify explicitly                 |
| 37  | Unjoinable threads                      | Wrap `std::thread` in RAII; joinable destructor = `std::terminate`             |
| 38  | Future destructor behavior              | `async` futures block; `packaged_task`/`promise` futures do not                |
| 39  | `void` futures for one-shot signals     | Simpler than `condition_variable`; no spurious wakeups; no lost signals        |
| 40  | `atomic` vs `volatile`                  | `atomic` = thread safety; `volatile` = special memory; orthogonal              |
| 41  | Pass by value for always-copied params  | One overload, one extra move; not for sliceable/expensive-move types           |
| 42  | `emplace` over `insert`                 | No temporary; bypasses `explicit` (caution); prefer for construction from args |
