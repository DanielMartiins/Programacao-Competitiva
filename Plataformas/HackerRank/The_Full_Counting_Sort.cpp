#include <bits/stdc++.h>
using namespace std;

#define MAX_FREQ 100

int main() {    

    int n;
    cin >> n;
    
    vector<pair<int,string>> arr(n);
    vector<pair<int,string>> answer(n);
    int freq[100];
    
    memset(freq, 0, sizeof(freq));
    
    for (int i = 0; i < n; i++) {
        int x;
        string s;
        cin >> x >> s;
        if (i < n/2) s = "-";
        
        freq[x]++;
        arr[i].first = x;
        arr[i].second = s;
    }
    
    for (int i = 1; i < MAX_FREQ; i++) freq[i] += freq[i-1];
    
    for (int i = n-1; i >= 0; i--) {
        int x = arr[i].first;
        answer[freq[x] - 1] = arr[i];
        freq[x]--;
    }
    
    cout << answer[0].second;
    for (int i = 1; i < n; i++) {
        cout << " " << answer[i].second;
    }
    cout << "\n";

}