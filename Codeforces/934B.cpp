#include <bits/stdc++.h>
using namespace std;

int main() {
    int n ;
    scanf("%d", &n);
    if(n > 18*2) {
        printf("-1\n");
        return 0 ;
    }

    for(int i=1; i < n; i+=2)
        printf("8");
    if(n % 2)
        printf("4");
    printf("\n");
}
