#include <bits/stdc++.h>
using namespace std;

void slove() {
    int n, k;
    bool peasoup = false, pancakes = false;
    string ans = "";
    
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &k);
        string rname;
        cin.ignore(1);
        getline(cin, rname);
        for (int j = 0; j < k; j++) {
            string str;
            getline(cin, str);
            if (str == "pea soup") peasoup = true;
            else if (str == "pancakes") pancakes = true;
        }
        if (ans.empty() && peasoup && pancakes) ans = rname;
        peasoup = false;
        pancakes = false;
    }

    if (ans.empty()) cout << "Anywhere is fine I guess\n";
    else cout << ans;
}

int main() {
    slove();
}
