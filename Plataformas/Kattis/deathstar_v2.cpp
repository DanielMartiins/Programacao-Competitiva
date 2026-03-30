#include <iostream>
using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int ans = 0;
        for (int j = 0; j < n; j++) {
            int mij;
            scanf("%d", &mij);
            ans |= mij;
        }
        printf("%s%d", (i > 0 ? " " : ""), ans);
    }
    printf("\n");
}