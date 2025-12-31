// Chapter 3: Sorting & Chapter 4: Data Structures
// Fundamental sorting algorithms and binary search
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

// ===== SORTING ALGORITHMS =====

// Bubble Sort: O(n^2) - Compare adjacent, swap if needed
void bubbleSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

// Selection Sort: O(n^2) - Find minimum, place at front
void selectionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIdx]) minIdx = j;
        }
        swap(arr[i], arr[minIdx]);
    }
}

// Insertion Sort: O(n^2) - Insert each element in correct position
void insertionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// Merge Sort: O(n log n) - Divide and conquer
void merge(vector<int>& arr, int l, int m, int r) {
    vector<int> left(arr.begin() + l, arr.begin() + m + 1);
    vector<int> right(arr.begin() + m + 1, arr.begin() + r + 1);
    
    size_t i = 0, j = 0;
    int k = l;
    while (i < left.size() && j < right.size()) {
        arr[k++] = (left[i] <= right[j]) ? left[i++] : right[j++];
    }
    while (i < left.size()) arr[k++] = left[i++];
    while (j < right.size()) arr[k++] = right[j++];
}

void mergeSort(vector<int>& arr, int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

// ===== COUNTING SORT: O(n + k) =====
// For integers in range [0, k]
void countingSort(vector<int>& arr, int maxVal) {
    vector<int> count(maxVal + 1, 0);
    for (int x : arr) count[x]++;
    
    int idx = 0;
    for (int i = 0; i <= maxVal; i++) {
        while (count[i]-- > 0) {
            arr[idx++] = i;
        }
    }
}

// ===== BINARY SEARCH VARIATIONS =====

// Standard binary search: find exact value
int binarySearch(vector<int>& arr, int target) {
    int lo = 0, hi = arr.size() - 1;
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if (arr[mid] == target) return mid;
        else if (arr[mid] < target) lo = mid + 1;
        else hi = mid - 1;
    }
    return -1;
}

// Find first occurrence of target
int lowerBound(vector<int>& arr, int target) {
    int lo = 0, hi = arr.size();
    while (lo < hi) {
        int mid = lo + (hi - lo) / 2;
        if (arr[mid] < target) lo = mid + 1;
        else hi = mid;
    }
    return lo;  // First index >= target
}

// Find first element greater than target
int upperBound(vector<int>& arr, int target) {
    int lo = 0, hi = arr.size();
    while (lo < hi) {
        int mid = lo + (hi - lo) / 2;
        if (arr[mid] <= target) lo = mid + 1;
        else hi = mid;
    }
    return lo;  // First index > target
}

// Binary search on answer: find minimum x satisfying condition
// Example: minimum time to complete tasks
bool canComplete(vector<int>& tasks, int workers, ll time) {
    ll workersNeeded = 0;
    for (int t : tasks) {
        workersNeeded += (t + time - 1) / time;  // Ceiling division
    }
    return workersNeeded <= workers;
}

ll minTimeToComplete(vector<int>& tasks, int workers) {
    ll lo = 1, hi = *max_element(tasks.begin(), tasks.end());
    
    while (lo < hi) {
        ll mid = lo + (hi - lo) / 2;
        if (canComplete(tasks, workers, mid)) {
            hi = mid;
        } else {
            lo = mid + 1;
        }
    }
    return lo;
}

// ===== CUSTOM SORTING =====

// Sort by custom comparator
bool compareBySecond(const pii& a, const pii& b) {
    return a.second < b.second;  // Sort by second element
}

// Sort objects
struct Person {
    string name;
    int age;
    int score;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cout << "===== SORTING ALGORITHMS =====\n";
    vector<int> arr = {64, 34, 25, 12, 22, 11, 90};
    
    cout << "Original: ";
    for (int x : arr) cout << x << " ";
    cout << "\n";
    
    vector<int> arr2 = arr;
    bubbleSort(arr2);
    cout << "Bubble Sort: ";
    for (int x : arr2) cout << x << " ";
    cout << "\n";
    
