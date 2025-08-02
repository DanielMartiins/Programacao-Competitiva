#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    int tempo_para_processar[n+1];
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> funcionarios; //pair<tempo_acumulado, id>
    
    for (int i = 1; i <= n; i++){ 
        cin >> tempo_para_processar[i];
        funcionarios.push({0, i});
    }

    for (int i = 0; i < m; i++) {
        
        int tempo_acumulado = funcionarios.top().first;
        int id_func = funcionarios.top().second;
        int v = tempo_para_processar[id_func];
        int c;
        cin >> c; 
        
        funcionarios.pop();
        funcionarios.push({tempo_acumulado + (v*c), id_func});
    }

    int ans = 0;
    while (!funcionarios.empty()) {
        ans = funcionarios.top().first;
        funcionarios.pop();
    }

    printf("%d\n", ans);
}