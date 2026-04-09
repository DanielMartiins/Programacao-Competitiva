#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int w, n, total_area = 0;
    cin >> w >> n;

    for (int i = 0; i < n; i++) {
        int wi, li;
        cin >> wi >> li;
        total_area += wi*li;
    }
    cout << total_area/w << "\n";
}