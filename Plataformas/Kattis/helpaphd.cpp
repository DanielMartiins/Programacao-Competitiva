
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    while(n--) {
        string str;
        cin >> str;
        if (str == "P=NP") cout << "skipped";
        else {
            cout << stoi(str.substr(0, (str.find("+"))))
                    + stoi(str.substr(str.find("+")+1, str.length()-str.find("+")));
        }
        cout << "\n";
    }
}
