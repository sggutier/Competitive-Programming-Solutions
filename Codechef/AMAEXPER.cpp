#include <bits/stdc++.h>
using namespace std;
const int LIM_N = 1e5 + 5 ;
typedef pair<int,int> pii;

vector <pii> adj[LIM_N];
int ans[LIM_N];
int dep[LIM_N];
int maxDep[LIM_N];
set <pii>* pss[LIM_N];

void dfs(const int pos = 1, const int prev = -1) {
    pii maxD0 = {0, -1}, maxD1 = {0, -1};
    for(const auto &e : adj[pos]) {
        if(e.second == prev)
            continue ;
        int nxt = e.second;
        int dst = e.first;
        dep[nxt] = dep[pos] + dst;
        dfs(nxt, pos);
        maxD1 = max(maxD1, {dst + maxDep[nxt], nxt});
        if(maxD0 < maxD1)
            swap(maxD0, maxD1);
    }
    maxDep[pos] = maxD0.first;
    pss[pos] = NULL;
    for(const auto &e : adj[pos]) {
        if(e.second == prev)
            continue ;
        int nxt = e.second;
        int novD = nxt != maxD0.second? maxD0.first : maxD1.first;
        if(novD == maxD0.first) {
            delete pss[nxt];
            pss[nxt] = NULL;
            continue;
        }
        pss[pos] = pss[nxt];
        int potPos, potDst ;
        pii minBw = {maxD0.first, pos};
        for(auto it = pss[pos]->begin(); it != pss[pos]->end(); ) {
            potPos = it->second;
            potDst = dep[potPos] - dep[pos] + novD;
            if(it->first < potDst) {
                minBw = min(minBw, {potDst, potPos});
                it = pss[pos]->erase(it);
            }
            else if(potDst < maxD0.first)
                break;
        }
        if(minBw.first != maxD0.first)
            pss[pos]->insert(minBw);
    }
    if(pss[pos] == NULL)
        pss[pos] = new set<pii>();
    pss[pos]->insert({maxDep[pos], pos});
    ans[pos] = pss[pos]->begin()->first;
}

void testCase() {
    int N ;
    scanf("%d", &N) ;
    for(int i=1, a, b, c; i < N; i++) {
        scanf("%d%d%d", &a, &b, &c);
        adj[a].push_back({c, b});
        adj[b].push_back({c, a});
    }
    dfs();
    delete pss[1];
    pss[1] = NULL;
    for(int i=1; i <= N; i++) {
        adj[i].clear();
        printf("%d\n", ans[i]);
    }
}

int main() {
    int tc ;
    for(scanf("%d", &tc); tc; tc--) {
        testCase();
    }
}
