#include <bits/stdc++.h>
using namespace std;
bool table[3] = {true, false, false};

void swap(int i, int j) {
    bool temp = table[i];
    table[i] = table[j];
    table[j] = temp;
}

void solve() {
    string moves;
    cin >> moves;

    for (auto m : moves) {
        if (m == 'A') swap(0,1);
        else if (m == 'B') swap(1,2);
        else swap(0,2);
    }

    for (int i = 0; i < 3; i++) {
        if (table[i]) cout << i + 1 << "\n";
    }
}

int main() {
    solve();
}