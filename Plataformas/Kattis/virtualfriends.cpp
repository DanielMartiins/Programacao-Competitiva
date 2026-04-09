// Virtual Friends

#include <bits/stdc++.h>
using namespace std;

class UnionFind {
    private:
        map<string, string> p;
        map<string, long long> rank; 
        map<string, long long> setSize;
        long long numSets;
    public:
        UnionFind(long long N) {
            //rank.assign(N, 0);
            //setSize.assign(N,1);
            numSets = N;
        }

        string findSet(string i) { 
            if (p.find(i) == p.end()) {
                p[i] = i;
                setSize[i] = 1;
                rank[i] = 0;
            }
            return (p[i] == i) ? i : (p[i] = findSet(p[i])); 
        }
        bool isSameSet(string i, string j) { return findSet(i) == findSet(j);}
        long long numDisjointSets() { return numSets; }
        long long sizeOfSet(string i) { return setSize[findSet(i)]; }

        void unionSet(string i, string j) {
            if (isSameSet(i, j)) return;
            string x = findSet(i), y = findSet(j);
            if (rank[x] > rank[y]) swap(x, y);
            p[x] = y;
            if (rank[x] == rank[y]) ++rank[y];
            setSize[y] += setSize[x];
            --numSets;
        }
};


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        long long f;
        cin >> f;
        UnionFind uf(f);

        while(f--) {
            string i, j;
            cin >> i >> j;

            uf.unionSet(i,j);
            cout << uf.sizeOfSet(i) << "\n";
        }
    }
}
