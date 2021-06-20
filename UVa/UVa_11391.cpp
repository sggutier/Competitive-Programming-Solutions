#include <bits/stdc++.h>
using namespace std;
const int dr[] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int dc[] = {-1, 0, 1, -1, 1, -1, 0, 1};
const int dirCnt = 8;
const int limN = 4;
const int limB = limN*limN;
const int limMsk = (1<<limB);

int mskNums[limN][limN];
bool usd[limMsk];
int waysMemo[limMsk];
int rowCnt, colCnt;
bool hasBlob[limN][limN];

inline bool inside(const int &r, const  int &c) {
    return 0 <= r && r < rowCnt && 0 <= c && c < colCnt;
}

int ways(int msk, int rem) {
    if(usd[msk])
        return waysMemo[msk];
    usd[msk] = true;
    if(rem==1)
        return waysMemo[msk] = 1;
    int ans = 0;
    for(int r=0; r<rowCnt; r++) {
        for(int c=0; c<colCnt; c++) {
            if(!hasBlob[r][c])
                continue;
            for(int d=0; d<dirCnt; d++) {
                int r2 = r + dr[d], r3 = r2 + dr[d];
                int c2 = c + dc[d], c3 = c2 + dc[d];
                if(inside(r2, c2) && inside(r3, c3) && hasBlob[r2][c2] && !hasBlob[r3][c3]) {
                    hasBlob[r][c] ^= 1;
                    hasBlob[r2][c2] ^= 1;
                    hasBlob[r3][c3] ^= 1;
                    ans += ways(msk ^ mskNums[r][c] ^ mskNums[r2][c2] ^ mskNums[r3][c3], rem-1);
                    hasBlob[r][c] ^= 1;
                    hasBlob[r2][c2] ^= 1;
                    hasBlob[r3][c3] ^= 1;
                }
            }
        }
    }
    return waysMemo[msk] = ans;
}

void precarga() {
    for(int i=0; i<limN; i++)
        for(int j=0; j<limN; j++)
            mskNums[i][j] = (1<<(i*limN + j));
}

int testCase() {
    scanf("%d%d", &rowCnt, &colCnt);
    int B, msk = 0 ;
    scanf("%d", &B);
    memset(usd, 0, sizeof(usd));
    memset(hasBlob, 0, sizeof(hasBlob));
    for(int i=0; i<B; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        hasBlob[x-1][y-1] = 1;
        msk |= mskNums[x-1][y-1];
    }
    return ways(msk, B);
}

int main() {
    precarga();
    int tc;

    scanf("%d", &tc);
    for(int i=1; i<=tc; i++)
        printf("Case %d: %d\n", i, testCase());
}
