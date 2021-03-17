#include <bits/stdc++.h>
using namespace std;
const int LIM_N = 1.5e5 + 5;

vector <int> adj[LIM_N];
bool hasMark[LIM_N];
int rawCst[LIM_N];
pair<int,int> maxDep[LIM_N][2];
pair<int,int> ans = {1e9, -1};

void explDfs(const int pos, const int prev = -1) {
    maxDep[pos][0] = maxDep[pos][1] = {-1, -1};
    rawCst[pos] = 0 ;
    if(hasMark[pos])
        maxDep[pos][0] = {0, pos};
    for(const int nxt : adj[pos]) {
        if(nxt == prev)
            continue;
        explDfs(nxt, pos);
        if(maxDep[nxt][0].second == -1)
            continue;
        maxDep[pos][1] = max(maxDep[pos][1], {maxDep[nxt][0].first + 1, nxt});
        if(maxDep[pos][0] < maxDep[pos][1])
            swap(maxDep[pos][0], maxDep[pos][1]);
        rawCst[pos] += 2 + rawCst[nxt];
    }
}

void finDfs(const int pos, const int prev = -1, const int upDep = -1, const int upRaw = 0) {
    ans = min(ans, {rawCst[pos] + upRaw - max(maxDep[pos][0].first, upDep), pos});
    // printf("%d => %d\n", pos, rawCst[pos] + upRaw - max(maxDep[pos][0].first, upDep));
    // printf("\trawCst = %d, upDep = %d, upRaw = %d\n", rawCst[pos], upDep, upRaw);
    // printf("\tdeps => %d, %d    |||  %d, %d\n", maxDep[pos][0].first, maxDep[pos][0].second, maxDep[pos][1].first, maxDep[pos][1].second);
    for(const int nxt : adj[pos]) {
        if(nxt == prev)
            continue;
        if(maxDep[nxt][0].second == -1)
            continue;
        int newUD = max(upDep,
                        nxt != maxDep[pos][0].second? maxDep[pos][0].first :  maxDep[pos][1].first);
        if(newUD != -1)
            newUD ++;
        finDfs(nxt,
               pos,
               newUD,
               upRaw + rawCst[pos] - rawCst[nxt] - (newUD == -1? 2 : 0)
            );
    }
}

int main() {
    int N, K ;
    scanf("%d%d", &N, &K);
    for(int i=1, a, b; i < N; i++) {
        scanf("%d%d", &a, &b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for(int i=0, a; i < K; i++) {
        scanf("%d", &a);
        hasMark[a] = true;
    }
    explDfs(1);
    finDfs(1);
    printf("%d\n%d\n", ans.second, ans.first);
}
