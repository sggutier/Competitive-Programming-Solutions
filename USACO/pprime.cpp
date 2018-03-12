/*
ID: me60
LANG: C++11
TASK: pprime
*/
#include <bits/stdc++.h>
using namespace std;
const int sivLim = 10005;

int lowBound, uppBound;
int primeCnt = 0;
int primes[sivLim];
bool isComp[sivLim];

void sieve() {
    isComp[0] = true;
    isComp[1] = true;
    for(int i=2; i*i<sivLim; i++) {
        if(isComp[i])
            continue;
        for(int j=i*i; j<sivLim; j+=i)
            isComp[j] = true;
    }
    for(int i=2; i<sivLim; i++)
        if(!isComp[i])
            primes[primeCnt++] = i;
}

bool isPrime(int n) {
    if(n<sivLim)
        return !isComp[n];
    for(int i=0; i<primeCnt; i++)
        if(n%primes[i]==0)
            return false;
    return true;
}

void generatePalindromes(int minPow, int maxPow, int num) {
    if(minPow>maxPow) {
        if(lowBound<=num && num<=uppBound && isPrime(num))
            printf("%d\n", num);
        return;
    }
    if(minPow==maxPow)
        maxPow = 0;
    for(int i=(minPow==1? 1 : 0); i<10; i++)
        generatePalindromes(minPow*10, maxPow/10, num + i*minPow + i*maxPow);
}

int main() {
    freopen("pprime.in", "r", stdin);
    freopen("pprime.out", "w", stdout);
    
    sieve();

    scanf("%d%d", &lowBound, &uppBound);

    for(int pot=1; pot<=uppBound; pot*=10)
        generatePalindromes(1, pot, 0);
    
    return 0;
}
