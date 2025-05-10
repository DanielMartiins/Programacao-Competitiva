// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    string strA,strB;
    vector<char> vA, vB;

    cin >> n;
    cin.ignore();
    getline(cin, strA);
    getline(cin, strB);

    for (int i = 0; i < n; i++) {
        if(strA.at(i) >= 'a' && strA.at(i) <= 'z') vA.push_back(strA.at(i));
        if(strB.at(i) >= 'a' && strB.at(i) <= 'z') vB.push_back(strB.at(i));
    }

    if (vA.size() != vB.size()) {
        cout << "N\n";
        return 0;
    }

    sort(vA.begin(), vA.end());
    sort(vB.begin(), vB.end());

    bool eql = true;
    for (int i = 0; i < vA.size(); i++) {
        if(vA.at(i) != vB.at(i)) { 
            eql = false;
            break;
        }
    }
    
    if (eql) cout << "S\n";
    else cout << "N\n";
}