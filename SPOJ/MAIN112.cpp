#include <bits/stdc++.h>
using namespace std;
const int limN = 15;
const int limB = 1<<limN;
const int inf = 1e9 ;

int anum[limB];

int N ;
int nms[limN], cs[limN];
bool usd[limN][limB];
int dp[limN][limB];

int memo(const int lst, const int msk, const int pos = 1) {
    if(pos == N) return 0 ;
    if(usd[lst][msk]) return dp[lst][msk] ;
    usd[lst][msk] = true;
    int &ans = dp[lst][msk];
    ans = inf;
    for(int t = msk, p, w; t; t -= p) {
        p = t&-t;
        w = anum[p];
        ans = min(ans,
                  abs(nms[w]-nms[lst]) * cs[pos] + memo(w, msk - p, pos+1));
    }
    return ans;
}

void testCase() {
    memset(usd, 0, sizeof(usd));
    scanf("%d", &N);
    for(int i=0; i<N; i++)
        scanf("%d", &nms[i]);
    for(int i=0; i<N; i++)
        scanf("%d", &cs[i]);
    int ans = memo(0, (1<<N) - 2);
    for(int i=1; i<N; i++)
        ans = min(ans, memo(i, (1<<N)-1 - (1<<i)));
    printf("%d\n", ans);
}

int main() {
    for(int i=0; i<limN; i++)
        anum[1<<i] = i;
    int tc;
    scanf("%d", &tc);
    for(int i=0; i<tc; i++)
        testCase();
}
