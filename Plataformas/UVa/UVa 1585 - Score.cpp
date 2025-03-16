//https://onlinejudge.org/index.php?option=onlinejudge&Itemid=8&page=show_problem&problem=4460

#include <bits/stdc++.h>
using namespace std;

int solve(string str) {

    int consecutive = 0;
    int ans = 0;
    for (int i = 0; i < str.size(); i++) {
        if (str.at(i) == 'X') consecutive = 0;
        else if (str.at(i) == 'O') ans += 1 + consecutive++;
    }

    return ans;
}

int main(int argc, char const *argv[])
{
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        string str;
        cin >> str;

        cout << solve(str) << '\n';
    }
    return 0;
}
