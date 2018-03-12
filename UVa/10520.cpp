#include <bits/stdc++.h>
using namespace std;
const int limN = 21;

int n;
bool usd[limN][limN];
long long recMemo[limN][limN];

long long rec(int i, int j) {
    if(usd[i][j])
        return recMemo[i][j];
    usd[i][j] = true;
    long long ans ;
    if(i < j) {
        ans = rec(i, i) + rec(i+1, j);
        for(int k=i+1; k<j; k++)
            ans = max(ans, rec(i, k) + rec(k+1, j));
    }
    else {
        long long axo=0, yaro=0;
        for(int k=i+1; k<=n; k++)
            axo = max(axo, rec(k, 1) + rec(k, j));
        for(int k=1; k<j; k++)
            yaro = max(yaro, rec(i, k) + rec(n, k));
        ans = axo + yaro;
    }
    return recMemo[i][j] = ans;
}

int main() {
    int a;

    while(scanf("%d%d", &n, &a)!=EOF) {
        memset(usd, 0, sizeof(usd));
        usd[n][1] = true;
        recMemo[n][1] = a;
        printf("%lld\n", rec(1, n));
    }
    
    return 0;
}
