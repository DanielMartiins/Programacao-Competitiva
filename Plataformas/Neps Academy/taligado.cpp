//https://neps.academy/br/exercise/289

#include <bits/stdc++.h>

#define MAX 100002
#define PERGUNTA 0
#define INFORMAR 1

int qtdIlhas; //N
int qtdInteracoes; //M
std::vector<int> grafo[MAX];

bool contemPonteEntreAsCidades(int cidadeA, int cidadeB){
    for (int i = 0; i < grafo[cidadeA].size(); i++)
    {
        if (grafo[cidadeA][i] == cidadeB)
            return true;
    }
    return false;
}

int main(int argc, char const *argv[])
{
    std::cin >> qtdIlhas >> qtdInteracoes;

    for (int i = 0; i < qtdInteracoes; i++)
    {
        int interacao, cidadeA, cidadeB;
        std::cin >> interacao >> cidadeA >> cidadeB;

        switch (interacao)
        {
            case PERGUNTA:
                if (contemPonteEntreAsCidades(cidadeA, cidadeB))
                    std::cout << 1;
                else
                    std::cout << 0;
                break;

            case INFORMAR:
                grafo[cidadeA].push_back(cidadeB);
                grafo[cidadeB].push_back(cidadeA);
                break;
        }
    }
    return 0;
}
