#include <bits/stdc++.h>
using namespace std;
const int limN = 8;
const int limStps = 16;
const int limB = (1<<limN);
const int limD = 4;
const int dr[] = {-1, 0, 1, 0};
const int dc[] = {0, 1, 0, -1};
const int inf = 1e8 ;

string numABits(int n, int b) {
    string ans;
    ans.resize(b);
    for(int i=0; i<b; i++) {
        if(n & (1<<i))
            ans[i] = '1';
        else
            ans[i] = '0';
    }
    return ans;
}

int casas[limN+3][limN+3];
int costos[limN+3][limN+3];
vector <int> dirs[limB][limD];
bool usd[limN+2][limN+2][limB][limStps];
int minCstMemo[limN+2][limN+2][limB][limStps];

void cargaPartcs(int msk, vector <int> *dirs, int a=0, int b=0, int c=0, int d=0) {
    if(msk == 0) {
        dirs[0].push_back(a);
        dirs[1].push_back(b);
        dirs[2].push_back(c);
        dirs[3].push_back(d);
        return;
    }
    int x = msk & -msk;
    //printf("%d => %d\n", msk, x);
    msk -= x;
    cargaPartcs(msk, dirs, a+x, b, c, d);
    cargaPartcs(msk, dirs, a, b+x, c, d);
    cargaPartcs(msk, dirs, a, b, c+x, d);
    cargaPartcs(msk, dirs, a, b, c, d+x);    
}

void precarga() {
    for(int i=limB-1; i; i--) {
    //for(int i=3; i; i--) {
        cargaPartcs(i, dirs[i]);
    }
}

int minCst(int r, int c, int msk, int stps=0) {
    if(stps == limStps)
        return inf;
    if(usd[r][c][msk][stps])
        return minCstMemo[r][c][msk][stps];
    usd[r][c][msk][stps] = true;    
    if(msk == 0) {
        return minCstMemo[r][c][msk][stps] = 0;
    }
    minCstMemo[r][c][msk][stps] = inf;
    if(casas[r][c] & msk) {
        //printf("{%d %d %s %s}\n", r, c, numABits(msk, 2).c_str(), numABits(casas[r][c], 2).c_str());
        if(msk - casas[r][c] == 0) {
            //printf("hiri?\n");
            return minCstMemo[r][c][msk][stps] = costos[r][c];
        }
        return minCstMemo[r][c][msk][stps] = minCst(r, c, msk - casas[r][c], stps);
    }
    if(r % (limN+1)==0 || c % (limN+1)==0) {
        return minCstMemo[r][c][msk][stps];
    }
    int ans = inf;
    vector <int> *drs = dirs[msk];
    for(int i=drs[0].size()-1; i>=0; i--) {
        int sumo = 0;
        for(int d=0; d<4; d++)
            sumo += minCst(r + dr[d], c + dc[d], drs[d][i], stps+1) ;
        ans = min(ans, sumo);
    }
    ans = min(inf, ans + costos[r][c]);
    // printf("%d %d %s [%d] (%s) VVV\n", r, c, numABits(msk, 2).c_str(), ans, numABits(casas[r][c], 2).c_str());
    // for(int i=drs[0].size()-1; i>=0; i--) {
    //     int sumo = 0;
    //     for(int d=0; d<4; d++) {
    //         int w = minCst(r + dr[d], c + dc[d], drs[d][i]) ;
    //         sumo += w;
    //         printf("[%d %d %s (%d)] ", r + dr[d], c + dc[d], numABits(drs[d][i], 2).c_str(), w);
    //     }
    //     printf(" ==> %d\n", sumo);
    // }
    //getchar();
    return minCstMemo[r][c][msk][stps] = ans;
}

void testCase() {
    int pl, pw;
    int iniR = 0, iniC = 0;
    int hoCnt = 0;
    char mapa[limN+5][limN+5];
    memset(mapa, 0, sizeof(mapa));
    memset(costos, 0, sizeof(costos));
    memset(usd, 0, sizeof(usd));

    scanf("%d%d", &pl, &pw);
    for(int i=1; i<=limN; i++) {
        scanf("%s", 1 + mapa[i]);
        for(int j=1; j<=limN; j++) {
            if(mapa[i][j]=='H')
                hoCnt ++;
        }
    }

    // for(int i=1; i<(1<<hoCnt); i++) {
    //     printf("%s => ", numABits(i, hoCnt).c_str());
    //     for(int j=dirs[i][0].size()-1; j>=0; j--) {
    //         printf("[%s %s %s %s]  ", numABits(dirs[i][0][j], hoCnt).c_str(), numABits(dirs[i][1][j], hoCnt).c_str(), numABits(dirs[i][2][j], hoCnt).c_str(), numABits(dirs[i][3][j], hoCnt).c_str());
    //     }
    //     printf("\n");
    // }

    for(int i=1, h=0; i<=limN; i++) {
        for(int j=1; j<=limN; j++) {
            if(mapa[i][j]=='H') {
                casas[i][j] = (1<<(h++));
                costos[i][j] = 1;
            }
            else
                casas[i][j] = 0;
            if(mapa[i][j]=='G')
                iniR = i, iniC = j;
            else if(mapa[i][j]=='W')
                costos[i][j] = 1+pw;
            else if(mapa[i][j]=='.')
                costos[i][j] = 1+pl;
        }
    }

    // for(int i=1; i<=limN; i++) {
    //     for(int j=1; j<=limN; j++) {
    //         //printf("%s ", numABits(casas[i][j], hoCnt).c_str());
    //         printf("%2d ", costos[i][j]);
    //     }
    //     printf("\n");
    // }

    printf("%d\n", minCst(iniR, iniC, (1<<hoCnt) - 1));
}

int main() {
    precarga();
    int tc;
    scanf("%d", &tc);
    for(int i=1; i<=tc; i++) {
        printf("Case %d: ", i);
        testCase();
    }
}

