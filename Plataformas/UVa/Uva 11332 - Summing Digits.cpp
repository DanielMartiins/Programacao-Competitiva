//https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=2307

#include <bits/stdc++.h>
using namespace std;

long long sumDigits(long long n) {
    
    long long sum = 0;
    while (n != 0) {
        sum += n % 10;
        n = n / 10;
        if (sum >= 10 && n == 0) {
            n = sum;
            sum = 0;
        }
    }
    return sum;
}

int main(int argc, char const *argv[])
{
    long long number;
    cin >> number;

    while (number != 0) {
        cout << sumDigits(number) << '\n';
        cin >> number;
    }
    return 0;
}
