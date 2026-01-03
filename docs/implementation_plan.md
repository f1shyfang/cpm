# Implementation Plan - C++ CP Notes

Goal: Convert the markdown reference notes into a structured collection of runnable C++ files for the user to practice with.

## Proposed Changes

### Directory Structure
Create a new directory `cpm_notes` in the root of the workspace.
- `cpm_notes/beginner/`: For beginner-friendly examples.
- `cpm_notes/library/`: For advanced reference algorithms.

### Beginner Files (`cpm_notes/beginner/`)
#### [NEW] [01_template.cpp](file:///Users/mf/dev/cpm/cpm_notes/beginner/01_template.cpp)
- Basic C++ template with comments explaining structure.

#### [NEW] [02_io_mastery.cpp](file:///Users/mf/dev/cpm/cpm_notes/beginner/02_io_mastery.cpp)
- Examples of `cin`, `cout`, `getline`, and fast I/O.

#### [NEW] [03_control_flow.cpp](file:///Users/mf/dev/cpm/cpm_notes/beginner/03_control_flow.cpp)
- Examples of `if/else`, loops (for, while), and test case logic.

#### [NEW] [04_vectors_arrays.cpp](file:///Users/mf/dev/cpm/cpm_notes/beginner/04_vectors_arrays.cpp)
- `vector` operations: push_back, access, sort, reverse.
- Iteration examples.

#### [NEW] [05_strings.cpp](file:///Users/mf/dev/cpm/cpm_notes/beginner/05_strings.cpp)
- String concatenation, substring, find, access.

#### [NEW] [06_simple_algos.cpp](file:///Users/mf/dev/cpm/cpm_notes/beginner/06_simple_algos.cpp)
- Min/Max, Swap, GCD, simple frequency array logic.

### Advanced Library Files (`cpm_notes/library/`)
#### [NEW] [contest_template.cpp](file:///Users/mf/dev/cpm/cpm_notes/library/contest_template.cpp)
- Optimized competitive programming template (macros, pragmas).

#### [NEW] [math_notebook.cpp](file:///Users/mf/dev/cpm/cpm_notes/library/math_notebook.cpp)
- Modular arithmetic class, Sieve, nCr.

#### [NEW] [data_structures.cpp](file:///Users/mf/dev/cpm/cpm_notes/library/data_structures.cpp)
- DSU, Fenwick Tree, Segment Tree implementations.

#### [NEW] [graphs.cpp](file:///Users/mf/dev/cpm/cpm_notes/library/graphs.cpp)
- Dijkstra, LCA, etc.

#### [NEW] [strings.cpp](file:///Users/mf/dev/cpm/cpm_notes/library/strings.cpp)
- KMP, Rolling Hash.

## Verification Plan

### Automated Tests
- Compile the created files to ensure they are valid C++ code.
- Run `g++ -std=c++17 -o /dev/null <filename>` for a sample of files.

### Manual Verification
- Check that the directory structure is created correctly.
