#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> par;
typedef pair<int, par> tri;
const int limD = 6;
const int limN = 35;
const int inf = (1<<29);
const int dl[] = {-1, 0, 0, 0, 0, 1};
const int dr[] = {0, -1, 0 ,1, 0, 0};
const int dc[] = {0, 0, -1, 0, 1, 0};
#define r second.first
#define c second.second
#define l first

int L, R, C;
char mapa[limN][limN][limN];
int minP[limN][limN][limN];

bool isInside(const tri &A) {
    return 0 <= A.l && A.l < L && 0 <= A.r && A.r < R && 0 <= A.c && A.c < C && mapa[A.l][A.r][A.c]!='#';
}

int bfs(tri pos) {
    minP[pos.l][pos.r][pos.c] = 0;
    queue <tri> Q ;
    Q.push(pos);
    while(!Q.empty()) {
        pos = Q.front(); Q.pop();
        int dst = minP[pos.l][pos.r][pos.c] + 1;
        // printf("%d %d %d => %d\n", pos.l, pos.r, pos.c, dst-1);
        if(mapa[pos.l][pos.r][pos.c]=='E')
            return dst-1;
        for(int d=0; d<limD; d++) {
            tri sig = tri(pos.l + dl[d], par(pos.r + dr[d], pos.c + dc[d]));
            // printf("\t%d %d %d => %d\n", sig.l, sig.r, sig.c, dst);
            if(isInside(sig) && minP[sig.l][sig.r][sig.c]==inf) {
                minP[sig.l][sig.r][sig.c] = dst;
                Q.push(sig);
            }
        }
    }
    return inf;
}

void testCase() {
    tri ini = tri(0, par(0, 0));
    for(int i=0; i<L; i++) {
        for(int j=0; j<R; j++) {
            scanf("%s", mapa[i][j]);
            for(int k=0; k<C; k++) {
                minP[i][j][k] = inf;
                if(mapa[i][j][k]=='S')
                    ini = tri(i, par(j, k));
            }
        }
    }

    int tim = bfs(ini);
    if(tim==inf)
        printf("Trapped!\n");
    else
        printf("Escaped in %d minute(s).\n", tim);
}

int main() {
    while(scanf("%d%d%d", &L, &R, &C)!=EOF && (L || R || C)) {
        testCase();
    }
}
