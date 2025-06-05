//https://neps.academy/exercise/1481

#include <bits/stdc++.h>
using namespace std;

void solve() {
    int vitorias = 0;
    for (int i = 0; i < 6; i++) {
        char resultado;
        cin >> resultado;
        if (resultado == 'V') vitorias++;
    }

    if (vitorias >= 5) cout << "1\n";
    else if (vitorias >= 3) cout << "2\n";
    else if (vitorias >= 1) cout << "3\n";
    else cout << "-1\n";
}

int main() {
    solve();
}