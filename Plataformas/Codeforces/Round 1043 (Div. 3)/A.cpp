#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        int la, lb;
        string strA, strB, turns;
        cin >> la >> strA;
        cin >> lb >> strB;
        cin >> turns;

        int c = 0;
        for (int i = 0; i < turns.size(); i++) {
            char turn  = turns[i];
            if (turn == 'V') 
                strA = strB[c++] + strA;
            else strA = strA + strB[c++]; 
        }

        cout << strA << "\n";
    }
}