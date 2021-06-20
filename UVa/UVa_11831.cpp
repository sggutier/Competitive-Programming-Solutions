#include <bits/stdc++.h>
using namespace std;
int dr[] = {-1, 0, 1, 0};
int dc[] = {0, -1, 0, 1};
const int limN = 105;
const int limI = 5e4 + 5 ;
int trad[300];
#define par pair<int, int>
#define r first
#define c second

par sigPos(int rens, int cols, char mapa[limN][limN], par pos, int d) {
    par sig = pos;
    sig.r += dr[d];
    sig.c += dc[d];
    if(sig.r<0 || sig.r>=rens || sig.c<0 || sig.c>=cols || mapa[sig.r][sig.c]=='#')
        sig = pos;
    return sig;
}

void testCase(int rens, int cols, int instCnt) {
    char mapa[limN][limN];
    char insts[limI];
    int ans = 0;
    par pos = par(0, 0);
    int dir = 0;
    for(int i=0; i<rens; i++) {
        scanf("%s", mapa[i]);
        for(int j=0; j<cols; j++) {
            if(mapa[i][j]=='*' || mapa[i][j]=='.' || mapa[i][j]=='#')
                continue ;
            pos = par(i, j);
            dir = trad[(int) mapa[i][j]];
            mapa[i][j] = '.';
        }
    }
    scanf("%s", insts);

    for(int i=0; i<instCnt; i++) {
        if(insts[i]=='F') {
            pos = sigPos(rens, cols, mapa, pos, dir);
            if(mapa[pos.r][pos.c]=='*') {
                ans ++;
                mapa[pos.r][pos.c]='.';
            }
        }
        else if(insts[i]=='D')
            dir = (dir+3)%4;
        else
            dir = (dir+1)%4;
    }

    printf("%d\n", ans);
}

int main() {
    trad['N'] = 0;
    trad['S'] = 2;
    trad['L'] = 3;
    trad['O'] = 1;
    int a, b, c;

    while(scanf("%d%d%d", &a, &b, &c)!=EOF && (a || b || c))
        testCase(a, b, c);
    
    return 0;
}
