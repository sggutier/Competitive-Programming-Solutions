#include <bits/stdc++.h>
using namespace std;
#define ll int
const int limN = 1e3 ;
const int limP = 800000;
const ll limK = 1e6 + 3;

int primCnt;
int primos[limP];
bool comp[limK + 1];
int semiP[limK];

void criba(int N = limK) {
    for(int i=5; i*i<N; i+=4)
        if(!comp[i])
            for(int j=i*i; j<N; j+=i)
                comp[j] = 1;
    for(int i=5; i<N; i+=4) {
        if(comp[i])
            continue;
        primos[primCnt++] = i;
        for(int w=0; w<primCnt && primos[w]*i<limK; w++)
            semiP[primos[w]*i] = 1;
    }
    for(int i=1; i<limK; i++)
        semiP[i] += semiP[i-1];
}

int main() {
    criba();

    int n;
    while(scanf("%d", &n)!=EOF && n)
        printf("%d %d\n", n, semiP[n]);
    
    return 0;
}
