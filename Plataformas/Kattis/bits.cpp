
#include <bits/stdc++.h>
using namespace std;

int count_ones(int num) {
    int ct = 0;

    for (int i = 0; (1ll << i) <= num; i++) {
        if (num & (1 << i)) ct++; 
    }

    return ct;
}

int solve(string x) {
    string aux = "";
    int ans = 0;

    for (auto digit : x) {
        aux += digit;
        ans = max(ans, count_ones(stoi(aux)));
    }

    return ans;
}

int main() {
    int t;
    cin >> t;

    while(t--) {
        string x;
        cin >> x;
        cout << solve(x) << "\n";
    }
}
