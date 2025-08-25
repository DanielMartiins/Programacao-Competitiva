#include <bits/stdc++.h>
using namespace std;

#define MAX_N 1001

int main() {
    priority_queue<int, vector<int>, greater<int>> vendedores_inativos;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> chamadas_em_andamento; //pair<duracao,vendedor>
    queue<int> ligacoes_pendentes;
    vector<int> chamadas(MAX_N, 0); //Indice = identificador do vendedor
                                    //Valor = quantidade atentidas

    
    int n, l;
    cin >> n >> l;

    for (int i = 1; i <= n; i++) vendedores_inativos.push(i);


    for (int i = 0; i < l; i++) {
        int t;
        cin >> t;
        ligacoes_pendentes.push(t);
    }

    while(!ligacoes_pendentes.empty()) {
        while(!vendedores_inativos.empty() && !ligacoes_pendentes.empty()) {
            int duracao = ligacoes_pendentes.front(); 
            int vendedor = vendedores_inativos.top(); 
            
            chamadas_em_andamento.push({duracao, vendedor});
            chamadas[vendedor]++;

            ligacoes_pendentes.pop();
            vendedores_inativos.pop();
        }

        while(!chamadas_em_andamento.empty()) {
            int vendedor = chamadas_em_andamento.top().second;
            chamadas_em_andamento.pop();

            if(!ligacoes_pendentes.empty()) {
                chamadas_em_andamento.push({ligacoes_pendentes.front(), vendedor});
                ligacoes_pendentes.pop();
                chamadas[vendedor]++;
            }
            else vendedores_inativos.push(vendedor);
        }
    }

    for (int i = 1; i <= n; i++)
        printf("%d %d\n", i, chamadas[i]);
}