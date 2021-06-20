#include <bits/stdc++.h>
using namespace std;
const int limN = 1e6 ;
const int mod = 1e6;

bool usd[limN + 1];
int funcMemo[limN + 1];

int memo(int N) {
    if(usd[N])
        return funcMemo[N];
    usd[N] = true;
    return funcMemo[N] = (memo(floor(N - sqrt(N))) + memo(floor(log(N))) + memo(floor(N*pow(sin(N),2))))%mod;
}

int main() {
    funcMemo[0] = usd[0] = 1;
    
    int n;

    while(scanf("%d", &n)!=EOF && n!=-1)
        printf("%d\n", memo(n));
    
    return 0;
}
