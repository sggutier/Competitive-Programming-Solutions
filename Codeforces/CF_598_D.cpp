#include <bits/stdc++.h>
using namespace std;
const int limN = 1e3 + 5;
const int dr[] = {-1, 0, 1, 0};
const int dc[] = {0, 1, 0, -1};
const int limD = 4;

char mapa[limN][limN];
int orgR[limN][limN];
int orgC[limN][limN];
int cnt[limN][limN];

int tots(int rIni, int cIni) {
    if(orgR[rIni][cIni])
        return cnt[orgR[rIni][cIni]][orgC[rIni][cIni]];
    int ans = 0;
    queue <int> qr, qc;
    qr.push(rIni);
    qc.push(cIni);
    orgR[rIni][cIni] = rIni;
    orgC[rIni][cIni] = cIni;
    while(!qr.empty()) {
        int r = qr.front(), c = qc.front();
        qr.pop(), qc.pop();
        for(int d=0; d<limD; d++) {
            int r2 = r + dr[d], c2 = c + dc[d];
            if(mapa[r2][c2]=='*') {
                ans ++;
            }
            else if(!orgR[r2][c2]) {
                orgR[r2][c2] = rIni;
                orgC[r2][c2] = cIni;
                qr.push(r2);
                qc.push(c2);
            }
        }
    }
    return cnt[rIni][cIni] = ans;
}

int main() {
    int R, C, Q;
    scanf("%d%d%d", &R, &C, &Q);
    for(int i=0; i<R; i++)
        scanf("%s", mapa[i]);
    while(Q--) {
        int a, b;
        scanf("%d%d", &a, &b);
        printf("%d\n", tots(a-1, b-1));
    }
}
