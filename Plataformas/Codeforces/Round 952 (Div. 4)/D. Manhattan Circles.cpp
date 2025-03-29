#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        int n,m;
        cin >> n >> m;     

        char grid[n+1][m+1];
        int linhaCentro;
        int colunaCentro;
        int maiorComprimento = 0;

        for (int i = 1; i <= n; i++)
        {
            int comprimento = 0;
            for (int j = 1; j <= m; j++)
            {
                cin >> grid[i][j];
                if (grid[i][j] == '#') comprimento++;
            }
            if (comprimento > maiorComprimento)
            { 
                maiorComprimento = comprimento;
                linhaCentro = i;
            }
        }

        if (maiorComprimento > 2)
        {
            int c = 0;
            for (int j = 1; j <= m; j++)
            {
                if (grid[linhaCentro][j] == '#')
                { 
                    c++;
                    if (c > maiorComprimento/2)
                    {
                        colunaCentro = j;
                        break;
                    }
                }
            }
        }
        else
        {
            for (int j = 1; j <= m; j++)
            {
                if (grid[linhaCentro][j] == '#')
                {
                    colunaCentro = j;
                    break;
                }
            }
        }
        cout << linhaCentro << ' ' << colunaCentro << '\n';
    }
}