/*
ID: me60
LANG: C++11
TASK: nocows
*/
#include <bits/stdc++.h>
using namespace std;
const int mod = 9901;

bool usdMain[201][201];
int treeCntMainMem[201][201];
bool usdSec[201][201];
int treeCntSecMem[201][201];

int treeCntSec(int n, int k);
int treeCntMain(int n, int k);

int main() {
    freopen("nocows.in", "r", stdin);
    freopen("nocows.out", "w", stdout);
    
    int n, k;

    scanf("%d%d", &n, &k);

    printf("%d\n", treeCntMain(n, k));
    
    return 0;
}


int treeCntMain(int n, int k) {
    if(usdMain[n][k])
        return treeCntMainMem[n][k];
    usdMain[n][k] = true ;
    if(k==1) {
        return treeCntMainMem[n][k] = (n==1);
    }
    if(n<2*k-1 || n>(1<<min(k, 30))-1 ) 
        return treeCntMainMem[n][k] = 0;
    for(int i=1; i+1<n; i++) {
        treeCntMainMem[n][k] = (treeCntMainMem[n][k] + 
                                (treeCntMain(n-1-i, k-1) * treeCntSec(i, k-2))%mod)%mod;
        treeCntMainMem[n][k] = (treeCntMainMem[n][k] + 
                                (treeCntMain(i, k-1) * treeCntSec(n-1-i, k-2))%mod)%mod;
        treeCntMainMem[n][k] = (treeCntMainMem[n][k] + 
                                (treeCntMain(n-1-i, k-1) * treeCntMain(i, k-1))%mod)%mod;
    }

    // printf("%d %d -> %d\n", n, k, treeCntMainMem[n][k]);
    return treeCntMainMem[n][k];
}

int treeCntSec(int n, int k) {
    if(usdSec[n][k])
        return treeCntSecMem[n][k];
    usdSec[n][k] = true ;
    for(int j=0; j<=k; j++)
        treeCntSecMem[n][k] = (treeCntSecMem[n][k] + treeCntMain(n, j));
    return treeCntSecMem[n][k];
}
