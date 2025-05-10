#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    string strA, strB;
    bool ehAnagrama = true;
    unordered_map<char, int> ocorrenciasA;
    unordered_map<char, int> ocorrenciasB;
    
    cin >> n;
    cin.ignore();
    getline(cin, strA);
    getline(cin, strB);

    for (auto c : strA) if (c >= 'a' && c <= 'z') ocorrenciasA[c]++;
    for (auto c : strB) if (c >= 'a' && c <= 'z') ocorrenciasB[c]++;

    //Acredito que sem esse if da próxima linha deveria dar Wrong Answer, mas dá Accepted.
    //Por exemplo, sem esse condicional, para N = 5 e A = "a    " e B = "abcde" vai dar que é um anagrama, mas não é.
    if (ocorrenciasA.size() != ocorrenciasB.size()) ehAnagrama = false; 
    else {
        for (auto occ : ocorrenciasA)
            if (ocorrenciasB[occ.first] != occ.second) ehAnagrama = false;
    }
    cout << (ehAnagrama ? "S\n" : "N\n");
}