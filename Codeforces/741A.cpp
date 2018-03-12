#include <bits/stdc++.h>
using namespace std;
const int limN= 105;

int mcm(int a, int b) {
    return (a/__gcd(a,b))*b;
}

int N ;
int sig[limN];
int ancCnt[limN];
bool usd[limN];

int dfs(int pos) {
    if(usd[pos])
        return 0;
    usd[pos] = true;
    return dfs(sig[pos])+1;
}

int main() {
    scanf("%d", &N);
    for(int i=0; i<N; i++) {
        scanf("%d", &sig[i]);
        sig[i]--;
        ancCnt[sig[i]]++;
    }

    for(int i=0; i<N; i++) {
        if(ancCnt[i]!=1) {
            printf("-1\n");
            return 0;
        }
    }

    int ans = 1;
    for(int i=0; i<N; i++) {
        if(usd[i])
            continue;
        int k = dfs(i);
        if(k%2==0) k/=2;
        ans = mcm(ans, k);
    }

    printf("%d\n", ans);
}
