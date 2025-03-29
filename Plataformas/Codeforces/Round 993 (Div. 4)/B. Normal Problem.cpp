#include <bits/stdc++.h>
#define vi vector<int>
using namespace std;

void solve() {
    string str;
    cin >> str;

    reverse(str.begin(), str.end());

    for (int i = 0; i < str.size(); i++) {
        if (str.at(i) == 'p') str.at(i) = 'q';
        else if (str.at(i) == 'q') str.at(i) = 'p';
    }

    cout << str << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--) {
        solve();
    }
}