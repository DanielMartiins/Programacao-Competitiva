#include <bits/stdc++.h>
using namespace std;

#define MAX_N 1000002
#define MAX_K 100001

#define LSOne(S) (S & (-S))

int ft[MAX_N];
int arr[MAX_N];
int n;


int rsq(int k) {
    int sum = 0;
    while(k) {
        sum += ft[k];
        k -= LSOne(k);
    }
    return sum;
}

int rsq(int i, int j) {
    return rsq(j) - rsq(i-1);
}

void update(int pos, int diff) {
    while(pos <= n) {
        ft[pos] += diff;
        pos += LSOne(pos);
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int k;
    cin >> n >> k;

    while(k--) {
        char op;
        cin >> op;
        if (op == 'F') {
            int bit;
            cin >> bit;
            
            arr[bit] = !arr[bit];
            
            update(bit, arr[bit] ? 1 : -1);
        } else {
            int l, r;
            cin >> l >> r;
            cout << rsq(l, r) << "\n";
        }
    }
}