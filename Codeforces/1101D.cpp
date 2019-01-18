#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
const int limN = 2e5 + 5;

bitset <limN> isC;
vector <int> primos;

void criba() {
    isC[0] = isC[1] = true;
    for(int i=2; i *i < limN; i++)
        for(int j=i*i; j < limN; j+= i)
            isC[j] = true;
    for(int i=2; i<limN; i++)
        if(!isC[i])
            primos.push_back(i);
}

int ans = 0 ;
int vals[limN];
vector <int> adj[limN];
map <int, pair<int, int> > dp[limN];

void proca(const int pos, const int pv, const int g, const int d) {    
    pair <int, int> &y = dp[pos][d];
    ans = max(ans, y.f + y.s + 1);
    if(g % d)
        return ;
    pair <int, int> &a = dp[pv][d];
    a.f = max(a.f, y.s + 1);
    if(a.s < a.f)
        swap(a.f, a.s);
}

void dfs(const int pos, const int pv) {
    for(const int sg : adj[pos])
        if(sg != pv)
            dfs(sg, pos);

    int g = pv==-1? 1 : __gcd(vals[pos], vals[pv]);
    for(const int p : primos) {
        if(vals[pos] % p)
            continue;
        if(p*p > vals[pos])
            break;
        proca(pos, pv, g, p);
        if(p*p != vals[pos])
            proca(pos, pv, g, vals[pos]/p);
    }

    if(!isC[vals[pos]])
        proca(pos, pv, g, vals[pos]);
}

int main() {
    criba();

    int N ;
    
    scanf("%d", &N);
    for(int i=0; i<N; i++)
        scanf("%d", &vals[i]);
    for(int i=1, a, b; i<N; i++) {
        scanf("%d%d", &a, &b);
        a--, b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(0, -1);

    printf("%d\n", ans);
}
