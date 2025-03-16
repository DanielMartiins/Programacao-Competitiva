#include <bits/stdc++.h>
using namespace std;

void solve(int n) {
    pair<int, int> ans = {-1, -1};
    vector<int> prices;
    int m;
    
    for (int i = 0; i < n; i++) {
        int price;
        cin >> price;
        prices.push_back(price);
    }
    cin >> m;
    
    sort(prices.begin(), prices.end());
    for (int i = 0; i < prices.size() - 1; i++) {
        int remaining = m - prices.at(i);

        if ((*lower_bound(prices.begin() + i, prices.end(), remaining)) != remaining) continue;
        else if (ans.first == -1 && ans.second == -1
        || ans.second - ans.first > remaining - prices.at(i)) ans = {prices.at(i), remaining};
    }
    cout << "Peter should buy books whose prices are " << ans.first << " and " << ans.second << ".\n\n";
}

int main(){
    
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    while (cin >> n) solve(n);

    return 0;
}