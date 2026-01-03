// Example 1: Basic Input and Output in C++
#include <iostream>
using namespace std;

int main() {
    // ===== OUTPUT WITH cout =====
    cout << "Hello World!\n";
    
    int x = 42;
    double pi = 3.14159;
    string name = "Alice";
    
    cout << "x = " << x << "\n";
    cout << "pi = " << pi << "\n";
    cout << "name = " << name << "\n";
    
    // Chaining outputs
    cout << "All together: " << x << ", " << pi << ", " << name << "\n";
    
    // ===== INPUT WITH cin =====
    cout << "\n--- Input Examples ---\n";
    
    cout << "Enter an integer: ";
    int n;
    cin >> n;
    cout << "You entered: " << n << "\n";
    
    cout << "Enter two numbers separated by space: ";
    int a, b;
    cin >> a >> b;
    cout << "Sum = " << a + b << "\n";
    
    cout << "Enter your name (one word): ";
    string yourName;
    cin >> yourName;
    cout << "Hello, " << yourName << "!\n";
    
    return 0;
}

/*
To compile and run:
    g++ 01_input_output.cpp -o 01_input_output
    ./01_input_output
*/
