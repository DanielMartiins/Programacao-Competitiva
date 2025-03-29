#include <bits/stdc++.h>
using namespace std;

void solve() {
    
    int n;
    cin >> n;

    long long v[n];
    long long ans = 0;

    for (int i = 0; i < n; i++) cin >> v[i];

    long long max = -1, sum = 0;
    for (int i = 0; i < n; i++) {
        if (max < v[i]) max = v[i];
        sum += v[i];
        if (sum - max == max) ans++;
    }
    cout << ans << '\n';
}

int main() {

    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int t;
    cin >> t;

    while(t--) {
        solve();
    }
}