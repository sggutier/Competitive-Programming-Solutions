#include <bits/stdc++.h>
using namespace std;
const int limN = 2005;
typedef long long ll;

int anso[limN][limN];
ll dp[limN][limN];
ll arr[limN];
char strA[limN*10];

void pans(int l, int r, int sz=0) {
    if(l==r) {
        strA[sz] = 0;
        printf("%s\n", strA);
        return;
    }
    strA[sz] = '0';
    pans(l, anso[l][r], sz+1);
    strA[sz] = '1';
    pans(anso[l][r]+1, r, sz+1);
}

int main() {
    freopen("codes.in", "r", stdin);
    freopen("codes.out", "w", stdout);
    int N ;
    scanf("%d", &N);
    for(int i=1; i<=N; i++) {
        scanf("%lld", &arr[i]);
        arr[i] += arr[i-1];
        anso[i][i] = i;
    }

    for(int d=1; d<N; d++) {
        for(int i=1, j=i+d; j<=N; i++, j++) {
            dp[i][j] = (1LL<<62);
            int mino = max(i, anso[i][j-1]);
            int maxo = min(j-1, anso[i+1][j]);
            for(int k=mino; k<=maxo; k++) {
            // for(int k=i; k<j; k++) {
                ll nov = dp[i][k] + dp[k+1][j];
                if(nov < dp[i][j]) {
                    dp[i][j] = nov;
                    anso[i][j] = k;
                }
            }
            dp[i][j] += arr[j] - arr[i-1];
        }
    }

    // for(int i=1; i<=N; i++) {
    //     for(int j=1; j<=N; j++) {
    //         printf("%2d ", anso[i][j]);
    //     }
    //     printf("\n");
    // }

    pans(1, N);
}
