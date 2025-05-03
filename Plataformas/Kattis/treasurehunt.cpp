
#include <bits/stdc++.h>
using namespace std;

struct position {
    int i;
    int j;
};

int main() {
    int r,c;
    cin >> r >> c;
    char area[r][c];
    for (int i = 0; i < r; i++) {
        string line;
        cin >> line;
        for (int j = 0; j < c; j++) area[i][j] = line.at(j);
    }

    position pos = {0,0};
    bool hasFound = false;
    int ans = 0;
    while(!hasFound) {
        
        if (pos.i == r || pos.j == c || pos.i < 0 || pos.j < 0){
            cout << "Out\n";
            return 0;
        }
        
        char move = area[pos.i][pos.j];
        if (move == 'E') pos.j++;
        else if (move == 'W') pos.j++;
        else if (move == 'N') pos.i++;
        else if (move == 'S') pos.i--;
        else hasFound = true;

        ans++;
        if (ans > r * c * 2) {
            cout << "Lost\n";
            return 0;
        }

    }
    cout << ans << "\n";
}
