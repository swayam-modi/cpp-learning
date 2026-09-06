#include <iostream>   // This is like Java's "import java.io.*"
using namespace std;                  // It brings in input/output functionality (cin, cout)

// In Java, everything lives inside a class.
// In C++, you CAN have classes, but you don't NEED one.
// Code can live at the top level — the entry point is just a function called 'main'.

int main() {
    // std::cout is the C++ equivalent of System.out.println()
    // "std::" means it lives in the "std" (standard) namespace
    // "<<" is the "insertion operator" — think of it as "send this TO the output stream"
    // std::endl flushes the buffer AND adds a newline (like println)
    cout << "Hello, C++!" << endl;

    // 'return 0' tells the OS: "program finished successfully"
    // In Java, main() is void. In C++, main() returns int.
    return 0;
}