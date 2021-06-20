#include <bits/stdc++.h>
using namespace std;
const int limN = 5e4 + 5;

int primCnt = 0;
bool comp[limN];
bool primos[limN];
int phi[limN];
long long phiSum[limN];

void criba() {
    for(int i=2; i*i<limN; i++)
        if(!comp[i])
            for(int j=i*i; j<limN; j+=i)
                comp[j] = true;
    for(int i=0; i<limN; i++)
        phi[i] = 1;
    for(int i=2; i<limN; i++) {
        if(comp[i])
            continue;
        primos[primCnt++] = i;
        for(int j=i; j<limN; j+=i) {
            int w = j/i;
            int a=i, b=1;            
            while(w%i==0) {
                w /= i;
                b = a;
                a *= i;
            }
            phi[j] *= a-b;
        }
    }
}

int main() {
    criba();
    phiSum[1] = 1;
    for(int i=2; i<limN; i++)
        phiSum[i] = 2*phi[i] + phiSum[i-1];
    int n;
    while(scanf("%d", &n)!=EOF && n) {
        printf("%lld\n", phiSum[n]);
        // for(int i=1; i<=n; i++) {
        //     printf("%d ", phi[i]);
        // }
        // printf("\n");
    }
}
