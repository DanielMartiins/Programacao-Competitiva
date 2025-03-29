#include <bits/stdc++.h>
using namespace std;

void solve(int n);
int somaMultiplos(int x, int n);

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

void solve(int n)
{
    int maiorSoma = 0;
    int soma = 0;
    int ans;
    for (int i = 2; i <= n/2; i++)
    {
        soma = somaMultiplos(i, n);
        if (maiorSoma < soma)
        {
            maiorSoma = soma;
            ans = i;
        }
    }
    if (maiorSoma == 0) cout << n;
    else cout << ans;
    cout << '\n';
}

int somaMultiplos(int x, int n)
{
    int soma = 0;
    int k = 1;
    while (k * x <= n)
    {
        soma += k*x;
        k++;
    }
    return soma;
}