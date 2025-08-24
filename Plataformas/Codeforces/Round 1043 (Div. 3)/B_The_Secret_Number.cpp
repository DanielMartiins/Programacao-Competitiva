#include <bits/stdc++.h>
using namespace std;

void solve(long long n) {
    
    vector<long long> ans;

    for (int k = 1; n >= (long long)pow(10, k) + 1; k++) {
        long long divisor = 1;
        for (int i = 0; i < k; i++) divisor *= 10;
        divisor += 1;
        if ((n % divisor) != 0) continue;

        long long x = n / divisor;
        ans.push_back(x);  
    }

    cout << ans.size();
    if (ans.size() > 0) cout << '\n';
    for (int i = ans.size() - 1; i >= 0; i--)
        cout << ans[i] << ' ';
    cout << "\n";
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        
        solve(n);
    }
}