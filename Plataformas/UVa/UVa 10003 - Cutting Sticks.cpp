#include <bits/stdc++.h>
using namespace std;

#define MAX_L 55
#define UNSOLVED -1
#define INF 100000000

vector<int> marks;
long long memo[MAX_L][MAX_L];

long long cut(int left, int right) {
    if (left+1 == right) return 0;
    if (memo[left][right] == UNSOLVED) {
        long long ans = INF;
        for(int i = left+1; i < right; i++)
            ans = min(ans, cut(left,i) + cut(i, right) + (marks[right]-marks[left]));
        memo[left][right] = ans;
    }
    return memo[left][right];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int l, n;
    cin >> l;
    while(l) {
        memset(memo, UNSOLVED, sizeof(memo));
        cin >> n;
        marks.push_back(0);
        while(n--) {
            int ci;
            cin >> ci;
            marks.push_back(ci);
        }
        marks.push_back(l);
        cout << "The minimum cutting is " << cut(0, marks.size() - 1) << ".\n";
        cin >> l;
        marks.clear();
    }
}