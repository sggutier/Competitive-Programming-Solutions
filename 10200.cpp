#include <bits/stdc++.h>
using namespace std;
const int limN = 1e4;

int primCnt = 0;
int primos[limN];
bool comp[limN+1];

void criba() {
    for(int i=2; i*i<=limN; i++)
        if(!comp[i])
            for(int j=i*i; j<=limN; j+=i)
                comp[j] = true;
    for(int i=2; i<=limN; i++)
        if(!comp[i])
            primos[primCnt++] = i;
}

bool isPrime(int n) {
    if(n<=limN)
        return !comp[n];
    for(int i=0; i<primCnt; i++)
        if(n%primos[i]==0)
            return false;
    return true;
}

int workSum[limN+3];

void precarga() {
    criba();
    for(int i=0; i<=limN; i++) 
        workSum[i+1] = workSum[i] + isPrime(i*i + i + 41);
}

int main() {
    precarga();
    int a, b;

    while(scanf("%d%d", &a, &b)!=EOF) {
        b++;
        printf("%.2Lf\n", 100.0 * (((long double)(workSum[b] - workSum[a]))/(b-a)) + 1e-9 );
    }
    
    return 0;
}
