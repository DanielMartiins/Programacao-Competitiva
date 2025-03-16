#include <bits/stdc++.h>
#define vi vector<int>
using namespace std;

void solve() {
    int m,a,b,c, seats;
    cin >> m >> a >> b >> c;
    
    seats = 2*m;

    int ans;
    ans = min(m, a) + min(m, b);
    ans += min((seats - ans), c);

    cout << ans << '\n';
}

int main() {
    //ios::sync_with_stdio(false);
    //cin.tie(0);

    int t;
    cin >> t;

    while(t--) {
        solve();
    }
}