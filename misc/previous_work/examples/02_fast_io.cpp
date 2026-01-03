// Example 2: Fast I/O for Competitive Programming
#include <bits/stdc++.h>
using namespace std;

int main() {
    // ESSENTIAL: These two lines make cin/cout much faster
    ios::sync_with_stdio(false);  // Disable sync with C stdio
    cin.tie(nullptr);             // Untie cin from cout
    
    // Now cin/cout are as fast as scanf/printf
    // IMPORTANT: Use "\n" instead of endl (endl flushes buffer = slow)
    
    // Read number of elements
    int n;
    cin >> n;
    
    // Read n elements into a vector
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    // Alternative: range-based for loop with reference
    // for (int &x : a) cin >> x;
    
    // Output all elements
    for (int i = 0; i < n; i++) {
        cout << a[i];
        if (i < n - 1) cout << " ";  // Space between elements
    }
    cout << "\n";
    
    return 0;
}

/*
Sample Input:
5
1 2 3 4 5

Sample Output:
1 2 3 4 5

To compile and run:
    g++ 02_fast_io.cpp -o 02_fast_io
    ./02_fast_io
*/
