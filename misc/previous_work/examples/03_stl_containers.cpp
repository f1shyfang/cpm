// Example 3: STL Containers (vector, set, map, etc.)
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    // ===== VECTOR (dynamic array) =====
    cout << "=== Vector ===\n";
    vector<int> v;              // Empty vector
    v.push_back(10);            // Add element
    v.push_back(20);
    v.push_back(30);
    
    vector<int> v2(5);          // Vector of size 5, initialized to 0
    vector<int> v3(5, -1);      // Vector of size 5, all elements = -1
    vector<int> v4 = {1, 2, 3}; // Initialize with values
    
    cout << "v size: " << v.size() << "\n";
    cout << "v[0] = " << v[0] << ", v.front() = " << v.front() << "\n";
    cout << "v.back() = " << v.back() << "\n";
    
    // Iterate
    for (int x : v) cout << x << " ";
    cout << "\n\n";
    
    // ===== PAIR =====
    cout << "=== Pair ===\n";
    pair<int, int> p = {3, 5};
    cout << "p.first = " << p.first << ", p.second = " << p.second << "\n";
    
    pair<string, int> person = {"Alice", 25};
    cout << person.first << " is " << person.second << " years old\n\n";
    
    // ===== SET (sorted unique elements) =====
    cout << "=== Set ===\n";
    set<int> s;
    s.insert(5);
    s.insert(2);
    s.insert(8);
    s.insert(2);  // Duplicate - won't be added
    
    cout << "Set contents (auto-sorted): ";
    for (int x : s) cout << x << " ";  // Output: 2 5 8
    cout << "\n";
    
    cout << "Contains 5? " << (s.count(5) ? "Yes" : "No") << "\n";
    cout << "Contains 7? " << (s.count(7) ? "Yes" : "No") << "\n\n";
    
    // ===== MAP (key-value pairs) =====
    cout << "=== Map ===\n";
    map<string, int> age;
    age["Alice"] = 25;
    age["Bob"] = 30;
    age["Charlie"] = 22;
    
    cout << "Alice's age: " << age["Alice"] << "\n";
    
    // Iterate map
    for (auto &[name, a] : age) {
        cout << name << " -> " << a << "\n";
    }
    cout << "\n";
    
    // ===== QUEUE (FIFO) =====
    cout << "=== Queue ===\n";
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    
    while (!q.empty()) {
        cout << q.front() << " ";  // Output: 1 2 3
        q.pop();
    }
    cout << "\n\n";
    
    // ===== STACK (LIFO) =====
    cout << "=== Stack ===\n";
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    
    while (!st.empty()) {
        cout << st.top() << " ";  // Output: 3 2 1
        st.pop();
    }
    cout << "\n\n";
    
    // ===== PRIORITY QUEUE (max-heap by default) =====
    cout << "=== Priority Queue ===\n";
    priority_queue<int> pq;
    pq.push(3);
    pq.push(1);
    pq.push(4);
    pq.push(1);
    pq.push(5);
    
    cout << "Max-heap order: ";
    while (!pq.empty()) {
        cout << pq.top() << " ";  // Output: 5 4 3 1 1
        pq.pop();
    }
    cout << "\n";
    
    // Min-heap
    priority_queue<int, vector<int>, greater<int>> minPq;
    minPq.push(3);
    minPq.push(1);
    minPq.push(4);
    
    cout << "Min-heap order: ";
    while (!minPq.empty()) {
        cout << minPq.top() << " ";  // Output: 1 3 4
        minPq.pop();
    }
    cout << "\n";
    
    return 0;
}

/*
To compile and run:
    g++ 03_stl_containers.cpp -o 03_stl_containers
    ./03_stl_containers
*/
