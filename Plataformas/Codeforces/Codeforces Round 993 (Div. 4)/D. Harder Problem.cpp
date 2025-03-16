#include <bits/stdc++.h>
#define vii vector<int>
using namespace std;


void solve() {
    map<int, int> occur;
    map<int, int> occur_a;
    map<int, int> occur_rand;
    int n, max_occurrence = 0, different_numbers = 0;
    cin >> n;
    vii a(n);
    vii b;

    for (int i = 0; i < n; i++) {
        cin >> a.at(i);
        occur_a[a[i]] = 1;
    }
    different_numbers = occur_a.size();

    for (int i = 0; i < n; i++) {
        if (occur.find(a.at(i)) == occur.end()) { 
            b.push_back(a[i]);
            occur[a[i]] = 1;
        }

        else if (occur.size() != different_numbers) {
            random_device rd;
            mt19937 gen(rd());
            uniform_int_distribution<> distrib(1, n);
            
            int randomValue = distrib(gen);
            while(occur_a.find(randomValue) != occur_a.end() 
            || occur_rand.find(randomValue) != occur_rand.end())
                randomValue = distrib(gen);
            
            occur_rand[randomValue] = 1;
            b.push_back(randomValue);
        }

        else {
            occur.clear();
            occur_rand.clear();
            b.push_back(a[i]);
            occur[a[i]] = 1;
        }
    }

    for (int i = 0; i < b.size(); i++) cout << b[i] << ' ';
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--) {
        solve();
    }
}