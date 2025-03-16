#include <bits/stdc++.h>
using namespace std;

set<pair<pair<int,int>,int>> responses = {}; //first.first = quality, first.second = nWords, second = nParticipant

void solve();

int main()
{
    int t;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        responses = {};
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            int a, b;
            cin >> a >> b;
            responses.insert({{b,a}, i});
        }       
        solve();
    }
}

void solve()
{
    int ans;
    for (auto &r : responses)
    {
        if (r.first.second <= 10)
            ans = r.second;
    }
    cout << ans << '\n';
}