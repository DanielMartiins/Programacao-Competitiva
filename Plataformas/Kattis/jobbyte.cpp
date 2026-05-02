#include <bits/stdc++.h>
using namespace std;

#define MAX_N 300002
bool visited[MAX_N];
int connection[MAX_N]; //connection[i] -> node 'i' is connected to which node?

int component_order(int i) {
    if (connection[i] == i) return 1;
    if (visited[i]) return 0; //Cycle graph
    
    visited[i] = true;
    return 1 + component_order(connection[i]);
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++)
        cin >> connection[i];
    
    int ans = 0;
    for (int i = 1; i <= n; i++)
        if (!visited[i]) ans += component_order(i) - 1;
    cout << ans << "\n";
}