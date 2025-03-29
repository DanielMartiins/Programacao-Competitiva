//https://codeforces.com/contest/1971/problem/D

#include <bits/stdc++.h>
using namespace std;

int solve(string s);

int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        string s;
        cin >> s;
        cout << solve(s) << '\n';
    }
}

int solve(string s)
{
    int res = 1;
    bool tem01 = 0;

    for (int i = 1; i < s.size(); i++)
    {
        if (s.at(i-1) != s.at(i)) res++;
        if (s.at(i-1) == '0' && s.at(i) == '1') tem01 = 1;
    }

    return res - tem01;
}