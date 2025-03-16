//https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=882&page=show_problem&problem=1365

#include <bits/stdc++.h>
using namespace std;


int sum(string s){
    int n = 0;
    
    //Somar o valor ASCII dos caracteres
    for (int i = 0; i < s.size(); i++) {
        if (s.at(i) >= 'A' && s.at(i) <= 'Z') n += s.at(i) - 'A' + 1;
        else if (s.at(i) >= 'a' && s.at(i) <= 'z') n += s.at(i) - 'a' + 1;
    }
    
    //Somar os dígitos dessa soma adquirida 
    int sum = 0;
    while (n != 0) {
        sum += n % 10;
        n = n / 10;
        if (n == 0 && sum >= 10) { 
            n = sum;
            sum = 0;
        }
    }
    return sum;
}
float solve(string a, string b) {

    float sumA = sum(a);
    float sumB = sum(b);

    if (sumA < sumB) return (sumA/sumB) * 100;
    else return (sumB/sumA) * 100;
}

int main() {

    string a, b;

    while (getline(cin, a)) {
        getline(cin, b);
        printf("%.2f %%\n", solve(a,b));
    }
}
