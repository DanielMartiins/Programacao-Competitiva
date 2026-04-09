// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    long long ans = 0;
    cin >> n;

    for(long long i = n-1; i >= 0; i--) {
        char c;
        cin >> c;
        if (c == 'O') ans += (1ll << i);
    }
    cout << ans << "\n";
}
