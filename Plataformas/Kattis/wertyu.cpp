#include <bits/stdc++.h>
using namespace std;

char keyboard[4][13] = {
    {'`', '1','2','3','4', '5', '6', '7', '8', '9', '0', '-', '='},
    {'Q', 'W','E','R','T', 'Y', 'U', 'I', 'O', 'P', '[', ']', '\\'},
    {'A', 'S','D','F','G', 'H', 'J', 'K', 'L', ';', '\'', ' ', ' '},
    {'Z', 'X','C','V','B', 'N', 'M', ',', '.', '/', ' ', ' ', ' '},
};


unordered_map<char, char> correctKey;

void solve(string str) {
    for (auto c : str) {
        if (c == ' ') cout << ' ';
        else
            cout << correctKey[c];
    }
    cout << '\n';
}

int main() {

    for (int i = 0; i < 4; i++) {
        for (int j = 1; j < 13; j++) {
            if (keyboard[i][j] != ' ')
                correctKey.insert({keyboard[i][j], keyboard[i][j-1]});
        }
    }

    string str;
    while (getline(cin, str)) {
        solve(str);
    }
}