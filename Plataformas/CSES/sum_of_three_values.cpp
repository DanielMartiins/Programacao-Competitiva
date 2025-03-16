//https://cses.fi/problemset/task/1641
//Solução com two pointers

#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
    int n, x;
    cin >> n >> x;

    vector<pair<int,int>> numeros; // Par <Numero, posição>

    for (int i = 0; i < n; i++)
    {
        int numero;
        cin >> numero;
        
        numeros.push_back({numero, i});
    }
    sort(numeros.begin(), numeros.end());

    for (int i = 0; i < n; i++)
    {
        for (int left = 0, right = n - 1; left < right;)
        {   
            int somaDesejadaLR = x - numeros.at(i).first;
            int somaLR = numeros.at(left).first + numeros.at(right).first;

            if (somaLR == somaDesejadaLR && left != i && right != i)
            {
                cout << numeros.at(left).second + 1 << ' ' 
                        << numeros.at(i).second + 1 << ' '
                        << numeros.at(right).second + 1;
                    return 0;
            }
            else if (somaLR < somaDesejadaLR)
                left++;
            else
                right--;
        }
    }
    cout << "IMPOSSIBLE";
    return 0;
}
