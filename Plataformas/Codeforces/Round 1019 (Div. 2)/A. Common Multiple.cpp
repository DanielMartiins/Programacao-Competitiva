#include <bits/stdc++.h>
using namespace std;

void solve() {
    set<int> diffNumbers;
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        diffNumbers.insert(num);
    }

    cout << diffNumbers.size() << "\n";
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--) solve();
}