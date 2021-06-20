#include <bits/stdc++.h>
using namespace std;
const int limN = 2005;

int nodCnt;
list<int> adj[limN];

int dfsCnt, sccCnt;
int dfs_min[limN], dfs_num[limN];
bool active[limN];
stack <int> S;

void tarjanSCC(int pos) {
    dfs_min[pos] = dfs_num[pos] = ++dfsCnt;
    active[pos] = true;
    S.push(pos);
    for(const int &sig:adj[pos]) {
        if(!dfs_num[sig])
            tarjanSCC(sig);
        if(active[sig])
            dfs_min[pos] = min(dfs_min[pos], dfs_min[sig]);
    }
    if(dfs_min[pos]!=dfs_num[pos])
        return;
    sccCnt ++;
    int w;
    do {
        w = S.top(); S.pop();
        active[w] = false;
    } while(w!=pos);
}

void testCase(int edgCnt) {
    for(int i=0; i<nodCnt; i++) {
        adj[i].clear();
        active[i] = (dfs_num[i] = dfs_min[i] = 0);        
    }
    while(edgCnt--) {
        int a, b, bidi;
        scanf("%d%d%d", &a, &b, &bidi);
        a--, b--;
        adj[a].push_back(b);
        if(bidi==2)
            adj[b].push_back(a);
    }
    sccCnt = dfsCnt = 0;
    for(int i=0; i<nodCnt; i++)
        if(!dfs_num[i])
            tarjanSCC(i);
    
    printf("%d\n", sccCnt==1);
}

int main() {
    int w;

    while(scanf("%d%d", &nodCnt, &w)!=EOF && (nodCnt || w))
        testCase(w);
    
    return 0;
}
