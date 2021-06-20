#include <bits/stdc++.h>
using namespace std;
const int LIM_N = 2e6;

bool isComp[LIM_N];
int P = 0;
int primes[LIM_N];

void sieve() {
    for(int i=2; i*i < LIM_N; i++)
        if(!isComp[i])
            for(int j=i*i; j < LIM_N; j += i)
                isComp[j] = true;
    for(int i=2; i < LIM_N; i++)
        if(!isComp[i])
            primes[P++] = i;
}

int testCase(int N) {
    int p_pos = lower_bound(primes, primes+P, N) - primes;
    return primes[p_pos] == N? 0 : primes[p_pos] - primes[p_pos - 1];
}

int main() {
    sieve() ;
    int N ;
    while(scanf("%d", &N) != EOF && N) {
        printf("%d\n", testCase(N));
    }
}
