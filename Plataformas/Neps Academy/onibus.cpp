//https://neps.academy/br/exercise/36

#include <bits/stdc++.h>

#define INFINITO 99999999

int dijkstra(std::vector<int> grafo[], int origem, int destino, int tamGrafo){

    //Para o dijkstra não analisar um vértice vizinho já visitado e analisado anteriormente.
    bool verticeVisitado[tamGrafo]; 

    //distancia[i] = distancia mais curta do vértice 'origem' até o vértice 'i'
    int distancia[tamGrafo]; 

    std::vector<int> fila;

    //Inicializar o vetor de vertices visitados e inicializar o vetor de distancia
    for (int i = 0; i < tamGrafo; i++){
        verticeVisitado[i] = false;
        distancia[i] = INFINITO;
    }
    distancia[origem] = 0; //Distancia do vertice de origem a ele mesmo é 0
    fila.push_back(origem); //Fazer o dijkstra começar a partir desse vértice

    while(!fila.empty()){

        //Pegar o vértice do topo da fila
        int verticeFila = fila.front();
        fila.erase(fila.begin());

        if (!verticeVisitado[verticeFila]){

            verticeVisitado[verticeFila] = true;

            //Percorrer o vizinho do vertice pego da fila
            for (int i = 0; i < grafo[verticeFila].size(); i++){
                int dist_verticeFila = distancia[verticeFila];
                int vizinho = grafo[verticeFila][i];

                //Calcular a distancia do vértice da fila a seus vizinhos ainda não visitados
                if (!verticeVisitado[vizinho] && distancia[vizinho] > (dist_verticeFila + 1)){
                    distancia[vizinho] = dist_verticeFila + 1;
                }

                fila.push_back(vizinho);
            }
        }
    }

    return distancia[destino];
}

int main(int argc, char const *argv[]){

    int nCidades, cidadeOrigem, cidadeDestino;
    std::cin >> nCidades >> cidadeOrigem >> cidadeDestino;

    std::vector<int> grafoCidade[nCidades + 1];

    for(int i = 0; i < nCidades - 1; i++){
        int p,q;

        std::cin >> p >> q;

        grafoCidade[p].push_back(q);
        grafoCidade[q].push_back(p);
    }

    int distancia = dijkstra(grafoCidade, cidadeOrigem, cidadeDestino, nCidades + 1);
    std::cout << distancia;

    return 0;
}