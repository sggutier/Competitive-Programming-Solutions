#include <bits/stdc++.h>
using namespace std;
const int LIM_N = 3005;

multiset <int> adj[LIM_N];
int N, E ;
int stps[LIM_N];
int ans[LIM_N];
set <int> fino ;


stack <int> finAns ;

void alFin(const int pos) {
    while(!adj[pos].empty()) {
        auto it = adj[pos].begin();
        int nxt = *it;
        adj[pos].erase(it);
        it = adj[nxt].find(pos);
        adj[nxt].erase(it);
        alFin(nxt);
    }
    finAns.push(pos);
}

int cntStt(const int pos) {
    if(fino.count(pos))
        return 0;
    // printf("Trying %d\n", pos);
    fino.insert(pos);
    int ans = 0 ;
    for(const int nxt : adj[pos])
        ans += cntStt(nxt);
    return ans + adj[pos].size();
}

void dfs(const int pos, const int sCnt) {
    // printf("%d %d\n", pos, sCnt);
    if(pos != stps[sCnt - 1]) {
        fino.clear();
        int x = cntStt(pos);
        // printf("------ %d\n", x);
        if(sCnt + x / 2 != E + 1)
            return ;
        // printf("||\n");
        // for(int i=1; i <= N; i++) {
        //     printf("%d => ", i);
        //     for(const int x : adj[i])
        //         printf("%d ", x);
        //     printf("\n");
        // }
        alFin(pos);
        for(int i=0; i < sCnt; i++)
            printf("%d ", ans[i]);
        // printf("| ");
        finAns.pop();
        while(!finAns.empty()) {
            printf("%d ", finAns.top());
            finAns.pop();
        }
        printf("\n");
        exit(0);
    }
    if(sCnt > E) {
        return ;
    }
    auto it = adj[pos].find(stps[sCnt]);
    while(it != adj[pos].end()) {
        ans[sCnt] = *it;
        auto xr = adj[ans[sCnt]].find(pos);
        adj[pos].erase(it);
        adj[ans[sCnt]].erase(xr);
        dfs(ans[sCnt], sCnt + 1);
        adj[pos].insert(ans[sCnt]);
        adj[ans[sCnt]].insert(pos);
        it = adj[pos].upper_bound(ans[sCnt]);
    }
}

int main() {
    scanf("%d%d", &N, &E);
    for(int i=0, pv=-1; i <= E; i++) {
        scanf("%d", &stps[i]);
        fino.insert(stps[i]);
        if(pv != -1) {
            adj[pv].insert(stps[i]);
            adj[stps[i]].insert(pv);
        }
        pv = stps[i];
    }
    // cout << T << endl;
    ans[0] = stps[0];
    dfs(stps[0], 1);
    printf("No solution\n");
}
