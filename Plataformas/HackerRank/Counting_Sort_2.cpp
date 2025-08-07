#include <bits/stdc++.h>
using namespace std;

#define MAX_FREQ 100
#define MAX_N 1000000

int main() {
    int freq[MAX_FREQ];
    int arr[MAX_N];
    int answer[MAX_N];
    int n;
    memset(freq, 0, sizeof(freq));
    
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        freq[arr[i]]++;
    }

    for (int i = 1; i < MAX_FREQ; i++)
        freq[i] += freq[i-1];

    for (int i = n-1; i >= 0; i--) {
        answer[freq[arr[i]] - 1] = arr[i];
        freq[arr[i]]--;
    }

    cout << answer[0];
    for (int i = 1; i < n; i++)
        cout << " " << answer[i];
    cout << '\n';
}