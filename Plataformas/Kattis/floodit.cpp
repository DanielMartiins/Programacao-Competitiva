#include <bits/stdc++.h>
using namespace std;

//Directions: South, East, North, West
int dc[4] = {0, 1, 0, -1}; //Direction Column 
int dr[4] = {1, 0, -1, 0}; //Direction row


char board[10][10];
bool visited[10][10];
vector<int> timesChosen = {0,0,0,0,0,0};
int n;

int floodfill(int r, int c, char current_color, char new_color) {
    if (r < 0 || r >= n) return 0;
    if (c < 0 || c >= n) return 0;
    if (board[r][c] != current_color && board[r][c] != new_color) return 0;
    int ans = 1;
    visited[r][c] = true;
    for (int d = 0; d < 4; d++) {
        if (!visited)
            ans += floodfill(r+dr[d], c+dc[d], current_color, new_color);
    }
    return ans;
}

// Number of new tiles for a new color
int connectedTiles(char current_color, char new_color) {

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            visited[i][j] = false;

    return floodfill(0, 0, current_color, new_color);    
}

void solve() {

    
    vector<int> newConnections = {0,0,0,0,0,0}; // i-th element = number of new tiles we'll have 
    for (int i = 0; i < 6; i++)
        newConnections[i] = connectedTiles(board[0][0], i+1);

    
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++) 
                cin >> board[i][j];
        solve();
    }
}