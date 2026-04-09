// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;

int main() {
    long long ans = 0;
    
    vector<string> strs;

    string s;
    string string_n = "";
    while(getline(cin, s)) {
        strs.push_back(s);
        if (strs[strs.size() - 1].size() > string_n.size()) string_n = strs[strs.size()-1];
    }

    for(int i = 0; i < strs.size() - 1; i++) {
        long long n = string_n.length();
        long long m = strs[i].length();
        ans += (n-m) * (n-m);
    }


    cout << ans << "\n";
}
