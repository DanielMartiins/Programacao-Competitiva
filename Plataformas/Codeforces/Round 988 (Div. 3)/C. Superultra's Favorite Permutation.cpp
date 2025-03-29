/*
Se eu juntar dois números de mesma paridade(dois pares ou dois ímpares), sempre terei um número composto. Então basta eu criar um grupo de números pares e um outro grupo de números ímpares e concatená-los no final.
Porém, com essa concatenação um número par se encontra com um número ímpar no meio. A menor combinação de par e ímpar possível, de modo que haja um número composto, é 4 e 5. Portanto não há solução quando n < 5.
*/


#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>

void solve() {
    int n;
    cin >> n;

    if (n <= 4) cout << "-1\n";
    else {
        vi even, odd;

        for (int i = 1; i <= n; i++) {
            if (i == 4 || i == 5) continue;
            if (i%2 == 0) even.push_back(i);
            else odd.push_back(i);
        }

        for (int i = 0; i < even.size(); i++)
            cout << even.at(i) << " ";

        cout << "4 5 ";

        for (int i = 0; i < odd.size() - 1; i++)
            cout << odd.at(i) << " ";

        cout << odd.at(odd.size() - 1) << '\n';
    }
}

int main(int argc, char const *argv[])
{
    int t;
    cin >> t;

    while (t--){
        solve();
    }   
    return 0;
}
