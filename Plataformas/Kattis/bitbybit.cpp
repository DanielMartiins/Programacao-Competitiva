#include <bits/stdc++.h>
using namespace std;

bool sure[32];
int bit[32];

void op_clear(int i) {
    bit[i] = 0;
    sure[i] = true;
}

void op_set(int i) {
    bit[i] = 1;
    sure[i] = true;
}

void op_or(int i, int j) {
    if (sure[i] && bit[i] == 0) {
        if (!sure[j]) sure[i] = false;
        else bit[i] |= bit[j];
    } 
    else if (!sure[i] && sure[j] && bit[j] == 1) {
        sure[i] = true;
        bit[i] = 1;
    }
}

void op_and(int i, int j) {
    if (sure[i] && bit[i] == 1) {
        if (sure[j]) bit[i] &= bit[j];
        else sure[i] = false;
    } else if (!sure[i] && sure[j] && bit[j] == 0) {
        sure[i] = true;
        bit[i] = 0;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,i,j;
    string op;
    while(cin >> n && n) {
        memset(sure, false, sizeof(sure));
        while(n--) {
            cin >> op >> i;
            if (op == "CLEAR")
                op_clear(i);
            else if (op == "SET")
                op_set(i);
            else {
                cin >> j;
                if (op == "OR") op_or(i,j);
                else op_and(i,j);
            }
        }

        for (int i = 31; i >= 0; i--)
            if (sure[i]) cout << bit[i];
            else cout << "?";
        cout << "\n";
    }
}