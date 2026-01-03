# Competitive Programming with C++: A Beginner's Guide

Welcome to the world of Competitive Programming (CP)! This guide will help you get started with C++, the most popular language for CP due to its speed and powerful Standard Template Library (STL).

## 1. Environment Setup

Before you start coding, you need a good setup.

### A. Compiler
You need a C++ compiler supporting modern standards (C++17 or C++20).
- **macOS**: Install Xcode Command Line Tools (`xcode-select --install`) or install GCC via Homebrew (`brew install gcc`).
- **Windows**: Install MinGW-w64 or use WSL (Windows Subsystem for Linux).
- **Linux**: Usually pre-installed, or use `sudo apt install g++`.

### B. Code Editor / IDE
- **VS Code**: Highly recommended. Lightweight and customizable. Extensions: C/C++, Code Runner, CPH (Competitive Programming Helper).
- **Sublime Text**: Very fast, popular among competitive programmers.
- **CLion**: Powerful IDE by JetBrains (free for students).
- **Vim/Neovim**: For advanced users who want speed on the terminal.

### C. The Basic Template
Start every problem with a standard template to save time.

```cpp
#include <bits/stdc++.h> // Includes almost all standard libraries
using namespace std;

// Shortcuts for common data types and functions
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define f first
#define s second

void solve() {
    // Your code goes here
    int n;
    cin >> n;
    cout << "Input received: " << n << "\n";
}

int main() {
    // Fast I/O
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    // cin >> t; // Uncomment if the problem has multiple test cases
    while (t--) {
        solve();
    }
    return 0;
}
```

> [!NOTE]
> `#include <bits/stdc++.h>` is non-standard but widely supported in CP environments (GCC). It saves you from including `<iostream>`, `<vector>`, `<algorithm>`, etc., separately.

## 2. Why C++? The Power of STL

The Standard Template Library (STL) is your best friend. It provides high-performance implementations of common data structures and algorithms.

### Essential Containers
- **`vector<T>`**: Dynamic array.
    ```cpp
    vector<int> v = {1, 2, 3};
    v.push_back(4); // O(1)
    ```
- **`string`**: Mutable string class.
- **`set<T>` / `unordered_set<T>`**: Store unique elements. `set` is sorted (O(log n)), `unordered_set` is hash-based (O(1) avg).
- **`map<K, V>` / `unordered_map<K, V>`**: Key-value pairs. `map` is sorted, `unordered_map` is unsorted.
- **`priority_queue<T>`**: Max heap (by default) or min heap. Returns the largest/smallest element in O(1).

### Essential Algorithms (`<algorithm>`)
- `sort(v.begin(), v.end())`: O(n log n) sorting.
- `reverse(v.begin(), v.end())`: Reverses the container.
- `lower_bound` / `upper_bound`: Binary search in sorted ranges.
- `min`, `max`, `__gcd`.

## 3. Roadmap: What to Learn

Don't try to learn everything at once. Follow a progression.

### Phase 1: Basics (Rating < 1200)
- conditions, loops, functions
- Arrays, Strings
- Basic Math (modulo arithmetic, GCD/LCM, primes)
- Time Complexity basics (Big O notation)
- Simple greedy logic
- **Practice on**: Codeforces Div 3 and Div 4 contests.

### Phase 2: Fundamental Algorithms (Rating 1200 - 1600)
- **Sorting & Searching**: Binary Search (very important!), Two Pointers.
- **Data Structures**: Stacks, Queues, Deques, Priority Queues.
- **Number Theory**: Sieve of Eratosthenes, Modular Inverse.
- **Graph Theory Basics**: DFS (Depth First Search), BFS (Breadth First Search), Connected Components.
- **Dynamic Programming (DP)**: Basic 1D DP (fibonacci style, knapsack).

### Phase 3: Advanced (Rating 1600+)
- **Graphs**: Dijkstra, Floyd-Warshall, Disjoint Set Union (DSU), Minimum Spanning Trees (Kruskal/Prim).
- **Advanced DP**: 2D DP, DP on trees, Bitmask DP.
- **Trees**: Segment Trees, Fenwick Trees (BIT).
- **Strings**: Hashing, KMP.

## 4. Practice Platforms

- **Codeforces**: The "gold standard" for contests. Host regular rounds.
- **AtCoder**: Japanese platform. Known for very high-quality math/logic problems. Highly recommended for beginners.
- **LeetCode**: geared towards interviews, but "Hard" problems are good for CP practice.
- **CSES Problem Set**: A classic collection of problems covering all standard topics. Essential for learning algorithms properly.

## 5. Tips for Success

1.  **Don't Give Up**: You will get Stuck. It's normal.
2.  **Upsolving**: After a contest, **always** try to solve the problems you missed. Read the editorial. This is where the real learning happens.
3.  **Typing Speed**: Matters less than you think. Thinking speed >> Typing speed.
4.  **Community**: Join usage discord servers or forums.

## Resources to Bookmark
- [CP-Algorithms](https://cp-algorithms.com/): The bible of algorithms.
- [USACO Guide](https://usaco.guide/): Structured curriculum for all levels.
- [C++ Reference](https://en.cppreference.com/): Documentation for STL.

Good luck on your journey!
