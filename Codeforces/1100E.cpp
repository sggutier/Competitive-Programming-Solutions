#include <bits/stdc++.h>
using namespace std;
const int limN = 1e5 + 5;
typedef pair<int,int> pii;
#define f first
#define s second

int N, E;
vector <int> adj[limN];
tuple <int, int, int, int> edgs[limN];
bitset <limN> usd, actv;

bool hasCicl(const int pos) {
    if(actv[pos]) return true;
    if(usd[pos]) return false;
    usd[pos] = actv[pos] = true;
    for(const int sig : adj[pos])
        if(hasCicl(sig))
            return true;
    actv[pos] = false;
    return false;
}

bool fca(const int k) {
    for(int i=0; i<N; i++)
        adj[i].clear();
    usd.reset();
    actv.reset();
    
    for(int i=k, a, b; i<E; i++) {
        tie(ignore, a, b, ignore) = edgs[i];
        adj[a].push_back(b);
    }

    for(int i=0; i<N; i++)
        if(hasCicl(i))
            return false;

    return true;
}

int W = 0 ;
int ordo[limN];

void topo(const int pos) {
    if(usd[pos]) return;
    usd[pos] = true;
    for(const int sig : adj[pos])
        topo(sig);
    ordo[pos] = W++;
}

int main() {
    scanf("%d%d", &N, &E);
    for(int i=0, a, b, c; i<E; i++) {
        scanf("%d%d%d", &a, &b, &c);
        a--, b--;
        edgs[i] = {c, a, b, i};
    }
    sort(edgs, edgs+E);

    int ini = 0, fin = E;
    while(ini < fin) {
        int piv = (ini+fin) / 2;
        if(fca(piv))
            fin = piv;
        else
            ini = piv+1;
    }

    fca(ini);
    usd.reset();
    for(int i=0; i<N; i++)
        topo(i);

    // for(int i=0; i<N; i++) {
    //     printf("%d  >>> %d\n", i+1, ordo[i]);
    // }

    set <int> ans ;
    int minR = 0;
    for(int i=0, a, b, p; i<ini; i++) {
        tie(ignore, a, b, p) = edgs[i];
        // printf("%d => %d\n", a+1, b+1);
        if(ordo[a] < ordo[b])
            ans.insert(p);
    }

    if(ini)
        tie(minR, ignore, ignore, ignore) = edgs[ini-1];

    
    printf("%d %d\n", minR, (int) ans.size());
    for(const int p : ans)
        printf("%d ", p+1);
    printf("\n");
}
