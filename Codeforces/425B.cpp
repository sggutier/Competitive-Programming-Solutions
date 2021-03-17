#include <bits/stdc++.h>
using namespace std;
const int LIM_N = 105;
const int LIM_K = 11;
const int INF = numeric_limits<int>::max() / 4 ;

int R, C ;
int org[LIM_N][LIM_N];
int sms[LIM_N][LIM_N];
int maxK ;

inline int getSum(const int rIni, const int cIni, const int rFin, const int cFin) {
    return sms[rFin][cFin] - sms[rFin][cIni] - sms[rIni][cFin] + sms[rIni][cIni];
}

int D = 1 ;
int divs[LIM_N];
int iniT ;

bool usd[LIM_N][2];
int memo[LIM_N][2];

int bruta2(const int H, const int rowT) {
    if(H == R)
        return 0 ;
    if(usd[H][rowT])
        return memo[H][rowT];
    usd[H][rowT] = true;
    int &ans = memo[H][rowT];
    ans = INF ;
    int totDif = 0 ;
    for(int pos=1, t=rowT; pos < D; pos++, t ^= 1) {
        int s = getSum(H, divs[pos-1], H+1, divs[pos]);
        int dif = abs((divs[pos] - divs[pos-1]) * t - s);
        totDif += dif ;
    }
    if(totDif > maxK) return ans ;
    return ans = totDif + min(bruta2(H+1, 0), bruta2(H+1, 1));
}

int bruta1(const int col, const int t, const int acm = 0) {
    if(col == C) {
        memset(usd, 0, sizeof(usd));
        return bruta2(0, iniT);
    }
    int ans = INF ;
    for(int j=col+1; j <= C; j++) {
        int s = getSum(0, col, 1, j);
        int dif = abs((j - col) * t - s);
        if(dif + acm > maxK || dif + acm >= 2) break;
        divs[D++] = j;
        ans = min(ans, bruta1(j, t ^ 1, dif + acm));
        D -- ;
    }
    return ans ;
}

int bruta0(const int t) {
    iniT = t ;
    return bruta1(0, t);
}

int main() {
    scanf("%d%d%d", &R, &C, &maxK);
    for(int i=1; i <= R; i++) {
        for(int j=1; j <= C; j++) {
            scanf("%d", &org[i][j]);
        }
    }

    int ans = INF;
    for(int d=0; d < 4; d++) {
        memset(sms, 0, sizeof(sms));
        for(int i=1; i <= R; i++) {
            for(int j=1; j <= C; j++) {
                sms[i][j] = org[i][j] + sms[i-1][j] + sms[i][j-1] - sms[i-1][j-1];
            }
        }
        ans = min(ans, bruta0(0));
        ans = min(ans, bruta0(1));
        for(int i=1; i <= R; i++) {
            for(int j=1; j <= C; j++) {
                sms[C-j+1][i] = org[i][j];
            }
        }
        swap(R, C);
        for(int i=1; i <= R; i++) {
            for(int j=1; j <= C; j++) {
                org[i][j] = sms[i][j];
                // printf("%d ", org[i][j]);
            }
            // printf("\n");
        }
        // printf("--------------\n");
    }

    printf("%d\n", ans <= maxK? ans : -1);
}
