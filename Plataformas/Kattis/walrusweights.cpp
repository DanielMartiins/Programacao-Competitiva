#include <bits/stdc++.h>
using namespace std;
#define MAX_N 1001
#define MAX_TARGET 2001

int n;
int weights[MAX_N];
int build[MAX_N][MAX_TARGET]; //[index][target_weight]

void initialize_memo_table() {
    for (int i = 0; i <= n; i++) {
        for(int t = 0; t < MAX_TARGET; t++) { 
            if (i == n && t != 0) build[i][t] = false;
            else if (t == 0) build[i][t] = true;
            else build[i][t] = -1;
        }
    }
}

bool dp(int index, int target) {

    if (target < 0) return false;
    if (index == n) {
        if (target != 0) return false;
        else return true;
    }
    
    if (build[index][target] != -1) return build[index][target];

    else {
        build[index+1][target] = dp(index+1, target);
        build[index+1][target - weights[index]] = dp(index+1, target - weights[index]);

        return build[index+1][target] || build[index+1][target-weights[index]];
    }
}

void solve() {
    initialize_memo_table();
    int delta = 0;

    while(delta <= 1000) {
        if (dp(0, (1000+delta))) {
            cout << 1000+delta << "\n";
            return;
        } else if (dp(0, (1000-delta))) {
            cout << 1000-delta << "\n";
            return;
        }
        delta++;
    }

}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> weights[i];

    solve();
}
