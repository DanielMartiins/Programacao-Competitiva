#include <bits/stdc++.h>
using namespace std;
string a,b;

void swap(int ax, int bx) {
    char char_a = a[ax], char_b = b[bx];
    a[ax] = char_b;
    b[bx] = char_a;
}

void solve() {
    
    int n;
    cin >> n;
    cin >> a >> b;

    for (int i = 0; i < n; i++) {
        if (a[i] == '1') {
            if (i > 0 && b[i-1] == '0') swap(i, i-1);
            else if (i < n - 1 && b[i+1] == '0') swap(i, i+1);
            else { cout << "NO\n"; return;}
        }
    }
    cout << "YES\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}