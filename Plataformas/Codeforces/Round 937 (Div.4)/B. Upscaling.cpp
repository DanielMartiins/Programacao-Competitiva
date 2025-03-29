#include <bits/stdc++.h>
using namespace std;

void solve(int n)
{
    char first = '#';
    char second = '.';

    for (int i = 0; i < 2 * n; i++)
    {
        if (n % 2 == 0 && i % 2 != 0)
        {
            //swap
            char aux = first;
            first = second;
            second = aux;
        }
        else if (n % 2 != 0 && i % 2 == 0 && i > 0)
        {
            //swap
            char aux = first;
            first = second;
            second = aux;
        }
         
        for (int j = 0; j < 2 * n; j+=2)
        {
            for (int k = 0; k < 2; k++) 
                cout << first;
            
            if (j+2 < 2 * n)
            {
                //swap
                char aux = first;
                first = second;
                second = aux;
            }
        }
        cout << '\n';
    }
}

int main()
{
    int t;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        int n;
        cin >> n;
        solve(n);
    }   
}