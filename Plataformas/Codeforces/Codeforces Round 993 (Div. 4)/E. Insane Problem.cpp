#include <bits/stdc++.h>
using namespace std;

long long k, lx, rx, ly, ry;

long long bSearchMaxX(long long n) { //Buscar o maior 'x' possível

    long long left = lx;
    long long right = rx;
    long long x;
    bool exists = false;

    while (left <= right) {
        x = (right + left)/2;
        //y = k^n * x
        if ((long long)pow(k,n) * x > ry) right = x-1;
        else if ((long long)pow(k,n) * x < ly) left = x + 1;
        else {
            if (x+1 > rx || (long long)pow(k,n) * (x+1) > ry) {
                exists = true;
                break;
            }
            else left = x + 1; 
        }
    }

    if (exists) return x;
    else return -1;
}

long long bSearchMinX(long long n) { //Buscar o menor 'x' possível

    long long left = lx;
    long long right = rx;
    long long x;
    bool exists = false;

    while (left <= right) {
        x = (right + left)/2;
        //y = k^n * x
        if ((long long)pow(k,n) * x > ry) 
            right = x-1;
        else if ((long long)pow(k,n) * x < ly) 
            left = x + 1;
        else {
            if (x-1 < lx || (long long)pow(k,n) * (x-1) < ly) {
                exists = true;
                break;
            }
            else 
                right = x - 1; 
        }
    }
    if (exists) return x;
    else return -1;
}

void solve() {
    cin >> k >> lx >> rx >> ly >> ry;
    long long ans = 0;

    long long n = 0;

    // Limite de 'n' é quando k^n for maior que max(y)/min(x)
    while ((long long)pow(k,n) <= ry/lx) {
        long long min_x= bSearchMinX(n);
        long long max_x = bSearchMaxX(n);
        if (min_x == -1 || max_x == -1) {
            n++;
            continue;
        }

        ans += max_x - min_x + 1;
        n++;
    }

    cout << ans << '\n';
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    long long t;
    cin >> t;

    while (t--) {
        solve();
    }
}