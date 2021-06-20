#include <bits/stdc++.h>
using namespace std;
const int limN = 1e5 + 1;
const int limP = 2e4 ;

bool comp[limN + 1];
int primCnt = 0;
int primos[limP];

void criba(int N = limN) {
    for(int i=2; i*i<=limN; i++)
        if(!comp[i])
            for(int j=i*i; j<=limN; j+=i)
                comp[j] = true;
    for(int i=2; i<=limN; i++)
        if(!comp[i])
            primos[primCnt++] = i;
}

void testCase(int a, int b) {
    if(b%a) {
        printf("NO SOLUTION\n");
        return;
    }
    int ans = 1;
    for(int i=0; i<primCnt && primos[i]<=b; i++) {
        int p = primos[i];
        int x=1, y=1;
        while(a%p==0) {
            a/=p; x*=p;
        }
        while(b%p==0) {
            b/=p; y*=p;
        }
        if(y>x)
            ans *= y;
    }
    if(b>a)
        ans *= b;
    printf("%d\n", ans);
}

int main() {
    criba();
    int tc;
    scanf("%d", &tc);
    while(tc--) {
        int a ,b; scanf("%d%d", &a, &b);
        testCase(a, b);
    }
}
