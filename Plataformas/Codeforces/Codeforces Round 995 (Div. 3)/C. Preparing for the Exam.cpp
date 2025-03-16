#include <bits/stdc++.h>
using namespace std;

#define vii vector<int>

void solve() {
    int n,m,k;
    cin >> n >> m >> k;
    vii a(m);
    set<int> b;

    for (int i = 0; i < m; i++)
        cin >> a[i];

    for (int i = 0; i < k; i++) {
        int num;
        cin >> num;
        b.insert(num);
    }

    if (k < n - 1) {
        for (int i = 0; i < m; i++)
            cout << '0';
        cout << '\n';
    }
    else if (k == n) {
        for (int i = 0; i < m; i++)
            cout << '1';
        cout << '\n';
    } 
    else {
        for (int i = 0; i < m; i++) {
            if (b.find(a[i]) == b.end())
                cout << '1';
            else
                cout << '0';
        }
        cout << '\n';
    }
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