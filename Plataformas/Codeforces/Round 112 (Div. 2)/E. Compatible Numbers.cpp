#include <bits/stdc++.h>
using namespace std;

#define MAX_BITS 22
#define MAX_MASK (1 << MAX_BITS)
#define IMPOSSIBLE -1

int F[MAX_MASK];
int S[MAX_MASK];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    int arr[n];

    memset(F, IMPOSSIBLE, sizeof(F));
    memset(S, IMPOSSIBLE, sizeof(S));

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        F[arr[i]] = arr[i];
        S[arr[i]] = arr[i];
    }

    //DP (bottom-up)
    for (int bit = 0; bit < MAX_BITS; bit++) {
        for(int mask = 0; mask < MAX_MASK; mask++) {
            if (mask & (1<<bit))
                S[mask] = max(S[mask], S[mask ^ (1<<bit)]);
        }
    }

    for (int i = 0; i < n; i++) {
        int inverted_x = arr[i] ^ ((1 << MAX_BITS) - 1);
        if (i == 0) 
            cout << S[inverted_x];
        else 
            cout << " " << S[inverted_x];
    }
    cout << "\n";
}