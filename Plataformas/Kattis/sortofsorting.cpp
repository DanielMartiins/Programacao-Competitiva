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
            cin >> full_name;
            names.insert({full_name.substr(0, 2), i, full_name});
        }
        for (auto s: names) 
            cout << get<2>(s) << "\n";
        cout << "\n";
    }
}
