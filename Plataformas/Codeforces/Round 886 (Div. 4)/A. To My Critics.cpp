#include <bits/stdc++.h>
using namespace std;

void solve(int a, int b, int c);

int main()
{
    int t;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        int a,b,c;
        cin >> a >> b >> c;
        solve(a,b,c);
    }
}

void solve(int a, int b, int c)
{
    if (a + b >= 10 || a + c >= 10 || b + c >= 10)
        cout << "YES\n";
    else
        cout << "NO\n";
}