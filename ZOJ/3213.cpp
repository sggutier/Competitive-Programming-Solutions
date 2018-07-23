#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
const int dr[] = {-1, 0, 1, 0};
const int dc[] = {0, 1, 0, -1};
typedef pair<ll, int> pli;
#define f first
#define s second

int R, C;
map <pli, int> dp;
int matr[9][9];

int toNum(int r, int c) {
    if(r < 0 || r>=R || c < 0 || c>=C)
        return -1;
    return r*C + c;
}

int memo(int r, int c, ll msk) {
    int p = toNum(r, c);
    if(p == -1 || !((1ULL<<p) & msk))
        return 0;
    // auto it = dp.find({msk, p});
    // if(it!=dp.end())
    //     return it->s;
    int ans = 0;
    for(int d=0; d<4; d++)
        ans = max(ans, memo(r+dr[d], c + dc[d], msk - (1ULL<<p)));
    // return dp[{msk, p}] = ans + matr[r][c];
    return ans + matr[r][c];
}

void testCase() {
    dp.clear();
    scanf("%d%d", &R, &C);
    ll msk = 0;
    for(int i=0; i<R; i++)
        for(int j=0; j<C; j++) {
            scanf("%d", &matr[i][j]);
            if(matr[i][j])
                msk += 1ULL<<toNum(i, j);
        }
    int ans = 0;
    for(int i=0; i<R; i++) {
        for(int j=0; j<C; j++) {
            if(!matr[i][j]) continue;
            ans = max(ans, memo(i, j, msk));
        }
    }
    printf("%d\n", ans);
}

int main() {
    int tc;
    for(scanf("%d", &tc); tc; tc--)
        testCase();
}
