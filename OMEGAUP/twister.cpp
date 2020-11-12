#include <bits/stdc++.h>
using namespace std;
const int dr[] = {-1, 0, 1, 0};
const int dc[] = {0, -1, 0, 1};
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef pair<int, pii> tri;
#define r first
#define c second
const int limB = 16;
const int INF = 1e9;

int R, C;
vector<vi> accumH, accumV;
vector<vi> minPT[2];

int blockedPath(const pii &ini, const pii &fin, const int &dir) {
    switch(dir) {
        case 0:
            return accumV[ini.r][ini.c] - accumV[fin.r - 1][ini.c];
        case 1:
            return accumH[ini.r][ini.c] - accumH[ini.r][fin.c - 1];
        case 2:
            return accumV[fin.r][ini.c] - accumV[ini.r - 1][ini.c];
        default:
            return accumH[ini.r][fin.c] - accumH[ini.r][ini.c - 1];
    }
    return 0;
}

void dijkstra(const pii &ini, vector <vi> &minP) {
    priority_queue <tri> Q;
    minP.resize(R + 1);
    for(int i=0; i <= R; i++) {
        minP[i].resize(C+1, INF);
    }
    minP[ini.r][ini.c] = 2;
    Q.emplace(-1, ini);
    Q.emplace(-2, ini);
    while(!Q.empty()) {
        tri a ;
        pii pos;
        int dst ;
        a = Q.top(); Q.pop();
        dst = -a.first;
        pos = a.second;
        if(dst > minP[pos.r][pos.c]) {
            continue;
        }
        for(int d = 0; d < 4; d++) {
            for(int p = 1; p <= limB; p++) {
                pii sig = {pos.r + dr[d] * ((1 << p) - 1),
                           pos.c + dc[d] * ((1 << p) - 1)};
                if(sig.r < 1 || sig.r > R || sig.c < 1 || sig.c > C) {
                    break;
                }
                if(minP[sig.r][sig.c] <= dst + p) {
                    continue;
                }
                if(blockedPath(pos, sig, d)) {
                    continue;
                }
                minP[sig.r][sig.c] = dst + p;
                Q.emplace(-(dst + p), sig);
            }
        }
    }
}

int main() {
    int B ;
    pii inis[2];

    scanf("%d%d", &R, &C);
    accumH.resize(R+1);
    accumV.resize(R+1);
    for(int i=0; i <= R; i++) {
        accumH[i].resize(C+1);
        accumV[i].resize(C+1);
    }
    for(int i=0; i < 2; i++) {
        scanf("%d%d", &inis[i].r, &inis[i].c);
    }
    scanf("%d", &B);
    for(int i = 0, x, y; i < B; i++) {
        scanf("%d%d", &x, &y);
        accumH[x][y] = accumV[x][y] = 1;
    }

    for(int i=1; i <= R; i++) {
        for(int j=1; j <= C; j++) {
            accumH[i][j] += accumH[i][j-1];
            accumV[i][j] += accumV[i-1][j];
        }
    }
    for(int i=0; i < 2; i++) {
        dijkstra(inis[i], minPT[i]);
    }

    tri ans = {INF, {0, 0}};
    for(int i = 1; i <= R; i++) {
        for(int j = 1; j <= C; j++) {
            ans = min(ans,
                      {max(minPT[0][i][j],
                           minPT[1][i][j]), {i, j}});
        }
    }

    printf("%d\n", ans.first % INF - 1);
}
