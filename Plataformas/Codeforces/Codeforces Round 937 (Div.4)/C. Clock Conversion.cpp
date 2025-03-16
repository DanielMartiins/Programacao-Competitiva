#include <bits/stdc++.h>
using namespace std;

void solve(string s);

int main()
{
    int t;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        string s;
        cin >> s;
        solve(s);
    }
}

void solve(string s)
{
    int hr, min;
    hr = stoi(s.substr(0, 2));
    min = stoi(s.substr(3 , 2));
    
    if (hr <= 12)
    {
        if (hr == 12)
            printf("%.2d:%.2d PM\n", hr, min);
        else
        {
            if (hr == 0) hr = 12;
            printf("%.2d:%.2d AM\n", hr, min);
        }
    }
    else
    {
        hr -= 12;
        printf("%.2d:%.2d PM\n", hr, min);
    }
}