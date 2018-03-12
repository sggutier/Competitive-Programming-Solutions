#include <bits/stdc++.h>
using namespace std;
const int limN = 30;
typedef pair<int,int> par;
#define r first
#define c second
typedef pair<int, par> tri;
const int dr[] = {-1, 0, 1, 0};
const int dc[] = {0, 1, 0, -1};
const int mod = 20437;

int N;
char mapa[limN][limN];
int minP[limN][limN][limN];
int ways[limN][limN][limN];

bool isInside(par pos) {
    return 0 <= pos.r && pos.r < N && 0<= pos.c && pos.c < N;
}

par bfs(par ini, int fin) {
    memset(minP, 0, sizeof(minP));
    memset(ways, 0, sizeof(ways));
    queue <tri> Q;
    Q.push(tri(0, ini));
    minP[0][ini.r][ini.c] = 1;
    ways[0][ini.r][ini.c] = 1;
    while(!Q.empty()) {
        par pos = Q.front().c;
        int w = Q.front().r; Q.pop();
        int dst = minP[w][pos.r][pos.c]+1, tot = ways[w][pos.r][pos.c];
        if(w==fin) {
            return par(dst-1, tot);
        }
        for(int d=0; d<4; d++) {
            par sig (pos.r + dr[d], pos.c + dc[d]);
            if(!isInside(sig) || mapa[sig.r][sig.c]=='#' || (isalpha(mapa[sig.r][sig.c]) && mapa[sig.r][sig.c]-'A'>w+1))
                continue;
            int z = isalpha(mapa[sig.r][sig.c]) && mapa[sig.r][sig.c]-'A'==w+1? w+1 : w;
            if(minP[z][sig.r][sig.c]==0) {
                Q.push(tri(z, sig));
                minP[z][sig.r][sig.c] = dst;
            }
            if(minP[z][sig.r][sig.c]==dst) {
                ways[z][sig.r][sig.c] = (tot + ways[z][sig.r][sig.c])%mod;
            }
        }
    }
    return par(0, 0);
}

void testCase() {
    for(int i=0; i<N; i++)
        scanf("%s", mapa[i]);
    par ans(0, 0) ;
    par ini;
    int maxL = 0;
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            if(mapa[i][j]=='A')
                ini = par(i, j);
            if(isalpha(mapa[i][j]))
                maxL = max(maxL, mapa[i][j]-'A');
        }
    }
    ans = bfs(ini, maxL);
    if(ans.first==0)
        printf("Impossible\n");
    else
        printf("%d %d\n", ans.first-1, ans.second);
    
}

int main() {
    int tc = 0;
    while(scanf("%d", &N)!=EOF && N) {
        printf("Case %d: ", ++tc);
        testCase();
    }
}
