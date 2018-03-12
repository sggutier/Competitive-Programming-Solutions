#include <bits/stdc++.h>
using namespace std;
const int limN = 305;
typedef pair<int,int> par;
#define f first
#define s second

par uneAns(par A, par B) {
    if(A.f != B.f)
        return max(A, B);
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

par maxP(int pos, int u) {
    if(usd[pos][u])
        return maxPMemo[pos][u];
    usd[pos][u] = true;
    if(adj[pos].size()==0) {
        return maxPMemo[pos][u] = par(1-u, 1);
    }

    par ans(1-u, 1);
    for(const int &sig:adj[pos]) {
        par W = maxP(sig, 1-u);
        ans.f += W.f;
        ans.s = min(2, ans.s * W.s);
    }

    return maxPMemo[pos][u] = (u==1)? ans : uneAns(ans, maxP(pos, 1));
}

void testCase(int N) {
    limpiaGlobs();
    map <string, int> ids;
    char tmp[15];

    scanf("%s", tmp);
    ids[tmp] = 0;
    for(int i=1, tot=1; i<N; i++) {
        int pat, pos;
        scanf("%s", tmp);
        if(ids.count(tmp)==0)
            ids[tmp] = tot++;
        pos = ids[tmp];
        scanf("%s", tmp);
        if(ids.count(tmp)==0)
            ids[tmp] = tot++;
        pat = ids[tmp];
        adj[pat].push_back(pos);
    }

    par ans = maxP(0, 0);

    printf("%d %s\n", ans.f, (ans.s==2)? "No" : "Yes");
}

int main() {
    int n ;

    while(scanf("%d", &n)!=EOF && n)
        testCase(n);
    
    return 0;
}
