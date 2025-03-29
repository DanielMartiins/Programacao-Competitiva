#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        string a,b;
        cin >> a >> b;

        char aux = a.at(0);
        a.at(0) = b.at(0);
        b.at(0) = aux;

        cout << a << ' ' << b << '\n';
    }
}