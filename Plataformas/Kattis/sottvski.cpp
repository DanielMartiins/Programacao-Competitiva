//https://open.kattis.com/challenge/tsbo5v7s

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k, d;
    cin >> n >> k >> d;

    stack<int> friends;
    for (int i = 0; i < n; i++) {
        int di;
        cin >> di;
        friends.push(di);
    }
    
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int di = friends.top(); friends.pop();
        if ((d + k) - di >= 14) ans++;
    }
    
    cout << ans << '\n';
}