//https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=272

#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;

#define INF INT_MAX

int nc;
int t = 0;
map<int, vector<int>> al; //Lista de adjacencia
map<int, int> dist;

//BFS
int query(int initial_node, int ttl) {

    int ans = 0;

    queue<int> q;

    dist[initial_node] = 0;
    q.push(initial_node);

    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (auto v : al[u]) {
            if (dist.find(v) != dist.end()) continue;
            
            dist[v] = dist[u] + 1;
            q.push(v);
            
            if (dist[v] > ttl) ans++;
        }
    }

    return ans;
}

void solve() {

    for (int i = 0; i < nc; i++) {
        int a,b;
        cin >> a >> b;

        al[a].push_back(b);
        al[b].push_back(a);
    }

    int initial_node, ttl;
    cin >> initial_node >> ttl;
    while (!(initial_node == 0 && ttl == 0)) {
        t++;
        dist.clear();

        // O judge pode fazer uma query para um nó que não existe na rede!
        if (al.find(initial_node) != al.end()) {
            int ans = query(initial_node, ttl);

            //Buscar possíveis redes isoladas
            for (auto it : al) {
                int v = it.first;
                if (dist.find(v) == dist.end()){
                    ans += query(v, -1000000000);
                    ans++; //Contabilizar o nó inicial (v)
                }
            }

            printf("Case %d: %d nodes not reachable from node %d with TTL = %d.\n", t, ans, initial_node, ttl);
        }

        else {
            printf("Case %d: %d nodes not reachable from node %d with TTL = %d.\n", t, al.size(), initial_node, ttl);
        }

        cin >> initial_node >> ttl;
    }
}

int main() {

    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> nc;

    while (nc != 0) {
        al.clear();
        dist.clear();
        solve();
        cin >> nc;
    }
}
