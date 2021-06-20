#include <bits/stdc++.h>
using namespace std;
const int limN = 1e3 + 5;
const int dr[] = {-1, 0, 1, 0};
const int dc[] = {0, 1, 0, -1};
const int limD = 4;
#define r first
#define c second
typedef pair<int,int> par;

int R, C;
char mapa[limN][limN];
int vis[limN][limN];

bool isValid(par pos) {
    return 0 <= pos.r && pos.r < R && 0 <= pos.c && pos.c < C && mapa[pos.r][pos.c]=='0';
}

void testCase() {
    int ans[5] = {0, 0, 0, 0, 0};
    
    for(int i=0; i<R; i++) {
        scanf("%s", mapa[i]);
        for(int j=0; j<C; j++) {
            vis[i][j] = 0;
        }
    }

    int d = 1;
    par ini = par(R-1, 0);
    par pos = ini;
    //vis[pos.r][pos.c] ++;
    do {
        //printf("(%d %d) => ", pos.r, pos.c);
        if( isValid(par(pos.r + dr[(d+1)%limD], pos.c + dc[(d+1)%limD])) )
            d = (d+1)%limD;
        while( !isValid(par(pos.r + dr[d], pos.c + dc[d])) )
            d = (d+3)%limD;
        pos = par(pos.r + dr[d], pos.c + dc[d]);
        //printf("(%d %d)\n", pos.r, pos.c);
        vis[pos.r][pos.c] ++;
    } while(pos!=ini) ;

    for(int i=0; i<R; i++) {
        for(int j=0; j<C; j++) {
            if(mapa[i][j]!='1' && vis[i][j] <= 4)
                ans[vis[i][j]] ++;
        }
    }

    for(int i=0; i<=4; i++) {
        printf("%3d", ans[i]);
    }
    printf("\n");
}

int main() {
    while( scanf("%d%d", &R, &C)!=EOF && (R || C) )
        testCase();
}
