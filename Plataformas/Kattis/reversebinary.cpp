// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n;
    cin >> n;
    string rep_binaria_inversa = "";

    for (long long i = 0; (1ll << i) <= n; i++) {
        if (n & (1 << i)) rep_binaria_inversa += '1';
        else rep_binaria_inversa += '0';
    }

    long long ans = 0;
    for (long long i = 0; i < rep_binaria_inversa.size(); i++) 
        ans += (rep_binaria_inversa[i] == '1' ? (1ll << rep_binaria_inversa.size() - 1 - i) : 0);

    cout << ans << "\n";
}
