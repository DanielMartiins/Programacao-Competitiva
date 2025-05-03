#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    int line[n];
    line[0] = 1;
    for (int i = 2; i <= n; i++) {
        int d;
        cin >> d;
        line[0+d+1] = i;
    }

    for (int i = 0; i < n-1; i++) {
        cout << line[i] << " ";
    }
    cout << line[n-1] << "\n";

}

int main() {
    solve();
}