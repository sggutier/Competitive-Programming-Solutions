#include <bits/stdc++.h>
using namespace std;

int main() {
    char X[1000], Z[1000], Y[1000];
    scanf("%s%s", X, Y);
    int n = strlen(X);
    for(int i=0; i<n; i++) {
        if(X[i]<Y[i]) {
            printf("-1\n");
            return 0 ;
        }
        Z[i] = min(X[i], Y[i]);
    }
    Z[n] = 0;
    printf("%s\n", Z);
    return 0 ;
}
