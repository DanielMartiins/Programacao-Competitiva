#include <bits/stdc++.h>
using namespace std;

#define MAX_N 500
#define MAX_M 500

int n, m;
char matriz[MAX_N][MAX_M];

void imprimirMatriz() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            //cout << matriz[i][j];
            printf("%c", matriz[i][j]);
        }
        printf("\n");
    }
}

void recursao(int i, int j) {
    
    //Casos base
    if (i == n || j == m || j < 0)
        return;

    matriz[i][j] = 'o';
    if (matriz[i+1][j] == '#') {
        
        //Comparações necessárias para não estourar a pilha de chamadas
        if (matriz[i][j+1] == '.') recursao(i, j+1);
        if (matriz[i][j-1] == '.') recursao(i, j-1);
    }
    else recursao(i+1, j);

}

void solve() {
    int pos_inicio;
    scanf("%d %d", &n, &m);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            //cin >> matriz[i][j];
            scanf(" %c", &matriz[i][j]);
            if (i == 0 && matriz[i][j] == 'o') 
                pos_inicio = j;
        }
    }
    recursao(0, pos_inicio);
    imprimirMatriz();
}

int main() {
    solve();
}