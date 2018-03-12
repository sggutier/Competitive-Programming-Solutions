#include <bits/stdc++.h>
using namespace std;
const int limN = 2005;
const int mod = 1e9 + 7;

int pasc[limN][limN];
int dp[limN];

void precarga(int N = limN) {
    for(int i=0; i<N; i++) {
        pasc[i][0] = pasc[i][i] = 1;
        for(int j=1; j<i; j++)
            pasc[i][j] = (pasc[i-1][j] + pasc[i-1][j-1]) % mod;
    }
    dp[0] = -1;
    dp[1] = 0;
    for(int i=2; i<N; i++) {
        int c = 0, w = i;
        while(w) {
            c += w%2;
            w /= 2;
        }
        dp[i] = dp[c]+1;
    }
}

int main() {
    precarga();
    char S[limN];
    int N, k ;
    int ans = 0;
    int c = 0;

    scanf("%s", S);
    N = strlen(S);
    scanf("%d", &k);

    if(k==1) {
        printf("%d\n", N-1);
        return 0;
    }

    for(int b=N, i=0; i<N; i++, b--) {
        int t = S[i]=='1'? 1 : 0;
        if(!t) continue;
        for(int j=0; j<b; j++) {
            // printf("%d %d => %d (%d)\n", j, c, dp[j+c], pasc[b-1][j]);
            if(dp[j+c]+1 == k) {
                ans = (ans + pasc[b-1][j]) % mod;
            }
        }
        c++;        
    }

    if(dp[c]+1 == k)
        ans = (ans+1) % mod;

    printf("%d\n", ans);
}
