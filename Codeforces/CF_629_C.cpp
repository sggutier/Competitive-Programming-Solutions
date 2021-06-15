#include <bits/stdc++.h>
using namespace std;
const int limS = 1e5 + 5;
const int limN = 2005;
const int mod = 1e9 + 7;

int N, M, D;
bool usd[limN][limN];
bool usd2[limN][limN];
int dpMemo[limN][limN];
int dpMemo2[limN][limN];
int s = 0, minS = 0;

int dp(int pos, int sumo) {
    if(sumo<0 || sumo > D)
        return 0;
    if(pos==D)
        return sumo==0? 1 : 0;
    if(usd[pos][sumo])
        return dpMemo[pos][sumo];
    usd[pos][sumo] = true;
    // printf("[] %d %d => %d\n", pos, sumo, (dp(pos+1, sumo+1) + dp(pos+1,sumo-1))%mod);
    return dpMemo[pos][sumo] = (dp(pos+1, sumo+1) + dp(pos+1,sumo-1))%mod;
}

int dp2(int pos, int sumo) {
    if(sumo<0)
        return 0;
    if(usd2[pos][sumo])
        return dpMemo2[pos][sumo];
    usd2[pos][sumo] = true;
    if(sumo + minS >= 0)
        dpMemo2[pos][sumo] = (dpMemo2[pos][sumo] + dp(pos, sumo + s)) % mod;
    if(pos < D) {
        dpMemo2[pos][sumo] = (dpMemo2[pos][sumo]
                              + (dp2(pos+1, sumo - 1) + dp2(pos+1, sumo + 1))%mod) % mod;
    }
    // printf("%d %d => %d\n", pos, sumo, dpMemo2[pos][sumo]);
    return dpMemo2[pos][sumo] ;
}

int main() {
    char str[limS];

    scanf("%d%d%s", &N, &M, str);
    D = N-M;
    for(int i=0; i<M; i++) {
        s += str[i]=='('? 1 : -1;
        minS = min(minS, s);
    }
    if(s > D) {
        printf("0\n");
        return 0;
    }

    printf("%d\n", dp2(0, 0));
}
