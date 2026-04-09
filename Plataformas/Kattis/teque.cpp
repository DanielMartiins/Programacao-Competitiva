

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;

    deque<int> a,b;
    while(n--) {
        string op;
        int x;
        cin >> op >> x;

        while(a.size() < b.size()) {
            a.push_back(b.front());
            b.pop_front();
        }
        while(a.size() - b.size() > 1) {
            b.push_front(a.back());
            a.pop_back();
        }

        if(op == "push_back") b.push_back(x);
        else if (op == "push_front") a.push_front(x);
        else if (op == "push_middle") b.push_front(x);
        else {
            if (x < a.size()) cout << a.at(x) << "\n";
            else cout << b.at(x-a.size()) << "\n";
        }
    }
}
