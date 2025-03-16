//https://neps.academy/br/exercise/309

#include <bits/stdc++.h>

void dfs(int vertice, std::vector<int> grafo[], bool jaChecado[]){

    for (int i = 0; i < grafo[vertice].size(); i++){
        int vizinho = grafo[vertice][i];

        if (!jaChecado[vizinho]){
            jaChecado[vizinho] = true;
            dfs(vizinho, grafo, jaChecado);
        }
    }
}

int main(int argc, char const *argv[]){
    int nAlunos, nLinhas;
    int numero_componentes = 0;

    std::cin >> nAlunos >> nLinhas;
    nAlunos += 1; //Pois o input vai ser a partir do 1

    //Os vértices serão os alunos. Um vértice será ligado a outro(aresta) se esses alunos forem amigos.
    std::vector<int> grafo[nAlunos];

    bool jaChecado[nAlunos]; 
    for (int i = 0; i < nAlunos; i++) jaChecado[i] = false;

    for (int linha = 0; linha < nLinhas; linha++){
        int i,j;
        std::cin >> i >> j;

        grafo[i].push_back(j);
        grafo[j].push_back(i);
    }

    for (int i = 1; i < nAlunos; i++){
        if (!jaChecado[i]){
            dfs(i, grafo, jaChecado);
            numero_componentes++;
        }
    }

    std::cout << numero_componentes;
    return 0;
}
