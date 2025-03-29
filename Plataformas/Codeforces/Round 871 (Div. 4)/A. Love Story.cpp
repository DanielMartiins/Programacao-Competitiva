#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        string s;
        string s2 = "codeforces";
        cin >> s;
        int count = 0;

        for (int i = 0; i < 10; i++)
            if (s.at(i) != s2.at(i)) count++;
        
        cout << count << '\n';
    }
}