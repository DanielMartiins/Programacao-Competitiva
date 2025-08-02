
#include <bits/stdc++.h>
using namespace std;

struct Dragao{
    int dias;
    int multa;
    double razao;

    Dragao(int t, int f) {
        dias = t;
        multa = f;
        razao = ((double)dias)/multa;
    }

    Dragao() {}
};
bool operator>(const Dragao& d1, const Dragao& d2) {
    return d1.razao > d2.razao;
}


int main() {
    priority_queue<Dragao, vector<Dragao>, greater<Dragao>> fila_treino;
    queue<Dragao> dragoes;
    long long resposta = 0;
    long long multa_acumulada = 0;
    
    int t, f;
    while (cin >> t >> f)
        dragoes.push(Dragao(t,f));

    fila_treino.push(dragoes.front());
    dragoes.pop(); 
    while(!fila_treino.empty()) {
        Dragao dragao_ativo = fila_treino.top();
        fila_treino.pop();

        while(dragao_ativo.dias > 0) {
            dragao_ativo.dias--;
            resposta += multa_acumulada;
            if(!dragoes.empty()) {
                multa_acumulada += dragoes.front().multa;
                fila_treino.push(dragoes.front());
                dragoes.pop();
            }

        }

        if (!fila_treino.empty())
            multa_acumulada -= fila_treino.top().multa;
    }

    cout << resposta << "\n";
}
