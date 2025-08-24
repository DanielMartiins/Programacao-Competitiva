#include <bits/stdc++.h>
using namespace std;

string str;

void solve() {
    cin >> str;
    int ans = 0;
    map<string, int> occurences;

    string substr = "";
    for (int i = 0; i < str.size(); i++) {
        substr += str.at(i);
        occurences[substr]++;
        for (int j = i+1; j < str.size(); j++) {
            substr += str.at(j);
            sort(substr.begin(), substr.end());
            occurences[substr]++;
        }
        substr = "";
    }

    for (auto m : occurences) {
        int n = m.second;
        ans += (n * (n-1)) / 2;
    }

    cout << ans << "\n";
}

int main() {
    int q;
    cin >> q;
    while(q--) {
        solve();
    }
}