#include <bits/stdc++.h>
using namespace std;

bool bsearch (vector<int> prices, int n, int i, int x) {
    int l = i + 1, r = n - 1, mid;

    while (l <= r) {
        mid = (l+r)/2;
        if (prices.at(mid) < x) l = mid + 1;
        else if (prices.at(mid) > x) r = mid - 1;
        else return true;
    }

    return false;
}

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

        if (!bsearch(prices, n, i, remaining)) continue;
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