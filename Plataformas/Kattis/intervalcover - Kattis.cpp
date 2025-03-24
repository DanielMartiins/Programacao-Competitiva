//https://open.kattis.com/problems/intervalcover

#include <bits/stdc++.h>
using namespace std;

struct Interval {
    double l,r;
    int index;
    bool valid; //to avoid considering the same interval more than once
};


bool compareByEnd(const Interval &i, const Interval &j) {
    return i.r > j.r;
}


/*
* The best interval 'i' to be chosen to cover until a point 'p' is when
* intervals[i].l <= p and intervals[i].r is the max possible
*/
void solve(double target_l, double target_r) {
    int n, count = 0;
    double p = target_l;
    bool found = false; //has found at least one locally optimal choice 
    vector<Interval> intervals;
    vector<Interval> ans;

    cin >> n;
    for (int i = 0; i < n; i++) {
        double l, r;
        cin >> l >> r;
        intervals.push_back({l,r,i, true});
    }

    sort(intervals.begin(), intervals.end(), compareByEnd);
    for (int i = 0; i <= n; i++) ans.push_back({-DBL_MAX, -DBL_MAX, INT_MIN, true});

    for (int i = 0; i < n && ans[count].r < target_r; i++) {
        if (intervals[i].l <= p && intervals[i].r >= p && intervals[i].r > ans[count].r && intervals[i].valid) { 
            ans[count] = intervals[i];
            found = true;
            intervals[i].valid = false;
            i = -1;
        }
        else if (found) {
            p = ans[count].r;
            if (p >= target_r) break;
            count++;
            found = false;

            ans[count].r = ans[count-1].r; //Sentinel
            i = -1;
        }    
    }

    if(!(ans[0].l <= target_l && ans[count].r >= target_r)) cout << "impossible\n";
    else {
        count++;
        cout << count << "\n";
        cout << ans[0].index;
        for (int i = 1; i < count; i++) cout << " " << ans[i].index;
        cout << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    double a,b;
    while (cin >> a >> b) {
        solve(a,b);
    }
}