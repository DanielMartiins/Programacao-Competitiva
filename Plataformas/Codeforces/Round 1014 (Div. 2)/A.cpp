#include <bits/stdc++.h>
using namespace std;

void solve() {
    long long mn = LONG_LONG_MAX, mx = LONG_LONG_MIN;
    int n;
    vector<int> numbers;
    cin >> n;
    for (int i = 0; i < n; i++) {
        long long num;
        cin >> num;
        mn = min(num, mn);
        mx = max(num, mx);
    }
    cout << mx - mn << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}