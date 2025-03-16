#include <bits/stdc++.h>
using namespace std;

void solve();

int main()
{
    int t;
    cin >> t;

    for (int i = 0; i < t; i++)
        solve();
}

void solve()
{
    int a1, a2, b1, b2, ans = 0;
    cin >> a1 >> a2 >> b1 >> b2;

    if (a1 > b1 && a2 > b2) ans += 2;
    if (a1 > b2 && a2 > b1) ans += 2;

    if (a1 == b1 && a2 > b2) ans += 2;
    if (a1 == b2 && a2 > b1) ans += 2;

    if (a2 == b2 && a1 > b1) ans += 2;
    if (a2 == b1 && a1 > b2) ans += 2;

    cout << ans << '\n';
}