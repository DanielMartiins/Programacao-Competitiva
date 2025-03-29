//Complexidade O(n + m * log(m))


#include <bits/stdc++.h>
#define pii pair<int,int>

using namespace std;

queue<pii> hurdles;
queue<pii> powerUps;
priority_queue<int> pq; //Power-ups pegos durante o loop da solução
int ans;

void solve() {
    int n,m,L, jumpPower = 1;
    ans = 0;

    cin >> n >> m >> L;

    hurdles = {};
    powerUps = {};
    pq = {};

    for (int i = 0; i < n; i++) {
        int l,r;
        cin >> l >> r;
        hurdles.push({l,r});
    }
    for (int i = 0; i < m; i++){
        int x,v;
        cin >> x >> v;
        powerUps.push({x,v});
    }

    while(!hurdles.empty()) {
        if (!powerUps.empty() && powerUps.front().first < hurdles.front().first) {
            pq.push(powerUps.front().second); // Push da fila de prioridade tem complexidade O(log(n))!
            powerUps.pop();
        }
        else {
            int nextHurdleSize = hurdles.front().second - hurdles.front().first + 1;

            while (jumpPower <= nextHurdleSize && !pq.empty()) {
                jumpPower += pq.top();
                pq.pop();
                ans++;
            }
            if (jumpPower <= nextHurdleSize) break;

            hurdles.pop();
        }
    }
    if (!hurdles.empty()) cout << "-1\n";
    else cout << ans << '\n';
}

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;

    while (t--){
        solve();
    }   
    return 0;
}
