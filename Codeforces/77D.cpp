#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int LIM_N = 2005 ;

const ll mod = 1e9 + 7;
struct Mod {
    ll x;
    Mod(ll xx = 0) : x(xx) {}
    Mod operator+(Mod b) { return Mod((x + b.x) % mod); }
    Mod operator-(Mod b) { return Mod((x - b.x + mod) % mod); }
    Mod operator*(Mod b) { return Mod((x * b.x) % mod); }
    Mod operator^(ll e) {
        if (!e) return Mod(1);
        Mod r = *this ^ (e / 2); r = r * r;
        return e&1 ? *this * r : r;
    }
};

bool spec[7] = {0, 0, 1, 1, 0, 0, 1};
int hrPos[7] = {0, 0, 0, 0, 0, 0, 1};

bool usdPar[LIM_N][LIM_N];
Mod dpPar[LIM_N][LIM_N];
bool usdCols[LIM_N];
Mod dpCol[LIM_N];

int R, C ;
char S[LIM_N][LIM_N];
// 1 V, 2 H
int matr[LIM_N][LIM_N];

void parseMatr() {
    for(int i=0; i < R; i++) {
        for(int j=0; j < C; j++) {
            int sm = 0 ;
            for(int a=0; a < 3; a++) {
                for(int b=0; b < 3; b++) {
                    sm += S[i*4 + 1 + a][j*4 + 1 + b]=='O'? 1 : 0;
                }
            }
            if(!spec[sm])
                matr[i][j] = 3;
            else if(S[i*4 + 1][j*4 + 1 + hrPos[sm]] == 'O')
                matr[i][j] = 2;
            else
                matr[i][j] = 1 ;
            // printf("%d(%d) ", sm, matr[i][j]);
        }
        // printf("\n");
    }
}

bool colWorks(const int col) {
    if(R % 2) return false;
    for(int i=0; i < R; i++)
        if(!(matr[i][col] & 1))
            return false;
    return true;
}

Mod memoPar(const int col, const int row = 0) {
    if(row == R) return 1;
    if(usdPar[col][row]) {
        return dpPar[col][row];
    }
    usdPar[col][row] = true;
    Mod &ans = dpPar[col][row];
    if(row + 2 <= R
       && (matr[row + 0][col + 0] & 1)
       && (matr[row + 0][col + 1] & 1)
       && (matr[row + 1][col + 0] & 1)
       && (matr[row + 1][col + 1] & 1)
        ) {
        ans = memoPar(col, row + 2);
    }
    if((matr[row + 0][col + 0] & 2) && (matr[row + 0][col + 1] & 2))
        ans = ans + memoPar(col, row + 1);
    return ans ;
}

Mod memoCol(const int col = 0) {
    if(col == C) {
        return 1 ;
    }
    if(usdCols[col]) {
        return dpCol[col];
    }
    usdCols[col] = true;
    Mod &ans = dpCol[col];
    if(col + 2 <= C) {
        ans = memoPar(col) ;
        if(colWorks(col) && colWorks(col+1))
            ans = ans - 1;
        ans = ans * memoCol(col + 2);
    }
    if(colWorks(col))
        ans = ans + memoCol(col + 1);
    return ans;
}

int main() {
    scanf("%d%d", &R, &C);
    for(int i=0; i <= 4*R; i++)
        scanf("%s", S[i]);
    parseMatr();
    printf("%lld\n", memoCol().x);
}
