//https://codeforces.com/contest/1971/problem/A

#include <iostream>

using namespace std;

int main()
{
    int t;
    int x,y;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        cin >> x >> y;
        if (x > y) cout << y << ' ' << x << '\n';
        else if (x < y) cout << x << ' ' <<  y << '\n';
        else if (x == y) cout << x << ' ' << y << '\n';
    }
}
