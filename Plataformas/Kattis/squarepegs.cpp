//https://open.kattis.com/problems/squarepegs

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, k;
    int ans = 0;
    cin >> n >> m >> k;

    vector<float> plots; //Stored and sorted by diameter
    vector<float> houses; //Stored and sorted by diameter
    for (int i = 0; i < n; i++) {
        float p;
        cin >> p;
        plots.push_back(2*p);
    }

    for (int i = 0; i < m; i++) {
        float h;
        cin >> h;
        houses.push_back(2*h);
    }

    for (int i = 0; i < k; i++) {
        float side, diameter;
        cin >> side;
        
        diameter = side * (float)sqrt(2);
        houses.push_back(diameter);
    }

    sort(plots.begin(), plots.end());
    sort(houses.begin(), houses.end());

    for (int p = 0, h = 0; p < plots.size() && h < houses.size();) {
        if (plots.at(p) > houses.at(h)) {
            h++;
            ans++;
        }
        p++;
    }

    cout << ans << '\n';
}