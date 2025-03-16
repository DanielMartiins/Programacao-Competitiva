//https://codeforces.com/contest/1968/problem/C

#include <iostream>

using namespace std;

void solve(int x[], int n)
{
    int a[n];
    a[0] = 501;
    /*
    A primeira posição(a[0]) pode ter qualquer coisa, desde que seja maior que 500
    porque, segundo o exercicio, 1 <= x[i] <= 500. Tenho que garantir que meu valor no
    vetor de resposta seja maior que qualquer x para não quebrar a conta de divisão. 
    Por exemplo: se quero achar um numero 'n' tal que n % 3 = 8, essa conta é impossível. 
    Para evitar essas contas impossíveis meu a[0] deve ser maior que 500 
    */

    for (int i = 1; i < n; i++)
        a[i] = a[i-1] + x[i-1];
    
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << ' ';
    }
    cout << '\n';
}

int main()
{
    int t;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        int n;
        cin >> n;
        int x[n-1];

        for (int i = 0; i < n - 1; i++)
            cin >> x[i];
        
        solve(x, n);
    }
}