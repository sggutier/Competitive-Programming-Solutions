#include <bits/stdc++.h>
using namespace std;
const int limN = 2e4 + 5;

int nodCnt;
list <int> adj[limN];
int dfs_min[limN], dfs_num[limN];
bool active[limN];
int dfsCnt;
stack <int> tarjan_S;
list <int> grups[limN];
int boss[limN];
int antCnt[limN];
int sum[limN];

void tarjan(int pos) {
    dfs_min[pos] = dfs_num[pos] = ++dfsCnt;
    active[pos] = true;
    tarjan_S.push(pos);
    for(const int &sig:adj[pos]) {
        if(!dfs_num[sig])
            tarjan(sig);
        if(active[sig])
            dfs_min[pos] = min(dfs_min[pos], dfs_min[sig]);
    }
    if(dfs_min[pos]!=dfs_num[pos])
        return;
    int sig ;
    // printf("Grup of %d => ", pos+1);
    do {
        sig = tarjan_S.top(); tarjan_S.pop();
        active[sig] = false;
        grups[pos].push_back(sig);
        boss[sig] = pos;
        // printf("%d ", sig+1);
    } while(sig!=pos) ;
    // printf("\n");
}

void cuenta() {
    for(int i=0; i<nodCnt; i++) {
        if(boss[i]!=i)
            continue;
        for(const int &g:grups[i]) {
            for(const int &sig:adj[g]) {
                if(boss[sig]!=i)
                    antCnt[boss[sig]]++;
            }
        }
    }

    queue <int> Q;
    for(int i=0; i<nodCnt; i++)
        if(boss[i]==i && !antCnt[i])
            Q.push(i);

    while(!Q.empty()) {
        int pos = Q.front(); Q.pop();
        sum[pos] += grups[pos].size();
        // printf("Sum of %d is %d\n", pos+1, sum[pos]);
        for(const int &g:grups[pos]) {
            for(const int &sig:adj[g]) {
                int j = boss[sig];
                if(j==pos)
                    continue;
                if(!(--antCnt[j]))
                    Q.push(j);
                sum[j] = max(sum[j], sum[pos]);
            }
        }
    }
}

void testCase() {
    memset(sum, 0, sizeof(sum));
    memset(antCnt, 0, sizeof(antCnt));
    dfsCnt = 0;
    memset(dfs_num, 0, sizeof(dfs_num));
    
    int edgCnt;
    scanf("%d%d", &nodCnt, &edgCnt);
    for(int i=0; i<nodCnt; i++) {
        adj[i].clear();
        grups[i].clear();
    }
    while(edgCnt--) {
        int a, b;
        scanf("%d%d", &a, &b);
        adj[a-1].push_back(b-1);
    }

    for(int i=0; i<nodCnt; i++)
        if(!dfs_num[i])
            tarjan(i);

    cuenta();

    int ans = 0;
    for(int i=0; i<nodCnt; i++)
        ans = max(ans, sum[i]);

    printf("%d\n", ans);
}

int main() {
    int tc;
    scanf("%d", &tc);
    while(tc--)
        testCase();
}
