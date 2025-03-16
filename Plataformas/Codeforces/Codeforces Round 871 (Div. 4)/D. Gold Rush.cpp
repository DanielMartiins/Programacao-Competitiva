#include <bits/stdc++.h>
#define MAX 10000002
using namespace std;

bool calculado[MAX];
int t, n, m;
map<int, pair<int,int>> dp;
//vector<int> tamanhoPilhas;

bool calculaPilhas(int n)
{
    //cout << n << '\n';
    if(n == m)
        return true;
    if(n <= 2) return false;
    if(calculado[n])
    {
        return calculaPilhas(dp[n].first) || calculaPilhas(dp[n].second);
    }
    calculado[n] = true;
    for(int i = 1; i < n; i++)
    {
        if(i * 2 == (n - i))
        {
            dp.insert({n, {i, n - i}});
            return calculaPilhas(i) || calculaPilhas(n - i);
        }
    }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    cin >> t;
    while(t--)
    {
        cin >> n >> m;
        if(m > n)
        {
            cout << "NO\n";
            continue;
        }
        else if(n == m)
        {
            cout << "YES\n";
            continue;
        }
        if(calculaPilhas(n))
            cout << "YES\n";
        else
            cout << "NO\n"; 
            
    } 
}