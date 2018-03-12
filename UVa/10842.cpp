#include <bits/stdc++.h>
using namespace std;
#define par pair<int,int>
#define f first
#define s second

int prim(const vector <list<par>> &adj, int pos, vector <char> &usd) {
    priority_queue <par> Q;
    int ans = (1<<30);
    Q.push(par(0, pos));
    while(!Q.empty()) {
        int pos = Q.top().s, dst = Q.top().f;
        Q.pop();
        if(usd[pos])
            continue;
        usd[pos] = true;
        if(dst)
            ans = min(dst, ans);
        for(const auto &sig:adj[pos])
            Q.push(sig);
    }
    return ans;
}

int testCase() {
    int nodeCnt, edgeCnt;
    scanf("%d%d", &nodeCnt, &edgeCnt);
    vector <list<par>> adj(nodeCnt);
    vector <char> usd(nodeCnt);
    while(edgeCnt--) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        adj[a].push_back(par(c, b));
        adj[b].push_back(par(c, a));
    }
    int ans = (1<<30);
    for(int i=0; i<nodeCnt; i++) {
        if(usd[i])
            continue;
        ans = min(ans, prim(adj, i, usd));
    }
    return ans;
}

int main() {
    int tc;

    scanf("%d", &tc);
    for(int i=1; i<=tc; i++) {
        printf("Case #%d: %d\n", i, testCase());
    }
    
    return 0;
}
