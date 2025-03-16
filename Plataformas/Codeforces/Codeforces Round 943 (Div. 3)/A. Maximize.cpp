//https://codeforces.com/contest/1968/problem/A
#include <iostream>

using namespace std;

int gcd(int a,int b) 
{
    int R;
    while ((a % b) > 0)  
    {
        R = a % b;
        a = b;
        b = R;
    }
    return b;
}

int solve(int x)
{
    int ans = 0, calc = 0;
 
    for (int y = x - 1; y > 0; y--)
    {
        int gcd_ = gcd(x,y);
        if (gcd_ + y > calc && y > ans)
        {
            ans = y;
            calc = gcd_ + y;
        }
    }
    return ans;
}

int main()
{
    int t;
    cin >> t;

    for(int test = 0; test < t; test++)
    {
        int x;
        cin >> x;
        cout << solve(x) << '\n';
    }
}