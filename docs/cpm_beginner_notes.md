# C++ Competitive Programming: Beginner's Reference Notes

**Target Audience**: Absolute Beginners (Codeforces Newbie / Grey)  
**Goal**: Master the basics of C++ syntax, STL containers, and simple algorithms to solve your first 50 problems.

---

## 1. The Structure of a C++ Program

Every C++ program you write for CP will look roughly like this:

```cpp
// 1. Header Files
#include <bits/stdc++.h> // The "magic" header that includes everything
using namespace std;     // Standard namespace (avoids typing std::cout)

// 2. The Main Function
int main() {
    // 3. Fast I/O (Makes cin/cout faster)
    ios::sync_with_stdio(0); 
    cin.tie(0);

    // 4. Your Code Goes Here
    cout << "Hello, Competitive Programming!" << "\n";

    return 0; // Exit code (0 means success)
}
```

> [!TIP]
> Always include the Fast I/O lines. Without them, `cin` and `cout` can be too slow for problems with large inputs (e.g., 100,000 numbers).

---

## 2. Variables & Data Types

Choose the right box for your data.

| Type | Description | Size | Range (Approx) |
| :--- | :--- | :--- | :--- |
| `int` | Integers | 4 bytes | -2 Billion to +2 Billion ($10^9$) |
| `long long` | Big Integers | 8 bytes | -9 Quintillion to +9 Quintillion ($10^{18}$) |
| `double` | Decimals | 8 bytes | 15 digits of precision |
| `char` | Single Character | 1 byte | 'a', 'Z', '9', '?' |
| `string` | Text | Dynamic | Sequence of characters |
| `bool` | Boolean | 1 byte | `true` (1) or `false` (0) |

> [!WARNING]
> **Overflow Danger**: If a problem says the answer can be up to $10^{10}$ or $10^{18}$, you **MUST** use `long long`. An `int` will overflow and give wrong negative answers.

---

## 3. Input and Output (I/O)

### Basic I/O

```cpp
int x;
cin >> x;        // Read an integer
cout << x;       // Print it
cout << "\n";    // Newline
```

### Reading multiple values
```cpp
int a, b;
cin >> a >> b; // Reads two integers separated by space or newline
```

### Reading a whole line
`cin >> s` stops at a space. To read a full sentence:
```cpp
string s;
getline(cin, s);
```

---

## 4. Control Flow

### If / Else
Logic gates of programming.

```cpp
if (x > 0) {
    cout << "Positive";
} else if (x == 0) {
    cout << "Zero";
} else {
    cout << "Negative";
}
```

### Loops (Repetition)

**For Loop**: When you know how many times to repeat.
```cpp
// Print numbers 0 to 4
for (int i = 0; i < 5; i++) {
    cout << i << " ";
}
```

**While Loop**: Repeat WHILE a condition is true.
```cpp
while (n > 0) {
    n = n / 2; // Keep dividing by 2 until n becomes 0
}
```

**Test Case Loop**: Most CP problems ask you to solve for `t` test cases.
```cpp
int t;
cin >> t;
while (t--) {
    solve(); // Call your solution function
}
```

---

## 5. STL: Vectors (Dynamic Arrays)

Standard C arrays (`int arr[100]`) are fixed size. `vector` is elastic.

```cpp
vector<int> v; 

// Adding elements
v.push_back(10); // Adds 10 to the end
v.push_back(20); // Adds 20 to the end [10, 20]

// Accessing
cout << v[0];    // 10
cout << v.size(); // 2

// Sorting (Important!)
sort(v.begin(), v.end()); // Sorts smallest to largest

// Reverse
reverse(v.begin(), v.end()); 
```

### Iterating through a Vector
```cpp
for (int x : v) { // "For each x in v"
    cout << x << " "; 
}
```
Or the classic way:
```cpp
for (int i = 0; i < v.size(); i++) {
    cout << v[i] << " ";
}
```

---

## 6. STL: Strings

Strings are mutable in C++.

```cpp
string s = "apple";
s += "pie"; // Concatenation -> "applepie"

// Access characters
cout << s[0]; // 'a'

// Substring
string sub = s.substr(0, 5); // "apple" (start index, length)

// Find functionality
if (s.find("pie") != string::npos) {
    cout << "Found pie!";
}
```

---

## 7. STL: Pairs

Store two related values together (e.g., coordinates x, y).

```cpp
pair<int, int> p = {3, 4};
cout << p.first << " " << p.second; // 3 4
```

---

## 8. Simple Algorithms

### Minimum / Maximum
```cpp
int mx = max(5, 10); // 10
int mn = min(5, 10); // 5

// Max element in a vector
int big = *max_element(v.begin(), v.end());
```

### Swap
```cpp
int a = 5, b = 10;
swap(a, b); // Now a=10, b=5
```

### GCD (Greatest Common Divisor)
Built-in!
```cpp
int g = __gcd(12, 18); // 6
```

---

## 9. Common Logic Patterns

### Frequency Array (Counting Sort Logic)
Used to count how many times numbers appear (if numbers are small, e.g., < 10^6).
```cpp
int cnt[1005] = {0}; // Initialize with 0
for (int x : v) {
    cnt[x]++;
}
```

### Accumulation (Summing up)
```cpp
long long total = 0; // Use long long for sums!
for (int x : v) {
    total += x;
}
```

### Checking for Primality (Simple < 10^9)
```cpp
bool isPrime(int n) {
    if (n < 2) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}
```

---

## 10. Checklist for Wrong Answers

1.  **Integer Overflow**: Did you multiply two large ints? Use `long long`.
    - `int a = 1e9, b = 1e9; long long c = a * b;` // WRONG! (overflows before assignment)
    - `long long c = (long long)a * b;` // CORRECT
2.  **Corner Cases**: Did you check $n=1$, $n=0$?
3.  **Array Bounds**: Are you accessing `v[-1]` or `v[n]` (when size is n)? Indices are `0` to `n-1`.
4.  **Infinite Loop**: Did you decrement your loop counter?

---

*Keep this guide open while you practice on Codeforces (Div 4 contests) or AtCoder (Beginner Contests).*
