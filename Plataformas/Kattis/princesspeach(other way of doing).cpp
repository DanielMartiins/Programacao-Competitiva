#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, y;
    set<int> foundObstacles;

    cin >> n >> y;
    for (int i = 0; i < y; i++) {
        int obstacle;
        cin >> obstacle;
        foundObstacles.insert(obstacle);
    }
    for (int i = 0; i < n; i++) 
        if (foundObstacles.find(i) == foundObstacles.end()) cout << i << "\n";
    printf("Mario got %d of the dangerous obstacles.\n", foundObstacles.size());
}