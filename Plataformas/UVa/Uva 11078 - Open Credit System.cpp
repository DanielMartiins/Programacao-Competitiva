//https://onlinejudge.org/index.php?option=onlinejudge&Itemid=8&page=show_problem&problem=2019

#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;

        int ans = INT_MIN;
        int max = INT_MIN;
        for (int j = 0; j < n; j++) {
            int score;
            cin >> score;
            if (score > max) { 
                if (j > 0 && ans < max - score) ans = max - score;
                max = score;
            }
            else if (ans < max - score) ans = max - score;
        }

        cout << ans << '\n';
    }
    return 0;
}
