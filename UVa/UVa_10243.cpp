#include <bits/stdc++.h>
using namespace std;
const int limN = 1005;
typedef pair<int,int> par;
#define f first
#define s second

par uneAns(par A, par B) {
    if(A.f != B.f)
        return min(A, B);
    return par(A.f, 2);
}

bool usd[limN][2];
par maxPMemo[limN][2];
list <int> adj[limN];

void limpiaGlobs(){
    memset(usd, 0, sizeof(usd));
    for(int i=0; i<limN; i++)
        adj[i].clear();
}

par maxP(int pos, int u, int prev=-1) {
    if(usd[pos][u])
        return maxPMemo[pos][u];
    usd[pos][u] = true;
    if(adj[pos].size()==0) {
        //printf("%d %d => %d\n", pos, u, u);
        return maxPMemo[pos][u] = par(u, 1);
    }

    par ans(u, 1);
    for(const int &sig:adj[pos]) {
        if(sig==prev)
            continue;
        par W = maxP(sig, 1-u, pos);
        ans.f += W.f;
        ans.s = min(2, ans.s * W.s);
    }
    //printf("%d %d => %d\n", pos, u, ans.f);

    return maxPMemo[pos][u] = (u==1)? ans : uneAns(ans, maxP(pos, 1, prev));
}

void testCase(int N) {
    limpiaGlobs();

    for(int i=0; i<N; i++) {
        int k = 0, sig;
        scanf("%d", &k);
        while(k--) {
            scanf("%d", &sig);
            sig --;
            adj[i].push_back(sig);
        }
    }

    par ans = maxP(0, 0);

    printf("%d\n", max(ans.f, 1));
}

int main() {
    int N;
    while(scanf("%d", &N)!=EOF && N)
        testCase(N);
    
    return 0;
}
