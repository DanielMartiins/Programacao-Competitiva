#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, p;
    cin >> n >> p;
    long long pref[n+1]; pref[0] = 0;
    long long arr[n+1]; arr[0] = 0;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        arr[i] -= p;
        pref[i] = arr[i] + pref[i-1];
    }

    int l=1, r=1;
    long long ans = 0;
    /*
    long long ans_esperado = 0;


    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            ans_esperado = max(ans_esperado, pref[j]-pref[i-1]);
        }
    }
    */

    while(l <= n && r <= n) {
        
        while(l <= n && arr[l] < 0) l++;
        if (l > n) break;
        
        r = l;
        long long sum = pref[r] - pref[l-1];
        while(r+1 <= n && arr[r+1] > 0) {
            r++;
            sum = pref[r] - pref[l-1];
        }
        
        
        ans = max(ans, pref[r] - pref[l-1]);
        while (r+1 <= n && arr[r+1] + sum > 0) {
            r++;
            sum = pref[r] - pref[l-1];
            ans = max(ans, sum);
        }
        l = r+1;

    }

    //cout << "resposta que deveria dar: " << ans_esperado << "\n";
    //cout << "resposta que deu: " << ans << "\n";
    cout << ans << "\n";

}