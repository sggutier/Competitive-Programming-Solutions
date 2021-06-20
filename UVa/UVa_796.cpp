#include <bits/stdc++.h>
using namespace std;

int nodeCnt;
int dfsCnt;
vector <int> dfs_low, dfs_num, dfs_parent;
vector <list<int>> adj;
vector <pair<int,int>> critiLinks;

void semiTarjan(int pos) {
    dfs_num[pos] = dfs_low[pos] = ++dfsCnt;
    for(const int &sig:adj[pos]) {
        if(!dfs_low[sig]) {
            dfs_parent[sig] = pos;
            semiTarjan(sig);
            if(dfs_low[sig] > dfs_num[pos])
                critiLinks.push_back(make_pair(min(pos, sig), max(pos, sig)));
            dfs_low[pos] = min(dfs_low[pos], dfs_low[sig]);
        }
        else if(sig!=dfs_parent[pos]) {
            dfs_low[pos] = min(dfs_low[pos], dfs_num[sig]);
        }
    }
}

void testCase() {
    dfsCnt = 1;
    critiLinks.clear();
    adj = vector<list<int>>(nodeCnt);
    dfs_num = dfs_low = vector<int>(nodeCnt, 0);
    dfs_parent = vector<int>(nodeCnt, -1);
    for(int i=0; i<nodeCnt; i++) {
        int pos, edgeCnt, tmp;
        scanf("%d (%d)", &pos, &edgeCnt);
        while(edgeCnt--) {
            scanf("%d", &tmp);
            adj[pos].push_back(tmp);
        }
    }
    for(int i=0; i<nodeCnt; i++) {
        if(!dfs_low[i])
            semiTarjan(i);
    }
    sort(critiLinks.begin(), critiLinks.end());
    printf("%d critical links\n", (int) critiLinks.size());
    for(const auto &cl:critiLinks) {
        printf("%d - %d\n", cl.first, cl.second);
    }
    printf("\n");
}

int main() {
    while(scanf("%d", &nodeCnt)!=EOF ) {
        testCase();        
    }
    
    return 0;
}
