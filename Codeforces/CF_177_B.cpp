#include <bits/stdc++.h>
using namespace std;
const int limN = 55;

int main() {
    int bc[limN];
    int n ;

    scanf("%d", &n);

    bc[1] = 1;
    for(int i=2; i<=n; i++)  {
        bc[i] = 0;
        printf("%d ", i);
        for(int j=1; j<i; j++) {
            if(i%j)
                continue;
            bc[i] = max(bc[i], i + bc[j]);
            // printf("[%d %d %d] ", i/j, j, bc[j] + i);
        }
        printf("%d\n", bc[i]);
    }

    printf("%d\n", bc[n]);
}
