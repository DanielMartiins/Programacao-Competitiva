//https://cses.fi/problemset/task/1640

#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
    int n, x;
    cin >> n >> x;

    vector<pair<int,int>> numeros; // Par <Numero, posição>

    for (int i = 0; i < n; i++)
    {
        int numero;
        cin >> numero;

        numeros.push_back({numero, i});
    }
    sort(numeros.begin(), numeros.end());

    for (int left = 0, right = n - 1; left < right;)
    {
        int soma;
        soma = numeros.at(left).first + numeros.at(right).first;
        if (soma == x){
            cout << numeros.at(left).second + 1 << ' ' << numeros.at(right).second + 1;
            return 0;
        } else if (soma > x)
            right--;
        else if (soma < x)
            left++;
    }
    cout << "IMPOSSIBLE";
    return 0;
}
