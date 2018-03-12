#include <bits/stdc++.h>
using namespace std;
const int limN = 44722;

bool comp[limN];
int primCnt = 0;
int primos[limN];

void criba(int N = limN) {
    for(int i=2; i*i<N; i++)
        if(!comp[i])
            for(int j=i*i; j<N; j+=i)
                comp[j] = true;
    for(int i=2; i<N; i++)
        if(!comp[i])
            primos[primCnt++] = i;
}

long long testCase(int N) {
    long long ans = 1;
    for(int p=0; p<primCnt && primos[p]<=N; p++) {
        if(N%primos[p])
            continue;
        int cnt = 0;
        while(N%primos[p]==0) {
            N /= primos[p];
            cnt ++;
        }
        ans *= 2*cnt+1;
    }
    if(N>1) {
        int cnt = 1;
        int q = sqrt(N);
        if(q*q==N)
            cnt ++;
        ans *= 2*cnt+1;
    }
    return ans/2 + ans%2;
}

int main() {
    criba();
    int n;
    while(scanf("%d", &n)!=EOF && n)
        printf("%d %lld\n", n, testCase(n));
}
