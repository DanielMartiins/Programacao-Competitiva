#include <bits/stdc++.h>
using namespace std;

int t;
int caso = 1;

vector<long long> weights;

void solve() {
    int n;
    cin >> n;
    weights.resize(n);
    long long ans = 0;
    
    for (int i = 0; i < n; i++)
        cin >> weights[i];

    bool isFalling;
    ans = 1;
    for(int i = 1; i < n; i++) {
        if(weights[i-1] > weights[i]) 
            isFalling = true;
        if (isFalling) {
            for (; i < n && isFalling && weights[i-1] >= weights[i]; i++);
            isFalling = false;
            if(i < n) ans++;
        }   
    }

    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;

    while(t--) { 
        solve();
        caso++;
    }
}