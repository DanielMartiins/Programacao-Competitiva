#include <bits/stdc++.h>
using namespace std;
// O(1)
/*
* gcd(x,y) = gcd(y, y-x) when x > y
* Therefore: gcd(a_i + d, a_j + d) = gcd (a_j + d, a_i - a_j)
* -> gcd <= (a_i - a_j)
*/

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

    cin.tie(0);
    ios::sync_with_stdio(false);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}