//https://open.kattis.com/problems/sok

#include <bits/stdc++.h>
using namespace std;

void solve() {
    float abc[3];
    float ijk[3];

    cin >> abc[0] >> abc[1] >> abc[2];
    cin >> ijk[0] >> ijk[1] >> ijk[2];

    float m = 99999999;
    for (int i = 0; i < 3; i++)
        m = min(m, abc[i]/ijk[i]);

    printf("%f %f %f\n",
        abc[0] - (ijk[0] * m),
        abc[1] - (ijk[1] * m),
        abc[2] - (ijk[2] * m)
    );

}

int main() {
    solve();
}