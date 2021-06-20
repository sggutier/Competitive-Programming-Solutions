#include <bits/stdc++.h>
using namespace std;
const int limB = 16;
const int limN = 4;
const int limMsk = (1<<limB);
const int dr[] = {0, 1, 0, -1};
const int dc[] = {1, 0, -1, 0};

bool usd[limMsk];
bool winsMemo[limMsk];
bool mat[limN][limN];
int decod[limN][limN];

inline bool inside(int r, int c) {
    return 0 <= r && r < limN && 0 <= c && c<limN;
}

int tot = 0;

bool wins(int msk) {
    if(usd[msk])
        return winsMemo[msk];
    // printf("%d\n", msk);
    // printf("%d\n", ++tot);
    // for(int i=0; i<limN; i++) {
    //     for(int j=0; j<limN; j++) {
    //         printf("%c", mat[i][j]? 'X' : '.');
    //     }
    //     printf("\n");
    // }
    usd[msk] = true;
    bool ans = false;
    
    for(int i=0; i<limN; i++) {
        for(int j=0; j<limN; j++) {
            if(mat[i][j])
                continue;
            mat[i][j] = 1;
            bool tmp = wins(msk | decod[i][j]);
            mat[i][j] = 0;
            if(!tmp) {
                ans = true;
            }
        }
    }
    int r=0, c=0, d=0;
    do {
        if(!mat[r][c]) {
            int d2 = (d+1)%4;
            int r2=r+dr[d2], c2=c+dc[d2], r3=r2+dr[d2], c3=c2+dc[d2];
            if(!mat[r2][c2]) {
                mat[r][c] = 1;
                mat[r2][c2] = 1;
                bool tmp = wins((msk | decod[r][c]) | decod[r2][c2]);
                mat[r][c] = 0;
                mat[r2][c2] = 0;
                if(!tmp) {
                    ans = true;
                }
                if(!mat[r3][c3]) {
                    mat[r][c] = 1;
                    mat[r2][c2] = 1;
                    mat[r3][c3] = 1;
                    bool tmp = wins(((msk | decod[r][c]) | decod[r2][c2]) | decod[r3][c3]);
                    mat[r][c] = 0;
                    mat[r2][c2] = 0;
                    mat[r3][c3] = 0;
                    if(!tmp) {
                        ans = true;
                    }
                }
            }
        }
        if(!inside(r+dr[d], c+dc[d]))
            d = (d+1)%4;
        else
            r += dr[d], c += dc[d];
    } while(r || c || d) ;    
    return winsMemo[msk] = ans;
}

void precarga() {
    usd[limMsk-1] = 1;
    winsMemo[limMsk-1] = 1;
    for(int i=0; i<limN; i++)
        for(int j=0; j<limN; j++)
            decod[i][j] = (1<<(i*limN + j));
    // for(int i=0; i<limN; i++) {
    //     for(int j=0; j<limN; j++)
    //         printf("%d ", decod[i][j]);
    //     printf("\n");
    // }
    wins(0);
    // for(int i=0; i<limMsk; i++)
    //     if(usd[i])
    //         printf("%d %d\n", i, winsMemo[i]);    
}

void testCase() {
    char S[limN][limN+5];
    int msk = 0;
    for(int i=0; i<limN; i++) {
        scanf("%s", S[i]);
        for(int j=0; j<limN; j++)
            msk += (S[i][j]=='X')*decod[i][j];
    }
    if(wins(msk))
        printf("WINNING\n");
    else
        printf("LOSING\n");
}

int main() {
    precarga();
    int tc;
    scanf("%d", &tc);
    while(tc--)
        testCase();
}
