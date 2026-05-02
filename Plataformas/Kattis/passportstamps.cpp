
#include <bits/stdc++.h>
using namespace std;

long long n, p;
long long carimbos = 0;
long long blocos_branco = 1; //blocos de páginas em branco contíguas

bool possivel(long long c) {
    
    /*
        - Tamanho necessário do passaporte para conspirar, ou seja, fazer uma configuração 
        com blocos contiguos de páginas em brancas de tamanho 
        exatamente c-1 com os carimbos já acumulados 
         
        - Se o passaporte tiver tamanho maior do que isso, então necessariamente
        cabe pelo menos um bloco de 'c' paginas em branco contíguas; portanto, dá para fazer a viagem.

        - Caso contrário, significa que dá para impedir a viagem fazendo uma configuração 
        com blocos de tamanhos no máximo c-1. 
    */

    __int128 necessario = (__int128)(carimbos) + ((__int128)(blocos_branco) * (c-1));
    return p > necessario;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> p;

    for (int i = 0; i < n; i++) {        
        long long c;
        cin >> c;
        if (!possivel(c)) {cout << i << "\n"; return 0;}
        else {
            carimbos += c;
            blocos_branco++;
        }
    }

    cout << n << "\n";
}