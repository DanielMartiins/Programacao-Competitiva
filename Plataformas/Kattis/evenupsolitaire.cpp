#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    stack<int> standby;

    for(int i = 0; i < n; i++) {
        int card;
        cin >> card;
        
        if (!standby.empty() && (standby.top() + card) % 2 == 0) 
            standby.pop();
        else standby.push(card);
    }
    cout << standby.size() << "\n";
}