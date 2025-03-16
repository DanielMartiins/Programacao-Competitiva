#include <bits/stdc++.h>
using namespace std;

bool chosen[20];

void solve(int n) {

    for (int i = 0; i < 20; i++) 
            chosen[i] = false;

    vector<int> a;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        a.push_back(num);
    }

    if (n == 1) {cout << "0\n"; return;}
    int ans = 0;

    for (int i = 0; i < n; i++)
        for (int j = i+1; j < n; j++)
            if (a.at(i) == a.at(j) && !chosen[i] && !chosen[j]) {
                chosen[i] = true;
                chosen[j] = true;
                //printf("[%d][%d]\n", i, j);
                ans++;
            } 

    cout << ans << "\n";
}

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;

    while (t--){
        int n;
        cin >> n;
        solve(n);
    }   
    return 0;
}
