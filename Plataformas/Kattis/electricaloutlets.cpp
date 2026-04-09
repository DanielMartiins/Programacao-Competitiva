// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    while(n--) {
        int answer = 0;
        int k;
        cin >> k;

        while(k--) {
            int outlets;
            cin >> outlets;
            answer += outlets - 1;
        }

        cout << answer + 1 << "\n";
    }
}
