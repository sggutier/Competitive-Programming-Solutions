#include <bits/stdc++.h>
using namespace std;
const int limN = 1e5+ 5;
typedef pair<int,int> par;
#define f first
#define s second

list <int> adj[limN];
bool usd[limN];
bool mdo[505];
bool epe[505];

bool isacl(int pos) {
    if(usd[pos])
        return false;
    if(mdo[pos])
        return true;
    usd[pos] = true;
    mdo[pos] = true;
    for(const int &sig:adj[pos]) {
        if(!isacl(sig)) {
            usd[pos] = false;
            return false;
        }
        if(epe[sig]) epe[pos] = true;
    }
    usd[pos] = false;
    return true;
}

bool funca(int N) {
    for(int i=0; i<N; i++)
        if(!isacl(i))
            return false;
    return true;
}

int main() {
    int N, E;
    bool ans = false;
    scanf("%d%d", &N, &E);
    for(int i=0; i<E; i++) {
        int a, b ;
        scanf("%d%d", &a, &b);
        a--, b--;
        adj[a].push_back(b);
    }
    ans = funca(N);
    for(int i=0; i<N && !ans; i++) {        
        memset(mdo, 0, sizeof(mdo));
        memset(epe, 0, sizeof(epe));
        mdo[i] = true;
        epe[i] = true;
        if(!funca(N))
            continue;
        int cnt = 0;
        for(const int &sig:adj[i])
            if(epe[sig])
                cnt ++;
        if(cnt <= 1)
            ans = true;
    }
    printf("%s\n", ans? "YES" : "NO");
}

