
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n,x;
    cin >> n >> x;

    if (n == 1 && x == 0) {
        cout << "0\n";
        return;
    }
    for (int i = 0; i < n - 1; i++) {
        if (i == x) cout << n - 1 << " ";
        else cout << i << " ";
    }
    if (n == x) cout << n - 1 << "\n";
    else cout << x << "\n";
}

int main() {
    int t;
    cin >> t;

    while(t--) solve();
}
