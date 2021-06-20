#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> par;
#define f first
#define s second
const int limN = 1e6 + 5;

int N, E;
priority_queue <par> Q;
list <par> adj[limN];
bool usd[limN];

void testCase() {
    int ansB = 0, ans = 0;

    usd[0] = false;
    adj[0].clear();
    for(int i=1; i<N; i++) {
        adj[i].clear();
        usd[i] = false;
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        ansB += c;
    }
    scanf("%d", &E);
    for(int i=0; i<E; i++) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        a--, b--, c*=-1;
        adj[a].push_back({c, b});
        adj[b].push_back({c, a});
    }
    scanf("%d", &E);
    for(int i=0; i<E; i++) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        a--, b--, c*=-1;
        adj[a].push_back({c, b});
        adj[b].push_back({c, a});
    }

    Q.push({0, 0});
    while(!Q.empty()) {
        int pos = Q.top().s, sm = -Q.top().f; Q.pop();
        if(usd[pos])
            continue;
        usd[pos] = true;
        ans += sm;
        for(const auto &p:adj[pos])
            if(!usd[p.s])
                Q.push(p);
    }

    printf("%d\n", ansB);
    printf("%d\n", ans);
}

int main() {
    int tc = 0;
    while(scanf("%d", &N)!=EOF) {
        if(tc++)
            printf("\n");
        testCase();
    }
}
