#include <bits/stdc++.h>
using namespace std;

#define MAX_N 100002
#define MAX_C 1000002

int pref[MAX_N];
int rsq[MAX_N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, c;
    scanf("%d %d", &n, &c);

    int s, e;
    s = e = 1;

    for (int i = 1; i <= n; i++) {
        scanf("%d", &pref[i]);
        pref[i] += pref[i-1];
    }

    while (s <= n) {
        rsq[s]++;
        rsq[e+1]--;
        if (e+1 > n) s++;
        else if (pref[e+1] - pref[s-1] > c) s++;
        else e++;
    }

    int sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += rsq[i];
        cout << sum << "\n";
    }
}