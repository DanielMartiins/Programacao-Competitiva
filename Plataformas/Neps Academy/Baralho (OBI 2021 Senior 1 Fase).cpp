//https://neps.academy/exercise/1489
#include <bits/stdc++.h>
using namespace std;

map<char,set<string>> naipe_cartas;
map<char,bool> tem_repetida = {
    {'C', false}, 
    {'E', false}, 
    {'U', false}, 
    {'P', false}    
};

void solve() {
    char naipes[4] = {'C', 'E', 'U', 'P'};
    string str;
    cin >> str;

    for (int i = 0; i < str.size(); i += 3) {
        string carta = str.substr(i,3);
        char naipe = str[i+2];

        if (naipe_cartas[naipe].find(carta) != naipe_cartas[naipe].end())
            tem_repetida[naipe] = true;

        naipe_cartas[naipe].insert(carta);
    }

    for (auto naipe : naipes) {
        if (tem_repetida[naipe])
            cout << "erro\n";
        else
            cout << 13 - naipe_cartas[naipe].size() << "\n";
    }
}

int main() {
    solve();
}
