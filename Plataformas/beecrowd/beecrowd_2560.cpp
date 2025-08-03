#include <bits/stdc++.h>
using namespace std;

int main() {
    
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, b;
    
    while(cin >> n >> b) {
        long long soma = 0;
        long long resposta = 0;
        int notas[n+1];
        multiset<int> bateria;
        
        int l = 1, r = b, i = 1;
        while (r <= n) {
            for (; i <= r; i++) {
                cin >> notas[i];
                soma += notas[i];
                bateria.insert(notas[i]);
            }
            resposta += soma - (*bateria.begin() + *bateria.rbegin());
            bateria.erase(bateria.find(notas[l]));
            soma -= notas[l];

            l++; r++;
        }

        cout << resposta << "\n";
    }
}