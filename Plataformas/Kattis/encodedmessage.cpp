#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    
    cin >> t;
    while(t--) {
        string str;
        cin >> str;
        int size = sqrt(str.size());
        char m[size][size];

        for (int i = 0; i < str.size(); i++)
            m[i/size][i%size] = str[i];

        for (int j = size-1; j >= 0; j--)
            for (int i = 0; i < size; i++)
                cout << m[i][j];
        cout << "\n";
    }
}