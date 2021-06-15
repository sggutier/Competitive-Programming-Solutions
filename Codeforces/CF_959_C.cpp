#include <bits/stdc++.h>
using namespace std;

void centrado(int n) {
    printf("%d %d\n", 1, 2);
    int mt = (n-2)/2;
    mt += 2;
    for(int i=3; i<=mt; i++)
        printf("%d %d\n", 1, i);
    for(int i=mt+1; i<=n; i++)
        printf("%d %d\n", 2, i);
}

int main() {
    int n ;
    scanf("%d", &n);
    if( n <= 5)
        printf("-1\n");
    else
        centrado(n);
    for(int i=2; i<=n; i++)
        printf("%d %d\n", i-1, i);
}
