#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, y;
    map<int, bool> hasFound;
    int x = 0;

    cin >> n >> y;

    
    for (int i = 0; i < n; i++) hasFound[i] = false;
    for (int i = 0; i < y; i++) {
        int obstacle;
        cin >> obstacle;
        if (!hasFound[obstacle]) x++;
        hasFound[obstacle] = true;
    }
    for (int i = 0; i < n; i++) if (!hasFound[i]) cout << i << "\n";
    printf("Mario got %d of the dangerous obstacles.\n", x);
}