//https://cses.fi/problemset/task/1193
 
/*
Minha ideia foi armazenar o labirinto num grafo no formato de lista de adjacências em que os vértices possuem coordenadas i,j de uma matriz.
Considero como vértice os caracteres "A", "B" e ".".
Realizo dijkstra para armazenar a distancia mais curta do vértice "B" do input até um vértice qualquer. Também armazeno o
vértice antecendente de cada um ao seguir o caminho mais curto. Uso essa informação para conseguir partir do ponto "A" do labirinto
até chegar ao ponto "B", sendo que cada vez que faço o percurso eu calculo a direção do movimento usando as coordenadas desse ponto.
*/
 
#include <bits/stdc++.h>
#define MAX 1000
#define INFINITO 99999999
 
int altura, largura;
char mapa[MAX][MAX];
std::vector<std::pair<int,int>> grafo[MAX][MAX];
std::pair<int, int> posA = std::make_pair(-1, -1);
std::pair<int, int> posB = std::make_pair(-1, -1);
 
//verticeAntecessor[i][j] = seguindo o caminho mais curto a partir de "B", armazena o antecessor do vértice i,j desse caminho.
std::pair<int, int> verticeAntecessor[MAX][MAX];
int distancia[MAX][MAX]; //distancia[i][j] = distancia mais curta de "B" ao vértice i,j
 
//Será considerado vértice tudo aquilo que não for parede('.', 'A' ou 'B')
void adicionarVizinhosDoVertice(int i, int j)
{
    //Verificar acima do vértice
    if (i - 1 >= 0 && mapa[i - 1][j] != '#')
    {
        grafo[i][j].push_back(std::make_pair(i - 1, j));
    }    
 
    //Verificar à direita do vértice
    if (j + 1 < largura && mapa[i][j + 1] != '#')
    {
        grafo[i][j].push_back(std::make_pair(i, j + 1));  
    }
    
    //Verificar abaixo do vértice
    if (i + 1 < altura && mapa[i + 1][j] != '#')
    {
        grafo[i][j].push_back(std::make_pair(i+1, j));
    }
 
    //Verificar à esquerda do vértice
    if (j - 1 >= 0 && mapa[i][j - 1] != '#')
    {
        grafo[i][j].push_back(std::make_pair(i, j-1));
    }
}
 
void dijkstra()
{
 
    bool visitado[altura][largura]; //Para o dijkstra não analisar um vizinho já visitado anteriormente
 
    std::queue<std::pair<int,int>> fila;
 
    //Inicializar o vetor de vertices visitados e inicializar o vetor de distancia
    for (int i = 0; i < altura; i++)
    {
        for (int j = 0; j < largura; j++)
        {
            visitado[i][j] = false;
            distancia[i][j] = INFINITO;
        }
    }
 
    //Distancia do vértice de origem a ele mesmo é 0
    distancia[posB.first][posB.second] = 0;
    fila.push(std::make_pair(posB.first, posB.second));
 
    while (!fila.empty())
    {
        
        //Pegar o vértice do topo da fila
        int iVerticeFila = fila.front().first;
        int jVerticeFila = fila.front().second;
        fila.pop();
 
        if (!visitado[iVerticeFila][jVerticeFila])
        {
            visitado[iVerticeFila][jVerticeFila] = true;    
 
            //Percorrer os vizinhos do vértice da fila
            for (int v = 0; v < grafo[iVerticeFila][jVerticeFila].size(); v++)
            {
                int dist_verticeFila = distancia[iVerticeFila][jVerticeFila];
                int iVizinho = grafo[iVerticeFila][jVerticeFila][v].first;
                int jVizinho = grafo[iVerticeFila][jVerticeFila][v].second;
 
                //Calcular a distancia do vértice da fila a seus vértices vizinhos ainda não visitados
                if (!visitado[iVizinho][jVizinho] && distancia[iVizinho][jVizinho] > (dist_verticeFila + 1))
                {
                    distancia[iVizinho][jVizinho] = dist_verticeFila + 1;
                    verticeAntecessor[iVizinho][jVizinho] = std::make_pair(iVerticeFila, jVerticeFila);
                }
 
                fila.push(std::make_pair(iVizinho, jVizinho));
            }
        }
    }
}
 
std::string direcaoMovimento(int linhaAtual, int colunaAtual, int linhaAntecessor, int colunaAntecessor)
{
     
    //Se o vértice antecessor estiver logo à esquerda do vértice atual
    if (linhaAtual == linhaAntecessor && colunaAtual > colunaAntecessor)
        return "L";
 
    //Se o vértice antecessor estiver logo à direita do vértice atual
    else if (linhaAtual == linhaAntecessor && colunaAtual < colunaAntecessor)
        return "R";
 
    //Se o vértice antecessor estiver logo acima do vértice atual
    else if (linhaAtual > linhaAntecessor && colunaAtual == colunaAntecessor)
        return "U";
 
    //Se o vértice antecessor estiver logo abaixo do vértice atual
    else
        return "D";
    
}
 
int main(int argc, char const *argv[])
{
    std::cin >> altura >> largura;
 
    //Eu leio cada linha como uma string e vou olhando cada caracter no loop
    for (int i = 0; i < altura; i++)
    {
        std::string linha;
        std::cin >> linha;
        for (int j = 0; j < largura; j++)
        {
            char caracter = linha.at(j);
            mapa[i][j] = caracter;
            if (caracter != '#')
                adicionarVizinhosDoVertice(i,j);
 
            //Se 'A' e/ou 'B' não foram encontrados, verificar se o caracter sendo lido é 'A' ou 'B' 
            if (posA == std::make_pair(-1, -1) || posB == std::make_pair(-1, -1))
            {
                if (caracter == 'A')
                    posA = std::make_pair(i,j);
                else if (caracter == 'B')
                    posB = std::make_pair(i,j);
            }
        }
    }
    //Se o ponto A e/ou o ponto B não tiverem vizinhos, já posso descartar e printar "NO" antes mesmo de executar o dijkstra
    if (grafo[posA.first][posA.second].empty() || grafo[posB.first][posB.second].empty())
        std::cout << "NO";
    else
    { 
        //Vou andar da posição "B" até chegar na posição "A", calculando e retornando a direção de cada movimento
 
        int qtdMovimentos = 0;
 
        dijkstra();
        if (distancia[posA.first][posA.second] == INFINITO)
            std::cout << "NO"; //Pois significa que não conseguiu calcular alguma distancia do ponto A até o B
        else 
        {
            std::cout << "YES\n";
            std::cout << distancia[posA.first][posA.second] << '\n';

            std::pair<int,int> vertice = std::make_pair(posA.first, posA.second);
            int iVertice, jVertice;
            int iAntecessor, jAntecessor;
            do
            {   
                iVertice = vertice.first;
                jVertice = vertice.second;
                
                iAntecessor = verticeAntecessor[iVertice][jVertice].first;
                jAntecessor = verticeAntecessor[iVertice][jVertice].second;

                std::cout << direcaoMovimento(iVertice, jVertice, iAntecessor, jAntecessor);
                
                vertice = std::make_pair(iAntecessor, jAntecessor);
            } while (mapa[iAntecessor][jAntecessor] != 'B');
        }
    }
    return 0;
}