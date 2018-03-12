/*
ID: me60
LANG: C++11
TASK: sprime
*/
#include <bits/stdc++.h>
using namespace std;
const int sivLim = 10005;

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

int main() {
    freopen("sprime.in", "r", stdin);
    freopen("sprime.out", "w", stdout);
    
    int reqDigs ;
    queue<int> primeQ;
    queue<int> digQ;

    scanf("%d", &reqDigs);

    sieve();

    for(int i=2; i<10; i++) {
        if(isComp[i])
            continue;
        primeQ.push(i);
        digQ.push(1);
    }
    while(!primeQ.empty()) {
        int curPrime = primeQ.front();
        int curDigs = digQ.front();
        primeQ.pop();
        digQ.pop();
        if(curDigs == reqDigs) {
            printf("%d\n", curPrime);
            continue;
        }
        curPrime*=10;
        curDigs++;
        for(int i=1; i<10; i+=2) {
            if(isPrime(curPrime+i)) {
                primeQ.push(curPrime+i);
                digQ.push(curDigs);
            }
        }
    }
    
    return 0;
}
