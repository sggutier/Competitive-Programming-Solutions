#include <bits/stdc++.h>
using namespace std;
const int limN = 1005;
const int inf = (1<<30);
#define par pair<int,int>
#define tri pair<int,par>
#define r first
#define c second
int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};

int rows, cols;
bool mapaBeta[limN][limN];
bool mapa[limN][limN];
int minP[4][limN][limN];

inline bool isValidPos(const tri &pos) {
    return 0 <= pos.second.r && pos.second.r < rows && 0 <= pos.second.c && pos.second.c < cols && !mapa[pos.second.r][pos.second.c] ;
}

void bfs(tri pos) {
    queue <tri> Q;
    tri sig ;
    minP[pos.r][pos.second.r][pos.second.c] = 1;
    Q.push(pos);
    while(!Q.empty()) {
        pos = Q.front(); Q.pop();
        // cout << pos.r << " " << pos.c.r << " " << pos.c.c << " =>> " << minP[pos.r][pos.second.r][pos.second.c] -1  << endl;
        for(int d = 1; d<4; d += 2) {
            sig = pos;
            sig.r = (sig.r+d)%4;
            if(!minP[sig.first][sig.second.r][sig.second.c]) {
                Q.push(sig);
                minP[sig.r][sig.c.r][sig.c.c] = minP[pos.r][pos.second.r][pos.second.c] +1;
            }
        }
        for(int k = 1; k<4; k ++ ) {
            sig = pos;
            sig.c.r += dr[sig.r]*k;
            sig.c.c += dc[sig.r]*k;
            if(isValidPos(sig)) {
                if(!minP[sig.first][sig.second.r][sig.second.c]) {
                    Q.push(sig);
                    minP[sig.r][sig.c.r][sig.c.c] = minP[pos.r][pos.second.r][pos.second.c] +1;
                }
            }
            else
                break;
        }
    }
}

void testCase() {
    par ini, fin;
    char ren[500];
    tri stp;
    int ans = inf;

    for(int i=0; i<rows; i++) {
        for(int j=0; j<cols; j++) {
            int k ;
            scanf("%d", &k);
            mapaBeta[i][j] = k;
            for(int d=0; d<4; d++)
                minP[d][i][j] = 0;
            if(i && j)
                mapa[i-1][j-1] = mapaBeta[i][j] || mapaBeta[i-1][j] || mapaBeta[i][j-1] || mapaBeta[i-1][j-1];
        }
    }
    // for(int i=0; i+1<rows; i++) {
    //     for(int j=0; j+1<cols; j++) {
    //         printf("%d", mapa[i][j]);
    //     }
    //     printf("\n");
    // }

    scanf("%d%d", &ini.r, &ini.c);
    ini.r --, ini.c --;
    scanf("%d%d", &fin.r, &fin.c);
    fin.r --, fin.c --;
    scanf("%s", ren);
    switch(ren[0]) {
    case 'n':
        stp.r = 0;
        break ;
    case 'e':
        stp.r = 1;
        break;
    case 's':
        stp.r = 2;
        break;
    case 'w':
        stp.r = 3;
        break; 
    }
    stp.c = ini;

    rows--, cols--;
    bfs(stp);
    for(int d=0; d<4; d++)
        if(minP[d][fin.r][fin.c])
            ans = min(ans, minP[d][fin.r][fin.c]);
    printf("%d\n", ans%inf -1);
}

int main() {
    while(scanf("%d%d", &rows, &cols)!=EOF && (rows || cols)) {
        testCase();
    }
}
