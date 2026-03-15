#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    float r,m,c;
    cin >> r >> m >> c;
    
    cout << setprecision(8);
    
    while(r != 0 && m != 0 && c != 0) {
        float square_area = 4*r*r;
        float real_circle_area = M_PI * r * r;
        float estimated_circle_area = square_area*(c/m);
        cout << real_circle_area << " " << estimated_circle_area << "\n";
        cin >> r >> m >> c;
    }
}