#include <bits/stdc++.h>
using namespace std;

#define vii vector<int>

void solve() {
    int n;
    vii a;
    vii b;

    cin >> n;

    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;

        a.push_back(num);
    }

    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;

        b.push_back(num);
    }
    long long m = 0, s = 0;
    for (int i = 0; i < n; i++) {

        if (i+1 == n) m += a.at(i);
        else if (a.at(i) > b.at(i+1)) {
            m += a.at(i);
            s += b.at(i+1);
        }
    }

    cout << (m - s) << '\n';
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        solve();
    }
}