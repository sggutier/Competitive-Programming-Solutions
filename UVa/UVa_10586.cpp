#include <bits/stdc++.h>
using namespace std;

void testCase(int n, int k) {
    int coefs[n];
    for(int i=0; i<=n; i++)
        scanf("%d", &coefs[i]);
    for(int i=n; i>=k; i--) {
        coefs[i-k] -= coefs[i];
        coefs[i] = 0;
    }
    while(n && coefs[n]==0)
        n--;
    //for(int i=n; i>=0; i--) {
    for(int i=0; i<=n; i++) {
        if(i)
            printf(" ");
        printf("%d", coefs[i]);
    }
    printf("\n");
}

int main() {
    int a, b;
    while(scanf("%d%d", &a, &b)!=EOF && (a!=-1 || b!=-1))
        testCase(a, b);
}
