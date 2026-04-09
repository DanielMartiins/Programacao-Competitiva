#include <bits/stdc++.h>
using namespace std;

struct Landmark {
    long long x;
    long long y;
};

unordered_map<string, Landmark> landmarks;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        string name;
        cin >> name >> landmarks[name].x >> landmarks[name].y;
    }

    long long ans = 0; 
    string prev,aux;
    cin >> prev;

    for (int i = 1; i < n; i++) {
        cin >> aux;
        long long x1 = landmarks[prev].x;
        long long x2 = landmarks[aux].x;
        long long y1 = landmarks[prev].y;
        long long y2 = landmarks[aux].y;
        ans += (abs(x1 - x2) + abs(y1 - y2)); 
        prev = aux;
    }

    cout << ans << "\n";
}
