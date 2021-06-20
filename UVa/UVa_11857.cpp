#include <bits/stdc++.h>
using namespace std;
#define par pair<int,int>
#define f first
#define s second

void testCase(int nodeCnt, int edgeCnt) {    
    vector<list<par>> adj(nodeCnt);
    int ans = -(1<<30);
    vector<char> usd(nodeCnt);
    int aCnt = 0;

    for(int i=0; i<edgeCnt; i++) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        adj[a].push_back(par(-c,b));
        adj[b].push_back(par(-c,a));
    }

    priority_queue <par> Q;
    Q.push(par((1<<30), 0));
    while(!Q.empty()) {
        int pos = Q.top().second, dst = -Q.top().first; Q.pop();
        if(usd[pos])
            continue;
        usd[pos] = true;
        ans = max(ans, dst);
        aCnt ++;
        for(const auto &sig:adj[pos])
            Q.push(sig);
    }

    if(aCnt!=nodeCnt) {
        printf("IMPOSSIBLE\n");
        return;
    }
    printf("%d\n", ans);
}

int main() {
    int nodeCnt, edgeCnt;

    while(scanf("%d%d", &nodeCnt, &edgeCnt)!=EOF && (nodeCnt || edgeCnt))
        testCase(nodeCnt, edgeCnt);
    
    
    return 0;
}
