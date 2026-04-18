#include <bits/stdc++.h>
using namespace std;

struct Time {
    int hh, mm, ss;
};

#define INF (24*3600+1)

vector<Time> arriving;
vector<Time> departing;
int n,m,s;

int solve() {
    int ans = INF;
    for(auto arr : arriving) {
        for (auto dep : departing) {
            int arriving_time_sec = (arr.hh * 3600) + (arr.mm * 60) + (arr.ss);  
            int departing_time_sec = (dep.hh * 3600) + (dep.mm * 60) + (dep.ss);
            int diff = departing_time_sec - arriving_time_sec; 
            if (diff >= s) ans = min(ans, diff);  
        }
    }
    return ans == INF ? -1 : ans;
}

int main() {
    scanf("%d %d", &n, &m);

    while(n--) {
        Time t;
        scanf("%d:%d:%d", &t.hh, &t.mm, &t.ss);
        arriving.push_back(t);
    }
    
    while(m--) {
        Time t;
        scanf("%d:%d:%d", &t.hh, &t.mm, &t.ss);
        departing.push_back(t);
    }

    scanf("%d", &s);
    printf("%d\n", solve());

}