//https://neps.academy/exercise/1486
#include <bits/stdc++.h>
using namespace std;

void solve() {
    stack<int> numeros;
    int soma = 0;
    
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;

        if (num != 0) {
            numeros.push(num);
            soma += num;
        }
        else {
            if (!numeros.empty()) {
                soma -= numeros.top();
                numeros.pop();
            }
        }
    }

    cout << soma << "\n";
}

int main() {
    solve();
}