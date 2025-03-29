#include <bits/stdc++.h>
using namespace std;

void solve() {
    map<int, int> count;
    vector<int> arr;
    int k;
    cin >> k;

    for (int i = 0; i < k; i++) {
        int num;
        cin >> num;
        arr.push_back(num);
        count[num]++;
    }

    for (int i = 0; i < k; i++) {
        
        if ((k-2)%arr.at(i) != 0) continue;

        int needed = (k - 2)/arr.at(i);
        if ((needed != arr.at(i) && count[needed] >= 1)
            || (needed == arr.at(i) && count[needed] > 1)) {
            printf("%d %d\n", arr.at(i), needed);
            return;
        }
    }
}

int main(int argc, char const *argv[])
{
    int t;
    cin >> t;

    while (t--)
        solve();
    return 0;
}
