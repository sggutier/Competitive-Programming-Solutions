#include <bits/stdc++.h>
using namespace std;

int nodeCnt, sccCnt, dfsCnt;
vector <int> dfs_min, dfs_num, scc_id;
vector <bool> active;
vector <list<int>> adj;
stack <int> S;

void tarjanSCC(int pos) {
    dfs_min[pos] = dfs_num[pos] = ++dfsCnt;
    active[pos] = true;
    S.push(pos);
    // printf("%d %d (", pos, dfsCnt);
    // for(const int &sig:adj[pos])
    //     printf("%d ", sig);
    // printf(")\n");
    for(const int &sig:adj[pos]) {
        if(!dfs_num[sig]) 
            tarjanSCC(sig);
        if(active[sig])
            dfs_min[pos] = min(dfs_min[pos], dfs_min[sig]);
    }
    if(dfs_min[pos]!=dfs_num[pos])
        return;
    sccCnt++;
    int num ;
    // printf("%d =>", pos);
    do {
        num = S.top(); S.pop();
        active[num] = false;
        scc_id[num] = sccCnt;
        // printf(" %d", num);
    } while(!S.empty() && num!=pos);
    // printf("\n");
}

void testCase(int edgeCnt) {
    dfsCnt = sccCnt = 0;
    scc_id = dfs_num = dfs_min = vector<int>(nodeCnt);
    active = vector<bool>(nodeCnt);
    adj = vector<list<int>> (nodeCnt);

    while(edgeCnt--) {
        int a, b;
        scanf("%d%d", &a, &b);
        adj[a-1].push_back(b-1);
    }

    for(int i=0; i<nodeCnt; i++) {
        if(!dfs_num[i])
            tarjanSCC(i);
    }

    for(int i=0; i<nodeCnt; i++) {
        for(const int &sig:adj[i]) {
            if(scc_id[i]!=scc_id[sig])
                active[scc_id[sig]] = true;
        }
    }

    int ans = 0;
    for(int i=0; i<sccCnt; i++) 
        if(!active[i])
            ans ++;

    printf("%d\n", ans);
}

int main() {
    int tc;

    scanf("%d", &tc);
    while(tc--) {
        int a;
        scanf("%d%d", &nodeCnt, &a);
        testCase(a);
    }
    
    return 0;
}
