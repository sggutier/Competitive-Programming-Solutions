#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
const int INF = numeric_limits<int>::max() / 4;
const int LIM_N = 6 ;
const int LIM_B = 1 << 25;

int N ;
int minF[LIM_N][LIM_N], maxF[LIM_N][LIM_N], actC[LIM_N][LIM_N];

int stts[LIM_N];
map<int, int> minP[10];

int memo(int pos, int nxt, int msk, int egId = 0) {
    if(pos == 0) {
        return 0 ;
    }
    if(minP[egId].count(msk)) {
        return minP[egId][msk];
    }
    int &ans = minP[egId][msk];
    ans = -INF;
    if(nxt == 0) {
        if(stts[pos] == 0 && minF[nxt][pos] == 0) {
            ans = memo(pos-1, pos-2, msk, egId + 1);
        }
        else if(minF[nxt][pos] <= stts[pos] && stts[pos] <= maxF[nxt][pos]) {
            stts[0] += stts[pos] ;
            ans = stts[pos]*stts[pos] + actC[nxt][pos] + memo(pos-1, pos-2, msk - (stts[pos] << (5 * pos))  + stts[pos], egId + 1);
            stts[0] -= stts[pos] ;
        }
        if(ans < 0)
            ans = -INF;
        // printf("%d %d => %d\n\t", pos + 1, nxt + 1, ans);
        // for(int i=0; i < N; i++)
        //     printf("%d ", stts[i]);
        // printf("\n");
        return ans;
    }
    if(minF[nxt][pos] == 0)
        ans = memo(pos, nxt-1, msk, egId + 1);
    for(int i=max(1, minF[nxt][pos]), x=min(maxF[nxt][pos], stts[pos]); i <= x; i++) {
        stts[pos] -= i;
        stts[nxt] += i;
        ans = max(ans, i*i + actC[nxt][pos] + memo(pos, nxt-1, msk - (i << (5 * pos)) + (i << (5 * nxt)), egId + 1));
        stts[nxt] -= i;
        stts[pos] += i;
    }
    if(ans < 0)
        ans = -INF;
    // printf("%d %d => %d\n\t", pos + 1, nxt + 1, ans);
    // for(int i=0; i < N; i++)
    //     printf("%d ", stts[i]);
    // printf("\n");
    return ans ;
}

int bruta(int rem, int nxt = N-2, int msk = 0, int pos = N-1) {
    int ans = -INF ;
    if(nxt == 0) {
        if(rem == 0 && minF[nxt][pos] == 0) {
            ans = memo(pos-1, pos-2, msk);
        }
        else if(minF[nxt][pos] <= rem && rem <= maxF[nxt][pos]) {
            stts[0] += rem ;
            ans = rem*rem + actC[nxt][pos] + memo(pos-1, pos-2, msk + rem);
            stts[0] -= rem;
        }
        if(ans < 0)
            ans = -INF;
    //     printf("%d %d (%d) => %d\n\t", pos + 1, nxt + 1, rem, ans);
    // for(int i=0; i < N; i++)
    //     printf("%d ", stts[i]);
    // printf("\n");
        return ans;
    }
    if(minF[nxt][pos] == 0)
        ans = bruta(rem, nxt-1, msk);
    for(int i=max(1, minF[nxt][pos]), x=min(rem, maxF[nxt][pos]); i <= x; i++) {
        stts[nxt] += i;
        ans = max(ans, i*i + actC[nxt][pos] + bruta(rem -i, nxt-1, msk + (i << (5 * nxt))));
        stts[nxt] -= i;
    }
    if(ans < 0)
        ans = -INF;
    // printf("%d %d (%d) => %d\n\t", pos + 1, nxt + 1, rem, ans);
    // for(int i=0; i < N; i++)
    //     printf("%d ", stts[i]);
    // printf("\n");
    return ans;
}

int main() {
    int ff = 0 ;
    int mf = 0 ;

    scanf("%d", &N);
    for(int i=0; i < N; i++) {
        for(int j=i+1, a, b, mino, maxo, cst; j < N; j++) {
            scanf("%d%d%d%d%d", &a, &b, &mino, &maxo, &cst);
            if(b == N) {
                ff += maxo;
                mf += mino;
            }
            a--, b--;
            minF[a][b] = mino;
            maxF[a][b] = maxo;
            actC[a][b] = cst;
        }
    }

    for(int i=mf; i <= ff; i++) {
        int v = bruta(i);
        if(v != -INF) {
            printf("%d %d\n", i, v);
            return 0 ;
        }
    }

    printf("-1 -1\n");
}
