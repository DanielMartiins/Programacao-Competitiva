//https://codeforces.com/contest/1971/problem/B

#include <bits/stdc++.h>
using namespace std;

string str;

void swap(int p1, int p2);
bool solve();

int main()
{
    int t;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        cin >> str;
        if (!solve()) cout << "NO" << '\n';
        else
        {
            cout << "YES" << '\n';
            cout << str << '\n';
        }
    }
}

bool solve()
{
    for (int i = 0; i < str.size(); i++)
        for (int j = i + 1; j < str.size(); j++)
            if (str.at(i) != str.at(j))
            {
                swap(i, j);
                return true;
            }
    return false;
}

void swap(int p1, int p2)
{
    char aux = str.at(p1);
    str.at(p1) = str.at(p2);
    str.at(p2) = aux;
}