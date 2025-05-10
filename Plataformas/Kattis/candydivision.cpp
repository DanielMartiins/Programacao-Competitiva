#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n;
    set<long long> answer;
    
    cin >> n;

    for (long long i = 1; i <= sqrt(n); i++) {
        if (n % i == 0) {
            answer.insert(i - 1);
            answer.insert((n/i - 1));
        }
    }

    auto num = answer.begin();
    cout << *num;
    for (num++; num != answer.end(); num++)
        cout << " " << *num;
    cout << "\n";
}