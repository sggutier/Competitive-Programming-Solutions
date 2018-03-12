#include <bits/stdc++.h>
using namespace std;

int nodeCnt, dfsCnt;
vector <list<int>> adj;
vector <int> dfs_low, dfs_num, dfs_parent, child_num;
vector <bool> isCritiNode;

void semiTarjan(int pos) {
    dfs_num[pos] = dfs_low[pos] = ++dfsCnt;
    for(const int &sig:adj[pos]) {
        if(dfs_num[sig]==0) {
            dfs_parent[sig] = pos;
            child_num[pos] ++;
            semiTarjan(sig);
            if(dfs_low[sig] >= dfs_num[pos])
                isCritiNode[pos] = true;
            dfs_low[pos] = min(dfs_low[pos], dfs_low[sig]);
        }
        else if(dfs_parent[pos] != sig)
            dfs_low[pos] = min(dfs_low[pos], dfs_num[sig]);
    }
}

void dfs(int pos) {
    stack <int> S;
    dfs_num[pos] = dfsCnt;
    S.push(pos);
    while(!S.empty()) {
        pos = S.top(); S.pop();
        for(const int &sig:adj[pos]) {
            if(dfs_num[sig]!=dfsCnt) {
                dfs_num[sig] = dfsCnt;
                S.push(sig);
            }
        }
    }
}

void testCase(int bombCnt) {
    dfsCnt = 0 ;
    adj = vector<list<int>> (nodeCnt);
    child_num = dfs_num = dfs_low = vector<int> (nodeCnt, 0);
    dfs_parent = vector<int> (nodeCnt, -1);
    isCritiNode = vector<bool> (nodeCnt, false);
    while(true) {
        int a, b;
        scanf("%d%d", &a, &b);
        if(a == -1)
            break;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int comps = 0;
    for(int i=0; i<nodeCnt; i++) {
        if(dfs_low[i]==0) {
            comps += 1 ;
            semiTarjan(i);
            isCritiNode[i] = child_num[i] > 1;
            child_num[i] -= 1;
        }
    }
    vector <pair<int,int>> ans (nodeCnt);
    for(int i=0; i<nodeCnt; i++) {
        if(!isCritiNode[i]) {
            ans[i] = make_pair(comps, -i);
            continue ;
        }
        dfs_num[i] =  ++dfsCnt ;
        int w = 0;
        for(int j=0; j<nodeCnt; j++) {
            if(dfs_num[j]!=dfsCnt) {
                dfs(j);
                w ++;
            }
        }
        ans[i] = make_pair(w, -i);
    }
    sort(ans.begin(), ans.end());
    for(int i=0; i<bombCnt; i++)
        printf("%d %d\n", -ans[nodeCnt-1-i].second, ans[nodeCnt-1-i].first);
    printf("\n");
}
              
int main() {
    int b;

    while(scanf("%d%d", &nodeCnt, &b)!=EOF && (nodeCnt || b))
        testCase(b);
    
    return 0;
}
