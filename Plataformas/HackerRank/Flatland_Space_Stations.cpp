#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    int answer = 0;
    cin >> n >> m;
    bool is_station[n];
    memset(is_station, false, sizeof(is_station));

    for (int i = 0; i < m; i++) {
        int station;
        cin >> station;
        is_station[station] = true;
    }

    if (n == m) {
        cout << "0\n"; 
        return 0;
    }
    else if (m == 1) {
        int idx_station;
        for (int i = 0; i < n; i++) { 
            if (is_station[i]) {
                idx_station = i;
                break;
            }
        }
        answer = max(idx_station, (n- 1) - idx_station );
        cout << answer << "\n"; 
        return 0;
    }

    int l, r;
    for (l = 0, r = 1; r < n; r++) {
        if (is_station[r]) {
            if (is_station[l]) 
                answer = max(answer, (r - l) / 2);
            else answer = max(answer, r - l);
            l = r;
        }
    }
    r--;
    if (is_station[l] && !is_station[r])
        answer = max(answer, r - l);
    cout << answer << "\n";

}