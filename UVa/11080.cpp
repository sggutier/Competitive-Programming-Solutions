#include <bits/stdc++.h>
using namespace std;

void testCase(int nodeCnt, int edgeCnt) {
    vector <int> color(nodeCnt, 2);
    vector<list<int>> adj(nodeCnt);
    queue <int> Q;
    int ans = 0;
    
    while(edgeCnt--) {
        int a, b;
        scanf("%d%d", &a, &b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for(int i=0; i<nodeCnt; i++) {
        if(color[i]!=2)
            continue;
        int cnt1 = 0, cntTot = 0;
        color[i] = 0;
        Q.push(i);
        while(!Q.empty()) {
            int pos = Q.front(); Q.pop();
            cnt1 += color[pos];
            cntTot ++;
            for(const int &sig:adj[pos]) {
                if(color[sig]==2) {
                    color[sig] = 1-color[pos];
                    Q.push(sig);
                }
                else if(color[sig]==color[pos]){
                    printf("-1\n");
                    return;
                }
            }
        }
        ans += max(min(cnt1, cntTot-cnt1), 1);
    }

    printf("%d\n", ans);
}

int main() {
    int tc;

    scanf("%d", &tc);
    while(tc--) {
        int a, b;
        scanf("%d%d", &a, &b);
        testCase(a,b);
    }
    
    return 0;
}
