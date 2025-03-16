#include <bits/stdc++.h>
using namespace std;

char grid[8][8];

void solve();

int main()
{
    int t;
    cin >> t;
    for (int test = 0; test < t; test++)
    {
        for (int i = 0; i < 8; i++)
            for (int j = 0; j < 8; j++)
                cin >> grid[i][j];    
        solve();
    }
}

void solve()
{
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (grid[i][j] != '.')
            {
                for (int k = i; k < 8 && grid[k][j] != '.'; k++)
                {
                    cout << grid[k][j];
                }
                cout << '\n';
                return;
            }
        }
    }
}