//Using the template from CP4 - Book 2

#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 200000000;

string T, P;        //T = text, P = pattern
int n, m;           //n = |T|, m = |P|
int b[MAX_N]; //b = back table

void kmpPreprocess() {
    int i = 0, j = -1; b[0] = -1;
    while (i < m) {
        while ((j >= 0) && (P[i] != P[j])) j = b[j];
        ++i; ++j;
        b[i] = j;
    }
}

void kmpSearch() {
    vector<int> ans;
    int i = 0, j = 0;
    while (i < n) {
        while ((j >= 0) && (T[i] != P[j])) j = b[j];
        ++i; ++j;
        if (j == m) {
            //printf("P is found at index %d in T\n", i - j);
            ans.push_back(i-j);
            j = b[j];
        }
    }

    if (ans.size() == 0) cout << "\n";
    else {
        cout << ans[0];
        for (int i = 1; i < ans.size(); i++) 
            cout << " " << ans[i];
        cout << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    while (getline(cin, P)) {
        getline(cin, T);
        n = T.size(); m = P.size();
        kmpPreprocess();
        kmpSearch();
    }
}