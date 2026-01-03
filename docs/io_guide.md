# Guide to Input/Output in C++ and `cpm`

This guide explains how to handle input and output (I/O) in C++, specifically tailored for the patterns found in your `cpm` (Competitive Programming Manager) workspace.

## 1. Basic C++ I/O (`iostream`)

The standard way to handle I/O in C++ is using the `<iostream>` library.

### Output with `cout`
Use `cout` and the insertion operator `<<` to print data to the console.
```cpp
#include <iostream>
using namespace std;

int main() {
    int age = 25;
    cout << "Age: " << age << endl; // 'endl' prints '\n' and flushes the buffer
    return 0;
}
```

### Input with `cin`
Use `cin` and the extraction operator `>>` to read data. It automatically skips whitespace (spaces, tabs, newlines).
```cpp
int x;
cin >> x; // Reads an integer
string s;
cin >> s; // Reads a single word
```

---

## 2. Fast I/O (The `cpm` Way)

In competitive programming (CP), standard `cin` and `cout` can be slow. Your workspace uses "Fast I/O" to speed things up.

### The Optimization Lines
You will see these lines in `template.cpp` and `examples/02_fast_io.cpp`:
```cpp
ios::sync_with_stdio(false);
cin.tie(nullptr);
```
- **`sync_with_stdio(false)`**: Disables the synchronization between C++ iostreams and C standard streams (`scanf`/`printf`), making I/O much faster.
- **`cin.tie(nullptr)`**: Unties `cin` from `cout`, preventing automatic flushing of `cout` every time `cin` is called.

### Crucial: Use `\n` instead of `endl`
In CP, `endl` is slow because it forces a "buffer flush." Use `\n` for better performance:
```cpp
cout << "Fast output" << "\n";
```

---

## 3. Reading Multiple Inputs

### Known Number of Inputs
```cpp
int n;
cin >> n;
vector<int> a(n);
for (int i = 0; i < n; i++) cin >> a[i];
```

### Reading until EOF (End of File)
```cpp
int x;
while (cin >> x) {
    // Process x
}
```

### Reading Entire Lines
```cpp
string line;
getline(cin, line);
```

---

## 4. What is `cpm`?

Based on your workspace, **`cpm`** (Competitive Programming Manager) is a structured environment for solving coding problems. It includes:
- **`template.cpp`**: A pre-configured file with Fast I/O and common shortcuts.
- **`examples/`**: Tutorial files covering I/O, STL, and algorithms.
- **`bin/`**: Compiled versions of your solutions/examples.

To use the `cpm` structure for a new problem:
1. Copy `template.cpp` to a new file (e.g., `solution.cpp`).
2. Write your logic inside `main()`.
3. Compile with: `g++ solution.cpp -o solution`
4. Run with: `./solution`
