#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;
        vector<pair<int, int>> a(n), b(n), c(n);
        for (int i = 0; i < n; i++) {cin >> a[i].first; a[i].second = i;}
        for (int i = 0; i < n; i++) {cin >> b[i].first; b[i].second = i;};
        for (int i = 0; i < n; i++) {cin >> c[i].first; c[i].second = i;};

        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        sort(c.begin(), c.end());

        int a_pointer, b_pointer, c_pointer;
        a_pointer = b_pointer = c_pointer = n - 1;
        priority_queue<int> possibilities;
        

        int sum = 0;
        for(int i = 0; i < 3; i++) {
            sum = a[a_pointer].first;
            for (int j = 0; j < 3; j++) {
                    sum += b[b_pointer - (b[b_pointer].second == a[a_pointer].second)].first;
                for(int k = 0; k < 3; k++) {
                }
            }
        }


        cout << "a";
    }
}