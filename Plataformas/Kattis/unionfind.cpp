#include <bits/stdc++.h>
using namespace std;

#define MAX_N 1000001
#define MAX_Q 1000001

int rep[MAX_N];

int find_rep(int i) {
    return rep[i] == i ? i : (rep[i] = find_rep(rep[i]));
}

bool is_same_set(int i, int j) {
    return find_rep(i) == find_rep(j);
}

void union_set(int i, int j) {
    if (is_same_set(i,j)) return;
    int rep_i = find_rep(i);
    int rep_j = find_rep(j);

    rep[rep_i] = rep_j;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n,q;
    cin >> n >> q;

    for (int i = 0; i < MAX_N; i++) rep[i] = i;

    while(q--) {
        char op;
        int a,b;
        cin >> op >> a >> b;
        if (op == '?') 
            cout << (is_same_set(a,b) ? "yes\n" : "no\n");
        else union_set(a,b);
    }
}