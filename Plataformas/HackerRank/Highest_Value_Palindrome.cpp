#include <bits/stdc++.h>
using namespace std;

string str;
int n, k;


bool solve() {
    int l = 0, r = str.size() - 1;
    int diff_count = 0;
    while(l < r) {
        if (str[l] != str[r]) diff_count++;
        l++; r--;
    }
    
    l = 0, r = str.size() - 1;
    while (l < r) {
        
        if (k > diff_count && k >= 2 && str[l] != '9' && str[r] != '9') {
            if (str[l] != str[r]) {
                diff_count = max(diff_count-1, 0);
            }
            if (k - 2 >= diff_count) {
                str[l] = '9';
                str[r] = '9';
                k -= 2;
            }
        }
        
        if (str[l] != str[r]) {
            char char_l = str[l];
            char char_r = str[r];
            if (k == 0) return false;
            else {
                str[l] = max(char_l, char_r);
                str[r] = max(char_l, char_r);
                k--;
                diff_count--;
            }
        }
        l++; r--;
    }

    if (str.size() % 2 != 0 && k > 0)
        str[l] = '9'; //l and r will be equal after the while loop above
    return true;
}

int main() {
    cin >> n >> k;
    cin >> str;
    
    if (!solve()) cout << "-1\n";
    else cout << str << "\n";
}