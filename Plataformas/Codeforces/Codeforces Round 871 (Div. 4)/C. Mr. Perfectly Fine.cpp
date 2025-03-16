//https://codeforces.com/contest/1829/problem/C

#include <bits/stdc++.h>
using namespace std;
#define INF 3000001
map<string, long long> skillTime;

void solve();

int main()
{
    int t;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        int n;
        cin >> n;
        skillTime["01"] = INF;
        skillTime["10"] = INF;
        skillTime["11"] = INF;

        for (int j = 0; j < n; j++)
        {
            long long time;
            string binStr;
            cin >> time >> binStr;
            skillTime[binStr] = min(time, skillTime[binStr]);
        }
        solve();
    }
}

void solve()
{
    if ((skillTime["01"] == INF || skillTime["10"] == INF) && skillTime["11"] == INF)
        cout << "-1\n";
    else
    {
        long long ans = min(skillTime["01"] + skillTime["10"], skillTime["11"]);
        cout << ans << '\n';
    }
}