#include <bits/stdc++.h>
using namespace std;

void solve(string s);

int main()
{
    int t;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        int n;
        string s;

        cin >> n;
        cin >> s;    

        solve(s);
    }
}

void solve(string s)
{
    bool passou = false;
    pair<int,int> coords = {0,0};

    for (int i = 0; i < s.size(); i++)
    {
        if (s.at(i) == 'L') coords.first--;
        else if (s.at(i) == 'R') coords.first++;
        else if (s.at(i) == 'U') coords.second++;
        else if (s.at(i) == 'D') coords.second--;

        if (coords.first == 1 && coords.second == 1)
        {
            passou = true;
            break;
        }
    }

    if (passou) cout << "YES" << '\n';
    else cout << "NO" << '\n';
}