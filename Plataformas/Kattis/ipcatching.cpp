#include <bits/stdc++.h>
using namespace std;

struct Ip {
    int a,b,c,d,mask;
};

vector<Ip> lkup_table;

bool match(Ip lkup, Ip ip) {
    if (lkup.mask == 0) return true;
    int abcd_lkup[4] = {lkup.a, lkup.b, lkup.c, lkup.d}; 
    int abcd_ip[4] = {ip.a, ip.b, ip.c, ip.d}; 
    int num_blocks = (lkup.mask / 8) + (lkup.mask % 8 != 0);
    for (int i = 0; i < num_blocks; i++) {
        int shift = max(0, (i+1)*8 - lkup.mask);
        if ((abcd_lkup[i] >> shift) != (abcd_ip[i] >> shift)) 
            return false;
    }
    return true;
}

int query(Ip ip) {
    int ans = -1;
    int longest_pref = -1;
    for (int i = 0; i < lkup_table.size(); i++) {
        Ip lkup = lkup_table[i];
        if (match(lkup, ip) && lkup.mask > longest_pref) {
            ans = i+1; 
            longest_pref = lkup.mask;   
        } 
    }
    return ans;
}

int main() {
    int n,m;
    scanf("%d %d", &n, &m);

    while(n--) {
        int a,b,c,d,mask;
        scanf("%d.%d.%d.%d/%d", &a, &b, &c, &d, &mask);
        lkup_table.push_back({a,b,c,d,mask});
    }

    while(m--) {
        int a,b,c,d;
        scanf("%d.%d.%d.%d", &a, &b, &c, &d);
        printf("%d\n", query({a,b,c,d,-1}));
    }
}