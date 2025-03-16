#include <bits/stdc++.h>

using namespace std;

long long solve(int x, int y)
{
    vector<pair<int,int>> telas;
    int qtdQuadradosY = y*4;

    while (qtdQuadradosY > 0)
    {
        if (qtdQuadradosY >= 8)
        {
            telas.push_back({0, 8});
            qtdQuadradosY -= 8;
        }
        else if (qtdQuadradosY == 4)
        {
            telas.push_back({0, 4});
            qtdQuadradosY -= 4;
        }
    }
    
    int qtdQuadradosX = x;
    if (telas.size() > 0)
    {
        for (int i = 0; i < telas.size(); i++)
        {
            int celulasVazias = 15 - telas.at(i).second;
            if (qtdQuadradosX >= celulasVazias) 
            {
                telas.at(i).first = celulasVazias; 
                qtdQuadradosX -= celulasVazias;
            } 
            else
            { 
                telas.at(i).first = qtdQuadradosX;
                qtdQuadradosX = 0;
                break;
            }
        }
    }
    while (qtdQuadradosX > 0)
    {
        telas.push_back({15,0});
        qtdQuadradosX -= 15;
    }

    return telas.size();
}

int main()
{
    int t;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        int x, y;
        cin >> x >> y;
        cout << solve(x,y) << '\n';
    }
}
