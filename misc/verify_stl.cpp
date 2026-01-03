#include <cassert>
#include <deque>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

int main() {
  // 1. Vector
  vector<int> v;
  v.push_back(10);
  assert(v[0] == 10);

  // 2. Deque
  deque<int> dq;
  dq.push_front(1);
  dq.push_back(2);
  assert(dq.front() == 1 && dq.back() == 2);

  // 3. List
  list<int> l;
  l.push_back(1);
  assert(*l.begin() == 1);

  // 4. Stack
  stack<int> s;
  s.push(1);
  assert(s.top() == 1);
  s.pop();

  // 5. Queue
  queue<int> q;
  q.push(1);
  assert(q.front() == 1);
  q.pop();

  // 6. Priority Queue
  priority_queue<int> pq;
  pq.push(5);
  pq.push(10);
  assert(pq.top() == 10);

  // 7. Set
  set<int> st;
  st.insert(10);
  assert(st.find(10) != st.end());

  // 8. Map
  map<string, int> m;
  m["apple"] = 5;
  assert(m["apple"] == 5);

  // 9. Unordered containers
  unordered_set<int> us;
  us.insert(1);
  assert(us.count(1));

  unordered_map<int, int> um;
  um[1] = 2;
  assert(um[1] == 2);

  cout << "All data structures verified successfully!" << endl;
  return 0;
}
