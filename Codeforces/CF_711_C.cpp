#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int limN = 105;
const ll inf = 1e18;

int N, M;
int cols[limN];
int csts[limN][limN];
bool usd[limN][limN][limN];
ll minCMem[limN][limN][limN];

ll minC(int k, int pos, int ult) {
    if(pos==N) {
        return k==0? 0 : inf;
    }
    if(k < 0)
        return inf;
    if(usd[k][pos][ult])
        return minCMem[k][pos][ult];
    usd[k][pos][ult] = true;
    ll &c = minCMem[k][pos][ult];    
    if(cols[pos]) {
        c = minC(k - (ult==cols[pos]? 0 : 1), pos+1, cols[pos]);
        return c ;            
    }
    c = inf;
    for(int i=1; i<=M; i++)
        c = min(c, csts[pos][i] + minC(k - (ult==i? 0 : 1), pos+1, i));
    return c;
}

int main() {
    int K ;
    scanf("%d%d%d", &N, &M, &K);
    for(int i=0; i<N; i++)
        scanf("%d", &cols[i]);
    for(int i=0; i<N; i++)
        for(int j=1; j<=M; j++)
            scanf("%d", &csts[i][j]);
    ll ans = minC(K, 0, 0);
    printf("%lld\n", ans==inf? -1 : ans);
}
