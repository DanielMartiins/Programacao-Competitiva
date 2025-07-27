#include <bits/stdc++.h>
using namespace std;

unordered_map<int, int> ways_to_sum;

int main() {
    int m;
    cin >> m;

    for (int i = 0; i*i*i <= m; i++) {
        for (int j = 0; j*j*j <= m; j++) {
            int i_cube = i*i*i;
            int j_cube = j*j*j;
            ways_to_sum[i_cube + j_cube]++; 
        }
    }

    for (int x = m; x >= 1; x--) {
        if (ways_to_sum[x] >= 4) {
            cout << x << "\n";
            return 0;
        }
    }
    cout << "none\n";
}