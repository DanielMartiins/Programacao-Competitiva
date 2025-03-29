#include <bits/stdc++.h>
using namespace std;
string strA, strB;
//O(N)

/* A counter for the number of '1's(-1 if in array a) and '0's(+1 if in array b) 
in a string represented by {a[0] + b[1] + a[0] + ...}*/
int c1;

/* A counter for the number of '1's(-1 if in array a) and '0's(+1 if in array b) 
in a string represented by {b[0] + a[1] + b[0] + ...}*/
int c2;

void solve() {
    
    int n;
    c1 = 0,c2 = 0;
    cin >> n;
    cin >> strA >> strB;

    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            if (strA[i] == '1') c1--;
            if (strB[i] == '0') c2++;
        } else {
            if (strA[i] == '1') c2--;
            if (strB[i] == '0') c1++;
        }
    }

    if (c1 >= 0 && c2 >= 0) cout << "YES\n";
    else cout << "NO\n";
}

int main() {

    cin.tie(0);
    ios::sync_with_stdio(false);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}