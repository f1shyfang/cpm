// Chapter 6: Greedy Algorithms
// Make locally optimal choice at each step
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

// ===== COIN PROBLEM (Greedy works for standard denominations) =====
// Given coin values, find minimum coins to make sum
vector<int> coinChange(vector<int>& coins, int amount) {
    vector<int> result;
    sort(coins.rbegin(), coins.rend());  // Sort descending
    
    for (int coin : coins) {
        while (amount >= coin) {
            amount -= coin;
            result.push_back(coin);
        }
    }
    return result;
}

// ===== ACTIVITY SELECTION (Interval Scheduling) =====
// Select maximum number of non-overlapping activities
// Strategy: Always pick the activity that ends earliest
int activitySelection(vector<pii>& activities) {
    // activities[i] = {end_time, start_time}
    // Sort by end time
    sort(activities.begin(), activities.end());
    
    int count = 0;
    int lastEnd = -1;
    
    for (auto& [end, start] : activities) {
        if (start >= lastEnd) {
            count++;
            lastEnd = end;
        }
    }
    return count;
}

// ===== FRACTIONAL KNAPSACK =====
// Can take fractions of items
// Strategy: Take items with best value/weight ratio first
double fractionalKnapsack(vector<pair<double, double>>& items, double capacity) {
    // items[i] = {value, weight}
    int n = items.size();
    
    // Create {ratio, index} pairs
    vector<pair<double, int>> ratio(n);
    for (int i = 0; i < n; i++) {
        ratio[i] = {items[i].first / items[i].second, i};
    }
    
    // Sort by ratio (descending)
    sort(ratio.rbegin(), ratio.rend());
    
    double totalValue = 0;
    for (auto& [r, idx] : ratio) {
        if (capacity <= 0) break;
        
        double take = min(capacity, items[idx].second);
        totalValue += take * r;
        capacity -= take;
    }
    
    return totalValue;
}

// ===== HUFFMAN CODING =====
// Build optimal prefix-free code for characters
struct HuffmanNode {
    char ch;
    int freq;
    HuffmanNode *left, *right;
    HuffmanNode(char c, int f) : ch(c), freq(f), left(nullptr), right(nullptr) {}
};

struct Compare {
    bool operator()(HuffmanNode* a, HuffmanNode* b) {
        return a->freq > b->freq;  // Min-heap
    }
};

void printHuffmanCodes(HuffmanNode* root, string code) {
    if (!root) return;
    if (!root->left && !root->right) {
        cout << root->ch << ": " << code << "\n";
    }
    printHuffmanCodes(root->left, code + "0");
    printHuffmanCodes(root->right, code + "1");
}

void huffmanCoding(map<char, int>& freq) {
    priority_queue<HuffmanNode*, vector<HuffmanNode*>, Compare> pq;
    
    for (auto& [ch, f] : freq) {
        pq.push(new HuffmanNode(ch, f));
    }
    
    while (pq.size() > 1) {
        HuffmanNode* left = pq.top(); pq.pop();
        HuffmanNode* right = pq.top(); pq.pop();
        
        HuffmanNode* merged = new HuffmanNode('\0', left->freq + right->freq);
        merged->left = left;
        merged->right = right;
        pq.push(merged);
    }
    
    printHuffmanCodes(pq.top(), "");
}

// ===== TASK SCHEDULING (Minimize Lateness) =====
// Each task has deadline and duration
// Strategy: Schedule by earliest deadline (EDF)
int minimizeLateness(vector<pii>& tasks) {
    // tasks[i] = {deadline, duration}
    sort(tasks.begin(), tasks.end());
    
    int currentTime = 0;
    int maxLateness = 0;
    
    for (auto& [deadline, duration] : tasks) {
        currentTime += duration;
        int lateness = max(0, currentTime - deadline);
        maxLateness = max(maxLateness, lateness);
    }
    
    return maxLateness;
}

// ===== MINIMUM SPANNING TREE (Kruskal's - uses greedy) =====
// Covered in graph section, but mentioned here as key greedy algorithm

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cout << "===== COIN CHANGE (Greedy) =====\n";
    vector<int> coins = {25, 10, 5, 1};  // US coins
    int amount = 93;
    vector<int> result = coinChange(coins, amount);
    cout << "Making " << amount << " cents: ";
    for (int c : result) cout << c << " ";
    cout << "\nTotal coins: " << result.size() << "\n\n";
    
    cout << "===== ACTIVITY SELECTION =====\n";
    // {end, start} pairs
    vector<pii> activities = {{3, 1}, {4, 2}, {6, 3}, {7, 5}, {9, 6}, {10, 8}};
    cout << "Activities (start, end): ";
    for (auto& [e, s] : activities) cout << "(" << s << "," << e << ") ";
    cout << "\n";
    cout << "Maximum non-overlapping: " << activitySelection(activities) << "\n\n";
    
    cout << "===== FRACTIONAL KNAPSACK =====\n";
    vector<pair<double, double>> items = {{60, 10}, {100, 20}, {120, 30}};  // {value, weight}
    double capacity = 50;
    cout << "Items (value, weight): ";
    for (auto& [v, w] : items) cout << "(" << v << "," << w << ") ";
    cout << "\nCapacity: " << capacity << "\n";
    cout << "Maximum value: " << fractionalKnapsack(items, capacity) << "\n\n";
    
    cout << "===== HUFFMAN CODING =====\n";
    map<char, int> freq = {{'a', 5}, {'b', 9}, {'c', 12}, {'d', 13}, {'e', 16}, {'f', 45}};
    cout << "Character frequencies:\n";
    for (auto& [ch, f] : freq) cout << ch << ": " << f << "\n";
    cout << "\nHuffman codes:\n";
    huffmanCoding(freq);
    cout << "\n";
    
    cout << "===== TASK SCHEDULING =====\n";
    vector<pii> tasks = {{4, 3}, {2, 1}, {6, 2}, {4, 1}};  // {deadline, duration}
    cout << "Tasks (deadline, duration): ";
    for (auto& [d, dur] : tasks) cout << "(" << d << "," << dur << ") ";
    cout << "\n";
    cout << "Minimum lateness: " << minimizeLateness(tasks) << "\n";
    
    return 0;
}

/*
Key Greedy Principles:
1. Make locally optimal choice at each step
2. Hope it leads to globally optimal solution
3. Greedy doesn't always work! Verify with proof or examples

When Greedy Works:
- Optimal substructure: optimal solution contains optimal solutions to subproblems
- Greedy choice property: locally optimal choice leads to globally optimal solution

Classic Greedy Problems:
- Activity Selection
- Fractional Knapsack (NOT 0/1 Knapsack)
- Huffman Coding
- Minimum Spanning Tree (Kruskal's, Prim's)
- Dijkstra's Shortest Path
- Job Scheduling
*/
