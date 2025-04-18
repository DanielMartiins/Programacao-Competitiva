#include <bits/stdc++.h>
using namespace std;

int main() {
    int k;
    string a,b;

    cin >> k;
    cin >> a >> b;

    int matches = 0;

    for (int i = 0; i < a.size(); i++)
        if (a.at(i) == b.at(i)) matches++;

    cout << a.size() - abs(k-matches) << '\n';
}