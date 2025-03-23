//https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=351

#include <bits/stdc++.h>
using namespace std;

int c,s, test = 0;

void solve() {
    test++;
    vector<vector<int>> chambers(c);
    vector<int> specimens;
    double sum_of_all_masses = 0;
    double imbalance = 0;
    double average_mass;

    for (int i = 0; i < s; i++) {
        int s;
        cin >> s;
        specimens.push_back(s);
        sum_of_all_masses += s;
    }
    average_mass = sum_of_all_masses/c;

    while (specimens.size() < 2*c) specimens.push_back(0);
    sort(specimens.begin(), specimens.end());

    for (int i = 0, r = (2*c) - 1; i < r; i++, r--) {
        if (specimens[i] > 0) chambers[i].push_back(specimens[i]);
        chambers[i].push_back(specimens[r]);
        
        imbalance += abs((specimens[i] + specimens[r]) - average_mass); 
    }

    cout << "Set #" << test << "\n";
    for (int i = 0; i < c; i++) {
        cout << " " << i << ":";
        for (int j = 0; j < chambers[i].size(); j++) {
            if (chambers[i][j]) cout << ' ' << chambers[i][j];
        }
        cout << "\n";
    }
    printf("IMBALANCE = %.5lf\n\n", imbalance);
}

int main() {

    while(cin >> c >> s) {
        solve();
    }
}