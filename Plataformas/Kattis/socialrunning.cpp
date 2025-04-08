//https://open.kattis.com/problems/socialrunning

#include <bits/stdc++.h>
using namespace std;

int main() {
	long long ans = LONG_MAX;
	vector<long long> dist;
    long long n;
    
    cin >> n;
    for (int i = 0; i < n; i++) {
        long long d;
        cin >> d;
        dist.push_back(d);
    }

    for (int i = 0; i < n; i++)
            ans = min(ans, (dist[(i+2) % n] + dist[(i) % n]));

    cout << ans << '\n';
}
