#include <bits/stdc++.h>
using namespace std;
const int dr[] = {-1, 0, 1, 0};
const int dc[] = {0 ,1, 0, -1};
typedef pair<int,int> pii;
#define r first
#define c second
const int limN = 505;

int R, C ;
char mapa[limN][limN];
pii iniP, finP;

bool funca() {
    int libCnt = 0;

    for(int d=0; d<4; d++) {
        if(mapa[finP.r + dr[d]][finP.c + dc[d]] == '.')
            libCnt ++;
    }

    if(iniP == finP) {
        if(mapa[iniP.r][iniP.c] == '.')
            libCnt --;
        return libCnt >= 1;
    }
    mapa[iniP.r][iniP.c] = '.';
    libCnt = 0;
    for(int d=0; d<4; d++) {
        if(mapa[finP.r + dr[d]][finP.c + dc[d]] == '.')
            libCnt ++;
    }

    if(mapa[finP.r][finP.c] == 'X') {
        mapa[finP.r][finP.c] = '.';
        libCnt ++;
    }

    queue <pii> Q ;
    Q.push(iniP);
    mapa[iniP.r][iniP.c] = 'X';
    while(!Q.empty()) {
        pii pos;
        pos = Q.front(); Q.pop();
        for(int d=0; d<4; d++) {
            pii sp = {pos.r + dr[d], pos.c + dc[d]};
            if(mapa[sp.r][sp.c] == 'X')
                continue;
            mapa[sp.r][sp.c] = 'X';
            Q.push(sp);
        }
    }

    return mapa[finP.r][finP.c] == 'X' && libCnt >= 2;
}

int main() {
    scanf("%d%d", &R, &C);
    for(int i=0; i<=R+1; i++)
        for(int j=0; j<=C+1; j++)
            mapa[i][j] = 'X';
    for(int i=1; i<=R; i++) {
        scanf("%s", mapa[i]+1);
        mapa[i][C+1] = 'X';
    }
    scanf("%d%d", &iniP.r, &iniP.c);
    scanf("%d%d", &finP.r, &finP.c);

    printf("%s\n", funca()? "YES" : "NO");
}
