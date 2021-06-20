#include <bits/stdc++.h>
using namespace std;
typedef __int128 bi;
const int limN = 105;
const bi unu = 1;

int N ;
bi adj[limN];
bi dp[limN][limN];
bi sts[limN];

bool funca(const int a, const bi l, const bi r) {
    return (sts[a] & l) && (adj[a] & r) ;
}

void calcDp(int ini, int k) {
    bi &ans = dp[ini][k];
    bi l, r;
    for(int i=1, x=(ini+1)%N; i<k; i++, x = (x+1) % N) {
        for(int w=0, a=ini; w<k; w++, a=(a+1) % N) {
            l = dp[ini][i];
            r = dp[x][k-i];
            if(funca(a, l, r) || funca(a, r, l))
                ans |= sts[a];
        }
    }
}

int main() {
    char tmp[limN];
    
    scanf("%d", &N);
    for(int i=0; i<N; i++)
        sts[i] = unu<<i;
    for(int i=0; i<N; i++) {
        scanf("%s", tmp);
        for(int j=0; j<N; j++)
            if(tmp[j] == '1')
                adj[i] |= sts[j];
        dp[i][1] = sts[i];
    }

    for(int k=2; k<=N; k++)
        for(int i=0; i<N; i++)
            calcDp(i, k);

    bi ans = 0;
    for(int i=0; i<N; i++)
        ans |= dp[i][N];

    int cnt = 0;
    for(int i=0; i<N; i++)
        if(sts[i] & ans)
            cnt ++;

    printf("%d\n", cnt);
    for(int i=0; i<N; i++)
        if(sts[i] & ans)
            printf("%d\n", i+1);    
}
