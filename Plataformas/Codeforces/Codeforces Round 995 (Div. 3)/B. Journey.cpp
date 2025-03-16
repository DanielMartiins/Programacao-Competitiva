#include <bits/stdc++.h>
using namespace std;

#define vii vector<int>

void solve() {
    long long n,a,b,c;
    long long ans;
    cin >> n >> a >> b >> c;

    long long abc[3] = {a,b,c};

    long long sum = a + b + c;
    ans = (n/sum) * 3;
    if (n%sum != 0) {
        long long x = sum * (n/sum);
        for (int i = 0; i < 3; i++) {
            x += abc[i];
            ans++;
            if (x >= n) break;
        }
    }
    cout << ans << '\n';
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