#include <vector>
#include <iostream>
#include <map>
#include <set>
#include <random>


#define vii vector<int>
using namespace std;


void solve() {
    set<int> occur;
    set<int> occur_a;
    set<int> occur_rand;
    int n, max_occurrence = 0, different_numbers = 0;
    cin >> n;
    vii a(n);

    for (int i = 0; i < n; i++) {
        cin >> a.at(i);
        occur_a.insert(a[i]);
    }
    different_numbers = occur_a.size();

    for (int i = 0; i < n; i++) {
        if (occur.find(a.at(i)) == occur.end()) { 
            cout << a[i];
            occur.insert(a[i]);
        }

        else if (occur.size() != different_numbers) {
            random_device rd;
            mt19937 gen(rd());
            uniform_int_distribution<> distrib(1, n);
            
            int randomValue = distrib(gen);
            while(occur_a.find(randomValue) != occur_a.end() 
            || occur_rand.find(randomValue) != occur_rand.end())
                randomValue = distrib(gen);
            
            occur_rand.insert(randomValue);
            cout << randomValue;
        }

        else {
            occur.clear();
            occur_rand.clear();
            cout << a[i];
            occur.insert(a[i]);
        }
        cout << ' ';
    }
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