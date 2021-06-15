#include <bits/stdc++.h>
using namespace std;
const int limN = 100000 + 5;
const int inf = 2147483647;
typedef pair<int, int> pii;
#define f first
#define s second

int N, E;
bool usd[limN][2];
queue <pii> Q;
vector<pii> adj[limN];

int calca(int msk) {
    memset(usd, 0, sizeof(usd));
    int pos, t ;
    usd[0][0] = true;
    Q.push({0, 0});

    while(!Q.empty()) {
        pos = Q.front().f, t = Q.front().s; Q.pop();
        printf("%d %d\n", pos, t);
        for(const pii &sig:adj[pos]) {
            int w = (sig.f & msk) ^ t;
            int c = w==0? 0 : 1;
            if(usd[sig.s][c]) continue;
            usd[sig.s][c] = true;
            Q.push({sig.s, w});
        }
    }
    printf("----\n");

    return usd[N][1]? msk : 0;
}

int main() {
    scanf("%d%d", &N, &E);
    for(int i=0, a, b, c; i<E; i++) {
        scanf("%d%d%d", &a, &b, &c);
        a--, b--;
        adj[a].push_back({c, b});
        adj[b].push_back({c, a});
    }

    int ans = 0;
    for(int i=0; i<=3; i++)
        ans += calca(1<<i);

    printf("%d\n", ans);
}
