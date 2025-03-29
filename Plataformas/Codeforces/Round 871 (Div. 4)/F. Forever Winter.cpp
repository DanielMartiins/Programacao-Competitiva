//https://codeforces.com/contest/1829/problem/F

#include <bits/stdc++.h>
using namespace std;
#define MAX 201

/*
Percorro o grafo procurando vértices que só tem um vizinho, pois esse vértice
é um vértice y e esse seu único vizinho é um vértice x. Adiciono esse vértice x
em um set "xVertices". A quantidade de vértices x será o tamanho desse set,
e a quantidade de vértices y será a quantidade de vizinhos de um vértice x
qualquer - 1 para desconsiderar o vértice central
*/

int n, m;

void solve(vector<int> graph[]);

int main()
{
    int t;
    cin >> t;

    while(t--)
    {
        cin >> n >> m;
        vector<int> graph[n+1];

        for (int i = 0; i < m; i++)
        {
            int u,v;
            cin >> u >> v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        solve(graph);
    }
}

void solve(vector<int> graph[])
{
    set<int> xVertices;
    int x,y;
    x = y = 0;

    for (int i = 1; i <= n; i++)
    {
        if (graph[i].size() == 1)
            xVertices.insert(graph[i].at(0));
    }

    x = xVertices.size();
    y = graph[(*xVertices.begin())].size() - 1;

    cout << x << ' ' << y << '\n';
}