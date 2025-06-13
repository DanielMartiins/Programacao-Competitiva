// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;

#define MAX_N 1000
#define MAX_G 100

int n, p, g;
vector<pair<int,int>> objects(MAX_N); //first = Price ; second = Weight

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> objects[i].first >> objects[i].second;
    }

    
}

int main() {
    int t;
    cin >> t;

    while(t--)
        solve();

}
