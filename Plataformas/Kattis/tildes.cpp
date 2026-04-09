
#include <bits/stdc++.h>
using namespace std;

#define MAX_N 1000001

int rep[MAX_N];
int size_uf[MAX_N];

int find_rep(int i) {
    return rep[i] == i ? i : (rep[i] = find_rep(rep[i]));
}

bool same_set(int i, int j) {
    return find_rep(i) == find_rep(j);    
}

void union_set(int i, int j) {
    if (same_set(i,j)) return;
    int rep_i = find_rep(i);
    int rep_j = find_rep(j);

    rep[rep_i] = rep_j;
    size_uf[rep_j] += size_uf[rep_i];
}

void initialize() {
    for(int i = 0; i < MAX_N; i++) {
        rep[i] = i;
        size_uf[i] = 1; 
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    initialize();
    int n,q;
    cin >> n >> q;

    while(q--) {
        char op;
        int a,b;
        cin >> op >> a;
        if (op == 't') {
            cin >> b;
            union_set(a,b);
        }
        else cout << size_uf[(find_rep(a))] << "\n";
    }
}
