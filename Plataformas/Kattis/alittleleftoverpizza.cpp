

#include <bits/stdc++.h>
using namespace std;

#define S_CAPACITY 6
#define M_CAPACITY 8
#define L_CAPACITY 12

map<char, int> num_slices;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;

    char si;
    int li;
    while(n--) {
        cin >> si >> li;
        num_slices[si] += li;
    }

    int ans = 0;
    int s = num_slices['S'];
    int m = num_slices['M'];
    int l = num_slices['L'];
    ans += s/S_CAPACITY + (s % S_CAPACITY == 0 ? 0 : 1);
    ans += m/M_CAPACITY + (m % M_CAPACITY == 0 ? 0 : 1);
    ans += l/L_CAPACITY + (l % L_CAPACITY == 0 ? 0 : 1);

    cout << ans << "\n";
}
