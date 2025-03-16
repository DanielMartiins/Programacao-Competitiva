#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        set<int> numeros = {};
        int n;
        cin >> n;

        for (int j = 0; j < n; j++)
        {
            int num;
            cin >> num;
            numeros.insert(num);
        }

        if (numeros.size() == n) cout << "YES\n";
        else cout << "NO\n";
    }
}