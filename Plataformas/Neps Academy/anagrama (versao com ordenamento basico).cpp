// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    string a,b;

    cin >> n;
    cin.ignore();
    getline(cin, a);
    getline(cin, b);

    vector<char> charA, charB;

    for (int i = 0; i < n; i++) {
        if(a.at(i) >= 'a' && a.at(i) <= 'z') charA.push_back(a.at(i));
        if(b.at(i) >= 'a' && b.at(i) <= 'z') charB.push_back(b.at(i));
    }

    if (charA.size() != charB.size()) {
        cout << "N\n";
        return 0;
    }

    sort(charA.begin(), charA.end());
    sort(charB.begin(), charB.end());

    bool eql = true;
    for (int i = 0; i < charA.size(); i++) {
        if(charA.at(i) != charB.at(i)) eql = false;
        break;
    }
    
    if (eql) cout << "S\n";
    else cout << "N\n";
}
