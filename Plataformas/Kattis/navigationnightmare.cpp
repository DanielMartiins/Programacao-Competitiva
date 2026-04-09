
#include <bits/stdc++.h>
using namespace std;

int main() {
    string str;
    cin >> str;

    for (auto c : str) {
        if (c == 'B') cout << "(ooo)";
        else cout << c;
    }
    cout << "\n";
}
