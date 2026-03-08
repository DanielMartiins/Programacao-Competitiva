#include <bits/stdc++.h>
using namespace std;

#define MAX_M 41
#define MAX_H 1001
#define NOT_CALC -1
#define INF 9999

#define UP 'U'
#define DOWN 'D'

int m;
int dist[MAX_M]; // dist[k] = distance of the 'k' jump
int memo[MAX_M][MAX_H];
char best_decision[MAX_M][MAX_H];

int dp(int k, int h) {
    if (k == m || h < 0) 
        return (h == 0 ? 0 : INF);

    if (memo[k][h] != NOT_CALC) return memo[k][h];
    else {
        int up_dp = dp(k+1, h+dist[k]);
        int down_dp = dp(k+1, h-dist[k]);

        if (up_dp < down_dp) //then going up is the best decision
            best_decision[k][h] = UP;
        else //then going down is the best decision
            best_decision[k][h] = DOWN;
        
        return memo[k][h] = max(h, min(up_dp, down_dp));
    }
}

void print_valid_answer() {
    int h = 0;
    for (int k = 0; k < m; k++) {
        cout << best_decision[k][h];
        if (best_decision[k][h] == UP) h += dist[k];
        else h -= dist[k];
    }
    cout << "\n";
}

int main() {

    cin.tie(0);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    while(n--) {
        memset(memo, NOT_CALC, sizeof(memo));
        cin >> m;
        for (int i = 0; i < m; i++) {
            cin >> dist[i];
        }
        if (dp(0,0) == INF) cout << "IMPOSSIBLE\n";
        else print_valid_answer(); 
    }
}