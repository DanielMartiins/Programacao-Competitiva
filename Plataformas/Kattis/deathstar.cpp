#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    
    cin >> n;

    long long m[n][n];
    long long ans[n];
    
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) cin >> m[i][j];

    for (int i = 0; i < n; i++) {
        ans[i] = 0;
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            ans[i] |= m[i][j]; //Another solution: ans[i] = max(ans[i], m[i][j])
        }
    }
    
    cout << ans[0];
    for (int i = 1; i < n; i++) {
        cout << " " << ans[i];
    }
    cout << "\n";
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
}

