#include <bits/stdc++.h>
using namespace std;

#define MAX_N 100
#define MAX_X 1000005
#define INF INT32_MAX

int coins[MAX_N];
int memo[MAX_X];
int n, x;

int optimal(int sum) {
    if (sum <= 0) return 0;
    if (memo[sum] != -1) return memo[sum];

    memo[sum] = INF;
    for (int i = 0; i < n; i++) {
        if (sum - coins[i] >= 0) {
            int dp_recursion = optimal(sum-coins[i]) + 1;
            if (dp_recursion >= 0) //Else: the sum caused overflow
            memo[sum] = min(memo[sum], dp_recursion);
        }
    }

    return memo[sum];
}

int main() {
    memset(memo, -1, sizeof(memo));
    cin >> n >> x;
    memo[0] = 0;
    
    for(int i = 0; i < n; i++) cin >> coins[i];
    int ans = optimal(x);
    if (ans == INF) printf("-1\n");
    else printf("%d\n", ans);
}