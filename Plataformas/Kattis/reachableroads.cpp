#include <bits/stdc++.h>
using namespace std;

class UnionFind {

    private:
        vector<int> p, setSize;
        int numSets;

    public:
        UnionFind(int n) {
            p.assign(n,0); 
            for(int i = 0; i < n; i++) p[i] = i;
            setSize.assign(n, 1);
            numSets = n;
        }

        int findSet(int i) {
            return (p[i] == i) ? i : (p[i] = findSet(p[i]));
        }

        bool isSameSet(int i, int j) {
            return findSet(i) == findSet(j);
        }

        int numDisjointSets() { return numSets;}

        int sizeOfSet(int i) {
            return setSize[findSet(i)];
        }

        void unionSet(int i, int j) {
            if (isSameSet(i, j)) return;

            int rep_i = findSet(i), rep_j = findSet(j);
            p[rep_i] = rep_j;
            setSize[rep_j] += setSize[rep_i];
            --numSets;
        }

        int solve(){
            return numSets - 1;
        }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int m,r;
        cin >> m >> r;

        UnionFind uf(m);
        while(r--) {
            int e1, e2;
            cin >> e1 >> e2;
            uf.unionSet(e1, e2);
        }
        cout << uf.solve() << "\n";
    }
}