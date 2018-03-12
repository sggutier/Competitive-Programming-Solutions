#include <bits/stdc++.h>
using namespace std;
const int limN = 405;

double dp[limN][limN];
bool usd[limN][limN];

double memo(int n, int k) {
    if(k==0)
        return 0.0;
    if(usd[n][k])
        return dp[n][k];
    usd[n][k] = true;
    if(n!=0)
        dp[n][k] = 0.5*memo(n, k-1) + 0.5*(1.0 + memo(n-1, k-1));
    else
        dp[n][k] = 0.5*memo(n, k-1) + 0.5*(-1.0 + memo(n+1, k-1));
    //printf("%d %d => %.9f\n", n, k, dp[n][k]);
    return dp[n][k];
}

int main() {
    int n, k;
    scanf("%d%d", &n, &k);
    printf("%.9lf\n", memo(n, k));
}
