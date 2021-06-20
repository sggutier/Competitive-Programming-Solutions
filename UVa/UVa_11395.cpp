#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int LIM_N = 1e6 + 2;

bool isComp[LIM_N];
int P ;
__int128 primes[LIM_N];

void criba() {
    for(int i=2; i*i < LIM_N; i++)
        if(!isComp[i])
            for(int j=i*i; j < LIM_N; j+=i)
                isComp[j] = true;
    for(ll i=3; i < LIM_N; i++)
        if(!isComp[i])
            primes[P++] = i*i;
}

ll _N ;
__int128 N ;
long long cnt = 0 ;

int bs(int k, __int128 prod) {
    int ini=k, fin = P-1, piv ;
    while(ini < fin) {
        piv = (ini + fin) / 2 + 1;
        if(prod * primes[piv] > N) {
            fin = piv - 1 ;
        }
        else  {
            ini = piv ;
        }
    }
    // for(int i=k; i <= ini; i++) {
    //     printf("%lld ", prod * primes[i]);
    // }
    // printf("\n");
    return ini - k + 1 ;
}

void dfs(__int128 prod, const int p=0) {
    if(p == P || primes[p] * prod > N) return;
    if(prod * primes[p] * primes[p] > N) {
        cnt += bs(p, prod);
        return ;
    }
    dfs(prod, p+1);
    for(prod *= primes[p]; prod <= N; prod *= primes[p]) {
        cnt ++ ;
        // printf("%lld\n", prod);
        dfs(prod, p+1);
    }
}

void testCase() {
    cnt = 0 ;
    for(int i=0; (1LL << i) <= _N;  i++) {
        // printf("%lld\n", 1LL << i);
        dfs(1LL << i);
        cnt ++ ;
    }
    printf("%lld\n", _N - cnt);
}

int main() {
    criba();
    while(scanf("%lld", &_N) != EOF && _N) {
        N = _N;
        testCase();
    }
}
