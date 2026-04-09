// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;

int main() {

    int a, b;
    cin >> a >> b;
    while(!(a == 0 && b == 0)){
        cout << a/b << " " << a%b << " / " << b << "\n";
        cin >> a >> b;
    }

}
