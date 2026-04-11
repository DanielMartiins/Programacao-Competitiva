#include <bits/stdc++.h>
using namespace std;

#define MAX_N 202
#define MAX_K 202

#define INVALID -80000

#define CLOSED_LEFT 0
#define CLOSED_RIGHT 1
#define NOT_CLOSED 2 

#define UNSOLVED -1

int gallery[MAX_N][2];  
int memo[MAX_N][3][MAX_K];
int n,k;

int dp(int row, int decision, int remaining) {

    if (remaining < 0) return INVALID;
    if (row == n) return remaining == 0 ? 0 : INVALID;

    if (memo[row][decision][remaining] == UNSOLVED) {
        int value_l = gallery[row][0];
        int value_r = gallery[row][1];
        int both    = value_l + value_r;

        int dp_closing_left
            = decision != CLOSED_RIGHT ? value_r + dp(row+1, CLOSED_LEFT, remaining-1) : INVALID;
        
        int dp_closing_right
            = decision != CLOSED_LEFT ? value_l + dp(row+1, CLOSED_RIGHT, remaining-1) : INVALID;

        int dp_not_closing
            = both + dp(row+1, NOT_CLOSED, remaining);
        
        memo[row][decision][remaining] = max({  dp_closing_left, 
                                                dp_closing_right, 
                                                dp_not_closing
                                            });
    }
    return memo[row][decision][remaining];

}

int main() {
    cin >> n >> k;
    while(!(n == 0 && k == 0)) {
        memset(memo, UNSOLVED, sizeof(memo));
        for(int i = 0; i < n; i++)
            cin >> gallery[i][0] >> gallery[i][1];
        cout << dp(0,NOT_CLOSED,k) << "\n";
        cin >> n >> k;
    }
}