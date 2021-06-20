#include <stdio.h>

int main() {
    int n, tc=0;
    while(scanf("%d", &n)!=EOF && n)
        printf("Case %d: %d\n", ++tc, n/2);
}
