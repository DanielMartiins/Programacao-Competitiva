#include <bits/stdc++.h>
using namespace std;

string str;
int n, k;


bool solve() {
    bool changed[n];
    memset(changed, false, sizeof(changed));
    int l = 0, r = str.size() - 1;
    
    //Make palindrome
    while (l < r) {
        if (str[l] != str[r]) {
            if (k == 0) return false;
            char mx = max(str[l], str[r]);
            str[l] = str[r] = mx;
            changed[l] = changed[r] = true;
            k--;
        }
        l++; r--;
    }

    //Maximize with '9'
    l = 0, r = str.size() - 1;
    while (l < r) {
        if (str[l] != '9') {
            /*Because the cost dependes on wheter you already "paid"
            to touch that position in pass 1*/
            int cost = (changed[l] || changed[r]) ? 1 : 2;
            if (k >= cost) {
                str[l] = str[r] = '9';
                k -= cost;
            }
        }
        l++; r--;
    }

    //Middle digit
    if (str.size() % 2 != 0 && k > 0)
        str[n/2] = '9'; //l and r will be equal after the while loop above
    return true;
}

int main() {
    cin >> n >> k;
    cin >> str;
    
    if (!solve()) cout << "-1\n";
    else cout << str << "\n";
}