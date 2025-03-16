//https://open.kattis.com/problems/guessthedatastructure

#include <bits/stdc++.h>
#include <queue>
using namespace std;

bool isStack, isQueue, isPQ;

int main() {
  int n;

  while (cin >> n) {
    
    stack<int> s;
    queue<int> q;
    priority_queue<int> pq;

    isStack = true, 
    isQueue = true, 
    isPQ = true;

    for (int i = 0; i < n; i++) {
      int command;
      int num;

      cin >> command >> num;

      if (command == 1) {
        s.push(num);
        q.push(num);
        pq.push(num);
      } else {
        if (s.empty() || s.top() != num) isStack = false;
        else (s.pop());
        
        if (q.empty() || q.front() != num) isQueue = false;
        else (q.pop());
        
        if (pq.empty() || pq.top() != num) isPQ = false;
        else (pq.pop());
        
      }
    }
    
    if (isStack && !isQueue && !isPQ) cout << "stack\n";
    else if (!isStack && isQueue && !isPQ) cout << "queue\n";
    else if (!isStack && !isQueue && isPQ) cout << "priority queue\n";
    else if (!isQueue && !isStack && !isPQ) cout << "impossible\n";
    else cout << "not sure\n";
  }
}
