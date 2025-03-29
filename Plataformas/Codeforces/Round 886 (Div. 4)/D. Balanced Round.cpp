#include <bits/stdc++.h>
using namespace std;

void solve(vector<long long> difficulties, long long k);

int main()
{
    int t;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        vector<long long> difficulties;
        long long n, k;
        cin >> n >> k;

        for (int j = 0; j < n; j++)
        {
            long long difficulty;
            cin >> difficulty;
            difficulties.push_back(difficulty);
        }
        sort(difficulties.begin(), difficulties.end());
        solve(difficulties,k);
    }
}

void solve(vector<long long> difficulties, long long k)
{
    long long ans;
    long long maxTam = 0;

    int i = 1;
    bool entrou = false;
    while (i < difficulties.size())
    {
        entrou = false;
        int tamSubarray = 1;
        for (; i < difficulties.size(); i++)
        {
            entrou = true;
            if (difficulties.at(i) - difficulties.at(i-1) <= k) tamSubarray += 1;
            else break;
        }
        if (entrou && tamSubarray > maxTam) maxTam = tamSubarray;
        i++;
    }
    if (difficulties.size() == 1) ans = 0;
    else ans = difficulties.size() - maxTam;
    cout << ans << '\n';
}