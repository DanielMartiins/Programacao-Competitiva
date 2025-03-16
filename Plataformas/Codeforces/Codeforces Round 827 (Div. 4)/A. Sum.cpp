#include <iostream>
using namespace std;

void solve(int a, int b, int c);

int main()
{
    int t, a, b, c;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        cin >> a >> b >> c;
        solve(a,b,c);
    }

    return 0;
}

void solve(int a, int b, int c)
{
    if (a == b + c || b == a + c || c == a + b) cout << "YES\n";
    else cout << "NO\n";
}