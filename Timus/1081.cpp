#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int limN = 50;

ll memo[limN][2];
bool usd[limN][2];

ll numSeq(int rem, int ant) {
    if(rem==0)
        return 1;
    if(usd[rem][ant])
        return memo[rem][ant];
    usd[rem][ant] = true;
    memo[rem][ant] = numSeq(rem-1, 0);
    if(!ant)
        memo[rem][ant] += numSeq(rem-1, 1);
    return memo[rem][ant];
}

char ans[limN];

int main() {
    ll N, K ;
    scanf("%lld%lld", &N, &K);
    for(int i=N, pv=0; i; i--) {
        if(pv) {
            pv = 0;
            ans[N-i] = '0';
            continue;
        }
        ll w = numSeq(i-1, pv);
        // printf("%d %s => %lld\n", i, ans, w);
        ans[N-i] = w<K? '1' : '0';
        if(w < K)
            K -= w;
        pv = ans[N-i] - '0';
    }
    printf("%s\n", K>1? "-1" : ans);
}
