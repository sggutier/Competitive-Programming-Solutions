#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int limN = 1e6 ;

int maxDig[limN+1];
int dp[10][limN+1];
int fin[10][limN+1];

int calcMaxDig(int n) {
    int ans = 0;
    while(n) {
        ans = max(ans, n%10);
        n /= 10;
    }
    return ans;
}

void precarga() {
    for(int i=0; i<=limN; i++)
        maxDig[i] = calcMaxDig(i);
    for(int i=1; i<10; i++) {
        for(int d=0; d<10; d++) {
            if(d > i) {
                dp[d][i] = 0;
                fin[d][i] = i;
            }
            else {
                dp[d][i] = 1;
            }
        }        
        if(i < 500) {
            printf("%3d => ", i);
            for(int d=0; d<10; d++) {
                printf("%3d ", dp[d][i]);
            }
            printf("\n");
        }
    }
    for(int i=10; i<=limN; i++) {
        int md = maxDig[i];
        for(int d=0; d<=md; d++) {
            dp[d][i] = dp[d][i-md] + 1;
            fin[d][i] = fin[d][i-md];
        }
        for(int d=md+1; d<10; d++) {
            dp[d][i] = dp[d][i-d] + 1;
            fin[d][i] = fin[d][i-d];
        }        
        if(i < 500) {
            printf("%3d => ", i);
            for(int d=0; d<10; d++) {
                printf("%3d ", dp[d][i]);
            }
            printf("\n");
            // for(int d=1; d<=4; d++) {
            //     if(dp[d][i] != dp[d-1][i]) {
            //         printf("atsara\n");
            //     }
            // }
        }
    }
}

int main() {
    precarga();
    return 0;
    ll n ;
    ll ans = 0;
    scanf("%lld", &n);
    while(n) {
        int r = n%limN, d = maxDig[n/limN];
        ans += dp[d][r];
        // printf("[%lld] %d %d => %d\n", n, r, d, dp[d][r]);
        // getchar();
        n = n-r+fin[d][r];
        if(n) {
            ans ++;
            n -= max(fin[d][r], d);
        }
    }
    printf("%lld\n", ans);
}
