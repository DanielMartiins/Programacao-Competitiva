#include <bits/stdc++.h>
using namespace std;

vector<long long> ft; //fenwick tree

long long rsq(int j) {
    if (j == 0) return 0;
    long long soma = 0;

    for (; j; j -= (j & (-j)))
        soma += ft.at(j);

    return soma;
}

void update(int i, long long v) {
    for (; i < (int)ft.size(); i += (i & (-i)))
        ft.at(i) += v;
}

int main() {
    int n, q;
    scanf("%d %d", &n, &q);
    ft.assign(n+1, 0);

    for (int i = 0; i < q; i++) {
        char op;
        int index; 
        long long value;

        scanf(" %c %d", &op, &index);

        if (op == '+') {
            scanf("%lld", &value);
            update(index + 1, value);
        }
        else printf("%lld\n", rsq(index));
    }

    return 0;
}