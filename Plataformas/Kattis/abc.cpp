//https://open.kattis.com/problems/abc

#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    int ABC[3];
    string desiredOrder;

    for (int i = 0; i < 3; i++) cin >> ABC[i];
    cin >> desiredOrder;

    if (ABC[0] > ABC[1])
        swap(ABC[0], ABC[1]);
    if (ABC[0] > ABC[2]) swap(ABC[0], ABC[2]);
    if (ABC[1] > ABC[2]) swap(ABC[1], ABC[2]);

    for (int i = 0; i < desiredOrder.size(); i++)
        cout << ABC[desiredOrder.at(i) - 'A'] << ' ';
    return 0;
}
