#include <bits/stdc++.h>
using namespace std;

#define MAX_N 201
#define MAX_M 201

bool jogo[MAX_N][MAX_M];
int prefix[MAX_N][MAX_M]; //Soma de prefixo
int n, m;

bool possivel(int s) {
    if (s == 1)
        return prefix[n][m] < n*m;
    
    for (int i = s; i <= n; i++) {
        for (int j = s; j <= m; j++) {
            int consulta 
            = prefix[i][j] - prefix[i][j-s] - prefix[i-s][j] + prefix[i-s][j-s];

            if (consulta == 0) return true;
        }
    }

    return false;
}

int main() {
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            int num;
            cin >> num;

            /*
                Assim, uma consulta à soma de prefixo terá soma 0
                se for uma configuração sem zeros
            */
            jogo[i][j] = (num == 0 ? 1 : 0);
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            prefix[i][j] 
            = jogo[i][j] + prefix[i][j-1] + prefix[i-1][j] - prefix[i-1][j-1];
        }
    }

    int q;
    cin >> q;
    while(q--) {
        int s;
        cin >> s;

        if(possivel(s)) cout << "yes\n";
        else cout << "no\n";
    }   
}