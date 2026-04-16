#include <bits/stdc++.h>
using namespace std;

int main() {
    int h1, m1, s1;
    while(scanf("%d : %d : %d", &h1, &m1, &s1) != EOF) {
        int h2, m2, s2;
        scanf("%d : %d : %d", &h2, &m2, &s2);

        int time1_sec = (h1 * 3600) + (m1 * 60) + s1;
        int time2_sec = (h2 * 3600) + (m2 * 60) + s2;

        int ans;
        if (time2_sec >= time1_sec)
            ans = time2_sec - time1_sec;
        else
            ans = (24*3600 - time1_sec) + time2_sec;
        cout << ans << "\n";
    }
}