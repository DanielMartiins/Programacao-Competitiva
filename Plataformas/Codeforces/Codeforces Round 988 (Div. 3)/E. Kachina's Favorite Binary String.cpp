#include <bits/stdc++.h>
using namespace std;

int f(int l, int r) {
    printf("? %d %d\n", l, r);
    fflush(stdout);
    int answer;
    scanf("%d", &answer);
    return answer;
}

void solve() {
    int n;
    bool complete = false; // Se entrar na condicional cur == 0, a string será construída até o fim
    scanf("%d", &n);
    int s[n+1];

    int prev = f(1,n);
    int cur;

    if (prev == 0){ printf("! IMPOSSIBLE\n");}
    else {
        for (int i = 2; i < n; i++) { 
            cur = f(i, n); 
            if (cur == 0) {
                s[i-1] = 0;
                s[i] = 1;

                int j;
                for (j = i + 1; j <= n && prev > 1; j++, prev--) s[j] = 1;
                for (; j <= n; j++) s[j] = 0;
                
                complete = true;
                break;    
            }
            if (cur < prev) s[i-1] = 0;
            else s[i-1] = 1;

            prev = cur;
        }

        //No fim, ou f(n-1, n) valerá 1 ou valerá 0
        if (!complete) {
            if (prev == 1) {
                s[n-1] = 0;
                s[n] = 1;
            }
            else s[n] = 0;
        }

        printf("! ");
        for (int i = 1; i <= n; i++)
            printf("%d", s[i]);
        printf("\n");
    }
    fflush(stdout);
}

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    scanf("%d", &t);

    while (t--){
        solve();
        fflush(stdout);
    }   
    return 0;
}
