//https://codeforces.com/contest/1968/problem/B

#include <iostream>

using namespace std;

string strA, strB;
int t, n, m;

int solve()
{
    int i,j = 0;
    int ans = 0;
    for (i = 0; i < n && j < m; i++)
    {
        while (j < m)
        {
            if (strB.at(j) == strA.at(i))
            {
                ans++;
                j++;
                break;
            }
            j++;
        }
    }
    return ans;    
}

int main()
{

    cin >> t;
    for (int test = 0; test < t; test++)
    {
        cin >> n >> m;
        cin >> strA;
        cin >> strB;

        cout << solve() << '\n';
    }
}
