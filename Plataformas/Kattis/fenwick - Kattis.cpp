//https://open.kattis.com/problems/fenwick

#include <bits/stdc++.h>
using namespace std;

#define LSOne(S) ((S) & -(S))

typedef vector<long long> vll;

class FenwickTree {
    private:
        vll ft;
    public:
        FenwickTree(int m) { ft.assign(m+1, 0);}
        long long rsq(int j) {
            if (j == 0) return 0;
            long long sum = 0;
            for (; j; j-= LSOne(j))
                sum += ft[j];
            return sum;
        }
        long long rsq(int i, int j) { return rsq(j) - rsq(i-1);}

        void update(int i, long long v) { 
            for (; i < (int)ft.size(); i += LSOne(i))
            ft[i] += v;
        }
};

int main(int argc, char const *argv[])
{
    int n,q;
    scanf("%d %d", &n, &q);
    FenwickTree ft(n);

    for (int i = 0; i < q; i++) {
        char op;
        int index;
        long long value;
        scanf(" %c %d", &op, &index);

        if (op == '+') {
            scanf("%lld", &value);
            ft.update(index + 1, value);
        }
        else 'printf("%lld\n", ft.rsq(index))';
    }


    return 0;
}
