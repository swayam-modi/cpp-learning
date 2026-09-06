# 📘 C++ Complete Reference — For Java Developers

## Part 0: How To Use This Document

This document covers ALL of C++ compared with Java. You can open it at any point and search for any concept. Since this is a single massive reference document, your best friend is **Ctrl+F** (or Cmd+F) to search for exactly what you need. 

### Symbol Legend
Keep an eye out for these symbols throughout the reference:
* 🔴 **Java Gotcha** — Java habits that will break your C++ code. Pay close attention to these!
* 🧠 **Behind the Scenes** — What the compiler, stack, heap, and memory are actually doing.
* ⚡ **Performance Notes** — How to make your C++ code blazingly fast.
* 💡 **Tip** — Best practices and modern C++ idioms.

### Quick Section Reference Index
* [**Part 0:** How To Use This Document](#part-0-how-to-use-this-document)
* [**Part 1:** Toolchain & Build System](#part-1-toolchain--build-system)
* [**Part 2:** Fundamental Types & Variables](#part-2-fundamental-types--variables)
* [**Part 3:** Input/Output](#part-3-inputoutput-31-37)
* [**Part 4:** Control Flow & Operators](#part-4-control-flow--operators-41-47)
* [**Part 5:** Functions](#part-5-functions-51-511)
* [**Part 6:** Pointers & References](#part-6-pointers--references--the-java-developers-wall)
* [**Part 7:** Memory Management](#part-7-memory-management--no-garbage-collector)
* [**Part 8:** Strings](#part-8-strings)
* [**Part 9:** Arrays & `std::vector`](#part-9-arrays--stdvector)
* [**Part 10:** STL Containers](#part-10-stl-containers-101-1012)
* [**Part 11:** Iterators & Algorithms](#part-11-iterators--algorithms-111-1111)
* [**Part 12:** OOP in C++](#part-12-oop-in-c-121-1217)
* [**Part 13:** Templates & Generic Programming](#part-13-templates--generic-programming)
* [**Part 14:** Error Handling & Exceptions](#part-14-error-handling--exceptions)
* [**Part 15:** Advanced & Modern C++ Topics](#part-15-advanced--modern-c-topics)
* [**Appendix A:** Java Habits That Bite You](#appendix-a-java-habits-that-bite-you-the-ledger)
* [**Appendix B:** STL ↔ Java Collections Complete Map](#appendix-b-stl--java-collections-complete-map)
* [**Appendix C:** Competitive Programming Quick Reference](#appendix-c-competitive-programming-quick-reference)
* [**Appendix D:** Compiler Flags & Debugging](#appendix-d-compiler-flags--debugging)
* [**Appendix E:** Complete C++ Syntax Quick Reference Card](#appendix-e-complete-c-syntax-quick-reference-card)

---

## Part 1: Toolchain & Build System

### 1.1 Compilation Model (C++ vs Java)

In Java, your source code `.java` is compiled into bytecode `.class` files, which are then run by the JVM anywhere. In C++, your source code `.cpp` is compiled directly into **machine code** specific to your OS and CPU architecture.

**Java Equivalent:** `javac` (compiles to bytecode) and `java` (runs bytecode in JVM).

| Feature | Java | C++ |
|---------|------|-----|
| Output | Bytecode (`.class` / `.jar`) | Native Machine Code (`.exe` / `.out` / binary) |
| Portability | Run anywhere (JVM) | Must be recompiled per OS/Architecture |
| Linking | Dynamic at runtime | Usually static at compile time (or dynamic `.so`/`.dll`) |
| Entry Point | `public static void main(String[] args)` | `int main(int argc, char* argv[])` |

🧠 **Behind the Scenes:** The C++ compilation process is actually 4 steps:
1. **Preprocessor:** Expands macros, `#include`s headers, strips comments. Outputs an expanded `.cpp` file.
2. **Compiler:** Compiles the expanded `.cpp` file into assembly code.
3. **Assembler:** Converts assembly code into object code (`.o` or `.obj` files).
4. **Linker:** Combines object files and libraries into a final executable.

🔴 **Gotcha:** If you don't define a function you declared, the compiler won't complain, but the **linker** will fail with an "undefined reference" error.

### 1.2 g++ Command

C++ compilers like `g++` or `clang++` have flags to control the build. 

**Java Equivalent:** `javac` flags and `java` VM arguments.

| Concept | Java Command | C++ Command (g++) |
|---------|--------------|-------------------|
| Compile basic | `javac MyClass.java` | `g++ main.cpp` (outputs `a.out`) |
| Compile and name | N/A | `g++ main.cpp -o my_program` |
| Warnings | `javac -Xlint` | `g++ main.cpp -Wall -Wextra` |

**Code Example:**
```bash
# Compiles main.cpp, outputs "my_app", turns on all warnings, adds debug symbols, and standard C++17
g++ -std=c++17 -Wall -Wextra -g main.cpp -o my_app

# Run the program
./my_app
```

💡 **Tip:** Always use `-Wall -Wextra`. Also use `-fsanitize=address,undefined` during development to catch memory leaks and undefined behaviors instantly!

### 1.3 Header Files & #include

In C++, code is typically split into **header files** (`.h` or `.hpp`) containing declarations, and **source files** (`.cpp`) containing definitions. `#include` is how you bring code into a file.

**Java Equivalent:** `import` statements.

| Feature | Java `import` | C++ `#include` |
|---------|---------------|----------------|
| Mechanism | Points the compiler to a class path | Literally copy-pastes the file contents |
| Order matters | No | Yes |
| Standard lib | `import java.util.List;` | `#include <vector>` |
| Own files | `import com.myproject.MyClass;` | `#include "MyClass.h"` |

**Code Example:**
```cpp
// Java: import java.util.ArrayList;
#include <iostream> // Angle brackets for standard library
#include <vector>

#include "MyClass.h" // Quotes for your own files

int main() {
    std::cout << "Hello!" << std::endl;
    return 0;
}
```

🧠 **Behind the Scenes:** The preprocessor literally takes the contents of the included file and pastes it into your `.cpp` file where the `#include` directive was.

### 1.4 Preprocessor Directives

The C++ preprocessor runs *before* the compiler. It processes lines starting with `#`.

**Java Equivalent:** None. Java doesn't have a preprocessor.

* `#define`: Creates macros (text replacement).
* `#ifdef` / `#endif`: Conditional compilation.

**Code Example:**
```cpp
#define PI 3.14159
#define DEBUG_MODE 1

int main() {
    double area = PI * 5 * 5; // PI is replaced with 3.14159 before compilation
    
#if DEBUG_MODE
    std::cout << "Debug mode is ON\n"; // This line is compiled
#endif
    return 0;
}
```

🔴 **Gotcha:** Macros do not respect scope or types. Avoid `#define` for constants; use `const` or `constexpr` instead.

### 1.5 Include Guards & #pragma once

Because `#include` copy-pastes, you can accidentally include the same header twice, leading to "multiple definition" errors. Include guards prevent this.

**Java Equivalent:** Not needed (JVM handles classes).

**Code Example:**
```cpp
// Traditional include guard
#ifndef MY_CLASS_H
#define MY_CLASS_H

class MyClass {
    // ...
};

#endif
```

```cpp
// Modern alternative (supported by all major compilers)
#pragma once

class MyClass {
    // ...
};
```
💡 **Tip:** Just use `#pragma once` at the top of every header file.

### 1.6 Namespaces & using

Namespaces prevent name collisions, similar to Java packages.

**Java Equivalent:** Packages.

| Feature | Java | C++ |
|---------|------|-----|
| Grouping | `package com.example;` | `namespace Example { }` |
| Usage | `import com.example.MyClass;` | `using Example::MyClass;` |
| Import all | `import com.example.*;` | `using namespace Example;` |

**Code Example:**
```cpp
#include <iostream>

namespace MathLib {
    int add(int a, int b) { return a + b; }
}

using namespace MathLib; // Like import MathLib.*

int main() {
    // Without using namespace, we'd write MathLib::add(1, 2)
    std::cout << add(1, 2) << std::endl;
    return 0;
}
```

🔴 **Gotcha:** NEVER put `using namespace std;` in a header file. It pollutes the global namespace for every file that includes that header, leading to horrific naming collisions.

### 1.7 Multiple File Projects

C++ splits classes into interface (header) and implementation (source).

**Java Equivalent:** One `.java` file containing both declaration and implementation.

**Code Example:**
*Math.h* (Header - Declaration)
```cpp
#pragma once
class Math {
public:
    int add(int a, int b);
};
```

*Math.cpp* (Source - Implementation)
```cpp
#include "Math.h"

int Math::add(int a, int b) { // Math:: indicates this belongs to the Math class
    return a + b;
}
```

*main.cpp*
```cpp
#include <iostream>
#include "Math.h"

int main() {
    Math m;
    std::cout << m.add(5, 10) << '\n';
    return 0;
}
```

### 1.8 Build Tools (Makefiles & CMake)

Because compiling multiple files manually is tedious, C++ uses build systems.

**Java Equivalent:** Maven or Gradle.

* **Makefiles:** The classic approach. Specifies targets and dependencies.
* **CMake:** The modern industry standard. It's a "meta-build system" that generates Makefiles (or Visual Studio projects) for you.

*CMakeLists.txt example:*
```cmake
cmake_minimum_required(VERSION 3.10)
project(MyProject)
set(CMAKE_CXX_STANDARD 17)
add_executable(my_app main.cpp Math.cpp)
```

### 1.9 Compiler Errors Decoded

C++ compiler errors can be famously long and terrifying.

* **Undefined reference to `X`:** Linker error. You declared `X` but didn't implement it, or didn't link the `.cpp` file containing it.
* **`X` was not declared in this scope:** Compiler error. You forgot to `#include` the header for `X`, or forgot a namespace (e.g., used `cout` instead of `std::cout`).
* **Expected `;` before `X`:** You forgot a semicolon on the previous line.
* **Massive template error (e.g., hundreds of lines for a vector error):** Usually means you tried to do something invalid with a type inside a container, like sorting custom objects without an `operator<`.

---

## Part 2: Fundamental Types & Variables

### 2.1 Primitive Types

C++ types are intimately tied to the hardware.

**Java Equivalent:** Java's primitive types (`int`, `boolean`, `double`, etc.).

| Java Type | C++ Equivalent | Size Guarantee |
|-----------|----------------|----------------|
| `byte` | `char` or `int8_t` | Exactly 1 byte |
| `short` | `short` or `int16_t` | At least 2 bytes |
| `int` | `int` or `int32_t` | At least 2 bytes (usually 4) |
| `long` | `long long` or `int64_t` | At least 8 bytes |
| `float` | `float` | Usually 4 bytes |
| `double` | `double` | Usually 8 bytes |
| `boolean` | `bool` | Usually 1 byte |
| `char` | `char` (ASCII) / `char16_t` / `wchar_t` | 1 byte (unlike Java's 2-byte UTF-16 char) |

🔴 **Gotcha:** In Java, an `int` is ALWAYS 32-bit. In C++, an `int` is just guaranteed to be at least 16 bits. On modern systems, it's usually 32 bits, but you cannot rely on it across all platforms.

### 2.2 Type Sizes & sizeof

To know exactly how big a type is on the current platform, use `sizeof`.

**Java Equivalent:** No direct equivalent (sizes are fixed by the JVM spec).

**Code Example:**
```cpp
#include <iostream>

int main() {
    std::cout << "Size of int: " << sizeof(int) << " bytes\n";
    std::cout << "Size of double: " << sizeof(double) << " bytes\n";
    return 0;
}
```

### 2.3 Type Modifiers

C++ allows modifying standard integer types.

* `unsigned`: The number cannot be negative, doubling the positive range.
* `long` / `short`: Modifies the size.

**Java Equivalent:** Java does NOT have unsigned types.

**Code Example:**
```cpp
int main() {
    unsigned int x = 4000000000; // Fits fine!
    long long int huge_num = 9000000000000000000;
    return 0;
}
```

🔴 **Gotcha:** `.size()` on standard containers (like `std::vector`) returns an **unsigned** integer type (`size_t`). If a vector is empty, `vec.size() - 1` will underflow and become a MASSIVE positive number, breaking loops.

### 2.4 auto Keyword

`auto` tells the compiler to deduce the type from the initialization.

**Java Equivalent:** `var` (introduced in Java 10).

**Code Example:**
```cpp
#include <vector>
#include <iostream>

int main() {
    auto age = 25;           // Deduced as int
    auto price = 19.99;      // Deduced as double
    auto name = "Swayam";    // Deduced as const char*
    
    std::vector<int> numbers = {1, 2, 3};
    auto size = numbers.size(); // Deduced as size_t
    
    return 0;
}
```
💡 **Tip:** Use `auto` extensively for complex types (like iterators), but prefer explicit types for simple primitives where readability matters.

### 2.5 Type Casting

C++ has strict rules for conversions and provides 4 specific cast operators.

**Java Equivalent:** `(Type) variable` (C-style cast).

| Java Cast | C++ Equivalent | Use Case |
|-----------|----------------|----------|
| `(int) myDouble` | `static_cast<int>(myDouble)` | Safe conversions at compile time |
| `(MyClass) myObj` | `dynamic_cast<MyClass*>(myObj)`| Safe downcasting of pointers (checks at runtime) |
| `(byte[]) myData` | `reinterpret_cast<char*>(myData)` | Unsafe reinterpretation of bit patterns |
| N/A | `const_cast<Type>(myConstVar)` | Removing `const` (rarely used, usually a code smell) |

**Code Example:**
```cpp
int main() {
    double pi = 3.14159;
    
    // C-style cast (AVOID IN C++)
    int a = (int)pi; 
    
    // C++ cast (PREFER THIS)
    int b = static_cast<int>(pi); 
    
    return 0;
}
```

### 2.6 Constants (const vs constexpr)

C++ has two levels of immutability.

**Java Equivalent:** `final`.

* `const`: The value won't change after initialization (can be evaluated at runtime).
* `constexpr`: The value is a constant expression evaluated at **compile time**.

**Code Example:**
```cpp
int calculate_size(int input) {
    const int runtime_const = input * 2; // Evaluated at runtime
    // runtime_const = 10; // ERROR: read-only variable
    return runtime_const;
}

int main() {
    constexpr int compile_const = 5 * 10; // Evaluated at compile time
    return 0;
}
```

### 2.7 Initialization Gotchas (Garbage Values!)

🔴 **CRITICAL GOTCHA:** In Java, class fields and arrays are automatically initialized to `0`, `false`, or `null`. In C++, primitive variables defined inside a function (on the stack) are **NOT initialized**. They contain whatever garbage data happened to be in that memory location!

**Code Example:**
```cpp
#include <iostream>

int main() {
    int uninitialized_var; // DANGER! 
    std::cout << uninitialized_var << '\n'; // Prints random garbage (e.g., 32767, -1934983, etc.)
    
    // Modern C++ Uniform Initialization (Brace Initialization)
    int initialized_var{}; // Initializes to 0 safely!
    int set_var{42};       // Initializes to 42
    
    return 0;
}
```
💡 **Tip:** ALWAYS use brace initialization `{}` to prevent garbage values and narrow conversions.

### 2.8 std::numeric_limits

To find the min/max values a type can hold.

**Java Equivalent:** `Integer.MAX_VALUE`, `Double.MIN_VALUE`.

**Code Example:**
```cpp
#include <iostream>
#include <limits> // Required

int main() {
    std::cout << "Max int: " << std::numeric_limits<int>::max() << '\n';
    std::cout << "Min int: " << std::numeric_limits<int>::min() << '\n';
    return 0;
}
```

### 2.9 Fixed-width Integers

Because standard `int` sizes vary, C++11 introduced fixed-width integers for when you need precise sizes (e.g., network protocols, binary parsing).

**Java Equivalent:** `int` (always 32-bit), `long` (always 64-bit).

**Code Example:**
```cpp
#include <cstdint> // Required

int main() {
    int32_t a = 100; // Exactly 32 bits, signed
    uint64_t b = 500; // Exactly 64 bits, unsigned
    
    // size_t is the type returned by sizeof and container.size()
    // It is an unsigned integer large enough to hold the maximum size of any object
    size_t length = 1024; 
    
    return 0;
}
```

### 2.10 Literals

C++ allows writing literals in various bases and using separators for readability.

**Java Equivalent:** Similar, Java uses `_` for separation.

**Code Example:**
```cpp
int main() {
    int dec = 42;
    int hex = 0x2A;
    int bin = 0b101010;
    
    // C++14 digit separators use single quotes
    long long big_number = 1'000'000'000; // Java: 1_000_000_000
    
    return 0;
}
```


# Part 3: Input/Output (3.1-3.7)

## 3.1 Console I/O: `cin` and `cout`

**Plain English Explanation:**
`std::cout` (Character OUTput) and `std::cin` (Character INput) are C++'s standard streams for writing to and reading from the console. They use overloaded bitwise shift operators: `<<` (insertion operator) pushes data into the output stream, and `>>` (extraction operator) pulls data from the input stream.

**Java Equivalent:**
`System.out.print()`, `System.out.println()`, and `java.util.Scanner`.

**Key Differences:**

| Feature | Java | C++ |
| :--- | :--- | :--- |
| **Output** | `System.out.println(x)` | `std::cout << x << "\n";` |
| **Input** | `Scanner sc = new Scanner(System.in); int x = sc.nextInt();` | `int x; std::cin >> x;` |
| **Type Safety** | Types checked via methods (`nextInt`, `nextDouble`) | Compiler deduces type automatically based on variable |
| **Chaining** | Requires string concatenation (`+`) | Chained via `<<` and `>>` operators |

**Code Example:**

```java
// Java
Scanner sc = new Scanner(System.in);
System.out.print("Enter your age: ");
int age = sc.nextInt();
System.out.println("You are " + age + " years old.");
```

```cpp
// C++
#include <iostream>

int main() {
    int age;
    std::cout << "Enter your age: ";
    std::cin >> age; // Reads directly into 'age', deducing it's an int
    std::cout << "You are " << age << " years old.\n";
    return 0;
}
```

🧠 **Behind the Scenes:**
`std::cin` and `std::cout` are global instances of `std::istream` and `std::ostream` classes. The `>>` and `<<` operators are function calls in disguise (`std::ostream& operator<<(std::ostream&, int)`). They return a reference to the stream object itself, allowing chaining like `cin >> x >> y;`.

🔴 **Gotchas:**
- `std::endl` flushes the output buffer, which is very slow. Use `\n` instead unless you explicitly need a flush.
- `cin >>` stops reading at the first whitespace (space, tab, newline). If the user types "John Doe", `cin >> name` only gets "John".

⚡ **Performance Notes:**
C++ standard streams are incredibly fast if properly tuned, but by default they are synchronized with C standard I/O (printf/scanf), adding overhead. (See 3.5 Fast I/O).

---

## 3.2 Reading Full Lines: `std::getline` and the `cin >> x` Trap

**Plain English Explanation:**
When you need to read an entire line of text including spaces, you use `std::getline()`. This reads characters until it hits a newline character (`\n`), consuming the newline but not adding it to the resulting string.

**Java Equivalent:**
`Scanner.nextLine()`.

**Key Differences:**

| Feature | Java | C++ |
| :--- | :--- | :--- |
| **Function** | `sc.nextLine()` | `std::getline(std::cin, myString)` |
| **Receiver Type** | Returns `String` | Takes `std::string&` as out-parameter |
| **Delimiter** | Newline | Newline by default, but accepts custom delimiter |

**Code Example:**

```cpp
#include <iostream>
#include <string>

int main() {
    std::string fullName;
    std::cout << "Enter full name: ";
    std::getline(std::cin, fullName);
    std::cout << "Hello, " << fullName << "!\n";
    return 0;
}
```

🔴 **Gotcha: The `cin >> x` Trap**
If you use `cin >>` to read an integer/double/word, it leaves the trailing newline (`\n`) in the input buffer. If you immediately call `std::getline()`, it instantly reads that leftover `\n` and returns an empty string!

**The Trap Code:**
```cpp
int age;
std::cin >> age; // User types "25<Enter>"
std::string name;
std::getline(std::cin, name); // Reads the '\n' immediately! 'name' is empty.
```

**The Fix:**
You must consume the stray newline. Often `std::cin >> std::ws` is used to discard leading whitespace, or `cin.ignore()` to skip the exact newline character.

```cpp
int age;
std::cin >> age;
std::cin >> std::ws; // Consume leading whitespace (including the newline)
std::string name;
std::getline(std::cin, name); // Now works correctly!
```

---

## 3.3 Stream Manipulators

**Plain English Explanation:**
Manipulators are special functions pushed into a stream using `<<` or `>>` to change formatting behavior (like padding, decimal precision, or base representation).

**Java Equivalent:**
`String.format()`, `System.out.printf()`, `DecimalFormat`.

**Key Differences:**

| Feature | Java | C++ |
| :--- | :--- | :--- |
| **Hexadecimal** | `Integer.toHexString(x)` | `std::cout << std::hex << x` |
| **Decimal Precision** | `String.format("%.2f", x)` | `std::cout << std::fixed << std::setprecision(2) << x` |
| **Padding** | `String.format("%10s", x)` | `std::cout << std::setw(10) << x` |
| **Booleans** | Prints "true"/"false" by default | Prints "1"/"0" by default, use `std::boolalpha` |

**Code Example:**

```cpp
#include <iostream>
#include <iomanip> // Required for parametrized manipulators (setw, setprecision)

int main() {
    double pi = 3.14159265;
    int num = 255;
    bool flag = true;

    // Output: 3.14
    std::cout << std::fixed << std::setprecision(2) << pi << "\n"; 
    
    // Output: ff
    std::cout << std::hex << num << "\n"; 
    
    // Output: true
    std::cout << std::boolalpha << flag << "\n";
    
    // Output: [      42] (right aligned, width 8)
    // Note: setw only affects the NEXT output item. Other manipulators are sticky!
    std::cout << "[" << std::setw(8) << std::dec << 42 << "]\n";
    
    return 0;
}
```

🧠 **Behind the Scenes:**
Most manipulators set a state flag on the stream object (e.g., `std::hex` sets `ios_base::hex`). These states are "sticky" (persist until changed). `std::setw` is the major exception—it automatically resets to 0 after formatting one item.

---

## 3.4 C-style I/O: `printf` and `scanf`

**Plain English Explanation:**
C++ inherits C's I/O functions. They use format specifiers (`%d`, `%f`, `%s`) instead of type deduction. They are sometimes preferred in competitive programming or when formatting is complex.

**Java Equivalent:**
`System.out.printf()`, `String.format()`.

**Key Differences:**

| Feature | Java | C++ |
| :--- | :--- | :--- |
| **Format Specifiers** | `%d`, `%f`, `%s` | Identical to Java |
| **Input** | `Scanner` | `scanf("%d", &var)` |
| **Strings** | `%s` prints Java String | `%s` prints C-style `char*`, NOT `std::string` |

**Code Example:**

```cpp
#include <cstdio> // <stdio.h> in C
#include <string>

int main() {
    int age = 30;
    double money = 99.95;
    
    // Output
    printf("Age: %d, Money: %.2f\n", age, money);
    
    // Input
    int inputVal;
    printf("Enter a number: ");
    scanf("%d", &inputVal); // MUST pass pointer using &
    
    // String gotcha
    std::string name = "Alice";
    // printf("Name: %s\n", name); // 🔴 COMPILE ERROR/UNDEFINED BEHAVIOR
    printf("Name: %s\n", name.c_str()); // Correct: get C-style pointer
    
    return 0;
}
```

🔴 **Gotchas:**
- `scanf` requires pointers (`&var`). Forgetting the `&` causes an instant segfault.
- Neither `printf` nor `scanf` know about `std::string`. You must use `.c_str()` to print, and you cannot easily `scanf` into a `std::string` directly.

---

## 3.5 Fast I/O (Competitive Programming Standard)

**Plain English Explanation:**
By default, `cin/cout` pause to sync themselves with `scanf/printf` so you can mix both in one program. They also flush `cout` before every `cin`. Disabling these safety features makes C++ streams insanely fast.

**Code Example:**

```cpp
#include <iostream>

int main() {
    // 1. Untie C++ streams from C streams
    std::ios_base::sync_with_stdio(false);
    
    // 2. Untie cin from cout (stops auto-flushing cout on cin)
    std::cin.tie(NULL);
    
    int n;
    // Now blazing fast!
    while (std::cin >> n) {
        std::cout << n << "\n";
    }
    return 0;
}
```

🔴 **Gotcha:** If you disable sync, NEVER mix `cin/cout` with `scanf/printf` in the same program, or your output order will be hopelessly mangled.

---

## 3.6 File I/O (`ifstream`, `ofstream`, `fstream`)

**Plain English Explanation:**
File reading and writing in C++ uses streams that work exactly like `cin` and `cout`. `ifstream` (Input File Stream) reads files, `ofstream` (Output File Stream) writes to files, and `fstream` does both.

**Java Equivalent:**
`FileReader`, `FileWriter`, `BufferedReader`, `PrintWriter`, `Scanner(File)`.

**Key Differences:**

| Feature | Java | C++ |
| :--- | :--- | :--- |
| **Object Type** | Nested wrappers (`BufferedReader(new FileReader(...))`) | Direct objects (`std::ifstream file("a.txt")`) |
| **Resource Management** | `try-with-resources` or explicit `close()` | RAII: Destructor closes file automatically! |
| **Checking Success** | Throws `IOException` | Stream acts like boolean (`if (file)`) |

**Code Example:**

```cpp
#include <iostream>
#include <fstream>
#include <string>

int main() {
    // WRITING
    {
        // ofstream creates file if missing, overwrites by default
        std::ofstream outFile("data.txt");
        if (!outFile) {
            std::cerr << "Failed to open file for writing\n";
            return 1;
        }
        outFile << "Line 1\n";
        outFile << "Line 2\n";
        // outFile is automatically closed when it goes out of scope here!
    }

    // READING
    {
        std::ifstream inFile("data.txt");
        if (!inFile) {
            std::cerr << "File not found\n";
            return 1;
        }

        std::string line;
        // std::getline evaluates to false when EOF is reached
        while (std::getline(inFile, line)) {
            std::cout << "Read: " << line << "\n";
        }
    }
    return 0;
}
```

🧠 **Behind the Scenes:**
The streams overload `operator bool()`. When you do `if(inFile)` or `while(cin >> x)`, it checks the stream's internal error state (EOF, bad format, IO failure).
C++ uses RAII (Resource Acquisition Is Initialization). When `inFile` goes out of scope, its destructor runs and automatically closes the OS file handle. No `finally` block needed!

---

## 3.7 String Streams (`stringstream`)

**Plain English Explanation:**
A `stringstream` lets you treat a `std::string` as if it were a file or the console. It's used for parsing strings, converting numbers to strings, or strings to numbers.

**Java Equivalent:**
`String.split()`, `Integer.parseInt()`, `String.valueOf()`.

**Key Differences:**

| Feature | Java | C++ |
| :--- | :--- | :--- |
| **Parsing** | `str.split(" ")` | `stringstream ss(str); ss >> word;` |
| **Int to String** | `String.valueOf(42)` | `std::to_string(42)` or `stringstream` |
| **String to Int** | `Integer.parseInt(s)` | `std::stoi(s)` or `stringstream` |

**Code Example:**

```cpp
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

int main() {
    std::string data = "10 20 30 40";
    std::stringstream ss(data);
    
    std::vector<int> numbers;
    int temp;
    
    // Automatically splits on spaces, just like cin!
    while (ss >> temp) {
        numbers.push_back(temp);
    }
    
    // Output generation
    std::stringstream out;
    out << "Sum is " << (10+20+30+40);
    std::string result = out.str(); // Extract standard string
    std::cout << result << "\n";
    
    return 0;
}
```

---
---

# Part 4: Control Flow & Operators (4.1-4.7)

## 4.1 C++ Operator Precedence Table

Operators in C++ behave largely the same as in Java, with a few additions for pointers and memory management.

| Precedence | Operator Type | Symbols | Associativity |
| :--- | :--- | :--- | :--- |
| 1 (Highest) | Scope Resolution | `::` | Left-to-Right |
| 2 | Suffix/Postfix | `()` `[]` `->` `.` `++` `--` | Left-to-Right |
| 3 | Prefix/Unary | `++` `--` `+` `-` `!` `~` `*` `&` `sizeof` | Right-to-Left |
| 4 | Pointer-to-Member | `.*` `->*` | Left-to-Right |
| 5 | Multiplicative | `*` `/` `%` | Left-to-Right |
| 6 | Additive | `+` `-` | Left-to-Right |
| 7 | Shift | `<<` `>>` | Left-to-Right |
| 8 | Relational | `<` `<=` `>` `>=` | Left-to-Right |
| 9 | Equality | `==` `!=` | Left-to-Right |
| 10 | Bitwise AND | `&` | Left-to-Right |
| 11 | Bitwise XOR | `^` | Left-to-Right |
| 12 | Bitwise OR | `\|` | Left-to-Right |
| 13 | Logical AND | `&&` | Left-to-Right |
| 14 | Logical OR | `\|\|` | Left-to-Right |
| 15 | Ternary Conditional | `?:` | Right-to-Left |
| 16 | Assignment | `=` `+=` `-=` `*=` `/=` etc. | Right-to-Left |
| 17 | Throw | `throw` | Right-to-Left |
| 18 (Lowest) | Comma | `,` | Left-to-Right |

🔴 **Gotcha:** Bitwise operators have surprisingly low precedence. `x & 1 == 0` evaluates as `x & (1 == 0)`, not `(x & 1) == 0`. Always use parentheses!

---

## 4.2 Control Flow: `if`, `else`, `switch`

**Plain English Explanation:**
Basic control flow in C++ is character-for-character identical to Java. However, C++17 introduced "init-statements" for `if` and `switch` which keep your scope clean.

**Java Equivalent:**
Identical.

**Key Differences:**

| Feature | Java | C++ |
| :--- | :--- | :--- |
| **Switch on String** | Supported (`switch(string)`) | **NOT Supported!** (Only integers/enums allowed) |
| **Condition Types** | Must evaluate strictly to `boolean` | Integers, pointers evaluate directly (0/null is false, else true) |
| **Scope Init** | Not available | Supported in C++17 (`if (init; condition)`) |

**Code Example:**

```cpp
#include <iostream>
#include <string>

int main() {
    int x = 5;
    
    // Classic if-else
    if (x > 0) {
        std::cout << "Positive\n";
    }
    
    // C++ implicit boolean cast (x is non-zero, so it's true)
    if (x) {
        std::cout << "x is not zero\n";
    }

    // C++17 init-statement in if!
    // 'val' is scoped ONLY to this if-else block.
    if (int val = x * 2; val > 5) {
        std::cout << "val is " << val << "\n";
    } // val is destroyed here

    // switch (cannot use std::string here!)
    char grade = 'A';
    switch (grade) {
        case 'A': std::cout << "Excellent\n"; break;
        default: std::cout << "Other\n"; break;
    }
    return 0;
}
```

🔴 **Gotchas:**
- C++ does not support switching on strings. You must use `if-else` chains or map strings to enums.
- Forgetting `break;` in a `switch` falls through, just like Java.

---

## 4.3 Loops (for, while, do-while) and Range-based for

**Plain English Explanation:**
C++ offers standard `for`, `while`, and `do-while` loops. C++11 introduced the range-based for loop (equivalent to Java's enhanced for loop).

**Java Equivalent:**
`for (Type item : collection)`

**Key Differences:**

| Feature | Java | C++ |
| :--- | :--- | :--- |
| **Enhanced For** | `for (String s : list)` | `for (std::string s : list)` (🔴 Bad!) <br> `for (const auto& s : list)` (✅ Good!) |
| **Auto keyword** | `var` (Java 10+) | `auto` |

**Code Example:**

```cpp
#include <iostream>
#include <vector>
#include <string>

int main() {
    std::vector<std::string> names = {"Alice", "Bob", "Charlie"};

    // Traditional index-based
    for (size_t i = 0; i < names.size(); ++i) {
        std::cout << names[i] << " ";
    }

    // Range-based for (C++11)
    
    // 🔴 DANGER: This COPIES every string in the vector! Slow!
    for (std::string name : names) { }

    // ✅ READ-ONLY: Use const auto& to bind by reference (No copy)
    for (const auto& name : names) {
        std::cout << name << " ";
    }

    // ✅ MUTATION: Use auto& to modify elements in place
    for (auto& name : names) {
        name += "!"; // Modifies the actual strings inside the vector
    }

    return 0;
}
```

🧠 **Behind the Scenes:**
Java objects are always references, so `for(String s : list)` just copies the reference (a pointer). C++ objects are values. `for(string s : list)` physically creates a brand new string, allocates heap memory, copies characters, and destroys it on every iteration. Always use references (`&`) in C++ loops!

---

## 4.4 break, continue, and goto

**Plain English Explanation:**
`break` exits the innermost loop or switch. `continue` skips to the next iteration. `goto` jumps to a named label.

**Java Equivalent:**
Java has `break`, `continue`, and *labeled* versions of both (`break outerLoop;`). Java does NOT have `goto`.

**Key Differences:**

| Feature | Java | C++ |
| :--- | :--- | :--- |
| **Labeled Break** | `break outer;` | Not supported. Use `goto` or flag variables. |
| **Goto** | Reserved word, unused | Fully functional jump statement |

**Code Example:**

```cpp
#include <iostream>

int main() {
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            if (i == 2 && j == 2) {
                // To break out of nested loops, use goto
                goto end_loops; 
            }
        }
    }
    
end_loops: // Label
    std::cout << "Escaped the nested loops!\n";
    return 0;
}
```

🔴 **Gotcha:** `goto` is generally frowned upon, but breaking out of deeply nested loops is one of its few accepted uses in C++, since C++ lacks Java's labeled `break`.

---

## 4.5 Bitwise Deep Dive and Tricks

**Plain English Explanation:**
Bitwise operators manipulate integers at the binary level. They are extremely fast and commonly used in low-level programming and competitive programming.

**Java Equivalent:**
Identical operators (`&`, `|`, `^`, `~`, `<<`, `>>`).
Java has `>>>` (unsigned right shift) because Java has no unsigned types. C++ doesn't have `>>>` because you just cast to `unsigned int` before shifting `>>`.

**Key Differences:**

| Feature | Java | C++ |
| :--- | :--- | :--- |
| **Unsigned Shift** | `x >>> 1` | `((unsigned int)x) >> 1` |

**Code Example / Tricks:**

```cpp
#include <iostream>

int main() {
    int x = 10; // 1010 in binary
    
    // Check if odd/even
    if (x & 1) std::cout << "Odd"; else std::cout << "Even";
    
    // Multiply by 2 (Left shift)
    int mul = x << 1; // 20
    
    // Divide by 2 (Right shift)
    int div = x >> 1; // 5
    
    // Swap two variables without temporary variable (using XOR)
    int a = 5, b = 9;
    a ^= b;
    b ^= a;
    a ^= b;
    // Now a=9, b=5

    // Check if power of 2
    int p = 16;
    bool isPow2 = (p > 0) && ((p & (p - 1)) == 0);

    return 0;
}
```

---

## 4.6 The Comma Operator

**Plain English Explanation:**
The comma operator `,` evaluates the left operand, discards the result, evaluates the right operand, and returns the right operand's value. It is rarely used outside of `for` loop headers.

**Java Equivalent:**
Java only allows commas in `for` loops headers or variable declarations. It does not have a general comma operator.

**Code Example:**

```cpp
#include <iostream>

int main() {
    int x = 0;
    
    // y will be 5.
    // The expression calculates (x=1), discards 1.
    // Calculates (x+2), discards 3.
    // Calculates 5, assigns to y.
    int y = (x = 1, x + 2, 5);
    
    std::cout << "y: " << y << "\n"; // 5
    
    // Most common valid use case:
    for (int i = 0, j = 10; i < j; ++i, --j) {
        // Two loop counters updated simultaneously
    }
    
    return 0;
}
```

---
---

# Part 5: Functions (5.1-5.11)

## 5.1 Function Basics

**Plain English Explanation:**
Functions in C++ are like static methods in Java. They can exist globally, entirely outside of any class. They must be declared before they are used, which is why header files (or forward declarations) are common.

**Java Equivalent:**
`public static ReturnType methodName(Args)` inside a class.

**Key Differences:**

| Feature | Java | C++ |
| :--- | :--- | :--- |
| **Location** | Must be in a class | Can be freestanding / global |
| **Declaration Order** | Order doesn't matter | **Must** be declared before use |

**Code Example:**

```cpp
#include <iostream>

// Forward declaration (prototype). Tells compiler "this exists".
int multiply(int a, int b);

int main() {
    // Compiler knows 'multiply' exists, so this works.
    std::cout << multiply(3, 4) << "\n";
    return 0;
}

// Definition (implementation)
int multiply(int a, int b) {
    return a * b;
}
```

---

## 5.2 🔴 Pass-by-Value vs Pass-by-Reference (THE CRITICAL TOPIC)

**Plain English Explanation:**
In C++, you explicitly control whether you pass a copy of data, or the original data itself.
- **Pass-by-Value:** Creates a brand-new copy of the variable. Modifying it inside the function doesn't affect the caller.
- **Pass-by-Reference:** Passes the actual memory address (secretly). Modifying it inside the function modifies the caller's variable. Denoted by `&`.

**Java Equivalent:**
Java is ALWAYS pass-by-value. However, for Objects, Java passes the *reference by value*. This means in Java, you don't copy the whole Array/Object, you copy the pointer to it.

**Key Differences:**

| Feature | Java | C++ |
| :--- | :--- | :--- |
| **Primitives (int, etc)** | Pass-by-value | Pass-by-value |
| **Objects (String, List)**| Pointer passed by value (Modifies original) | **Deep Copied by default!** |
| **To avoid copying...** | Happens automatically | Must explicitly use `&` |

**Code Example: The Vector Copy Disaster**

```cpp
#include <iostream>
#include <vector>

// 🔴 DISASTER: PASS BY VALUE
// Every time this is called, C++ loops through the entire vector,
// allocates new heap memory, and copies every single element. O(N) operation!
void slowFunction(std::vector<int> v) {
    // Modifications to 'v' here DO NOT affect the original!
    v[0] = 99; 
}

// ✅ GOOD: PASS BY REFERENCE
// 'v' is just an alias to the caller's vector. Zero copying. O(1) operation.
void fastFunction(std::vector<int>& v) {
    // Modifications here DO affect the original!
    v[0] = 99; 
}

// ✅ BEST: PASS BY CONST REFERENCE
// Zero copying, but enforced read-only.
// Use this for any non-primitive type you don't want to modify!
void safeFunction(const std::vector<int>& v) {
    // v[0] = 99; // COMPILE ERROR: v is const!
    std::cout << v[0] << "\n";
}

int main() {
    std::vector<int> myVec = {1, 2, 3};
    slowFunction(myVec);
    std::cout << myVec[0] << "\n"; // Prints 1 (unchanged)
    
    fastFunction(myVec);
    std::cout << myVec[0] << "\n"; // Prints 99 (changed!)
    return 0;
}
```

🧠 **Behind the Scenes:**
Because C++ lacks garbage collection, variables live on the stack. `std::vector` is a stack object that holds a pointer to a heap array. If you pass it by value, C++ calls the vector's "Copy Constructor", which actively allocates a new heap array and clones the data. Java objects are always pointers, so copying a Java pointer is cheap (4-8 bytes). In C++, you must use `&` to get this cheap reference behavior!

---

## 5.3 Default Arguments

**Plain English Explanation:**
You can assign default values to function parameters. If the caller omits them, the default is used.

**Java Equivalent:**
Java does not have default arguments. You have to write overloaded methods.

**Key Differences:**

| Feature | Java | C++ |
| :--- | :--- | :--- |
| **Default Args** | No native support | Supported (`int f(int x = 0)`) |

**Code Example:**

```cpp
#include <iostream>

// All default arguments MUST be at the end of the parameter list.
void printInfo(std::string name, int age = 18, bool active = true) {
    std::cout << name << ", " << age << ", " << active << "\n";
}

int main() {
    printInfo("Alice", 25, false); // Alice, 25, 0
    printInfo("Bob", 30);          // Bob, 30, 1 (uses default active)
    printInfo("Charlie");          // Charlie, 18, 1 (uses default age and active)
    
    // printInfo("Dave", false); // 🔴 ERROR: 'false' gets cast to age! 
                                 // You cannot skip arguments in the middle.
    return 0;
}
```

---

## 5.4 Function Overloading

**Plain English Explanation:**
Functions with the same name can exist as long as they have different parameter types or counts.

**Java Equivalent:**
Identical to Java method overloading.

**Code Example:**

```cpp
#include <iostream>

void print(int i) { std::cout << "Integer: " << i << "\n"; }
void print(double f) { std::cout << "Double: " << f << "\n"; }
void print(const std::string& s) { std::cout << "String: " << s << "\n"; }

int main() {
    print(5);       // Calls int version
    print(5.5);     // Calls double version
    print("Hello"); // Calls string version (via implicit cast from char* to std::string)
    return 0;
}
```

---

## 5.5 `inline` Functions

**Plain English Explanation:**
The `inline` keyword suggests to the compiler that it should copy-paste the function's body directly into the calling code instead of making a standard function call (which involves jumping in memory and pushing to the call stack).

**Java Equivalent:**
The JVM JIT compiler automatically inlines small, frequently called methods at runtime. In C++, you can hint this explicitly at compile-time.

**Code Example:**

```cpp
#include <iostream>

// Hint to the compiler to inline this function
inline int max(int a, int b) {
    return (a > b) ? a : b;
}

int main() {
    int result = max(5, 10);
    // The compiler likely transforms the above into:
    // int result = (5 > 10) ? 5 : 10;
    return 0;
}
```

⚡ **Performance Notes:** Modern C++ compilers (GCC/Clang with `-O2` or `-O3`) automatically inline functions even without the `inline` keyword. Today, `inline` is primarily used to bypass the One Definition Rule (allowing function definitions in header files).

---

## 5.6 Lambda Expressions

**Plain English Explanation:**
Lambdas are anonymous functions. They can "capture" variables from their surrounding scope.

**Java Equivalent:**
`() -> {}` (Lambda expressions).

**Key Differences:**

| Feature | Java | C++ |
| :--- | :--- | :--- |
| **Variable Capture** | Captured variables must be "effectively final" | You can capture by value (read-only), or by reference (fully mutable) |
| **Syntax** | `(args) -> { body }` | `[captures](args) { body }` |

**Code Example:**

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int multiplier = 2;
    int counter = 0;

    // [] : Capture nothing
    // [=] : Capture everything by VALUE (read-only copy)
    // [&] : Capture everything by REFERENCE (read/write original)
    // [x, &y] : Capture x by value, y by reference
    
    // Example: Capture 'multiplier' by value, 'counter' by reference
    auto myLambda = [multiplier, &counter](int val) {
        counter++; // Modifies outer counter
        // multiplier = 5; // 🔴 COMPILE ERROR: Captured by value, is read-only
        return val * multiplier;
    };

    std::cout << myLambda(5) << "\n"; // 10
    std::cout << "Calls: " << counter << "\n"; // 1

    // Mutable lambda: allows changing value-captured variables locally (rare)
    auto mutLambda = [multiplier]() mutable {
        multiplier++; // Changes the LOCAL COPY, not the outer one
        return multiplier;
    };
    
    // Generic lambda (C++14): auto parameter types!
    auto printAny = [](auto x) { std::cout << x << "\n"; };
    printAny(10);
    printAny("Hello");

    return 0;
}
```

🧠 **Behind the Scenes:**
The compiler generates a unique, hidden `class` for every lambda. Captured variables become private member variables of this class. The `()` operator is overloaded to execute the body.

---

## 5.7 Function Pointers

**Plain English Explanation:**
In C++, you can store the memory address of a function in a variable, pass it to other functions, and call it later.

**Java Equivalent:**
Passing a class that implements an interface (like `Comparator`), or using Method References (`Math::max`).

**Code Example:**

```cpp
#include <iostream>

int add(int a, int b) { return a + b; }
int multiply(int a, int b) { return a * b; }

// Function that takes a function pointer
void executeAndPrint( int (*operation)(int, int), int x, int y ) {
    std::cout << operation(x, y) << "\n";
}

int main() {
    // ptr is a pointer to a function taking two ints and returning an int
    int (*ptr)(int, int) = add;
    std::cout << ptr(5, 3) << "\n"; // 8
    
    ptr = multiply;
    std::cout << ptr(5, 3) << "\n"; // 15
    
    executeAndPrint(add, 10, 20); // 30
    return 0;
}
```

🔴 **Gotcha:** The syntax `int (*ptr)(int, int)` is famously horrible to read. Use `std::function` instead!

---

## 5.8 `std::function`

**Plain English Explanation:**
`std::function` (from `<functional>`) is a modern, clean wrapper that can hold *anything* callable: standard functions, lambdas, or objects acting as functions (functors).

**Java Equivalent:**
`java.util.function.Function`, `Predicate`, `Supplier`, `Consumer`.

**Code Example:**

```cpp
#include <iostream>
#include <functional>

int add(int a, int b) { return a + b; }

// Much cleaner parameter syntax!
void execute(std::function<int(int, int)> op) {
    std::cout << op(4, 5) << "\n";
}

int main() {
    // Can hold a regular function
    std::function<int(int, int)> func1 = add;
    
    // Can hold a lambda
    std::function<int(int, int)> func2 = [](int a, int b) { return a * b; };
    
    execute(func1); // 9
    execute(func2); // 20
    
    return 0;
}
```

⚡ **Performance Notes:** `std::function` has minor overhead compared to raw function pointers or passing lambdas via templates due to potential heap allocations (type erasure).

---

## 5.9 Recursion Notes

**Plain English Explanation:**
Functions calling themselves. Works exactly like Java.

**Key Differences:**
Like Java, deeply recursive functions will cause a Stack Overflow. However, the stack size in C++ is determined by the operating system (typically 8MB on Linux, 1MB on Windows). Java's stack size is determined by the JVM (`-Xss`).

---

## 5.10 Variadic Functions

**Plain English Explanation:**
Functions that take an arbitrary number of arguments.

**Java Equivalent:**
Varargs (`String... args`).

**Key Differences:**
In C++, C-style varargs (`...`) are completely unsafe and bypass type checking (used in `printf`). Modern C++ uses Variadic Templates (advanced topic, Part 9), which are type-safe.

**Code Example (C-style, discourage use):**
```cpp
#include <iostream>
#include <cstdarg>

// First arg must dictate how many follow
void printInts(int count, ...) {
    va_list args;
    va_start(args, count);
    for(int i = 0; i < count; ++i) {
        int val = va_arg(args, int); // Extracted dynamically!
        std::cout << val << " ";
    }
    va_end(args);
    std::cout << "\n";
}

int main() {
    printInts(3, 10, 20, 30);
    return 0;
}
```

---

## 5.11 `constexpr` Functions

**Plain English Explanation:**
`constexpr` tells the compiler: "If you know the inputs at compile-time, evaluate this function during compilation rather than at runtime." It's a huge performance optimization.

**Java Equivalent:**
None. The Java compiler does some constant folding (e.g., `2 + 3` becomes `5`), but doesn't run arbitrary methods at compile time.

**Code Example:**

```cpp
#include <iostream>

// Evaluated at compile-time if inputs are compile-time constants
constexpr int factorial(int n) {
    return n <= 1 ? 1 : (n * factorial(n - 1));
}

int main() {
    // The compiler pre-computes 5! and physically replaces this line 
    // with 'int result = 120;' in the compiled binary!
    constexpr int result = factorial(5); 
    
    std::cout << result << "\n";
    
    // Can also be used normally at runtime
    int x;
    std::cin >> x;
    std::cout << factorial(x) << "\n"; // Computes at runtime
    
    return 0;
}
```


## Part 6: Pointers & References — "The Java Developer's Wall"

### 6.1 What is a Pointer?

In C++, a pointer is a variable that stores a **memory address**. While Java hides memory addresses entirely, C++ exposes them so you can manipulate exactly where data lives and how it is shared. The `&` operator gets the address of a variable (the "address-of" operator). The `*` operator accesses the value at a given address (the "dereference" operator).

**Java Equivalent:** Java Object References. When you do `MyClass obj = new MyClass();`, `obj` is essentially a pointer under the hood, but Java manages the memory and doesn't let you see or alter the raw hexadecimal address.

**Key Differences:**

| Feature | Java Object References | C++ Pointers |
| :--- | :--- | :--- |
| **Visibility** | Opaque (cannot see the address) | Transparent (can print and manipulate the hex address) |
| **Syntax** | Implicit (all objects are references) | Explicit (must use `*` to declare, `&` to assign, `*` to dereference) |
| **Reassignment** | Can be reassigned to point elsewhere | Can be reassigned to point elsewhere |
| **Target Type** | Only Objects | **Any** type (primitives, objects, pointers to pointers) |

**Code Example:**

```cpp
#include <iostream>
#include <string>

int main() {
    // Java: int x = 10;
    int x = 10;
    
    // Java: (No direct equivalent, but like an Object reference storing an address)
    int* ptr = &x; // 'ptr' stores the memory address of 'x'

    std::cout << "Value of x: " << x << std::endl;       // Prints: 10
    std::cout << "Address of x: " << &x << std::endl;    // Prints e.g., 0x7ffeefbff5ac
    std::cout << "Value of ptr: " << ptr << std::endl;   // Prints e.g., 0x7ffeefbff5ac
    
    // Dereferencing: following the pointer to its target
    std::cout << "Value AT ptr: " << *ptr << std::endl;  // Prints: 10

    // Modifying value through the pointer
    *ptr = 42; 
    std::cout << "New value of x: " << x << std::endl;   // Prints: 42

    return 0;
}
```

🧠 **Behind the Scenes:** A pointer is just an integer (usually 64 bits on a 64-bit system) representing a slot in RAM. When you compile with `-Wall -Wextra -fsanitize=address,undefined`, the compiler tracks if you are trying to read or write to an invalid memory slot.

🔴 **Gotchas:** 
* Uninitialized pointers point to garbage addresses, not `null`! Using one causes undefined behavior (often a segmentation fault).
* Forgetting the `*` when changing the value. `ptr = 42` tries to change the *address* to memory location 42 (which will crash). You mean `*ptr = 42`.

---

### 6.2 Pointer Arithmetic

Pointer arithmetic allows you to add or subtract integers from a pointer. Doing so moves the pointer forward or backward in memory by multiples of the *size of the type it points to*.

**Java Equivalent:** None. Java strictly forbids pointer arithmetic to prevent memory corruption and ensure type safety. Array indexing (`arr[i]`) is the closest functional equivalent.

**Key Differences:**

| Feature | Java | C++ |
| :--- | :--- | :--- |
| **Math on Addresses** | Forbidden | Completely allowed (`ptr + 1`, `ptr++`) |
| **Meaning of `+ 1`** | N/A | Moves address forward by `sizeof(type)` bytes |
| **Array Access** | `arr[i]` | `arr[i]` OR `*(arr + i)` |

**Code Example:**

```cpp
#include <iostream>

int main() {
    int arr[] = {10, 20, 30, 40};
    
    // Arrays decay to pointers to their first element
    int* ptr = arr; // Points to arr[0] (value 10)

    std::cout << *ptr << std::endl;       // Prints: 10

    // Pointer arithmetic: Move to the next integer
    ptr = ptr + 1; // Moves forward by 4 bytes (size of an int)
    std::cout << *ptr << std::endl;       // Prints: 20

    ptr++; // Moves forward another 4 bytes
    std::cout << *ptr << std::endl;       // Prints: 30
    
    // Accessing an offset without changing the pointer itself
    std::cout << *(ptr + 1) << std::endl; // Prints: 40

    return 0;
}
```

🧠 **Behind the Scenes:** If `ptr` is at address `0x1000` and points to a 4-byte `int`, `ptr + 1` evaluates to `0x1004`. The compiler does this math automatically based on the pointer's type.

🔴 **Gotchas:** 
* Moving outside the bounds of an array (e.g., `ptr + 100`) doesn't throw an `ArrayIndexOutOfBoundsException`. It simply reads whatever garbage data is in memory at that location, potentially causing catastrophic crashes or silent data corruption.

---

### 6.3 `nullptr`

`nullptr` is a literal representing a null pointer. It indicates that a pointer currently points to *nothing*.

**Java Equivalent:** `null`.

**Key Differences:**

| Feature | Java `null` | C++ `nullptr` |
| :--- | :--- | :--- |
| **Underlying Type** | Special null type | `std::nullptr_t` (can implicitly convert to any pointer type) |
| **Legacy Equivalents** | None | `NULL` or `0` (avoid these in modern C++) |

**Code Example:**

```cpp
#include <iostream>

void doSomething(int* ptr) {
    if (ptr == nullptr) {
        std::cout << "Pointer is null!" << std::endl;
        return;
    }
    std::cout << "Value: " << *ptr << std::endl;
}

int main() {
    int* p1 = nullptr; // Explicitly points to nothing
    doSomething(p1);   // Prints: Pointer is null!

    int x = 5;
    p1 = &x;
    doSomething(p1);   // Prints: Value: 5

    return 0;
}
```

💡 **Tip:** Always initialize raw pointers to `nullptr` if you don't have an address to assign immediately.
🔴 **Gotchas:** In older C++ codebases, you will see `NULL`. `NULL` is just a macro for the integer `0`. This caused horrible bugs in function overloading (where passing `NULL` might call a function taking an `int` instead of a pointer). Always use `nullptr` in modern C++.

---

### 6.4 References (`&`)

A reference is an **alias** for an existing variable. Once initialized, it behaves exactly like the original variable. You cannot change which variable a reference aliases.

**Java Equivalent:** Java does not have this concept. Java passes primitives by value and objects by reference. C++ references allow you to alias *any* type (even primitives like `int`), and are heavily used to implement pass-by-reference.

**Key Differences:**

| Feature | C++ Pointers | C++ References |
| :--- | :--- | :--- |
| **Reassignment** | Can point to different things | **Cannot** be reassigned after initialization |
| **Nullability** | Can be `nullptr` | **Cannot** be null; must bind to a valid object |
| **Syntax** | Use `*` to dereference | Use like a normal variable (no `*` needed) |
| **Initialization** | Can be uninitialized | **Must** be initialized on creation |

**Code Example:**

```cpp
#include <iostream>
#include <string>

// Pass-by-reference function
void modifyString(std::string& strRef) {
    strRef += " World"; // Modifies the original string directly
}

int main() {
    int original = 10;
    int& ref = original; // 'ref' is now an alias for 'original'

    ref = 20;
    std::cout << original << std::endl; // Prints: 20

    // int& badRef; // ERROR: References must be initialized

    std::string greeting = "Hello";
    modifyString(greeting);
    std::cout << greeting << std::endl; // Prints: Hello World

    return 0;
}
```

🧠 **Behind the Scenes:** The compiler usually implements references under the hood exactly like pointers. However, it completely hides the address management and dereferencing from you.

🔴 **Gotchas:** 
* A reference is permanently bound. If you try `ref = anotherVariable;`, it doesn't make `ref` point to `anotherVariable`; it assigns the *value* of `anotherVariable` into the *original* variable `ref` aliases!

---

### 6.5 Rvalue References (`&&`)

Introduced in C++11, an rvalue reference binds to temporary objects (rvalues) that are about to be destroyed. This is the foundation of **Move Semantics**, allowing resources (like heap memory) to be "stolen" from a dying object instead of being expensively copied.

**Java Equivalent:** None. In Java, all object assignment is by reference, so "copying" an object reference is inherently cheap. In C++, assigning an object by value copies the *entire internal state*, which is slow. Move semantics fix this.

**Key Differences:**

| Feature | Java | C++ Lvalue Ref (`&`) | C++ Rvalue Ref (`&&`) |
| :--- | :--- | :--- | :--- |
| **Target** | All objects | Persistent variables (lvalues) | Temporary/dying variables (rvalues) |
| **Purpose** | Share objects | Aliasing, pass-by-reference | Stealing resources (Move Semantics) |

**Code Example:**

```cpp
#include <iostream>
#include <string>
#include <vector>

void processString(std::string& s) {
    std::cout << "Lvalue process (can modify long-living string): " << s << std::endl;
}

void processString(std::string&& s) {
    std::cout << "Rvalue process (stealing from dying temporary string): " << s << std::endl;
    // We can safely gut 's' because nobody else can use it after this!
}

int main() {
    std::string name = "Swayam";
    
    // "name" is an lvalue (it has a name and persists in memory)
    processString(name); // Calls processString(std::string&)

    // "Hello" + " There" creates a temporary, unnamed std::string
    // It is an rvalue (it will be destroyed at the end of the line)
    processString(std::string("Hello") + " There"); // Calls processString(std::string&&)

    // Using std::move casts an lvalue to an rvalue reference, 
    // saying "treat this as if it's dying, you can steal its guts"
    processString(std::move(name)); // Calls processString(std::string&&)
    
    // WARNING: 'name' is now in a valid but unspecified state. Do not use its value!

    return 0;
}
```

⚡ **Performance Notes:** When you return a `std::vector` from a function in modern C++, you don't need to return a pointer. The compiler uses rvalue references (Move Semantics) to instantly transfer the internal array pointer to the caller without copying the actual elements.

---

### 6.6 `const` with Pointers (The Right-to-Left Rule)

`const` guarantees that a value won't be modified. With pointers, things get tricky: is the *pointer* constant, or is the *data it points to* constant?

**Java Equivalent:** `final`. However, Java's `final` on a reference only means the reference cannot point to a new object (equivalent to a `const` pointer). Java has no way to say "the object being pointed to cannot be mutated" (equivalent to pointer to `const`).

**Key Differences:**

| Feature | Java | C++ |
| :--- | :--- | :--- |
| **Reference cannot change target** | `final MyClass obj` | `MyClass* const ptr` |
| **Target data cannot be modified** | N/A (requires Immutable classes) | `const MyClass* ptr` |

**Code Example (The Right-to-Left Rule):**
Read pointer declarations from right to left to understand what is constant.

```cpp
#include <iostream>

int main() {
    int x = 10;
    int y = 20;

    // 1. Pointer to const int (Read right-to-left: ptr1 is a pointer to an int that is const)
    const int* ptr1 = &x; 
    // *ptr1 = 15; // ERROR: Cannot modify the value
    ptr1 = &y;     // OK: Can change the pointer to point to something else

    // 2. Const pointer to int (Read: ptr2 is a const pointer to an int)
    int* const ptr2 = &x;
    *ptr2 = 15;    // OK: Can modify the value
    // ptr2 = &y;  // ERROR: Cannot change the pointer itself

    // 3. Const pointer to const int
    const int* const ptr3 = &x;
    // *ptr3 = 15; // ERROR
    // ptr3 = &y;  // ERROR

    return 0;
}
```

---

### 6.7 Smart Pointers

Smart pointers act like raw pointers but automatically clean up their memory when they go out of scope. **They are the C++ equivalent of Garbage Collection.**

**Java Equivalent:** All standard Java object references.

**Key Differences:**

| Feature | Java Objects | C++ `std::unique_ptr` | C++ `std::shared_ptr` |
| :--- | :--- | :--- | :--- |
| **Ownership** | Shared (Garbage Collected) | Exclusive (Only 1 owner) | Shared (Reference Counted) |
| **Copying** | Always allowed | **Forbidden** (must `std::move`) | Allowed (increments ref count) |
| **Destruction** | Unpredictable (GC cycle) | Immediate (when scope ends) | Immediate (when ref count == 0) |

**Code Example:**

```cpp
#include <iostream>
#include <memory>

class Entity {
public:
    Entity() { std::cout << "Created\n"; }
    ~Entity() { std::cout << "Destroyed\n"; } // Destructor
    void doWork() { std::cout << "Working\n"; }
};

int main() {
    {
        // unique_ptr: Exclusive ownership
        // ALWAYS use std::make_unique instead of new
        std::unique_ptr<Entity> uPtr = std::make_unique<Entity>();
        uPtr->doWork();
        
        // std::unique_ptr<Entity> uPtr2 = uPtr; // ERROR: Cannot copy!
        std::unique_ptr<Entity> uPtr3 = std::move(uPtr); // OK: Transfers ownership
    } // "Destroyed" prints here automatically when uPtr3 goes out of scope!

    {
        // shared_ptr: Shared ownership (Ref Counting)
        std::shared_ptr<Entity> sPtr1 = std::make_shared<Entity>();
        std::cout << "Ref count: " << sPtr1.use_count() << std::endl; // 1
        
        {
            std::shared_ptr<Entity> sPtr2 = sPtr1; // OK: Copies and shares ownership
            std::cout << "Ref count: " << sPtr1.use_count() << std::endl; // 2
        } // sPtr2 dies, Ref count drops to 1. Object NOT destroyed.
        
    } // sPtr1 dies, Ref count drops to 0. "Destroyed" prints here!

    return 0;
}
```

🧠 **Behind the Scenes:** 
* `unique_ptr` has zero overhead compared to a raw pointer. It just wraps a raw pointer and calls `delete` in its destructor.
* `shared_ptr` allocates a separate "control block" in memory to hold the reference count. It is thread-safe for the reference count, making it slightly heavier than a raw pointer.

🔴 **Gotchas:** Never construct two `shared_ptr`s independently from the same raw pointer. Always use `std::make_shared`.

---

### 6.8 Raw vs Smart Pointers

If smart pointers exist, why use raw pointers?

*   **Smart Pointers (`unique_ptr`, `shared_ptr`)** are for **Ownership**. Use them when the pointer is responsible for cleaning up the memory.
*   **Raw Pointers (`*`) and References (`&`)** are for **Observation**. Use them when you want to look at or modify an object, but you do *not* own it, and you trust the owner will keep it alive longer than you need it.

**The Golden Rule in Modern C++:** 
Never use `new` or `delete`. 
* Use `std::make_unique` by default.
* Use `std::make_shared` if multiple owners genuinely need to share the object's lifespan.
* Use raw pointers/references as function parameters to *view* the data.

---

### 6.9 Dangling Pointers & Use-After-Free

A dangling pointer is a pointer that points to a memory location that has been deleted or returned to the operating system.

**Java Equivalent:** Doesn't exist. The Garbage Collector guarantees that an object is never deleted as long as a reference to it exists.

**Code Example (What NOT to do):**

```cpp
#include <iostream>

int* getDanglingPointer() {
    int localVariable = 42;
    return &localVariable; // ERROR! Returns address of a stack variable that dies now.
}

int main() {
    int* ptr = getDanglingPointer();
    // ptr is now "dangling". 
    // Accessing *ptr is Undefined Behavior (Use-After-Free).
    // It might print 42, it might crash, it might print garbage.
    std::cout << *ptr << std::endl; 
    return 0;
}
```

🔴 **Gotchas:** The compiler won't always catch this. You MUST run tools like AddressSanitizer (`-fsanitize=address`) which will immediately crash your program with a detailed report if you dereference a dangling pointer.

---

### 6.10 `void*`

`void*` is a generic pointer. It points to a memory address, but it has no idea *what* type of data is there.

**Java Equivalent:** `Object` reference (historically, before Generics, this was how you wrote generic code).

**Key Differences:**

| Feature | Java `Object` ref | C++ `void*` |
| :--- | :--- | :--- |
| **Type Info** | Knows its real type via Reflection/RTTI | Completely loses type information |
| **Usage** | Cast back to subclass (`(MyClass) obj`) | Cast back to correct pointer type (`static_cast<MyClass*>(ptr)`) |
| **Dereferencing**| Can call `Object` methods | Cannot be dereferenced directly |

**Code Example:**

```cpp
#include <iostream>

void printGeneric(void* data, char type) {
    if (type == 'i') {
        // Must cast it back to the correct pointer type before using!
        int* intPtr = static_cast<int*>(data);
        std::cout << "Integer: " << *intPtr << std::endl;
    } else if (type == 'c') {
        char* charPtr = static_cast<char*>(data);
        std::cout << "Char: " << *charPtr << std::endl;
    }
}

int main() {
    int x = 100;
    char c = 'Z';

    printGeneric(&x, 'i');
    printGeneric(&c, 'c');

    return 0;
}
```

💡 **Tip:** Avoid `void*` in modern C++. Use templates, `std::any`, or `std::variant` instead for type-safe generic programming.

---
---

## Part 7: Memory Management — "No Garbage Collector"

### 7.1 Stack vs Heap

In Java, local primitives live on the Stack, and ALL objects live on the Heap.
In C++, **ANY type (primitive or object) can live on EITHER the Stack or the Heap.**

**Key Differences:**

| Feature | Stack (Automatic Storage) | Heap (Dynamic Storage) |
| :--- | :--- | :--- |
| **Speed** | ⚡ Blazing fast | Slower (requires OS intervention) |
| **Size** | Small (typically 1MB - 8MB) | Massive (limited by system RAM) |
| **Creation** | Normal variable declaration | Requires `new` (or `make_unique`) |
| **Cleanup** | Automatic (when scope `{ }` ends) | Manual (requires `delete`) or Smart Pointers |
| **C++ Default** | Use this by default! | Use only when necessary! |

**Code Example:**

```cpp
#include <iostream>
#include <string>

class User {
public:
    std::string name;
    User(std::string n) : name(n) {}
};

int main() {
    // 1. STACK ALLOCATION (The C++ Way)
    // Instantly allocated. Automatically destroyed at the closing '}'.
    User stackUser("Alice");
    std::cout << stackUser.name << std::endl; // Use dot operator (.)

    // 2. HEAP ALLOCATION (The Java Way - but requires manual cleanup!)
    // Allocated dynamically. Will live forever until deleted.
    User* heapUser = new User("Bob");
    std::cout << heapUser->name << std::endl; // Use arrow operator (->) for pointers

    delete heapUser; // MUST manually clean up!

    return 0;
}
```

🔴 **Gotchas:** Java developers instinctually type `MyClass* obj = new MyClass();` for everything. In C++, this is terrible practice. Unless an object needs to outlive its current scope or is massive, **allocate it on the stack**.

---

### 7.2 `new` and `delete` (and `delete[]`)

`new` requests memory from the OS on the Heap and calls the object's constructor. `delete` calls the object's destructor and returns memory to the OS.

**Java Equivalent:** `new` keyword. (Java has no `delete`).

**Code Example:**

```cpp
#include <iostream>

int main() {
    // Single object
    int* ptr = new int(42);
    delete ptr; // Cleanup single object

    // Arrays on the heap
    int* arr = new int[100]; 
    // ... use arr ...
    
    // 🔴 GOTCHA: Arrays MUST be deleted with delete[]
    delete[] arr; 

    return 0;
}
```

🔴 **Gotchas:** 
* Mixing `new` with `delete[]` or `new[]` with `delete` causes Undefined Behavior.
* **Modern C++ Rule:** You should almost *never* see `new` or `delete` in your code. Use `std::vector` for arrays and `std::unique_ptr` for heap objects.

---

### 7.3 RAII — The Most Important C++ Idiom

**RAII** stands for **Resource Acquisition Is Initialization**. 
It is the heart of C++. The rule is:
1. When a class is created (constructor), it acquires a resource (memory, file handle, network socket).
2. When the class goes out of scope (destructor), it releases that resource.

**Java Equivalent:** `try-with-resources`. However, RAII is automatic and works everywhere natively, whereas `try-with-resources` requires explicit syntax (`try (Resource r = ...)`) and only works with `AutoCloseable`.

**Code Example:**

```cpp
#include <iostream>
#include <fstream>

class FileHandler {
private:
    std::ofstream file;
public:
    // Constructor acquires the resource
    FileHandler(const std::string& filename) {
        file.open(filename);
        std::cout << "File opened.\n";
    }

    void write(const std::string& text) {
        file << text;
    }

    // Destructor automatically releases the resource!
    ~FileHandler() {
        if (file.is_open()) {
            file.close();
            std::cout << "File closed automatically.\n";
        }
    }
};

void process() {
    FileHandler fh("test.txt");
    fh.write("Hello RAII");
    // No need to close the file!
    // When 'fh' goes out of scope at the end of this function, 
    // its destructor is guaranteed to run.
}

int main() {
    process();
    return 0;
}
```

🧠 **Behind the Scenes:** The C++ compiler injects the destructor call for stack objects at every possible exit point of a function (including normal returns and exceptions). This guarantees no leaks.

---

### 7.4 Smart Pointer Ownership Deep Dive (Circular References)

What happens if `std::shared_ptr` objects point to each other? The reference count will never reach zero. This is a **memory leak via circular reference**.

**Java Equivalent:** Java's Garbage Collector handles circular references using root-reachability analysis. C++ uses reference counting, which is blind to cycles.

**The Fix:** `std::weak_ptr`. It observes a `shared_ptr` but *does not increment the reference count*.

**Code Example:**

```cpp
#include <iostream>
#include <memory>

class B; // Forward declaration

class A {
public:
    std::shared_ptr<B> b_ptr;
    ~A() { std::cout << "A destroyed\n"; }
};

class B {
public:
    // If this was shared_ptr<A>, A and B would leak!
    // weak_ptr breaks the cycle.
    std::weak_ptr<A> a_ptr; 
    ~B() { std::cout << "B destroyed\n"; }
};

int main() {
    {
        std::shared_ptr<A> a = std::make_shared<A>();
        std::shared_ptr<B> b = std::make_shared<B>();
        
        a->b_ptr = b;
        b->a_ptr = a; // Weak assignment, doesn't trap 'a'
    } 
    // Both 'a' and 'b' are successfully destroyed here!

    return 0;
}
```

🔴 **Gotchas:** You cannot use a `weak_ptr` directly. You must temporarily convert it to a `shared_ptr` using `.lock()` to ensure the object hasn't been destroyed while you are trying to use it.

---

### 7.5 Memory Leaks & Tooling

Because there is no GC, if you lose track of a heap allocation without calling `delete` (or using a smart pointer), that memory is gone until the program exits. This is a **Memory Leak**.

**How to find them:**
1. **AddressSanitizer (ASan):** Compile with `-fsanitize=address`. It catches memory leaks, out-of-bounds access, and use-after-free *at runtime*, printing exactly where the error occurred.
2. **Valgrind:** An external tool (Linux/Mac) that profiles your executable and reports leaked bytes. Run via `valgrind --leak-check=full ./my_program`.

---

### 7.6 Object Lifetime & Scope (Deterministic Destruction)

In Java, you know *when* an object is created, but you never know exactly *when* it is destroyed (when the GC runs). 
In C++, destruction is **deterministic**. The exact microsecond an object's scope ends, its destructor is called.

**Key Differences:**

| Feature | Java | C++ |
| :--- | :--- | :--- |
| **Destructor/Finalizer**| `finalize()` (unpredictable, deprecated) | `~ClassName()` (guaranteed, immediate) |
| **Timing** | Sometime later (or never) | Exact moment scope `{ ... }` ends |

**Code Example:**

```cpp
#include <iostream>
#include <mutex>

std::mutex myMutex;

void safeFunction() {
    // std::lock_guard is an RAII object for Mutexes!
    // It locks the mutex in its constructor.
    std::lock_guard<std::mutex> lock(myMutex);
    
    // Do thread-safe work...
    
    // What if an exception is thrown here? 
    // In Java, you'd need a finally block to unlock the mutex.
    // In C++, the stack unwinds, 'lock' is destroyed, and the mutex 
    // is automatically unlocked by the destructor. Guaranteed.
}
```

---

### 7.7 Allocators Overview

By default, `std::vector`, `std::string`, and smart pointers ask the standard heap (`new`/`malloc`) for memory. C++ allows you to override *how* and *where* memory is fetched using **Allocators**.

**Java Equivalent:** None. Java gives you zero control over memory fragmentation or custom allocation strategies (like pooling or arena allocators).

🧠 **Behind the Scenes:** 
Every STL container actually has a hidden template parameter.
`std::vector<int>` is actually `std::vector<int, std::allocator<int>>`.
For ultra-high-performance code (like game engines or high-frequency trading), developers write custom allocators to grab massive blocks of memory upfront and hand it out internally, completely bypassing the OS overhead of normal heap allocation. (You won't need to write one as a beginner, but you should know they exist!).


## Part 8: Strings

### 8.1 Introduction to `std::string` (Construction)
In C++, `std::string` (found in `<string>`) is the standard way to handle text. Unlike Java's `String`, which is a built-in object with special JVM support, `std::string` is just a standard library class. 

**Java Equivalent:** `java.lang.String`

| Feature | Java `String` | C++ `std::string` |
| :--- | :--- | :--- |
| **Location** | Built-in | `#include <string>` |
| **Type** | Reference type (Object) | Value type (Class) |
| **Default init** | `null` | Empty string `""` |
| **Creation** | `String s = "Hello";` | `std::string s = "Hello";` |

```cpp
#include <iostream>
#include <string>

int main() {
    // Java: String s1 = "Hello";
    std::string s1 = "Hello";           // Implicit construction
    
    // Java: String s2 = new String("World");
    std::string s2("World");            // Direct initialization
    
    // Java: String s3 = "";
    std::string s3;                     // Default constructor (empty string)
    
    // Java: String s4 = new String(new char[]{'A', 'B', 'C'});
    std::string s4(5, 'A');             // Fills with 5 'A's: "AAAAA"
    
    std::cout << s1 << " " << s2 << "\n";
    return 0;
}
```

🧠 **Behind the Scenes:** `std::string` manages a dynamic array of characters on the heap. However, many modern C++ implementations use Small String Optimization (SSO), where short strings (typically under 15-22 characters) are stored entirely on the stack within the `std::string` object itself, avoiding a heap allocation!

---

### 8.2 🔴 Strings are Mutable Values
This is one of the most critical differences for Java developers to grasp. Java strings are immutable and live in a string pool. When you pass a string in Java, you pass a reference. In C++, strings are **mutable value types**. 

**Java Equivalent:** Closest to a `StringBuilder` passed by value.

| Feature | Java `String` | C++ `std::string` |
| :--- | :--- | :--- |
| **Mutability** | Immutable (cannot change) | Mutable (can modify in place) |
| **Assignment (`a = b`)**| Points to same object | Copies the entire string content |
| **Passing to method** | Copies reference (fast) | Copies entire string (slow) |
| **Pool** | String pool (interning) | No string pool for `std::string` |

```cpp
#include <iostream>
#include <string>

int main() {
    std::string a = "Hello";
    std::string b = a;  // 🔴 DEEP COPY! 'b' is a completely independent string
    
    b[0] = 'J';         // Modifies 'b' in place
    
    std::cout << a << "\n"; // Output: Hello
    std::cout << b << "\n"; // Output: Jello
    
    return 0;
}
```

🔴 **Gotcha:** If you write `void process(std::string s)` in C++, you are passing by value. Calling `process("extremely long string...")` will copy every single character. Always pass by reference-to-const unless you need a copy: `void process(const std::string& s)`.

---

### 8.3 String Operations (Complete API)
C++ `std::string` provides a rich set of methods, many of which parallel Java's `String` or `StringBuilder` methods.

**Java Equivalent:** `String` and `StringBuilder` methods.

| Operation | Java `String` | C++ `std::string` |
| :--- | :--- | :--- |
| **Length** | `str.length()` | `str.length()` or `str.size()` |
| **Check empty** | `str.isEmpty()` | `str.empty()` |
| **Access char** | `str.charAt(i)` | `str[i]` or `str.at(i)` |
| **Concatenation** | `a + b`, `a.concat(b)` | `a + b`, `a += b`, `a.append(b)` |
| **Substring** | `str.substring(start, end)` | `str.substr(start, length)` 🔴 Note: Length, not end! |
| **Search** | `str.indexOf("text")` | `str.find("text")` |
| **Contains** | `str.contains("text")` | `str.find("text") != std::string::npos` |
| **Compare** | `a.equals(b)` | `a == b` (Operator overloaded!) |
| **Modify (Insert)**| `builder.insert(i, "a")` | `str.insert(i, "a")` |
| **Modify (Erase)** | `builder.delete(start, end)` | `str.erase(start, length)` |

```cpp
#include <iostream>
#include <string>

int main() {
    std::string s = "Hello World";
    
    // Access & Size
    std::cout << s.length() << "\n";  // 11
    std::cout << s[0] << "\n";        // 'H' (no bounds check)
    std::cout << s.at(0) << "\n";     // 'H' (throws std::out_of_range if invalid)
    
    // Concatenation
    std::string s2 = s + "!!!";
    s2 += " Yes.";                    // Modifies s2 in place
    
    // Substring: substr(startIndex, length)
    // 🔴 Java uses substring(startIndex, endIndex)
    std::string sub = s.substr(6, 5); // "World"
    
    // Search
    size_t pos = s.find("World");
    if (pos != std::string::npos) {   // std::string::npos means "not found"
        std::cout << "Found at " << pos << "\n";
    }
    
    // Compare
    std::string a = "apple";
    std::string b = "apple";
    if (a == b) { // True! Compares contents, not memory addresses.
        std::cout << "Strings match\n";
    }
    
    return 0;
}
```

🧠 **Behind the Scenes:** `std::string::npos` is a constant representing the maximum possible value for `size_t` (an unsigned integer type), practically meaning -1.

---

### 8.4 C-style Strings (Null-terminated)
Before `std::string`, C++ inherited strings from C. A C-string is just an array of `char` that ends with a special null character `'\0'`. 

**Java Equivalent:** `char[]` (but Java `char[]` knows its length, C-strings do not).

| Feature | Java | C++ (C-style) |
| :--- | :--- | :--- |
| **Type** | `char[]` | `char*` or `const char*` |
| **Length** | `arr.length` | `strlen(arr)` (searches for `\0`) |
| **Equality** | `Arrays.equals(a,b)` | `strcmp(a,b) == 0` |
| **Concatenation**| N/A | `strcat(dest, src)` (unsafe!) |

```cpp
#include <iostream>
#include <cstring> // For strlen, strcmp

int main() {
    // Literal is a const char array ending in '\0'
    const char* c_str1 = "Hello"; 
    const char* c_str2 = "Hello";
    
    // 🔴 GOTCHA: == compares pointers for C-strings!
    if (c_str1 == c_str2) { 
        // Might be true due to string pooling of literals in the binary, 
        // but it's comparing ADDRESSES, not content!
    }
    
    // Correct way to compare C-strings:
    if (strcmp(c_str1, c_str2) == 0) {
        std::cout << "Contents match\n";
    }
    
    // Length (O(N) operation, scans until '\0')
    std::cout << "Length: " << strlen(c_str1) << "\n";
    
    // Converting C-string to std::string is easy and implicit
    std::string cpp_str = c_str1; 
    
    // Converting std::string back to C-string (needed for legacy C APIs)
    const char* ptr = cpp_str.c_str(); 
    
    return 0;
}
```

🔴 **Gotcha:** String literals `"like this"` in C++ are arrays of `const char`. When you assign them to `auto` or use them in templates, they decay to `const char*`. They are NOT `std::string`! If you need a `std::string` literal, you can use the `s` suffix (C++14): `auto my_str = "Hello"s;`

---

### 8.5 `std::string_view` (C++17)
Passing strings efficiently in C++ used to be tricky. Passing by value `(std::string s)` copies. Passing by `const` reference `(const std::string& s)` is fast but requires the caller to actually have a `std::string` object. If the caller passes a C-string literal `"Hello"`, a temporary `std::string` is dynamically allocated just to bind to the reference!

`std::string_view` solves this. It's a lightweight, non-owning view of a string (just a pointer and a length).

**Java Equivalent:** `CharSequence` (conceptually), or passing array bounds explicitly.

```cpp
#include <iostream>
#include <string>
#include <string_view>

// Fast, non-copying, accepts both std::string and C-strings without allocations!
void print_string(std::string_view sv) {
    std::cout << sv << " (length: " << sv.length() << ")\n";
}

int main() {
    std::string s = "Hello C++";
    
    print_string(s);                  // Passes std::string (O(1), no copy)
    print_string("Literal string");   // Passes C-string (O(1) after length calc, NO heap alloc)
    print_string(s.substr(0, 5));     // Even substrings can be views!
    
    return 0;
}
```

⚡ **Performance Note:** Pass `std::string_view` by value, not reference. It's usually just two pointers size. Use it as a drop-in replacement for `const std::string&` in function parameters.

🔴 **Gotcha:** `string_view` does NOT own the string. If the original string is destroyed, the `string_view` becomes a dangling pointer!

---

### 8.6 String Conversions
Converting between numbers and strings.

**Java Equivalent:** `Integer.parseInt(s)`, `String.valueOf(n)`.

| Operation | Java | C++ |
| :--- | :--- | :--- |
| **String to Int** | `Integer.parseInt(s)` | `std::stoi(s)` |
| **String to Double** | `Double.parseDouble(s)` | `std::stod(s)` |
| **Int to String** | `String.valueOf(n)` | `std::to_string(n)` |

```cpp
#include <iostream>
#include <string>

int main() {
    // Number to String
    int x = 42;
    std::string s = std::to_string(x);
    
    // String to Number
    std::string num_str = "3.14";
    double pi = std::stod(num_str);
    int int_val = std::stoi("100");
    
    // Note: stoi/stod will throw std::invalid_argument if it fails to parse
    return 0;
}
```

---

### 8.7 Character Operations
C++ provides C-style character classification functions in `<cctype>`.

**Java Equivalent:** `Character.isDigit()`, `Character.toUpperCase()`.

```cpp
#include <iostream>
#include <cctype>

int main() {
    char c = 'a';
    
    // Java: Character.isDigit(c)
    bool is_num = std::isdigit(c);
    
    // Java: Character.isLetter(c)
    bool is_alpha = std::isalpha(c);
    
    // Java: Character.toUpperCase(c)
    char upper = std::toupper(c);
    
    return 0;
}
```

---

### 8.8 String Formatting
Historically, C++ relied on C's `printf` or verbose stream operations (`std::cout << "x=" << x;`). Since C++20, `std::format` exists (similar to Python's `f-strings` or Java's `String.format`), but since this guide focuses on up to C++17, here are the common ways:

**Java Equivalent:** `String.format()`

```cpp
#include <iostream>
#include <string>
#include <sstream> // Required for stringstream

int main() {
    int age = 25;
    std::string name = "Alice";
    
    // Pre-C++20: The std::stringstream way (very common)
    std::ostringstream oss;
    oss << name << " is " << age << " years old.";
    std::string result = oss.str();
    
    std::cout << result << "\n";
    
    return 0;
}
```


---
---


## Part 9: Arrays & `std::vector`

### 9.1 C-style Arrays
C++ inherits raw arrays from C. They are extremely low-level and generally avoided in modern C++ in favor of `std::vector` or `std::array`.

**Java Equivalent:** Primitive arrays `int[]`, but far more dangerous.

| Feature | Java `int[]` | C++ `int[]` |
| :--- | :--- | :--- |
| **Bounds checking** | Yes (Throws `ArrayIndexOutOfBoundsException`) | No (🔴 Undefined Behavior!) |
| **Knows its size?** | Yes (`arr.length`) | No (Decays to pointer) |
| **Initialization** | Zero-initialized | 🔴 Contains Garbage data |

```cpp
#include <iostream>

int main() {
    // Java: int[] arr = new int[5]; (all zeros)
    int arr[5]; // 🔴 UNINITIALIZED! Contains random garbage from memory.
    
    int arr2[5] = {0}; // Zero-initializes all elements
    int arr3[] = {1, 2, 3}; // Size inferred as 3
    
    // 🔴 OUT OF BOUNDS
    // Java would throw an exception.
    // C++ will silently corrupt memory or crash with a Segfault.
    arr2[100] = 42; // UNDEFINED BEHAVIOR
    
    return 0;
}
```

🧠 **Behind the Scenes (Array Decay):** When you pass a C-style array to a function, it "decays" into a pointer to its first element. The function has no idea how large the array is. You must always pass the size alongside it: `void process(int* arr, int size)`.

---

### 9.2 `std::array` (Fixed-size)
Introduced in C++11, `std::array` is a thin wrapper around a C-style array. It provides a standard container interface without the overhead of dynamic allocation.

**Java Equivalent:** `int[]` (but stack-allocated).

| Feature | Java `int[]` | C++ `std::array<int, N>` |
| :--- | :--- | :--- |
| **Allocation** | Heap | Stack (usually) |
| **Size** | Fixed at creation (runtime) | Fixed at compile-time |
| **Assignment** | References same array | Deep copies entire array! |

```cpp
#include <iostream>
#include <array>

int main() {
    // Must specify type and exact size at compile-time
    std::array<int, 5> arr = {1, 2, 3, 4, 5};
    
    std::cout << "Size: " << arr.size() << "\n"; // Knows its size!
    
    // Bounds checked access using .at()
    try {
        arr.at(10) = 42; // Throws std::out_of_range
    } catch (const std::exception& e) {
        std::cout << "Caught: " << e.what() << "\n";
    }
    
    // Standard algorithms work perfectly
    std::sort(arr.begin(), arr.end());
    
    return 0;
}
```

---

### 9.3 `std::vector` (The Workhorse)
`std::vector` is the most important container in C++. It is a dynamic, resizable array. Whenever you would reach for an array or `ArrayList` in Java, use `std::vector` in C++.

**Java Equivalent:** `java.util.ArrayList<T>`

| Feature | Java `ArrayList<T>` | C++ `std::vector<T>` |
| :--- | :--- | :--- |
| **Memory** | Array of references to heap objects | Contiguous block of actual objects |
| **Primitives** | Boxed (`Integer`, `Double`) -> slow | Unboxed directly (`int`, `double`) -> fast! |
| **Default Init**| Size 0, capacity 10 (typical) | Size 0, capacity varies |
| **Passing** | Passes reference | 🔴 DEEP COPIES entire vector by default! |

```cpp
#include <iostream>
#include <vector>

int main() {
    // 1. Empty vector
    std::vector<int> v1;
    
    // 2. Vector with 5 elements, all initialized to 0
    std::vector<int> v2(5);
    
    // 3. Vector with 5 elements, all initialized to 42
    std::vector<int> v3(5, 42);
    
    // 4. Initializer list (C++11)
    std::vector<int> v4 = {1, 2, 3, 4, 5};
    
    // 5. Copy construction (Deep copy!)
    std::vector<int> v5 = v4; 
    
    return 0;
}
```

🧠 **Behind the Scenes:** A vector holds three pointers internally: `begin` (start of data), `end` (current number of elements), and `capacity` (end of allocated heap space). Because elements are stored contiguously, vectors are incredibly cache-friendly and extremely fast compared to Java's `ArrayList` of pointers.

---

### 9.4 Vector Operations (Complete API)
How to manipulate a `std::vector`.

| Operation | Java `ArrayList` | C++ `std::vector` |
| :--- | :--- | :--- |
| **Add to end** | `add(e)` | `push_back(e)` / `emplace_back(args)` |
| **Remove last** | `remove(size() - 1)` | `pop_back()` |
| **Get element** | `get(i)` | `[i]` (no check) or `.at(i)` (checked) |
| **Set element** | `set(i, val)` | `v[i] = val` or `v.at(i) = val` |
| **Current count**| `size()` | `size()` |
| **Clear all** | `clear()` | `clear()` |
| **Check empty** | `isEmpty()` | `empty()` |

```cpp
#include <iostream>
#include <vector>

int main() {
    std::vector<std::string> v;
    
    v.push_back("Apple");
    v.push_back("Banana");
    
    // Access
    std::cout << v[0] << "\n";
    
    // Iteration (Range-based for loop)
    // 🔴 Use 'const auto&' to avoid copying every string!
    for (const auto& fruit : v) {
        std::cout << fruit << "\n";
    }
    
    v.pop_back(); // Removes "Banana"
    
    // Pre-allocate memory if you know the size in advance to avoid reallocations
    v.reserve(100); 
    
    return 0;
}
```

---

### 9.5 2D Vectors (DP Table Patterns)
In Java, a 2D array is `int[][]`. In C++, it's a vector of vectors: `std::vector<std::vector<int>>`.

**Java Equivalent:** `ArrayList<ArrayList<Integer>>` or `int[][]`.

```cpp
#include <iostream>
#include <vector>

int main() {
    int rows = 3;
    int cols = 4;
    
    // Java: int[][] grid = new int[rows][cols]; (all zeros)
    
    // C++: Create a vector of 'rows' elements. 
    // Each element is a vector of 'cols' elements initialized to 0.
    std::vector<std::vector<int>> grid(rows, std::vector<int>(cols, 0));
    
    grid[1][2] = 5;
    
    // Iteration
    for (const auto& row : grid) {
        for (int cell : row) {
            std::cout << cell << " ";
        }
        std::cout << "\n";
    }
    
    return 0;
}
```

---

### 9.6 🔴 `.size()` returns `size_t` (The unsigned subtraction trap!)
This is a **major** gotcha that catches almost every Java developer.
In Java, `List.size()` returns a signed `int`.
In C++, `std::vector::size()` returns `size_t`, which is an **unsigned** integer.

```cpp
#include <iostream>
#include <vector>

int main() {
    std::vector<int> v; // Empty vector, v.size() is 0
    
    // 🔴 DISASTER AHEAD:
    // In Java, 0 - 1 = -1. 
    // In C++, unsigned 0 - 1 = 18446744073709551615 (Integer underflow!)
    
    // This loop will NOT skip execution. It will run out of bounds and crash!
    // for (int i = 0; i < v.size() - 1; ++i) { ... }
    
    // ✅ Fix 1: Cast to int
    for (int i = 0; i < (int)v.size() - 1; ++i) { /* safe */ }
    
    // ✅ Fix 2: Add 1 to the other side
    for (size_t i = 0; i + 1 < v.size(); ++i) { /* safe */ }
    
    return 0;
}
```

---

### 9.7 🔴 `[]` vs `.at()` (UB vs exception)
In Java, array access is strictly bounds-checked by the JVM. 
In C++, the `operator[]` on arrays and vectors does **NO** bounds checking by default for performance reasons.

```cpp
#include <iostream>
#include <vector>

int main() {
    std::vector<int> v = {1, 2, 3};
    
    // v[5] = 10; // 🔴 UNDEFINED BEHAVIOR. Might corrupt memory, might crash.
    
    try {
        v.at(5) = 10; // ✅ Throws std::out_of_range cleanly
    } catch (const std::out_of_range& e) {
        std::cout << "Caught out of bounds!\n";
    }
    
    return 0;
}
```

💡 **Tip:** While learning C++, use `.at()` everywhere. Switch to `[]` only when you are 100% mathematically certain of your bounds and need the performance.

---

### 9.8 Sorting & Searching Vectors
C++ separates algorithms from containers. You don't call `v.sort()`; you pass the vector's iterators to `std::sort` in `<algorithm>`.

**Java Equivalent:** `Collections.sort(list)`, `Collections.binarySearch(list, val)`.

```cpp
#include <iostream>
#include <vector>
#include <algorithm> // Required for sort, binary_search, etc.

int main() {
    std::vector<int> v = {5, 2, 9, 1, 5, 6};
    
    // 1. Sort ascending
    std::sort(v.begin(), v.end()); 
    // v is now: {1, 2, 5, 5, 6, 9}
    
    // 2. Sort descending using a lambda (custom comparator)
    // Java: Collections.sort(list, (a, b) -> b.compareTo(a));
    std::sort(v.begin(), v.end(), [](int a, int b) {
        return a > b; // true if 'a' should come before 'b'
    });
    // v is now: {9, 6, 5, 5, 2, 1}
    
    // 3. Binary Search (Requires sorted vector!)
    std::sort(v.begin(), v.end());
    bool found = std::binary_search(v.begin(), v.end(), 6); // true
    
    // 4. Lower Bound (Find first element >= target)
    // Very useful for finding insertion points or counting elements
    auto it = std::lower_bound(v.begin(), v.end(), 5);
    if (it != v.end()) {
        std::cout << "First element >= 5 is at index: " 
                  << std::distance(v.begin(), it) << "\n";
    }
    
    return 0;
}
```

---

### 9.9 `std::span` (Brief Mention, C++20 Preview)
*Note: This guide focuses on C++17, but `span` is worth mentioning as the array equivalent of `string_view`.*

If `std::string_view` is a non-owning window into a string, `std::span` is a non-owning window into a contiguous array (like `std::vector` or C-array). It allows you to pass arrays to functions without copying them and without losing their size information. 

**Java Equivalent:** Passing array slices / bounds manually.

```cpp
// Requires C++20 and #include <span>
// void process(std::span<int> data) {
//     for (int x : data) { ... }
// }
// 
// std::vector<int> v = {1, 2, 3};
// process(v); // No copies, knows size!
```


# Part 10: STL Containers (10.1-10.12)

## 10.1 STL Overview
The Standard Template Library (STL) provides generic, template-based containers, iterators, and algorithms.
- **Java Equivalent**: `java.util.Collections` framework.

| Java Way | C++ Way |
| --- | --- |
| Reference types in collections | Value types (by default), copied into container |
| `size()` returns `int` | `size()` returns `size_t` (unsigned) |
| Garbage Collected | RAII - automatically cleans up elements when container goes out of scope |
| Hierarchy-based interfaces (`List`, `Set`) | Concept-based (Iterators define capabilities) |

🧠 **Behind the Scenes**: C++ containers store elements contiguously or via node-based allocations on the heap. But the container object itself can live on the stack.
🔴 **Gotcha**: `.size()` is unsigned `size_t`. If a container is empty, `container.size() - 1` underflows to a massive positive number!

---

## 10.2 pair & tuple (structured bindings)
`std::pair` holds two heterogeneous values. `std::tuple` holds any number. C++17 introduced structured bindings to unpack them easily.
- **Java Equivalent**: `Map.Entry` (for pairs), or custom classes. No native tuple.

| Java Way | C++ Way |
| --- | --- |
| Create a custom class or use `Object[]` | `std::pair<T1, T2>` or `std::tuple<T1, ...>` |
| Manual unpacking | `auto [a, b] = my_pair;` |

```cpp
#include <iostream>
#include <utility> // for pair
#include <tuple>

int main() {
    // std::pair
    std::pair<int, std::string> p = {1, "One"};
    // C++17 Structured Binding
    auto [num, str] = p;
    
    // std::tuple
    std::tuple<int, double, char> t = {1, 3.14, 'c'};
    auto [i, d, c] = t;
    
    // Access by index if needed
    double pi = std::get<1>(t);
}
```

🧠 **Behind the Scenes**: Structured bindings create hidden variables and bind references/values to them at compile time.
💡 **Tip**: Use structured bindings in range-based for loops over maps: `for(const auto& [key, value] : my_map)`

---

## 10.3 std::map
`std::map` is a sorted associative container (Red-Black tree).
- **Java Equivalent**: `java.util.TreeMap`.

| Java Way | C++ Way |
| --- | --- |
| `TreeMap<K, V>` | `std::map<K, V>` |
| `map.get(key)` returns `null` if absent | `map[key]` inserts default value if absent! |

```cpp
#include <iostream>
#include <map>
#include <string>

int main() {
    std::map<std::string, int> ages;
    ages["Alice"] = 30; // Inserts
    
    // 🔴 GOTCHA: operator[] inserts a default element if the key is not found!
    int bobAge = ages["Bob"]; // Bob is inserted with value 0!
    
    // Proper way to check for existence
    if (ages.find("Charlie") != ages.end()) {
        // found
    }
    
    // C++20 way:
    // if (ages.contains("Charlie")) { ... }
}
```

🔴 **Gotcha**: Using `map[key]` in a read-only context (or on a `const map`) will fail to compile or silently insert garbage default elements if not careful. Use `.at(key)` for bounds-checked read access, which throws `std::out_of_range`.

---

## 10.4 std::unordered_map
Hash table implementation. Average O(1) lookups.
- **Java Equivalent**: `java.util.HashMap`.

| Java Way | C++ Way |
| --- | --- |
| `HashMap<K, V>` | `std::unordered_map<K, V>` |
| Key must override `hashCode()`/`equals()` | Key must have `std::hash` specialization and `operator==` |

```cpp
#include <iostream>
#include <unordered_map>

int main() {
    std::unordered_map<int, std::string> umap = {{1, "One"}, {2, "Two"}};
    umap.insert({3, "Three"});
}
```

🧠 **Behind the Scenes**: Uses an array of buckets containing linked lists (chaining) for collision resolution.

---

## 10.5 set/unordered_set
Collections of unique elements. `set` is sorted (Red-Black tree), `unordered_set` is hashed.
- **Java Equivalent**: `TreeSet` / `HashSet`.

```cpp
#include <set>
#include <unordered_set>

int main() {
    std::set<int> ordered = {3, 1, 2}; // Stores as 1, 2, 3
    std::unordered_set<int> hashed = {3, 1, 2}; // Order not guaranteed
    
    ordered.insert(4);
    // Returns pair<iterator, bool> where bool is true if inserted
    auto [it, inserted] = ordered.insert(3); // inserted is false
}
```

---

## 10.6 multimap/multiset
Like `map` and `set`, but allow duplicate keys/elements.
- **Java Equivalent**: No exact standard library equivalent; typically achieved via `Map<K, List<V>>`.

```cpp
#include <map>

int main() {
    std::multimap<std::string, int> grades;
    grades.insert({"Alice", 90});
    grades.insert({"Alice", 95}); // Multiple values for "Alice" allowed
    
    auto range = grades.equal_range("Alice");
    for (auto it = range.first; it != range.second; ++it) {
        // iterates over 90 and 95
    }
}
```

---

## 10.7 std::stack
LIFO data structure. It's an adapter over an underlying container (usually `deque`).
- **Java Equivalent**: `java.util.Stack` or `Deque` acting as stack.

| Java Way | C++ Way |
| --- | --- |
| `pop()` removes and returns top element | `pop()` removes element but returns `void`! |
| `peek()` views top | `top()` views top |

```cpp
#include <stack>

int main() {
    std::stack<int> s;
    s.push(1);
    s.push(2);
    
    // 🔴 GOTCHA: pop() does NOT return the element!
    int val = s.top(); // Get it first
    s.pop();           // Then remove it
}
```

🧠 **Behind the Scenes**: `pop()` returning `void` is for exception safety. If `pop()` returned by value and the copy constructor threw an exception, the element would be removed from the stack but lost forever.

---

## 10.8 queue/deque
`std::queue` is FIFO (adapter). `std::deque` is a double-ended queue (can insert/remove at both ends O(1)).
- **Java Equivalent**: `java.util.Queue` / `ArrayDeque`.

```cpp
#include <queue>
#include <deque>

int main() {
    std::queue<int> q;
    q.push(1);
    int front = q.front(); q.pop(); // Same pop gotcha!
    
    std::deque<int> dq;
    dq.push_back(2);
    dq.push_front(1); // [1, 2]
    dq.pop_back();    // [1]
}
```

🧠 **Behind the Scenes**: `deque` is typically implemented as a collection of fixed-size contiguous memory blocks, not a single monolithic array.

---

## 10.9 priority_queue
Heap data structure.
- **Java Equivalent**: `java.util.PriorityQueue`.

| Java Way | C++ Way |
| --- | --- |
| Default is Min-Heap | Default is MAX-HEAP 🔴 |

```cpp
#include <queue>
#include <vector>

int main() {
    // 🔴 GOTCHA: Max-heap by default
    std::priority_queue<int> max_heap;
    max_heap.push(1); max_heap.push(5);
    // max_heap.top() is 5
    
    // To make a min-heap, provide container type and comparator:
    std::priority_queue<int, std::vector<int>, std::greater<int>> min_heap;
    min_heap.push(5); min_heap.push(1);
    // min_heap.top() is 1
}
```

---

## 10.10 list/forward_list
`std::list` is a doubly-linked list. `std::forward_list` is a singly-linked list.
- **Java Equivalent**: `java.util.LinkedList`.

⚡ **Performance Note**: You rarely want these in C++! Because of cache-misses iterating through non-contiguous memory, `std::vector` is almost always faster even for insertions/deletions unless elements are huge.

---

## 10.11 bitset
Fixed-size sequence of bits.
- **Java Equivalent**: `java.util.BitSet`.

```cpp
#include <bitset>
#include <iostream>

int main() {
    std::bitset<8> bits("10101010");
    bits.set(0);   // Set bit 0 to 1
    bits.flip();   // Invert all bits
    std::cout << bits.count(); // Number of set bits
}
```

---

## 10.12 Container Comparison Master Table

| Container | Underlying DS | Access O(n) | Insert/Erase O(n) | Best For... |
| --- | --- | --- | --- | --- |
| `vector` | Dynamic Array | O(1) | O(1) at end, O(N) mid | Default choice 99% of time |
| `deque` | Array of Arrays | O(1) | O(1) front/back | Need fast push_front |
| `list` | Doubly-linked | O(N) | O(1) anywhere | Heavy splice operations |
| `set`/`map` | Red-Black Tree | O(log N) | O(log N) | Ordered unique items |
| `unordered_*`| Hash Table | O(1) avg | O(1) avg | Fast lookup, unordered |

---

# Part 11: Iterators & Algorithms (11.1-11.11)

## 11.1 Iterator Basics
Iterators generalize pointers. They allow iterating over any container using the same interface.
- **Java Equivalent**: `java.util.Iterator`.

| Java Way | C++ Way |
| --- | --- |
| `iterator.hasNext()`, `iterator.next()` | `it != container.end()`, `++it`, `*it` |
| One iterator type | Many categories (forward, bidirectional, random access) |

🧠 **Behind the Scenes**: C++ iterators operate on a **half-open range**: `[begin, end)`. `begin()` points to the first element, `end()` points to one past the last element.

```cpp
#include <vector>
#include <iostream>

int main() {
    std::vector<int> v = {1, 2, 3};
    for (std::vector<int>::iterator it = v.begin(); it != v.end(); ++it) {
        std::cout << *it << " "; // Dereference to get value
    }
}
```

---

## 11.2 Iterator Categories
Different algorithms require different iterator power:
1. **Input/Output**: Can read/write once (`istream_iterator`).
2. **Forward**: Can read multiple times, move forward (`forward_list`).
3. **Bidirectional**: Can move forward and backward (`list`, `set`, `map`).
4. **Random Access**: Can jump `it + n` in O(1) (`vector`, `deque`, arrays).

---

## 11.3 Range-based for
C++11 introduced an easier way to iterate, akin to Java's enhanced for loop.

```cpp
std::vector<int> v = {1, 2, 3};
// Copy each element
for (int x : v) {} 

// By reference, to modify
for (int& x : v) { x *= 2; } 

// By const reference, to read without copying (BEST PRACTICE)
for (const auto& x : v) {} 
```
🔴 **Gotcha**: If you write `for (auto x : my_vector_of_huge_strings)`, you will COPY every string. Always use `const auto&` for reading!

---

## 11.4 <algorithm> Non-modifying
Don't write raw loops! C++ has rich algorithms in `<algorithm>`.
- **Java Equivalent**: `java.util.Collections` methods, Streams API.

```cpp
#include <algorithm>
#include <vector>

int main() {
    std::vector<int> v = {1, 2, 3, 4, 5};
    
    // find
    auto it = std::find(v.begin(), v.end(), 3);
    if (it != v.end()) { /* found */ }
    
    // count
    int num = std::count(v.begin(), v.end(), 2);
    
    // all_of / any_of / none_of
    bool all_even = std::all_of(v.begin(), v.end(), [](int i){ return i % 2 == 0; });
    
    // for_each (prefer range-based for in modern C++)
    std::for_each(v.begin(), v.end(), [](int& i){ i++; });
}
```

---

## 11.5 <algorithm> Modifying & The Erase-Remove Idiom
Algorithms that modify containers operate on ranges.

```cpp
#include <algorithm>
#include <vector>

int main() {
    std::vector<int> v = {1, 2, 3, 2, 4};
    
    // sort
    std::sort(v.begin(), v.end());
    
    // reverse
    std::reverse(v.begin(), v.end());
    
    // 🔴 GOTCHA: Erase-Remove Idiom
    // std::remove doesn't actually resize the vector! It just shifts non-removed 
    // elements to the front and returns an iterator to the new logical end.
    // You MUST call erase() to actually shrink the container size.
    v.erase(std::remove(v.begin(), v.end(), 2), v.end()); 
    // C++20 makes this std::erase(v, 2);
}
```

---

## 11.6 Searching (binary_search, lower_bound, upper_bound)
Requires sorted ranges!

```cpp
#include <algorithm>
#include <vector>

int main() {
    std::vector<int> v = {10, 20, 20, 20, 30};
    
    // binary_search returns bool
    bool has_20 = std::binary_search(v.begin(), v.end(), 20);
    
    // lower_bound returns iterator to FIRST element >= target
    auto lb = std::lower_bound(v.begin(), v.end(), 20); // points to first 20
    
    // upper_bound returns iterator to FIRST element > target
    auto ub = std::upper_bound(v.begin(), v.end(), 20); // points to 30
}
```

---

## 11.7 Set Operations
Requires sorted ranges.
`set_union`, `set_intersection`, `set_difference`.

```cpp
std::vector<int> v1 = {1, 2, 3};
std::vector<int> v2 = {2, 3, 4};
std::vector<int> dest;
std::set_intersection(v1.begin(), v1.end(),
                      v2.begin(), v2.end(),
                      std::back_inserter(dest)); // dest will have 2, 3
```

---

## 11.8 Heap Operations
Make a random-access range act like a heap.

```cpp
std::vector<int> v = {3, 1, 4, 1, 5, 9};
std::make_heap(v.begin(), v.end()); // default is max-heap
std::pop_heap(v.begin(), v.end());  // moves largest to end
v.pop_back();                       // actually remove it
```

---

## 11.9 Permutations
Generates lexicographical permutations.

```cpp
std::vector<int> v = {1, 2, 3};
do {
    // processes 123, 132, 213, 231, 312, 321
} while (std::next_permutation(v.begin(), v.end()));
```

---

## 11.10 <numeric>
Mathematical algorithms.

```cpp
#include <numeric>

// accumulate (like reduce / fold)
int sum = std::accumulate(v.begin(), v.end(), 0); 
// 🔴 Gotcha: The initial value (0) determines the return type. 
// Use 0LL for long long sum to prevent overflow!

// iota: fills with sequential values
std::vector<int> seq(5);
std::iota(seq.begin(), seq.end(), 1); // 1, 2, 3, 4, 5

// gcd and lcm (C++17)
int g = std::gcd(12, 18); // 6
```

---

## 11.11 Custom Comparators (3 ways)
Many algorithms take comparators.

| Java Way | C++ Way |
| --- | --- |
| Implement `Comparable` or pass `Comparator` | Lambda, Functor (struct with `operator()`), or Function pointer |

```cpp
// 1. Lambda (Most common modern C++)
std::sort(v.begin(), v.end(), [](int a, int b) {
    return a > b; // Descending
});

// 2. Functor (Struct with operator())
struct Descend {
    bool operator()(int a, int b) const { return a > b; }
};
std::sort(v.begin(), v.end(), Descend());

// 3. std::greater (Built-in functor)
std::sort(v.begin(), v.end(), std::greater<int>());
```

---

# Part 12: OOP in C++ (12.1-12.17)

## 12.1 struct vs class
In C++, `struct` and `class` are 100% identical except for default visibility.
- **Java Equivalent**: `class` (Java has no struct).

| Java Way | C++ Way |
| --- | --- |
| Everything is a `class` | `struct` defaults to `public` members. `class` defaults to `private`. |

```cpp
struct Data {
    int x; // public by default
};

class Object {
    int y; // private by default
public:
    void method() {}
};
```
💡 **Tip**: Convention is to use `struct` for plain data objects (PODs) and `class` when there are invariants to protect via getters/setters.

---

## 12.2 Constructors
Initializes objects.
- **Java Equivalent**: Constructors. Same syntax `ClassName()`.

| Java Way | C++ Way |
| --- | --- |
| Assign in constructor body | **Member Initializer Lists** (Initialize before body executes!) |
| No `explicit` keyword | Use `explicit` to prevent implicit conversions |

```cpp
class Person {
    std::string name;
    int age;
public:
    // Member Initializer List - highly recommended for performance!
    Person(std::string n, int a) : name(std::move(n)), age(a) {
        // body
    }
    
    // explicit prevents: Person p = "Alice"; (which would implicitly convert)
    explicit Person(std::string n) : name(std::move(n)), age(0) {}
};
```
🧠 **Behind the Scenes**: If you don't use the initializer list, member variables are default-constructed first, THEN assigned in the body. Initializer lists construct them directly with the values.

---

## 12.3 Destructors
Cleans up resources when object goes out of scope.
- **Java Equivalent**: `finalize()` (deprecated/unreliable) or `try-with-resources`.

```cpp
class Resource {
    int* data;
public:
    Resource() { data = new int[100]; }
    
    // Destructor: named ~ClassName
    ~Resource() {
        delete[] data; 
        // RAII: This executes automatically when Resource goes out of scope!
    }
};
```
🔴 **Gotcha**: If a class is meant to be derived from, its destructor MUST be `virtual`. Otherwise, deleting a derived class via a base pointer leaks memory!

---

## 12.4 Copy Semantics
C++ copies objects by value by default, meaning every member is copied.
- **Java Equivalent**: `.clone()` (but Java assigns references by default).

```cpp
class StringWrapper {
public:
    std::string str;
    
    // Copy Constructor
    StringWrapper(const StringWrapper& other) : str(other.str) {}
    
    // Copy Assignment Operator
    StringWrapper& operator=(const StringWrapper& other) {
        if (this != &other) { // Self-assignment check
            str = other.str;
        }
        return *this;
    }
};
```

---

## 12.5 Move Semantics (std::move)
Introduced in C++11 to eliminate expensive copies of temporary objects. Instead of copying, it "steals" the internals.

```cpp
class StringWrapper {
public:
    std::string str;
    
    // Move Constructor (noexcept is crucial for vector reallocation)
    StringWrapper(StringWrapper&& other) noexcept : str(std::move(other.str)) {}
    
    // Move Assignment Operator
    StringWrapper& operator=(StringWrapper&& other) noexcept {
        if (this != &other) {
            str = std::move(other.str);
        }
        return *this;
    }
};
```
🧠 **Behind the Scenes**: `std::move` doesn't actually move anything! It just casts an lvalue to an rvalue reference (`&&`), telling the compiler "it is safe to steal resources from this object."

---

## 12.6 Rule of 0/3/5
A core C++ design idiom.
- **Rule of 3 (Pre-C++11)**: If you need to manually define a destructor, copy constructor, or copy assignment operator, you probably need all 3.
- **Rule of 5 (Modern C++)**: Add move constructor and move assignment to the Rule of 3.
- **Rule of 0 (Ideal)**: Design classes so they don't need any of them! Use smart pointers and standard containers (like `std::string` and `std::vector`) that manage their own memory.

---

## 12.7 Operator Overloading
You can make standard operators (+, ==, []) work with your classes.
- **Java Equivalent**: `+` for Strings only. No custom operator overloading.

```cpp
class Vector2D {
public:
    int x, y;
    
    // Overload +
    Vector2D operator+(const Vector2D& rhs) const {
        return {x + rhs.x, y + rhs.y};
    }
    
    // Overload ==
    bool operator==(const Vector2D& rhs) const {
        return x == rhs.x && y == rhs.y;
    }
};
```
(Almost all operators can be overloaded: `+ - * / % ^ & | ~ ! = < > += -= *= /= %= ^= &= |= << >> >>= <<= == != <= >= && || ++ -- , ->* -> () []`)

---

## 12.8 Inheritance
Classes can inherit from others.
- **Java Equivalent**: `extends`.

| Java Way | C++ Way |
| --- | --- |
| `class Child extends Parent` | `class Child : public Parent` |
| Single inheritance only | Multiple inheritance supported (via `,`) |
| `super()` | Call base constructor in initializer list |

```cpp
class Base {
public:
    Base(int x) {}
};

// public inheritance means public members of Base stay public
class Derived : public Base {
public:
    // Call base constructor
    Derived() : Base(10) {} 
};
```
🔴 **Gotcha**: The diamond problem (multiple inheritance) is solved via `virtual` inheritance (`class B : virtual public A`).

---

## 12.9 Polymorphism
Using base class pointers/references to call derived class methods.
- **Java Equivalent**: All methods are implicitly virtual in Java.

| Java Way | C++ Way |
| --- | --- |
| Implicit virtual methods | Must explicitly declare `virtual` |
| `@Override` | `override` keyword (C++11) |
| `final` keyword | `final` keyword (C++11) |

```cpp
class Animal {
public:
    // 🔴 Must be virtual, or polymorphism won't work!
    virtual void speak() const {
        std::cout << "...\n";
    }
    virtual ~Animal() = default; // ALWAYS virtual destructor
};

class Dog : public Animal {
public:
    // override ensures you actually overrode a base method
    void speak() const override {
        std::cout << "Woof!\n";
    }
};
```
🧠 **Behind the Scenes**: Virtual functions use a **vtable** (virtual table). Objects get a hidden pointer (`vptr`) to this table, adding slight memory and performance overhead (dynamic dispatch).

---

## 12.10 Abstract Classes
Classes that cannot be instantiated.
- **Java Equivalent**: `abstract class`.

| Java Way | C++ Way |
| --- | --- |
| `abstract void method();` | `virtual void method() = 0;` (Pure Virtual) |

```cpp
class Shape {
public:
    // "= 0" makes it a "pure virtual" function. Shape is now abstract.
    virtual void draw() const = 0; 
    virtual ~Shape() = default;
};
```

---

## 12.11 Access Specifiers
Controls visibility.
- **Java Equivalent**: `public`, `private`, `protected`.

| Java Way | C++ Way |
| --- | --- |
| Applied per member/method | Grouped into blocks (`public:`) |
| No inheritance modifiers | You can inherit privately (`class A : private B`) |

🧠 **Behind the Scenes**: Private inheritance means "Implemented-in-terms-of". Public methods of the base class become private in the derived class.

---

## 12.12 friend
A class or function can be granted access to private members of another class.
- **Java Equivalent**: Package-private visibility (somewhat similar).

```cpp
class BankAccount {
    int balance = 0;
    // Grants access to private members
    friend void audit(BankAccount& b);
};

void audit(BankAccount& b) {
    std::cout << b.balance; // Allowed!
}
```

---

## 12.13 static Members
Belongs to the class, not instances.
- **Java Equivalent**: `static`.

```cpp
class Counter {
public:
    // Declaration inside class
    static int count; 
    
    // C++17 inline static allows initialization here!
    inline static int fast_count = 0; 
};

// Pre-C++17 Definition outside class
int Counter::count = 0; 
```

---

## 12.14 Nested Classes
Classes inside classes.
- **Java Equivalent**: Inner classes.

🔴 **Gotcha**: In Java, inner classes have a hidden reference to the outer class instance. In C++, nested classes DO NOT! They are just regular classes scoped to the outer class's namespace.

---

## 12.15 this Pointer
Refers to the current object.
- **Java Equivalent**: `this` reference.

🔴 **Gotcha**: In C++, `this` is a POINTER. You must use `->` to access members, not `.`.

```cpp
class Player {
    int health;
public:
    void setHealth(int health) {
        this->health = health; // use -> not .
    }
};
```

---

## 12.16 Enumerations
Named integral constants.
- **Java Equivalent**: `enum`.

| Java Way | C++ Way |
| --- | --- |
| Heavyweight, methods allowed | `enum` (C-style) or `enum class` (strongly typed) |

```cpp
// C-Style enum (pollutes surrounding scope, implicit int conversion)
enum Color { RED, GREEN }; 

// Modern enum class (Scoped, no implicit conversion)
enum class Status { OK, ERROR };

Status s = Status::OK; // Must scope it
```

---

## 12.17 Aggregate Types
A struct/class with no constructors, private members, or virtual methods. Can be initialized with curly braces.

```cpp
struct Point {
    int x, y;
};

// Aggregate initialization
Point p = {10, 20}; 
```
🧠 **Behind the Scenes**: This maps directly to memory layout, similar to C structs, guaranteeing zero-overhead initialization.


## Part 13: Templates & Generic Programming

### 13.1 Function Templates

**Plain English Explanation**  
Function templates are blueprints for functions. Instead of writing separate functions for `int`, `double`, or `std::string`, you write one template, and the compiler generates the specific versions you need automatically based on the types you pass to it.

**Java Equivalent**  
Generic methods (`<T> void doSomething(T item)`).

**Key Differences Table**

| Feature | Java Generic Methods | C++ Function Templates |
|---------|----------------------|------------------------|
| **Implementation** | Type Erasure (one bytecode version) | Code Generation (multiple compiled versions) |
| **Primitives** | Requires boxing (e.g., `Integer`) | Works natively with primitives (`int`, `double`) |
| **Type Deduction** | Infers from context | Infers from arguments (or explicitly specified) |
| **Errors** | Caught at generic declaration | Often caught during instantiation (long error messages) |

**Code Example**

```cpp
#include <iostream>
#include <string>

// Template declaration. 'T' is the template parameter.
template <typename T>
T max(T a, T b) {
    return (a > b) ? a : b;
}

int main() {
    // Implicit type deduction
    std::cout << max(5, 10) << "\n";       // Compiler generates: int max(int, int)
    std::cout << max(5.5, 3.2) << "\n";    // Compiler generates: double max(double, double)
    
    // Explicit type specification
    std::cout << max<double>(5, 3.2) << "\n"; // Forces double version
    
    return 0;
}
```

**🧠 Behind the Scenes**  
When you call `max(5, 10)`, the C++ compiler literally writes a new function `int max(int, int)` into your object file. This is called **instantiation**. If you call it with 10 different types, you get 10 different compiled functions. This causes binary bloat but ensures zero runtime overhead.

**🔴 Gotchas**  
- If types don't perfectly match and you don't explicitly specify them, deduction fails. `max(5, 3.2)` fails because `5` is `int` and `3.2` is `double`. The compiler won't guess which `T` you mean.

---

### 13.2 Class Templates

**Plain English Explanation**  
Class templates allow you to define a class where some or all of the types used within it are left unspecified until the class is instantiated. This is the foundation of the C++ Standard Template Library (STL), like `std::vector<T>`.

**Java Equivalent**  
Generic classes (`class Box<T> { ... }`).

**Key Differences Table**

| Feature | Java Generic Classes | C++ Class Templates |
|---------|----------------------|---------------------|
| **Type Info at Runtime**| Erased | Preserved (Different types are different classes) |
| **Implementation Location**| `.java` file | Usually entirely in header files (`.h`/`.hpp`) |
| **Static Members** | Shared across all instances of `Box<T>` | Unique per instantiated type (e.g., `Box<int>` vs `Box<double>`) |

**Code Example**

```cpp
template <typename T>
class Box {
private:
    T item;
public:
    Box(T initial) : item(initial) {}
    
    T getItem() const {
        return item;
    }
    
    void setItem(T newItem) {
        item = newItem;
    }
};

int main() {
    Box<int> intBox(42);
    Box<std::string> strBox("Hello");
    
    std::cout << intBox.getItem() << "\n";
    std::cout << strBox.getItem() << "\n";
    return 0;
}
```

**🧠 Behind the Scenes**  
Because the compiler needs to generate the code for `Box<int>` when it sees it in `main`, it must have access to the *entire implementation* of the template, not just the declaration. This is why C++ templates are usually fully implemented in header files, unlike regular classes which are split between `.h` and `.cpp`.

**🔴 Gotchas**  
- `Box<int>` and `Box<double>` are completely unrelated types in C++. You cannot assign one to another unless you define a conversion operator.

---

### 13.3 Templates vs Java Generics (Deep Dive)

**Plain English Explanation**  
Java and C++ took fundamentally opposite approaches to generic programming. Java uses **Type Erasure** to maintain backward compatibility, while C++ uses **Code Generation** (Monomorphization) for maximum performance.

**COMPLETE Comparison Table**

| Aspect | Java Generics (Type Erasure) | C++ Templates (Code Generation) |
|--------|------------------------------|---------------------------------|
| **Mechanism** | Compiler replaces `T` with `Object` (or bounds) and adds casts. | Compiler generates a distinct copy of the code for every type used. |
| **Runtime Types** | `List<Integer>` and `List<String>` are the same class at runtime (`List.class`). | `std::vector<int>` and `std::vector<std::string>` are completely different types. |
| **Primitives** | Cannot use primitives directly (`List<int>` is invalid). Requires wrappers. | Supports primitives natively with zero overhead. |
| **Performance** | Overhead from boxing/unboxing and implicit casts. | Maximum performance; identical to hand-written specific code. |
| **Binary Size** | Minimal footprint (one bytecode class). | "Code Bloat": Larger binaries if used heavily with many types. |
| **Capabilities** | Cannot do `new T()`, `new T[]`, or `instanceof T`. | Can do `new T()`, size checks, type checks, and static assertions on `T`. |
| **Duck Typing** | Bounded by interfaces (e.g., `<T extends Comparable>`). | "Compile-time duck typing": If `T` has the methods used in the template, it compiles. |

---

### 13.4 Template Specialization

**Plain English Explanation**  
Sometimes a generic template works for 99% of types, but for one specific type (like `bool` or `char*`), you need a completely different implementation. Template specialization lets you override the generic template for specific types.

**Java Equivalent**  
None. Java cannot change the implementation based on the generic type since the type is erased.

**Key Differences Table**

| Feature | Java | C++ Template Specialization |
|---------|------|-----------------------------|
| **Custom logic per type** | Not possible | Full and Partial specialization available |
| **Type-specific fields** | Not possible | A specialized class can have completely different members |

**Code Example**

```cpp
#include <iostream>
#include <vector>

// 1. Primary Template
template <typename T>
class Printer {
public:
    void print(const T& val) {
        std::cout << "Generic: " << val << "\n";
    }
};

// 2. Full Specialization for 'bool'
template <>
class Printer<bool> {
public:
    void print(const bool& val) {
        std::cout << "Boolean: " << (val ? "TRUE" : "FALSE") << "\n";
    }
};

// 3. Partial Specialization for pointers
template <typename T>
class Printer<T*> {
public:
    void print(T* ptr) {
        if (ptr) std::cout << "Pointer to: " << *ptr << "\n";
        else std::cout << "Null Pointer\n";
    }
};

int main() {
    Printer<int> p1; p1.print(42);         // Calls Primary
    Printer<bool> p2; p2.print(true);      // Calls Full Specialization
    
    int val = 10;
    Printer<int*> p3; p3.print(&val);      // Calls Partial Specialization
}
```

**🧠 Behind the Scenes**  
The compiler always looks for the most specialized version of a template that matches the provided types. This allows standard libraries to optimize containers. For example, `std::vector<bool>` is partially specialized to pack booleans into single bits rather than full bytes!

**🔴 Gotchas**  
- `std::vector<bool>`'s specialization means it doesn't behave like a normal vector (you can't safely take a reference to a single bit).

---

### 13.5 Non-Type Template Parameters

**Plain English Explanation**  
Templates aren't just for types. You can pass compile-time constants (like integers) as template parameters. This is highly useful for fixed-size arrays or matrices where the size is known at compile time.

**Java Equivalent**  
None. Java generics only accept object types.

**Key Differences Table**

| Feature | Java | C++ Non-Type Parameters |
|---------|------|-------------------------|
| **Value in Generic** | Unsupported | Supported (integers, enums, pointers, C++20 allows more) |
| **Fixed Size Types** | Need dynamic allocations or raw arrays | Enables `std::array<int, 5>` (size is part of the type) |

**Code Example**

```cpp
#include <iostream>

// T is a type, Size is a compile-time constant integer
template <typename T, size_t Size>
class FixedArray {
private:
    T data[Size]; // Stack allocated! No 'new' needed.
public:
    constexpr size_t size() const { return Size; }
    
    T& operator[](size_t index) {
        return data[index];
    }
};

int main() {
    FixedArray<int, 5> arr; // Generates a class specifically holding 5 ints
    arr[0] = 10;
    std::cout << "Size: " << arr.size() << "\n";
    return 0;
}
```

**⚡ Performance Notes**  
Non-type template parameters allow you to do stack allocations for generic classes, avoiding the heap overhead completely. `std::array<T, N>` is the standard library version of this and should be used whenever array size is known at compile time.

---

### 13.6 Variadic Templates

**Plain English Explanation**  
Variadic templates allow a template to accept an arbitrary number of template parameters of varying types. This is the mechanism behind C++'s type-safe `printf` equivalents or tuple types.

**Java Equivalent**  
Varargs (`Object... args`), but varargs operate at runtime via arrays and require boxing primitives.

**Key Differences Table**

| Feature | Java Varargs | C++ Variadic Templates |
|---------|--------------|------------------------|
| **Types** | Homogeneous (or `Object...`) | Heterogeneous (each argument can be a different type) |
| **Resolution** | Runtime array creation | Compile-time code generation |
| **Primitives** | Boxed | Handled natively |

**Code Example**

```cpp
#include <iostream>

// Base case for recursion
void printAll() {
    std::cout << std::endl;
}

// Variadic Template: unpacks one element at a time
template <typename T, typename... Rest>
void printAll(T first, Rest... rest) {
    std::cout << first << " ";
    printAll(rest...); // Recursive call with remaining arguments
}

// C++17 Fold Expressions (Cleaner alternative)
template <typename... Args>
void printAllModern(Args... args) {
    // Folds the << operator over all arguments
    (std::cout << ... << args) << std::endl;
}

int main() {
    printAll(1, "hello", 3.14, 'A'); 
    printAllModern(1, " ", "hello", " ", 3.14);
    return 0;
}
```

**🧠 Behind the Scenes**  
For the recursive `printAll`, the compiler generates four different functions, each one peeling off one argument and calling the next function in the chain until the base case is hit. Fold expressions (C++17) let the compiler flatten this out without explicit recursion.

---

### 13.7 SFINAE (Substitution Failure Is Not An Error)

**Plain English Explanation**  
SFINAE is a C++ compiler principle. When the compiler is trying to match a template to a function call, if it attempts to substitute a type and that substitution creates invalid code, *it doesn't throw a compiler error*. Instead, it silently ignores that template and looks for another one.

**Java Equivalent**  
None. 

**Code Example (Brief)**

```cpp
#include <iostream>
#include <type_traits>

// Enable this function ONLY if T is an integral type (int, long, etc.)
template <typename T>
typename std::enable_if<std::is_integral<T>::value>::type
process(T value) {
    std::cout << "Processing integer: " << value << "\n";
}

// Enable this function ONLY if T is a floating point type
template <typename T>
typename std::enable_if<std::is_floating_point<T>::value>::type
process(T value) {
    std::cout << "Processing float: " << value << "\n";
}

int main() {
    process(5);     // Calls integer version. Float version fails substitution, but no error!
    process(3.14);  // Calls float version.
}
```

**🧠 Behind the Scenes**  
SFINAE is what allowed metaprogramming in C++. C++20 introduced "Concepts" which greatly simplify this syntax, but SFINAE (`std::enable_if`) is heavily present in pre-C++20 codebases.

---

### 13.8 `auto` in Templates

**Plain English Explanation**  
As of C++14, you can use `auto` in the parameter list of normal functions to automatically turn them into function templates.

**Code Example**

```cpp
#include <iostream>

// This is literally a function template under the hood!
auto add(auto a, auto b) {
    return a + b;
}

int main() {
    std::cout << add(5, 10) << "\n";       // ints
    std::cout << add(5.5, 2.1) << "\n";    // doubles
    std::cout << add(std::string("A"), std::string("B")) << "\n"; // strings
}
```

---

### 13.9 CTAD (Class Template Argument Deduction) - C++17

**Plain English Explanation**  
Before C++17, if you created a class template, you always had to specify the type. C++17 allows the compiler to deduce class template types from the constructor arguments, just like it does for function templates.

**Java Equivalent**  
Java's Diamond Operator (`List<String> list = new ArrayList<>();`).

**Code Example**

```cpp
#include <vector>
#include <utility>

int main() {
    // Pre-C++17: Explicitly specify types
    std::pair<int, double> p1(1, 3.14);
    
    // C++17 CTAD: Deduces <int, double> automatically!
    std::pair p2(1, 3.14); 
    
    // Works for STL containers too
    std::vector v = {1, 2, 3}; // Deduces std::vector<int>
}
```

---
---

## Part 14: Error Handling & Exceptions

### 14.1 Exception Model

**Plain English Explanation**  
C++ uses a `try/catch/throw` model similar to Java. However, unlike Java, C++ exceptions are not limited to objects inheriting from a specific class. You can literally `throw` anything: an `int`, a `std::string`, or a custom class.

**Java Equivalent**  
`try`, `catch`, `throw`, `finally` (Note: C++ has no `finally` block).

**Key Differences Table**

| Feature | Java | C++ |
|---------|------|-----|
| **What can be thrown?**| Must inherit `Throwable` | **Anything** (`int`, `string`, objects) |
| **Checked Exceptions** | Supported (`throws Exception`)| **Removed** (Dynamic exception specs removed in C++17) |
| **Resource Cleanup** | `finally` block or try-with-resources | **RAII** (Destructors run during stack unwinding) |
| **Catch-All** | `catch (Exception e)` | `catch (...)` |

**Code Example**

```cpp
#include <iostream>
#include <stdexcept>
#include <string>

void mightGoWrong(int val) {
    if (val == 1) throw std::runtime_error("Bad value");
    if (val == 2) throw 404; // Throwing an integer!
    if (val == 3) throw std::string("String error");
}

int main() {
    try {
        mightGoWrong(1);
    } 
    catch (const std::runtime_error& e) { // Catch by const reference!
        std::cout << "Runtime error: " << e.what() << "\n";
    }
    catch (int errorCode) {
        std::cout << "Error code: " << errorCode << "\n";
    }
    catch (...) { // Catch-all block
        std::cout << "Unknown exception caught!\n";
    }
    return 0;
}
```

**🧠 Behind the Scenes (Stack Unwinding)**  
When an exception is thrown, C++ performs **Stack Unwinding**. It looks for the nearest `catch` block up the call stack. As it pops function frames off the stack, **it calls the destructor of every fully constructed local object**. This guarantees no memory leaks for RAII objects (like `std::vector` or smart pointers), which is why C++ doesn't need a `finally` block.

**🔴 Gotchas**  
- **ALWAYS catch by `const` reference (`catch (const std::exception& e)`)**. If you catch by value (`catch (std::exception e)`), you will suffer from **object slicing**, losing the specific subclass data (like `std::runtime_error` details).
- **Never throw from a destructor.** If stack unwinding is already occurring due to an exception, and a destructor throws a second exception, C++ instantly calls `std::terminate()` and crashes your program without warning.

---

### 14.2 `std::exception` Hierarchy

**Plain English Explanation**  
While you can throw anything, modern C++ dictates you should throw objects inheriting from `std::exception`. The STL provides a hierarchy of standard exceptions you should use.

**Java Equivalent**  
`java.lang.Exception` and its subclasses.

**COMPLETE Tree Diagram**

```text
std::exception (Provides virtual const char* what() const)
│
├── std::logic_error (Errors preventable by better programming)
│   ├── std::invalid_argument (e.g., passing negative to sqrt)
│   ├── std::domain_error
│   ├── std::length_error (e.g., resizing vector beyond max_size)
│   └── std::out_of_range (e.g., vector::at() bounds check failed)
│
├── std::runtime_error (Errors occurring strictly at runtime)
│   ├── std::range_error
│   ├── std::overflow_error
│   └── std::underflow_error
│
├── std::bad_alloc (Thrown by 'new' if out of memory)
├── std::bad_cast (Thrown by dynamic_cast on references)
└── std::bad_typeid (Thrown by typeid on null pointers)
```

---

### 14.3 `noexcept`

**Plain English Explanation**  
`noexcept` is a keyword you attach to a function to explicitly tell the compiler (and other programmers): "This function will never, ever throw an exception." 

**Java Equivalent**  
No exact equivalent. Java's `throws` indicates what *can* be thrown.

**Code Example**

```cpp
#include <vector>

// We guarantee this function will not throw
void safeFunction() noexcept {
    int x = 5;
    // If an exception occurs here and isn't caught internally,
    // std::terminate() is called immediately.
}

int main() {
    // You can check at compile time if a function is noexcept
    constexpr bool isSafe = noexcept(safeFunction());
}
```

**⚡ Performance Notes**  
Marking move constructors and destructors as `noexcept` is highly recommended. STL containers like `std::vector` check if an object's move constructor is `noexcept`. If it isn't, the vector will perform slow *copies* during reallocation instead of fast *moves* to guarantee strong exception safety.

---

### 14.4 Custom Exceptions

**Plain English Explanation**  
To create custom exceptions, inherit from `std::exception` or its subclasses, and override the `what()` method.

**Java Equivalent**  
Inheriting from `Exception` or `RuntimeException`.

**Code Example**

```cpp
#include <iostream>
#include <exception>
#include <string>

class DatabaseConnectionError : public std::exception {
private:
    std::string message;
public:
    DatabaseConnectionError(const std::string& msg) : message(msg) {}
    
    // Override what() - Note the noexcept specifier!
    const char* what() const noexcept override {
        return message.c_str();
    }
};

void connect() {
    throw DatabaseConnectionError("Failed to reach 127.0.0.1");
}
```

---

### 14.5 Error Codes vs Exceptions

**Plain English Explanation**  
In Java, exceptions are heavily used for everything. In C++, many codebases (like game engines or embedded systems) ban exceptions completely (using compiler flags like `-fno-exceptions`) because exception handling adds hidden control flow and binary size overhead. Instead, they use Error Codes or modern `std::expected` (C++23) / `std::optional` (C++17).

**Key Differences Table**

| Approach | Pros | Cons |
|----------|------|------|
| **Exceptions** | Clean happy path, automatic stack unwinding. | Hidden control flow, binary bloat, requires RAII discipline. |
| **Error Codes** | Predictable performance, explicit control flow. | Cluttered logic (`if (err) return err;`), easy to ignore by mistake. |
| **`std::optional`**| Great for functions that might fail to return a value but where failure isn't an "error". | Only returns "value or no value", doesn't carry error reasons. |

---

### 14.6 🔴 Undefined Behavior (The Most Important C++ Concept)

**Plain English Explanation**  
In Java, doing something wrong (like accessing an array out of bounds or dereferencing a null pointer) throws an exception (e.g., `ArrayIndexOutOfBoundsException`, `NullPointerException`). The program safely halts.

In C++, doing something wrong usually triggers **Undefined Behavior (UB)**. When UB occurs, the C++ Standard says the compiler can do *literally anything*. It might crash. It might run perfectly. It might silently corrupt data. It might allow a hacker to take over the system. **UB means you have voided the warranty of the language.**

**Java Equivalent**  
None. Java is a "safe" language that guarantees behavior even upon failure. C++ trusts you completely.

**CRITICAL Examples of UB:**

1. **Uninitialized Variables**
   ```cpp
   int x; // In Java, this is 0. In C++, this holds garbage data from memory!
   if (x == 10) { ... } // UB! Reading uninitialized memory.
   ```
2. **Out of Bounds Array Access**
   ```cpp
   int arr[5] = {1, 2, 3, 4, 5};
   arr[10] = 99; // UB! No bounds checking. You just overwrote random memory.
   ```
3. **Dangling Pointers/References**
   ```cpp
   int* getPointer() {
       int local = 5;
       return &local; // UB! Returning pointer to local variable that is destroyed!
   }
   ```
4. **Signed Integer Overflow**
   ```cpp
   int max = 2147483647;
   max = max + 1; // UB! In Java this wraps around. In C++, signed overflow is UB.
   ```
5. **Modifying String Literals**
   ```cpp
   char* str = "Hello"; 
   str[0] = 'h'; // UB! String literals are stored in read-only memory in C++.
   ```

**🧠 Why does UB exist?**  
Performance. If C++ checked array bounds on every access, arrays would be slower. By making it UB, the compiler assumes you *never* access out of bounds, allowing it to optimize loops heavily. It is the programmer's job to ensure UB never happens. 

*(Tip: Compile with `-fsanitize=address,undefined` during development. These flags catch many UBs at runtime!)*

---

### 14.7 Assertions

**Plain English Explanation**  
Assertions are checks that run in debug mode to verify assumptions, but can be completely stripped out in release builds for zero performance cost.

**Java Equivalent**  
`assert condition;`

**Code Example**

```cpp
#include <iostream>
#include <cassert> // Required for assert()

// Runtime assertion
void divide(int a, int b) {
    assert(b != 0 && "Divisor cannot be zero"); // Fails loudly in Debug mode
    std::cout << a / b << "\n";
}

// Compile-time assertion (static_assert)
template <typename T>
void processIntsOnly(T val) {
    // If T is not an int, the code WILL NOT COMPILE.
    static_assert(std::is_same<T, int>::value, "This function only accepts integers!");
}

int main() {
    divide(10, 2);
    // divide(10, 0); // Would abort the program if NDEBUG is not defined
    
    processIntsOnly(5); 
    // processIntsOnly(5.5); // Compiler error!
    return 0;
}
```

**🧠 Behind the Scenes**  
`assert()` is a macro. If you compile your code with the `-DNDEBUG` flag (which is standard for Release builds), all `assert()` statements literally disappear from the code. `static_assert` evaluates purely at compile time and costs nothing at runtime.


# Part 15: Advanced & Modern C++ Topics

## 15.1 Move Semantics Deep Dive

### Plain English Explanation
Move semantics allow the resources (like heap memory) owned by an object to be *transferred* ("moved") to another object instead of being *copied*. This prevents expensive deep copies when an object is about to be destroyed anyway (e.g., a temporary object). 

### Java Equivalent
Java doesn't have an exact equivalent because it uses garbage collection and reference passing. In Java, assigning an object simply copies the reference, which is O(1). In C++, variables are value types, meaning assignment copies the entire object unless you explicitly move it.

### Key Differences Table
| Feature | Java | C++ |
|---------|------|-----|
| Object Assignment | Copies the reference (O(1)) | Deep copies the object by default (O(N)) |
| Temporary Objects | Garbage collected | Cleaned up deterministically; resources can be "stolen" via `std::move` |
| Rvalue References | N/A | `T&&` represents an object that can be safely gutted |

### Code Example
```cpp
#include <iostream>
#include <vector>
#include <string>
#include <utility> // For std::move

class HugeData {
public:
    std::vector<int> data;
    std::string name;

    // Default constructor
    HugeData(std::string n) : name(n), data(1000000, 42) {}

    // Copy Constructor (Expensive)
    HugeData(const HugeData& other) : data(other.data), name(other.name) {
        std::cout << "Copied!\n";
    }

    // Move Constructor (Cheap) - 'noexcept' is crucial!
    HugeData(HugeData&& other) noexcept 
        : data(std::move(other.data)), name(std::move(other.name)) {
        std::cout << "Moved!\n";
    }
};

int main() {
    HugeData a("Source");
    
    // Expensive copy
    HugeData b = a; 

    // Cheap move - 'a' is left in a valid but unspecified state
    HugeData c = std::move(a); 
    
    std::cout << "Size of a's data: " << a.data.size() << "\n"; // Usually 0
    return 0;
}
```

🧠 **Behind the Scenes**: `std::move` doesn't actually move anything! It simply casts a variable to an "rvalue reference" (`T&&`). This cast tells the compiler: "I no longer care about this variable's state; you can call the move constructor/assignment operator to steal its resources."

🔴 **Gotchas**: Never use an object after it has been moved from, except to destroy it or assign a new value to it. Its state is valid but unspecified (usually empty).

⚡ **Performance Notes**: Always declare move constructors and move assignment operators as `noexcept`. If a move constructor can throw, containers like `std::vector` will fall back to using the copy constructor when reallocating memory, silently destroying your performance.

---

## 15.2 std::optional (C++17)

### Plain English Explanation
`std::optional` is a wrapper that either contains a value or doesn't. It's the type-safe way to represent a value that might be missing, replacing the old practice of returning pointers (which could be null) or magic values (like `-1`).

### Java Equivalent
`java.util.Optional<T>`

### Key Differences Table
| Feature | Java | C++ |
|---------|------|-----|
| Overhead | Heap allocated object | Stack allocated, no heap allocation (just adds a boolean flag) |
| Primitive Types | Boxed (e.g., `Optional<Integer>`) | Unboxed (e.g., `std::optional<int>`) |
| Null check | `.isPresent()` | `.has_value()` or cast to `bool` |

### Code Example
```cpp
#include <iostream>
#include <optional>
#include <string>

std::optional<int> findAge(const std::string& name) {
    if (name == "Alice") return 25;
    if (name == "Bob") return 30;
    return std::nullopt; // Explicitly empty
}

int main() {
    std::optional<int> age = findAge("Alice");
    
    if (age) { // Implicit cast to bool
        std::cout << "Age: " << *age << "\n"; // Dereference to access
        std::cout << "Age (safe): " << age.value() << "\n"; // Throws if empty
    }
    
    int ageBob = findAge("Charlie").value_or(18); // Default value
    return 0;
}
```

🧠 **Behind the Scenes**: `std::optional<T>` stores the `T` directly inside itself on the stack, alongside a boolean flag. Its size is `sizeof(T) + sizeof(bool)` plus alignment padding. It never allocates memory on the heap unless `T` itself does.

🔴 **Gotchas**: Using `*opt` or `opt->` when the optional is empty causes undefined behavior. Always check `if (opt)` first, or use `.value()` which throws `std::bad_optional_access` if empty.

---

## 15.3 std::variant and std::any (C++17)

### Plain English Explanation
`std::variant` is a type-safe union that can hold one of a predefined list of types. 
`std::any` is a container that can hold a single value of *any* type whatsoever.

### Java Equivalent
Java doesn't have `std::variant`. You'd typically use an interface or a common base class like `Object`, which is closer to `std::any`.

### Key Differences Table
| Feature | Java | C++ |
|---------|------|-----|
| Multiple types | Common base class (`Object`) | `std::variant<A, B>` (Type-safe union) |
| Any type | `Object` | `std::any` |
| Storage | Heap (Reference) | Stack (Value) / Heap for large `any` |
| Type Checking | `instanceof` | `std::holds_alternative<T>`, `std::get<T>`, `std::visit` |

### Code Example
```cpp
#include <iostream>
#include <variant>
#include <any>
#include <string>
#include <vector>

int main() {
    // --- std::variant ---
    std::variant<int, double, std::string> v = 42;
    v = "Hello Variant";
    
    // Check type and get value
    if (std::holds_alternative<std::string>(v)) {
        std::cout << std::get<std::string>(v) << "\n";
    }
    
    // std::visit (Visitor pattern without inheritance)
    std::visit([](auto&& arg) {
        std::cout << "Visited: " << arg << "\n";
    }, v);

    // --- std::any ---
    std::any a = 10;
    a = std::string("Hello Any");
    
    try {
        std::cout << std::any_cast<std::string>(a) << "\n";
    } catch (const std::bad_any_cast& e) {
        std::cout << "Wrong type!\n";
    }

    return 0;
}
```

🧠 **Behind the Scenes**: `std::variant` takes exactly enough space to store its largest alternative type, plus a small integer tag to remember which type is active. `std::any` uses Small Object Optimization (SOO): small types are stored directly inside the `any` object without heap allocation, while large types require a heap allocation.

⚡ **Performance Notes**: Prefer `std::variant` over `std::any` when possible. `std::variant` avoids heap allocation entirely and gives you compile-time type safety.

---

## 15.4 Structured Bindings (C++17)

### Plain English Explanation
Structured bindings let you unpack a tuple, pair, array, or struct into multiple distinct variables in a single line.

### Java Equivalent
Java lacks this natively (though Java 21 previewed record patterns).

### Key Differences Table
| Feature | Java | C++ |
|---------|------|-----|
| Unpacking Tuples/Structs | Manual assignment to separate variables | `auto [x, y] = myStruct;` |
| Unpacking Maps | `Map.Entry<K,V> e : map.entrySet()` | `for (auto [key, val] : map)` |

### Code Example
```cpp
#include <iostream>
#include <map>
#include <string>

struct Point { int x, y; };

int main() {
    Point p{10, 20};
    auto [x, y] = p; // Unpack struct
    std::cout << "x=" << x << ", y=" << y << "\n";

    std::map<std::string, int> scores = {{"Alice", 90}, {"Bob", 85}};
    
    // Iterating map with structured bindings
    for (const auto& [name, score] : scores) {
        std::cout << name << ": " << score << "\n";
    }
    
    return 0;
}
```

🧠 **Behind the Scenes**: The compiler creates a hidden, anonymous variable holding the compound object, and the declared names become references or aliases to the members of that hidden object. 

---

## 15.5 if constexpr (C++17)

### Plain English Explanation
`if constexpr` is a compile-time `if` statement. The compiler evaluates the condition; if it's false, the code inside the block is entirely discarded during compilation. It is used heavily in template metaprogramming.

### Java Equivalent
Java doesn't have this. It relies on runtime polymorphism or `if` conditions that the JIT compiler *might* optimize away if the condition is constant.

### Key Differences Table
| Feature | Java | C++ |
|---------|------|-----|
| Branch resolution | Runtime (or JIT optimization) | Compile-time (`if constexpr`) |
| Dead code | Still compiled and type-checked | Discarded entirely; doesn't even have to compile |

### Code Example
```cpp
#include <iostream>
#include <type_traits>
#include <string>

template <typename T>
void printValue(const T& val) {
    // If T is a pointer type...
    if constexpr (std::is_pointer_v<T>) {
        if (val) std::cout << "Pointer to: " << *val << "\n";
    } 
    // If T is not a pointer...
    else {
        std::cout << "Value: " << val << "\n";
    }
}

int main() {
    int x = 42;
    int* ptr = &x;
    
    printValue(x);   // Uses the 'else' branch
    printValue(ptr); // Uses the 'if constexpr' branch
    return 0;
}
```

🧠 **Behind the Scenes**: In the `printValue(x)` call, `std::is_pointer_v<int>` is false. The compiler literally deletes the code `if (val) std::cout << ... *val` from the instantiated function. This prevents a compilation error, since `*x` would be illegal on an `int`.

---

## 15.6 chrono Library (Timing/Benchmarking)

### Plain English Explanation
`<chrono>` is the C++ library for dealing with time, durations, and clocks. It is highly type-safe.

### Java Equivalent
`java.time` package (`Instant`, `Duration`, `System.currentTimeMillis()`, `System.nanoTime()`).

### Key Differences Table
| Feature | Java | C++ |
|---------|------|-----|
| High-res timer | `System.nanoTime()` | `std::chrono::high_resolution_clock::now()` |
| Time units | Passed as enums or implicit `long` | Distinct types (e.g., `std::chrono::milliseconds`) |

### Code Example
```cpp
#include <iostream>
#include <chrono>
#include <thread>

int main() {
    // Start clock
    auto start = std::chrono::high_resolution_clock::now();
    
    // Simulate work
    std::this_thread::sleep_for(std::chrono::milliseconds(150));
    
    // End clock
    auto end = std::chrono::high_resolution_clock::now();
    
    // Calculate duration in milliseconds
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    
    std::cout << "Time taken: " << duration.count() << " ms\n";
    
    return 0;
}
```

🧠 **Behind the Scenes**: `duration_cast` is necessary because time units are actual distinct types in C++. You can't assign seconds directly to an integer representing milliseconds without an explicit cast.

---

## 15.7 Filesystem (C++17)

### Plain English Explanation
`<filesystem>` provides cross-platform operations for files and directories (creating, checking existence, iterating, copying).

### Java Equivalent
`java.nio.file.Files` and `java.nio.file.Path`.

### Code Example
```cpp
#include <iostream>
#include <filesystem>
#include <fstream>

namespace fs = std::filesystem;

int main() {
    fs::path dir = "./my_directory";
    
    // Create directory
    if (!fs::exists(dir)) {
        fs::create_directory(dir);
    }
    
    // Create a file inside
    std::ofstream(dir / "hello.txt") << "Hello World!";
    
    // Iterate over directory
    for (const auto& entry : fs::directory_iterator(dir)) {
        std::cout << entry.path() << " (Size: " << entry.file_size() << " bytes)\n";
    }
    
    // Remove recursively
    fs::remove_all(dir);
    
    return 0;
}
```
💡 **Tip**: Use `dir / "filename"` to safely append paths with the correct OS separator.

---

## 15.8 Regex

### Plain English Explanation
The `<regex>` library supports string matching, searching, and replacing using regular expressions.

### Java Equivalent
`java.util.regex.Pattern` and `Matcher`.

### Code Example
```cpp
#include <iostream>
#include <regex>
#include <string>

int main() {
    std::string text = "My email is user@example.com and test@test.org";
    std::regex email_pattern(R"((\w+)@(\w+\.[a-z]+))"); // Raw string literal R"(...)"
    
    std::smatch match; // Holds matches for string
    
    // 1. Search for first match
    if (std::regex_search(text, match, email_pattern)) {
        std::cout << "Found email: " << match[0] << "\n";
        std::cout << "Username: " << match[1] << "\n"; // Group 1
    }
    
    // 2. Iterate over all matches
    auto words_begin = std::sregex_iterator(text.begin(), text.end(), email_pattern);
    auto words_end = std::sregex_iterator(); // Default constructed is end
    
    for (std::sregex_iterator i = words_begin; i != words_end; ++i) {
        std::smatch m = *i;
        std::cout << "Match: " << m.str() << "\n";
    }
    
    return 0;
}
```
🔴 **Gotchas**: Building a `std::regex` object is extremely slow. Always create them outside of loops or mark them `static`.

---

## 15.9 Random Numbers

### Plain English Explanation
Modern C++ uses the `<random>` library instead of the ancient C `rand()`. It separates the generator (which produces random bits) from the distribution (which shapes those bits into a specific range/pattern).

### Java Equivalent
`java.util.Random` and `java.util.concurrent.ThreadLocalRandom`.

### Code Example
```cpp
#include <iostream>
#include <random>

int main() {
    // 1. Obtain a random seed from the hardware
    std::random_device rd; 
    
    // 2. Standard mersenne_twister_engine seeded with rd()
    std::mt19937 gen(rd()); 
    
    // 3. Define the distribution
    std::uniform_int_distribution<> dist(1, 100); // 1 to 100 inclusive
    
    for (int i = 0; i < 5; ++i) {
        std::cout << dist(gen) << " ";
    }
    std::cout << "\n";
    
    return 0;
}
```

---

## 15.10 Multithreading (C++11/14/17)

### Plain English Explanation
C++ standardizes multithreading with `std::thread`, mutexes, and futures. 

### Java Equivalent
`java.lang.Thread`, `synchronized`, `ReentrantLock`, `CompletableFuture`.

### Key Differences Table
| Feature | Java | C++ |
|---------|------|-----|
| Creating a thread | `new Thread(Runnable).start()` | `std::thread t(func);` |
| Synchronized block| `synchronized(obj) { ... }` | `std::lock_guard<std::mutex> lock(m);` |
| Future | `CompletableFuture<T>` | `std::future<T>`, `std::async` |

### Code Example: Threads & Mutexes
```cpp
#include <iostream>
#include <thread>
#include <mutex>
#include <vector>

std::mutex mtx;
int counter = 0;

void incrementWork(int id) {
    for (int i = 0; i < 1000; ++i) {
        // RAII lock: automatically locks, and unlocks when out of scope
        std::lock_guard<std::mutex> lock(mtx);
        counter++;
    }
}

int main() {
    std::vector<std::thread> threads;
    for (int i = 0; i < 10; ++i) {
        threads.emplace_back(incrementWork, i); // Pass arguments to thread
    }
    
    // Must join (or detach) all threads before they go out of scope!
    for (auto& t : threads) {
        t.join();
    }
    
    std::cout << "Final counter: " << counter << "\n";
    return 0;
}
```

### Code Example: Async and Futures
```cpp
#include <iostream>
#include <future>
#include <chrono>

int heavyComputation(int x) {
    std::this_thread::sleep_for(std::chrono::seconds(1));
    return x * x;
}

int main() {
    // Launch function asynchronously
    std::future<int> result = std::async(std::launch::async, heavyComputation, 10);
    
    std::cout << "Doing other work...\n";
    
    // .get() blocks until the result is ready
    std::cout << "Result: " << result.get() << "\n"; 
    
    return 0;
}
```

🔴 **Gotchas**: If a `std::thread` goes out of scope without being `.join()`ed or `.detach()`ed, the program will instantly crash (`std::terminate`).

---

## 15.11 Dynamic Programming Patterns in C++

C++ vectors are highly optimized for DP due to contiguous memory allocation.

### 1D DP (Fibonacci Tabulation)
```cpp
#include <iostream>
#include <vector>

int fib(int n) {
    if (n <= 1) return n;
    std::vector<int> dp(n + 1, 0);
    dp[1] = 1;
    for (int i = 2; i <= n; ++i) {
        dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[n];
}
```

### 2D DP (Memoization)
Use `vector<vector<int>>` and initialize it with `-1`.
```cpp
#include <iostream>
#include <vector>
#include <string>

int solve(const std::string& a, const std::string& b, int i, int j, std::vector<std::vector<int>>& memo) {
    if (i == 0 || j == 0) return 0;
    if (memo[i][j] != -1) return memo[i][j];
    
    if (a[i-1] == b[j-1]) {
        return memo[i][j] = 1 + solve(a, b, i-1, j-1, memo);
    }
    return memo[i][j] = std::max(solve(a, b, i-1, j, memo), solve(a, b, i, j-1, memo));
}

int lcs(std::string a, std::string b) {
    std::vector<std::vector<int>> memo(a.length() + 1, std::vector<int>(b.length() + 1, -1));
    return solve(a, b, a.length(), b.length(), memo);
}
```

⚡ **Performance Notes**: For tight CP limits, avoid `vector<vector<int>>` due to cache locality overhead and initialization time. Use a flat 1D vector `vector<int> dp(rows * cols)` or a static array if limits are known.

---

## 15.12 Spaceship Operator `<=>` (C++20)

*Note: While outside strictly C++17, this is commonly requested as it fundamentally changes how C++ handles comparisons.*

### Plain English Explanation
The three-way comparison operator `<=>` (Spaceship Operator) auto-generates all 6 comparison operators (`==, !=, <, <=, >, >=`) with a single line of code.

### Java Equivalent
`Comparable<T>` / `compareTo()` method.

### Code Example
```cpp
#include <iostream>
#include <compare> // Required for <=>
#include <string>

struct Player {
    std::string name;
    int score;

    // Compiler automatically generates all comparison operators
    // It compares members in the order they are declared (lexicographically)
    auto operator<=>(const Player&) const = default;
};

int main() {
    Player p1{"Alice", 100};
    Player p2{"Bob", 150};
    
    if (p1 < p2) std::cout << "Alice is smaller (lexicographically by name)\n";
    return 0;
}
```

---
---

# Appendix A: Java Habits That Bite You (The Ledger)

1. **Uninitialized Primitive Variables**
   * **Java**: `int x;` defaults to `0`.
   * **C++**: `int x;` holds **garbage data** (whatever was in memory).
   * **Fix**: `int x = 0;`

2. **Passing Objects by Value**
   * **Java**: `void foo(ArrayList list)` passes a reference. O(1).
   * **C++**: `void foo(vector<int> list)` makes a **full deep copy**. O(N).
   * **Fix**: `void foo(const vector<int>& list)`

3. **`unsigned` Subtraction Trap**
   * **Java**: `.size()` is a signed `int`.
   * **C++**: `.size()` returns `size_t` (unsigned). If the vector is empty, `vec.size() - 1` wraps around to `18446744073709551615`.
   * **Fix**: Cast it `(int)vec.size() - 1` or use `vec.empty()`.

4. **Array Bounds Checking**
   * **Java**: `arr[100]` throws `ArrayIndexOutOfBoundsException`.
   * **C++**: `arr[100]` silently reads/writes garbage memory (Undefined Behavior).
   * **Fix**: Use `arr.at(i)` which throws `std::out_of_range`.

5. **Garbage Collection vs RAII**
   * **Java**: `new Obj()` is cleaned up by the GC.
   * **C++**: Raw pointers created with `new` leak memory unless explicitly `delete`d.
   * **Fix**: Never use `new`. Use `std::unique_ptr` or allocate on the stack.

6. **String Mutability**
   * **Java**: `String` is immutable.
   * **C++**: `std::string` is mutable. `str[0] = 'a';` modifies it in place.

7. **String Comparison**
   * **Java**: `s1.equals(s2)`
   * **C++**: `s1 == s2`

8. **`map::operator[]` Auto-Insertion**
   * **Java**: `map.get("key")` returns `null` if not found.
   * **C++**: `map["key"]` **inserts** a default value if not found!
   * **Fix**: Use `map.find("key") != map.end()` or `map.at("key")`.

9. **`PriorityQueue` Default Order**
   * **Java**: Min-heap by default.
   * **C++**: Max-heap by default (`std::priority_queue`).
   * **Fix**: `priority_queue<int, vector<int>, greater<int>>` for min-heap.

10. **The `static` Keyword Meaning**
    * **Java**: Class-level variable/method.
    * **C++**: Means class-level inside a class, but inside a file it means "file-private", and inside a function it means "persist between calls".

11. **Interface vs Multiple Inheritance**
    * **Java**: `implements A, B`
    * **C++**: True multiple inheritance `class C : public A, public B`. Can cause the Diamond Problem.

12. **Virtual Functions**
    * **Java**: All instance methods are dynamically bound (overridable) by default.
    * **C++**: Methods are statically bound unless marked `virtual`.

13. **Local Variable Lifetimes (Dangling Pointers)**
    * **Java**: Returning an object created in a method is fine.
    * **C++**: Returning a reference or pointer to a local variable is fatal. It's destroyed when the function ends.

14. **Template Compilation**
    * **Java**: Generics are compiled once (Type Erasure).
    * **C++**: Templates generate new machine code for every type used. Put template definitions in `.h` files, not `.cpp`.

15. **Exceptions for Control Flow**
    * **Java**: Throwing/catching exceptions is somewhat common.
    * **C++**: Exceptions are extremely slow. Avoid them for normal control flow.

16. **Class Member Initialization**
    * **Java**: Members initialized in the order written.
    * **C++**: Members initialized in the order declared in the class definition, regardless of the constructor's initializer list order!

17. **File Organization**
    * **Java**: One class per `.java` file, directory structure matches packages.
    * **C++**: Freeform. Usually `.h` for declarations, `.cpp` for definitions.

18. **Namespace vs Package**
    * **Java**: `com.google.project`
    * **C++**: `namespace com { namespace google { namespace project { ... } } }`

19. **`char` Size**
    * **Java**: `char` is 16-bit (UTF-16).
    * **C++**: `char` is 1 byte. Usually ASCII/UTF-8.

20. **Main Signature**
    * **Java**: `public static void main(String[] args)`
    * **C++**: `int main(int argc, char* argv[])`

---

# Appendix B: STL ↔ Java Collections Complete Map

| Java Collection | C++ STL Container | Internal Structure | Inclusion |
|-----------------|-------------------|--------------------|-----------|
| `ArrayList<T>`  | `std::vector<T>`  | Contiguous array | `<vector>` |
| `LinkedList<T>` | `std::list<T>`    | Doubly-linked list | `<list>` |
| `ArrayDeque<T>` | `std::deque<T>`   | Paged arrays | `<deque>` |
| `HashSet<T>`    | `std::unordered_set<T>`| Hash Table | `<unordered_set>` |
| `TreeSet<T>`    | `std::set<T>`     | Red-Black Tree | `<set>` |
| `HashMap<K,V>`  | `std::unordered_map<K,V>`| Hash Table | `<unordered_map>` |
| `TreeMap<K,V>`  | `std::map<K,V>`   | Red-Black Tree | `<map>` |
| `PriorityQueue<T>` | `std::priority_queue<T>`| Heap (Default MAX) | `<queue>` |
| `Stack<T>`      | `std::stack<T>`   | Adapter | `<stack>` |

### `ArrayList` vs `std::vector` Mapping

| Action | Java `ArrayList` | C++ `std::vector` |
|--------|------------------|-------------------|
| Create | `new ArrayList<>()` | `vector<int> v;` |
| Add to end | `.add(val)` | `.push_back(val)` |
| Read at `i` | `.get(i)` | `v[i]` or `v.at(i)` |
| Write at `i` | `.set(i, val)` | `v[i] = val` |
| Size | `.size()` | `.size()` |
| Is Empty | `.isEmpty()` | `.empty()` |
| Clear | `.clear()` | `.clear()` |
| Sort | `Collections.sort(list)` | `std::sort(v.begin(), v.end())` |

---

# Appendix C: Competitive Programming Quick Reference

### CP Starter Template
```cpp
#include <bits/stdc++.h> // Includes all standard libraries (GCC only)
using namespace std;

#define endl '\n'
using ll = long long;

void solve() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int& x : v) cin >> x;
    
    // logic here
}

int main() {
    // Optimize standard I/O operations for speed
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t = 1;
    cin >> t; // Remove if only 1 test case
    while (t--) {
        solve();
    }
    return 0;
}
```

### Graph Adjacency List
```cpp
int n, m; // nodes, edges
cin >> n >> m;
vector<vector<int>> adj(n + 1); // 1-indexed

for(int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u); // undirected
}
```

### CP Gotchas
1. Use `long long` for variables if sums can exceed `2 * 10^9`.
2. Do NOT use `endl`; it flushes the output stream and causes Time Limit Exceeded. Use `'\n'`.
3. Array sizes `10^5` must be initialized globally or dynamically on the heap (`vector`). Large stack allocations cause Stack Overflow (Segmentation Fault).

---

# Appendix D: Compiler Flags & Debugging

### Essential Compiler Flags (GCC/Clang)
Compile with: `g++ main.cpp -o app -Wall -Wextra -Wpedantic -std=c++17`
* `-Wall -Wextra`: Enables standard and extra warnings. Always use these.
* `-Wpedantic`: Enforces strict ISO C++ standards.
* `-O3`: Maximum optimization (for release/production).
* `-g`: Generates debug symbols (needed for GDB).

### Sanitizers (Magic tools for debugging)
Compile with: `g++ main.cpp -g -fsanitize=address,undefined`
* **AddressSanitizer**: Immediately halts and points to the exact line where an array out-of-bounds, use-after-free, or memory leak occurred.
* **UndefinedBehaviorSanitizer**: Halts on signed integer overflow, division by zero, null pointer dereference.

### Top Common Errors
1. **Segmentation Fault (Core Dumped)**: You dereferenced a null pointer, went out of bounds on an array, or overflowed the stack. Use AddressSanitizer.
2. **Undefined Reference to `foo()`**: Linker error. You declared a function but didn't define it, or forgot to compile the `.cpp` file containing it.
3. **Double Free / Corruption**: You tried to `delete` memory twice. Use Smart Pointers!

### GDB Basics
1. `gdb ./app`
2. `break main.cpp:10` (Set breakpoint at line 10)
3. `run` (Start program)
4. `next` (Step over), `step` (Step into), `continue` (Run to next breakpoint)
5. `print x` (Show variable value)

---

# Appendix E: Complete C++ Syntax Quick Reference Card

### Variables & Types
```cpp
int a = 5;
double b = 3.14;
bool c = true;
char d = 'Z';
std::string e = "Hello";
auto f = 10.5; // Type inference (double)
const int g = 100; // Immutable
constexpr int h = 200; // Compile-time constant
```

### Smart Pointers (Memory Management)
```cpp
#include <memory>
// Unique ownership
std::unique_ptr<int> u = std::make_unique<int>(42);

// Shared ownership (Reference counted)
std::shared_ptr<int> s = std::make_shared<int>(42);
```

### Loops
```cpp
// Range-based for loop (Read-only)
for (const auto& val : vec) { ... }

// Range-based for loop (Modifying)
for (auto& val : vec) { val *= 2; }

// Traditional loop
for (size_t i = 0; i < vec.size(); ++i) { ... }
```

### Functions & Lambdas
```cpp
// Lambda: [captures](params) { body }
auto add = [](int x, int y) { return x + y; };

// Capture by reference [&] or value [=]
int multiplier = 2;
auto multiply = [&](int x) { return x * multiplier; };
```

### Classes
```cpp
class MyClass {
private:
    int x; // Private by default
public:
    // Constructor with initializer list
    MyClass(int val) : x(val) {}
    
    // Const method (promises not to modify object)
    int getX() const { return x; } 
};
```

### Top `<algorithm>` Functions
```cpp
#include <algorithm>
// Sort
std::sort(v.begin(), v.end()); 
std::sort(v.rbegin(), v.rend()); // Reverse sort

// Count occurrences
int c = std::count(v.begin(), v.end(), 42);

// Min/Max Element
auto min_it = std::min_element(v.begin(), v.end());

// Reverse
std::reverse(v.begin(), v.end());
```