    arr2 = arr;
    mergeSort(arr2, 0, arr2.size() - 1);
    cout << "Merge Sort: ";
    for (int x : arr2) cout << x << " ";
    cout << "\n\n";
    
    cout << "===== STL SORT =====\n";
    arr2 = arr;
    sort(arr2.begin(), arr2.end());
    cout << "Ascending: ";
    for (int x : arr2) cout << x << " ";
    cout << "\n";
    
    sort(arr2.begin(), arr2.end(), greater<int>());
    cout << "Descending: ";
    for (int x : arr2) cout << x << " ";
    cout << "\n\n";
    
    cout << "===== BINARY SEARCH =====\n";
    vector<int> sorted = {1, 3, 3, 3, 5, 7, 9, 11};
    cout << "Array: ";
    for (int x : sorted) cout << x << " ";
    cout << "\n";
    
    cout << "Index of 5: " << binarySearch(sorted, 5) << "\n";
    cout << "lower_bound(3): " << lowerBound(sorted, 3) << " (first 3)\n";
    cout << "upper_bound(3): " << upperBound(sorted, 3) << " (after last 3)\n";
    cout << "Count of 3s: " << upperBound(sorted, 3) - lowerBound(sorted, 3) << "\n\n";
    
    // STL versions
    cout << "STL lower_bound(3): " << (lower_bound(sorted.begin(), sorted.end(), 3) - sorted.begin()) << "\n";
    cout << "STL upper_bound(3): " << (upper_bound(sorted.begin(), sorted.end(), 3) - sorted.begin()) << "\n\n";
    
    cout << "===== CUSTOM SORTING =====\n";
    vector<pii> pairs = {{3, 5}, {1, 2}, {4, 1}, {2, 4}};
    
    cout << "Original pairs: ";
    for (auto& [a, b] : pairs) cout << "(" << a << "," << b << ") ";
    cout << "\n";
    
    // Sort by first element (default)
    sort(pairs.begin(), pairs.end());
    cout << "By first: ";
    for (auto& [a, b] : pairs) cout << "(" << a << "," << b << ") ";
    cout << "\n";
    
    // Sort by second element
    sort(pairs.begin(), pairs.end(), compareBySecond);
    cout << "By second: ";
    for (auto& [a, b] : pairs) cout << "(" << a << "," << b << ") ";
    cout << "\n";
    
    // Lambda comparator
    sort(pairs.begin(), pairs.end(), [](const pii& a, const pii& b) {
        return a.first + a.second < b.first + b.second;  // By sum
    });
    cout << "By sum: ";
    for (auto& [a, b] : pairs) cout << "(" << a << "," << b << ") ";
    cout << "\n\n";
    
    cout << "===== SORTING OBJECTS =====\n";
    vector<Person> people = {{"Alice", 25, 85}, {"Bob", 30, 90}, {"Charlie", 20, 85}};
    
    // Sort by score desc, then age asc
    sort(people.begin(), people.end(), [](const Person& a, const Person& b) {
        if (a.score != b.score) return a.score > b.score;
        return a.age < b.age;
    });
    
    cout << "Sorted by score (desc), age (asc):\n";
    for (auto& p : people) {
        cout << p.name << " (age " << p.age << ", score " << p.score << ")\n";
    }
    
    return 0;
}

/*
Sorting Complexity:
- Bubble/Selection/Insertion: O(n^2)
- Merge Sort: O(n log n), stable
- Quick Sort: O(n log n) avg, O(n^2) worst
- Heap Sort: O(n log n)
- Counting Sort: O(n + k), for small integer range
- STL sort(): O(n log n), uses introsort

Binary Search Tips:
- Array must be sorted!
- Use lo < hi for finding boundaries
- Use lo <= hi for exact match
- Watch out for integer overflow: use lo + (hi - lo) / 2
*/
