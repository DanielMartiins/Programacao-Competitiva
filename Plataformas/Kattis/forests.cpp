// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;

#define MAX_P 101
#define MAX_T 101


set<int> opinions[MAX_P];

int rep[MAX_P];
int num_sets = -1; //To be initialized by initialize_ufs()

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
    num_sets--;

    rep[rep_i] = rep_j;
}

void initialize_ufs(int p) {
    num_sets = p;
    for (int i = 1; i < MAX_P; i++) rep[i] = i;
}

int main() {
    int p,t;
    cin >> p >> t;
    initialize_ufs(p);

    int i,j;
    while(cin >> i >> j) {
        opinions[i].insert(j);
    }

    for (int i = 1; i < p; i++) {
        for (int j = i+1; j <= p; j++) {
            if (opinions[i] == opinions[j]) union_set(i,j);
        }
    }

    cout << num_sets;
}
