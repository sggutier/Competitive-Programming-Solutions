#include <bits/stdc++.h>
using namespace std;
#define par pair<int,int>
#define f first
#define s second
#define r second.second.first
#define c second.second.second
#define dira second.first
#define cyca first
#define tri pair<int, par>
#define kva pair<int, tri>
#define mp make_pair
const int dr[] = {-1, 0, 1, 0};
const int dc[] = {0, 1, 0, -1};
const int limN = 30;
const int limCyc = 5;
const int limD = 4;
const int inf = (1<<30);

int rowCnt, colCnt;
char mapa[limN][limN];
int minP[limCyc][limD][limN][limN];

inline bool validPos(kva pos) {
    return 0 <= pos.r && pos.r < rowCnt && 0 <= pos.c && pos.c < colCnt && mapa[pos.r][pos.c]!='#' && !minP[pos.cyca][pos.dira][pos.r][pos.c];
}

void bfs(par ini) {
    queue <kva> Q;
    minP[0][0][ini.f][ini.s] = 1;
    Q.push(mp(0, mp(0, ini)));
    while(!Q.empty()) {
        par pos = Q.front().s.s;
        int dir = Q.front().dira, cyc = Q.front().cyca;
        int dst = minP[cyc][dir][pos.f][pos.s] +1;
        Q.pop();
        for(int sum=-1; sum<=1; sum+=2) {
            if(validPos(mp(cyc, mp((dir+sum+limD)%limD, pos)))) {
                minP[cyc][(dir+sum+limD)%limD][pos.f][pos.s] = dst;
                Q.push(mp(cyc, mp((dir+sum+limD)%limD, pos)));
            }
        }
        pos.f += dr[dir], pos.s += dc[dir];
        cyc = (cyc+1)%limCyc;
        if(validPos(mp(cyc, mp(dir, pos)))) {
            minP[cyc][dir][pos.f][pos.s] = dst;
            Q.push(mp(cyc, mp(dir, pos)));
        }
    }
}

void testCase() {
    memset(minP, 0, sizeof(minP));
    par ini=mp(0,0), fin=ini;
    for(int i=0; i<rowCnt; i++) {
        scanf("%s", mapa[i]);
        for(int j=0; j<colCnt; j++) {
            if(mapa[i][j]=='S') {
                ini = par(i,j);
                mapa[i][j] = '.';
            }
            else if(mapa[i][j]=='T') {
                fin = par(i, j);
                mapa[i][j] = '.';
            }
        }
    }
    bfs(ini);
    int ans = inf;
    for(int d=0; d<limD; d++) {
        if(minP[0][d][fin.f][fin.s])
            ans = min(ans, minP[0][d][fin.f][fin.s] -1);
    }
    if(ans==inf) 
        printf("destination not reachable\n");
    else
        printf("minimum time = %d sec\n", ans);
}

int main() {
    for(int i=1; scanf("%d%d", &rowCnt, &colCnt) && (rowCnt || colCnt); i++) {
        if(i>1)
            printf("\n");
        printf("Case #%d\n", i);
        testCase();
    }
    
    return 0;
}
