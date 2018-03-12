#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> par;
#define f first
#define s second
const int limN = 1e5 + 5;

bitset <limN> isGNode;
bitset <limN> isCTree;
vector <par> adj[limN];
map <int, int> cols[limN];
int scTreeCnt[limN], childCnt[limN];

void marca(int pos=0, int prev=-1) {
    isCTree[pos] = true;
    for(const auto &sig:adj[pos]) {
        if(sig.s == prev) continue;
        cols[pos][sig.f]++;
        childCnt[pos]++;
        marca(sig.s, pos);
        if(!isCTree[sig.s] || cols[sig.s].count(sig.f)) {
            isCTree[pos] = false;
            continue;
        }
        scTreeCnt[pos]++;
    }
    // printf("%d [%d] => %d %d %d %d\n", pos+1, prev+1, (int) cols[pos].size(), scTreeCnt[pos], childCnt[pos], isCTree[pos]? 1 : 0);
    // printf("\t");
    // for(const auto &sig:adj[pos]) {
    //     if(sig.s == prev) continue;
    //     printf("%d ", sig.s+1);
    // }
    // printf("\n");
}

void calca(int pos=0, int prev=-1, int prevCol=-1) {
    if(isCTree[pos])
        isGNode[pos] = true;
    // printf("@ %d => %d %d\n", pos+1, prev+1, prevCol);
    for(const auto &sig:adj[pos]) {
        if(sig.s == prev || sig.f==prevCol || cols[pos][sig.f] > 1) continue;
        if( childCnt[pos] - 1 != scTreeCnt[pos]-(isCTree[sig.s] && cols[sig.s].count(sig.f)==0? 1 : 0) ) continue;
        calca(sig.s, pos, sig.f);
    }
}

int main() {
    int N ;
    int ans = 0;
    
    scanf("%d", &N);
    for(int i=1; i<N; i++) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        a--, b--;
        adj[a].push_back({c, b});
        adj[b].push_back({c, a});
    }
    marca();
    calca();

    for(int i=0; i<N; i++)
        if(isGNode[i])
            ans++;

    printf("%d\n", ans);
    for(int i=0; i<N; i++)
        if(isGNode[i])
            printf("%d\n", i+1);
}
