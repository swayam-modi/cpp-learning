#include <iostream>

int main() {
    // 1. Primitive Types in C++
    int age = 21;                  // 4 bytes (typically)
    long long bigNum = 1e18;       // 8 bytes (Equivalent to Java's 'long')
    double pi = 3.14159;           // 8 bytes (64-bit floating point)
    char grade = 'A';              // 1 byte (ASCII char, 0-255)
    bool isPassed = true;          // 1 byte (true/false)

    std::cout << "--- Primitive Types Summary ---" << std::endl;
    std::cout << "int: " << age << ", long long: " << bigNum << std::endl
              << ", double: " << pi << ", char: " << grade << std::endl 
              << ", bool: " << std::boolalpha << isPassed << std::endl;

    // 2. Input with std::cin (Extraction Operator >>)
    std::cout << "\nEnter your age and target score: ";
    int userAge = 0;               // Explicitly initialized to avoid garbage memory!
    long long targetScore = 0;

    std::cin >> userAge >> targetScore;

    // 3. Output with std::cout (Insertion Operator <<)
    std::cout << "You entered -> Age: " << userAge 
              << ", Target Score: " << targetScore << std::endl;

    return 0;
}
