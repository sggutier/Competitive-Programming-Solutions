#include <bits/stdc++.h>
using namespace std;
const int limP = 31625;

int primCnt = 0;
int isComp[limP];
int primos[limP];

void criba(int n = limP) {
    for(int i=2; i*i<n; i++)
        if(!isComp[i])
            for(int j=i*i; j<n; j+=i)
                isComp[j] = true;
    for(int i=2; i<n; i++)
        if(!isComp[i])
            primos[primCnt++] = i;
}

void testCase(int n) {
    if(n==1) {
        printf("0\n");
        return;
    }
    int ans = 1;
    for(int i=0; i<primCnt && n > 1; i++) {
        int p = primos[i];
        if(n % p == 0) {
            int k = 1;
            while(n % p == 0) {
                n /= p;
                k *= p;
            }
            ans *= k - k/p;
        }
    }
    if(n > 1) {
        ans *= n - 1;
    }
    printf("%d\n", ans);
}

int main() {
    criba();
    int n ;
    while(scanf("%d", &n)!=EOF && n) {
        testCase(n);
    }
}
