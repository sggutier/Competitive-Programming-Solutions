#include <bits/stdc++.h>
using namespace std;
const int limN = 27;
#define par pair<int,int>

list <par> adj[limN];
bool usd[limN];

int longestDFS(int pos) {
    int ans = 0;
    for(const auto &sig:adj[pos]) {
        if(usd[sig.second])
            continue;
        usd[sig.second] = true;
        ans = max(ans, 1 + longestDFS(sig.first));
        usd[sig.second] = false;
    }
    return ans;
}

void testCase(int nodeCnt, int edgeCnt) {
    for(int i=0; i<=nodeCnt; i++)
        adj[i].clear();
    while(edgeCnt--) {
        int a, b;
        scanf("%d%d", &a, &b);
        a++, b++;
        adj[a].push_back(par(b, edgeCnt));
        adj[b].push_back(par(a, edgeCnt));
    }
    int ans = 0;
    for(int i=1; i<=nodeCnt; i++)
        ans = max(ans,  longestDFS(i));
    printf("%d\n", ans);
}

int main() {
    int a, b;

    while(scanf("%d%d", &a, &b)!=EOF && (a || b)) {
        testCase(a, b);
    }
    
    return 0;
}
