//https://open.kattis.com/problems/rollcall

#include <bits/stdc++.h>
using namespace std;

map<string, int> occurrences;
set<pair<string,string>> names;// pair[lastName, firstName]

int main() {
    string firstName, lastName;
    while (cin >> firstName >> lastName) {
        occurrences[firstName]++;
        names.insert({lastName, firstName});
    }

    for(auto n : names) {
        if (occurrences[n.second] == 1) cout << n.second << '\n';
        else cout << n.second << ' ' << n.first << '\n';
    }
}