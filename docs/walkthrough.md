# Walkthrough: Runnable C++ CP Notes

I have successfully implemented your Competitive Programming notes as runnable C++ files! You can find them in the `cpm_notes/` directory.

## Directory Structure

### 1. Beginner Examples (`cpm_notes/beginner/`)
Start here if you are new. Each file demonstrates a specific concept.
- `01_template.cpp`: Your starting block for every problem.
- `02_io_mastery.cpp`: How to read/write fast.
- `03_control_flow.cpp`: Loops and If/Else.
- `04_vectors_arrays.cpp`: Using `std::vector` (Dynamic Arrays).
- `05_strings.cpp`: String manipulation.
- `06_simple_algos.cpp`: Basic algorithms like GCD, Swap, Min/Max.

### 2. Advanced Library (`cpm_notes/library/`)
Copy-paste ready implementations for contests.
- `contest_template.cpp`: Optimized, macro-heavy template.
- `math_notebook.cpp`: Modular arithmetic, Sieve, nCr.
- `data_structures.cpp`: DSU, Fenwick Tree, Segment Tree.
- `graphs.cpp`: Dijkstra, LCA.
- `strings.cpp`: KMP, Hashing.

## How to Run the Code

Since you are on macOS, I included a `bits/stdc++.h` file in `cpm_notes/bits/` so you can use the standard CP header without errors.

To compile any file, **you must include the `cpm_notes` directory** in your include path:

```bash
g++ -std=c++17 -I cpm_notes cpm_notes/beginner/01_template.cpp -o run_me
./run_me
```

> [!TIP]
> **VS Code Setup**: If you see red squiggles under `#include <bits/stdc++.h>`, add `"${workspaceFolder}/cpm_notes"` to your `includePath` in `.vscode/c_cpp_properties.json`.

## Next Steps

1.  Open `cpm_notes/beginner/01_template.cpp` and try modifying it.
2.  Practice submitting problems on Codeforces using the template.
3.  When you encounter a hard problem (e.g., "Find the Shortest Path"), looking at `cpm_notes/library/graphs.cpp` for the Dijkstra implementation.

Happy Coding!
