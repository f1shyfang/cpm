# C++ Data Structures & STL Guide

This guide covers the essential data structures in the C++ Standard Template Library (STL) used frequently in competitive programming.

## 1. Sequence Containers

Sequence containers maintain the order of elements in a linear fashion.

### `vector`
The most versatile and commonly used container. It's a dynamic array that can resize itself.
- **Usage**: `vector<int> v; v.push_back(10);`
- **Time Complexity**: 
    - Random Access: O(1)
    - Insertion/Deletion at end: Amortized O(1)
    - Insertion/Deletion at middle/front: O(N)

### `deque` (Double-ended Queue)
A dynamic array that allows fast insertion and deletion at both ends.
- **Usage**: `deque<int> dq; dq.push_front(1); dq.push_back(2);`
- **Time Complexity**:
    - Random Access: O(1)
    - Insertion/Deletion at front/end: O(1)

### `list`
A doubly linked list. Fast insertion/deletion anywhere if you have the iterator.
- **Usage**: `list<int> l; l.push_back(1);`
- **Time Complexity**:
    - Access: O(N)
    - Insertion/Deletion: O(1) (given iterator)

---

## 2. Container Adapters

These provide specific interfaces for other containers.

### `stack` (LIFO)
- **Usage**: `stack<int> s; s.push(1); int top = s.top(); s.pop();`
- **Complexity**: O(1) for all operations.

### `queue` (FIFO)
- **Usage**: `queue<int> q; q.push(1); int front = q.front(); q.pop();`
- **Complexity**: O(1) for all operations.

### `priority_queue`
A heap structure (max-heap by default).
- **Usage**: `priority_queue<int> pq; pq.push(5); int highest = pq.top();`
- **Min-Heap**: `priority_queue<int, vector<int>, greater<int>> minPq;`
- **Complexity**: Push/Pop O(log N), Top O(1).

---

## 3. Associative Containers

These store sorted data and allow fast lookup.

### `set` / `multiset`
Stored as a balanced BST (Binary Search Tree). Elements are unique in `set`.
- **Usage**: `set<int> s; s.insert(10); if (s.find(10) != s.end()) ...`
- **Complexity**: O(log N) for Search, Insert, Delete.

### `map` / `multimap`
Key-value pairs, sorted by key.
- **Usage**: `map<string, int> m; m["apple"] = 5;`
- **Complexity**: O(log N) for Search, Insert, Delete.

---

## 4. Unordered Containers

These use hash tables instead of trees.

### `unordered_set` / `unordered_map`
- **Usage**: Same syntax as `set` and `map`.
- **Complexity**: 
    - Average: O(1) for Search, Insert, Delete.
    - Worst Case: O(N) (though rare in practice unless specific hash collisions occur).

---

## 5. Summary Table

| Container | Search | Insert | Delete |
| :--- | :--- | :--- | :--- |
| `vector` | O(N) (O(1) index) | O(N) (O(1) end) | O(N) (O(1) end) |
| `deque` | O(N) (O(1) index) | O(N) (O(1) ends) | O(N) (O(1) ends) |
| `set` / `map` | O(log N) | O(log N) | O(log N) |
| `unordered_map` | O(1) avg | O(1) avg | O(1) avg |
| `stack` / `queue` | N/A | O(1) | O(1) |
| `priority_queue`| top: O(1) | O(log N) | O(log N) |

---

## Best Practices for Competitive Programming

1.  Always use `bits/stdc++.h` and `ios::sync_with_stdio(0); cin.tie(0);` for speed.
2.  Prefer `vector` over `list` or `deque` unless you specifically need front insertions.
3.  Use `unordered_map` for speed when order doesn't matter, but be aware of possible TLE (Time Limit Exceeded) due to worst-case O(N) in some platforms (C++ library hash table is vulnerable).
4.  Reach for `priority_queue` whenever you need the "best" element repeatedly.
