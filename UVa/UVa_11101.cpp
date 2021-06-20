#include <bits/stdc++.h>
using namespace std;
const int limN = 2001;
const int inf = (1<<30);
#define par pair<int,int>
#define r first
#define c second
const int dr[] = {-1, 0, 1, 0};
const int dc[] = {0, 1, 0, -1};

int minP[limN][limN];

inline bool validPos(par pos) {
    return 0 <= pos.r && pos.r < limN && 0 <= pos.c && pos.c < limN && !minP[pos.r][pos.c];
}

void bfs(queue <par> &Q) {
    while(!Q.empty()) {        
        par pos = Q.front(); Q.pop();
        // cout << pos.r << " " << pos.c << " " << minP[pos.r][pos.c] << endl;
        for(int d=0; d<4; d++) {
            par sig = pos;
            sig.r += dr[d]; sig.c += dc[d];
            if(validPos(sig)) {
                minP[sig.r][sig.c] = minP[pos.r][pos.c] +1;
                Q.push(sig);
            }
        }
    }
}

void testCase(int posCnt) {
    memset(minP, 0, sizeof(minP));
    queue <par> Q;
    par pos;
    int ans = inf;
    while(posCnt--) {
        scanf("%d%d", &pos.r, &pos.c);
        minP[pos.r][pos.c] = 1;
        Q.push(pos);
    }
    bfs(Q);
    scanf("%d", &posCnt);
    while(posCnt--) {
        scanf("%d%d", &pos.r, &pos.c);
        ans = min(ans, minP[pos.r][pos.c]);
    }
    printf("%d\n", ans-1);
}

int main() {
    int k;
    while(scanf("%d", &k)!=EOF && k)
        testCase(k);
}
