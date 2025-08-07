#include <bits/stdc++.h>
using namespace std;

#define MAX_N 251
#define MAX_M 50
#define NOT_CALCULATED -1

int n, m;
long long memo[MAX_M][MAX_N];
int coin[MAX_M];

long long count(int i, int remaining) {
    if (remaining == 0) return 1;
    if (remaining < 0 || i == m) return 0;
    
    if (memo[i][remaining] != NOT_CALCULATED)
        return memo[i][remaining];

    return memo[i][remaining] =   count(i,   remaining - coin[i])
                                + count(i+1, remaining);
}

int main() {
    memset(memo, NOT_CALCULATED, sizeof(memo));
    cin >> n >> m;

    for (int i = 0; i < m; i++)
        cin >> coin[i];

    cout << count(0, n) << "\n";
}