#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<pair<int, int>> answer;
    int smallest_diff = INT_MAX;
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++) cin >> arr[i];

    sort(arr, arr + n);

    smallest_diff = abs(arr[0] - arr[1]);
    answer.push_back({arr[0], arr[1]});
    for (int i = 2; i < n; i++) {
        int diff = abs(arr[i] - arr[i-1]);
        if (diff == smallest_diff)
            answer.push_back({arr[i-1], arr[i]});
        else if (diff < smallest_diff) {
            smallest_diff = diff;
            answer.clear();
            answer.push_back({arr[i-1], arr[i]});
        }
    }

    printf("%d %d", answer[0].first, answer[0].second);
    for (int i = 1; i < answer.size(); i++) {
        printf(" %d %d", answer[i].first, answer[i].second);
    }
    cout << "\n";
}