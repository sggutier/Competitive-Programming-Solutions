#include <bits/stdc++.h>
using namespace std;
const int limN = 303;
const int limD = 4;
const int limP = 3;
#define par pair<int,int>
#define r first
#define c second
#define tri pair<par, int>
const int dr[] = {-1, 0, 1, 0};
const int dc[] = {0, 1, 0, -1};


int rowCnt, colCnt;
int minP[limN][limN][limP];
char mapa[limN][limN];

inline bool validPos(const par &pos)  {
    return 0 <= pos.r && pos.r < rowCnt && 0 <= pos.c && pos.c < colCnt && mapa[pos.r][pos.c]!='#';
}


void bfs(par ini) {
    memset(minP, -1, sizeof(minP));
    minP[ini.r][ini.c][0] = 0;
    queue <tri> Q;

    Q.push(tri(ini, 0));
        
    while(!Q.empty()) {
        par pos = Q.front().r;
        int stp = Q.front().c + 1, pts = stp%3, dst = minP[pos.r][pos.c][stp-1] + 1;
        Q.pop();
        for(int d=0; d<4; d++) {
            bool works = true;
            for(int k=1; k<=stp; k++) {
                if(!validPos(par(pos.r + dr[d]*k, pos.c + dc[d]*k))) {
                    works = false;
                    break;
                }
            }
            par sig = par(pos.r + dr[d]*stp, pos.c + dc[d]*stp);
            if(works && minP[sig.r][sig.c][pts]==-1) {
                minP[sig.r][sig.c][pts] = dst;
                Q.push(tri(sig, pts));
            }
        }
    }
}

void testCase() {
    par ini, fin;
    
    scanf("%d%d", &rowCnt, &colCnt);
    for(int i=0; i<rowCnt; i++) {
        scanf("%s", mapa[i]);
        for(int j=0; j<colCnt; j++) {
            if(mapa[i][j]=='S')
                ini = par(i, j);
            else if(mapa[i][j]=='E')
                fin = par(i, j);
        }
    }

    bfs(ini);
    int ans = (1<<30);
    for(int k=0; k<3; k++) {
        if(minP[fin.r][fin.c][k]!=-1)
            ans = min(ans, minP[fin.r][fin.c][k]);
    }
    if(ans==(1<<30))
        printf("NO\n");
    else
        // printf("%d\n", (int) ceil(ans/3.0));
        printf("%d\n", ans);
}


int main() {
    int tc;

    scanf("%d", &tc);
    while(tc--)
        testCase();
    
    return 0;
}
