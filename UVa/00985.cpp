#include <bits/stdc++.h>
using namespace std;
#define par pair<int,int>
#define tri pair<int, par>
#define r first
#define c second
const int MAX_N = 505;
const int dr[] = {-1, 0, 1, 0};
const int dc[] = {0, 1, 0, -1};
const int MAX_D = 4;
const int INF = 2147483647;

int R, C;
int mapa[MAX_N][MAX_N][MAX_D];
int minP[MAX_N][MAX_N][MAX_D];

inline int diro(const char &c) {
    switch(c) {
    case 'N':
        return 0;
    case 'E':
        return 1;
    case 'S':
        return 2;
    default:
        return 3;
    }
}

inline bool isInside(const par &pos) {
    return 0 <= pos.r && pos.r < R && 0 <= pos.c && pos.c < C;
}

int bfs() {
    memset(minP, 0, sizeof(minP));
    queue <tri> Q;
    Q.push(tri(0, par(0, 0)));
    minP[0][0][0] = 1;
    while(!Q.empty()) {
        int dir, dst;
        par pos = Q.front().second;
        dir = Q.front().first;
        Q.pop();
        dst = minP[pos.r][pos.c][dir] + 1;
        if(pos.r == R-1 && pos.c == C-1)
            return dst-1;
        int dir2 = (dir+1)%4, k = mapa[pos.r][pos.c][dir];
        for(int d=0; d<MAX_D; d++) {
            if((1<<d) & k) {
                par sig(pos.r + dr[d], pos.c + dc[d]);
                if(isInside(sig) && !minP[sig.r][sig.c][dir2]) {
                    minP[sig.r][sig.c][dir2] = dst;
                    Q.push(tri(dir2, sig));
                }
            }
        }
    }
    return 0;
}

inline int reco(const int &c) {
    return ((c%8)<<1) + (c&8? 1 : 0);
}

void testCase() {
    memset(mapa, 0, sizeof(mapa));
    for(int i=0; i<R; i++) {
        for(int j=0; j<C; j++) {
            if(i!=R-1 || j!=C-1) {
                char str[6];
                scanf("%s", str);
                for(char *s=str; *s; s++)
                    mapa[i][j][0] |= 1<<diro(*s);
                for(int d=1; d<MAX_D; d++)
                    mapa[i][j][d] = reco(mapa[i][j][d-1]);
            }
        }
    }
    int ans = bfs();
    if(ans)
        printf("%d\n", ans-1);
    else
        printf("no path to exit\n");
}

int main() {
    while(scanf("%d%d", &R, &C)!=EOF)
        testCase();
}
