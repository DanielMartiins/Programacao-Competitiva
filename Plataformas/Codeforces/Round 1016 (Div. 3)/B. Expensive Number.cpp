#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        string n;
        cin >> n;
        int index_sobra = 0;
        int ans = 0;
        for (int i = n.size() - 1; i >= 0; i--) {
            if (n.at(i) != '0') { 
                index_sobra = i; 
                break;
            }
        }

        for (int i = index_sobra - 1; i >= 0; i--) 
            if (n.at(i) != '0') ans++;

        ans += n.size() - 1 - index_sobra;

        cout << ans << "\n";
    }
}