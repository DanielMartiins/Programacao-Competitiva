#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    while(cin >> n) {
        set<tuple<string, int, string>> names; //<2 characters, order, full name>
        for(int i = 0; i < n; i++) {
            string full_name;
            string two_chars;
            cin >> full_name;
            two_chars = full_name.substr(0, 2);
            names.insert({two_chars, i, full_name});
        }

        for (auto s : names) 
            cout << get<2>(s) << "\n";
        cout << "\n";
    }
}
