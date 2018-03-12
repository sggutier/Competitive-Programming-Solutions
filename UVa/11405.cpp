#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 8;
const int MAX_V = 64;
const int MAX_B = 1<<MAX_N;
const int INF = (1<<29);
const int dr[] = {-1, -1, -2, -2, 1, 1, 2, 2};
const int dc[] = {-2, 2, -1, 1, -2, 2, -1, 1};
#define par pair<int,int>
#define r first
#define c second

inline bool isInside(const par &A) {
    return 0 <= A.r && A.r < MAX_N && 0 <= A.c && A.c < MAX_N;
}

char mapa[MAX_N][MAX_N + 5];
int minP[MAX_V][MAX_V];
int pnCnt;
int pnPos[MAX_N];
int pnDsts[MAX_N][MAX_N];
int minMvsMemo[MAX_B][MAX_N];

void testCase() ;
int minMvs(int msk, int pos);

int main() {
    int tc;
    scanf("%d", &tc);
    while(tc--)
        testCase();
}

void testCase() {
    pnCnt = 0;
    for(int i=0; i<MAX_V; i++) {
        for(int j=0; j<MAX_V; j++)
            minP[i][j] = INF;
        minP[i][i] = 0;
    }
    memset(minMvsMemo, 0, sizeof(minMvsMemo));
    
    int maxMvs;
    int ans = INF;
    int ini = 0;

    scanf("%d", &maxMvs);
    for(int i=0; i<MAX_N; i++) {
        scanf("%s", mapa[i]);
        for(int j=0; j<MAX_N; j++) {
            if(mapa[i][j]=='K')
                mapa[i][j] = 'p';
            else if( mapa[i][j] == 'k') {
                mapa[i][j] = '.';
                ini = i*MAX_N + j;
            }
        }
    }

    for(int i=0; i<MAX_N; i++) {
        for(int j=0; j<MAX_N; j++) {
            if(mapa[i][j]=='p')
                continue;
            par sig;
            int a = i*MAX_N + j;
            for(int d=0; d<MAX_N; d++) {
                sig = par(i+dr[d], j + dc[d]);
                if(!isInside(sig) || mapa[sig.r][sig.c]=='p')
                    continue;
                minP[a][sig.r*MAX_N + sig.c] = 1;
            }
            if(mapa[i][j]=='P') {
                pnPos[pnCnt++] = i*MAX_N + j;
            }
        }
    }

    for(int k=0; k<MAX_V; k++) 
        for(int i=0; i<MAX_V; i++) 
            for(int j=0; j<MAX_V; j++)
                minP[i][j] = min(minP[i][j], minP[i][k] + minP[k][j]);
    for(int i=0; i<pnCnt; i++)
        for(int j=0; j<pnCnt; j++)
            pnDsts[i][j] = minP[pnPos[i]][pnPos[j]];

    for(int i=0; i<pnCnt; i++)
        ans = min(ans, minP[ini][pnPos[i]] + minMvs((1<<i), i));
    if(pnCnt==0)
        ans = 0;

    printf("%s\n", ans<=maxMvs? "Yes" : "No");
}

int minMvs(int msk, int pos) {
    if(msk==(1<<pnCnt)-1)
        return 0;
    if(minMvsMemo[msk][pos])
        return minMvsMemo[msk][pos];
    int ans = INF;
    for(int i=0; i<pnCnt; i++) {
        if( !((1<<i)&msk) )
            ans = min(ans, minMvs(msk | (1<<i), i) + pnDsts[i][pos]);
    }
    return minMvsMemo[msk][pos] = ans;
}
