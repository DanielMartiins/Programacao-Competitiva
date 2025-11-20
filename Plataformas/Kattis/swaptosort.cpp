#include <bits/stdc++.h>
using namespace std;

#define MAX_N 1000001
int uf[MAX_N];

int findSet(int i) {
    if (uf[i] != i) return uf[i] = findSet(uf[i]);
    return i;
}

bool isSameSet(int i, int j) {
    int rep_i = findSet(uf[i]);
    int rep_j = findSet(uf[j]);
    
    return rep_i == rep_j;
}

void unionSet(int i, int j) {
    int rep_i = findSet(uf[i]);
    int rep_j = findSet(uf[j]);

    if (rep_i != rep_j) uf[rep_i] = rep_j;
}


int main() {


    ios::sync_with_stdio(false);
    cin.tie(0);

    int n,k;
    cin >> n >> k;

    for (int i = 0; i < MAX_N; i++) uf[i] = i;

    for (int i = 0; i < k; i++) {
        int ai, bi;
        cin >> ai >> bi;

        unionSet(ai, bi);
    }

    for (int i = 1; i <= n; i++) {
        if (!isSameSet(i, n-i+1)) {
            cout << "No\n";
            return 0;
        }
    }
    cout << "Yes\n";
}