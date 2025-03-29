//https://codeforces.com/contest/1971/problem/C

#include <bits/stdc++.h>
using namespace std;
int connections[4];
#define A 0
#define B 1
#define C 2
#define D 3

string solve();

int main()
{
    int t;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        for (int i = 0; i < 4; i++)
            cin >> connections[i]; 
        cout << solve() << '\n';
    }
}

string solve()
{
    string pattern = "";

    for (int i = 1; i <= 12; i++)
    {
        if (i == connections[A] || i == connections[B])
            pattern += 'r';
        else if (i == connections[C] || i == connections[D])
            pattern += 'b';
    }

    if (pattern == "rbrb" || pattern == "brbr") return "YES";
    return "NO";
    /* TAMBÉM FUNCIONA:
    if (pattern == "rbbr" || pattern == "brrb"
        || pattern == "bbrr" || pattern == "rrbb") return "NO";
    return "YES";
    */
}