#include <bits/stdc++.h>
using namespace std;
const int limN = 22;
const int limB = 1<<limN;

int N ;
int adj[limN];
int sig[limB];
int dpMemo[limB];

int dp(int pos) {
    if(sig[pos]!=-1)
        return dpMemo[pos];
    int &sg = sig[pos];
    int &ans = dpMemo[pos];
    sg = 0;
    ans = limN + 7;
    for(int k=0; k<N; k++) {
        if((1<<k) & pos) {
            int w = dp(pos | adj[k]) + 1;
            if(w < ans) {
                ans = w;
                sg = k;
            }
        }
    }
    return ans;
}

int main() {
    memset(sig, -1, sizeof(sig));
    int E;
    scanf("%d%d", &N, &E);
    if(E==(N*(N-1))/2) {
        printf("0\n\n");
        return 0;
    }
    for(int i=0; i<E; i++) {
        int a, b ;
        scanf("%d%d", &a, &b);
        a--, b--;
        adj[a] |= (1<<b);
        adj[b] |= (1<<a);
    }
    
    sig[(1<<N)-1] = 0;
    pair<int,pair<int,int>> ans(limN+7, make_pair(0, 0));
    for(int i=0; i<N; i++) {
        for(int j=i+1; j<N; j++) {
            if((1<<j) & adj[i]) {
                ans = min(ans, make_pair(dp((1<<i) | (1<<j)), make_pair(i, j)));
            }
        }
    }
    printf("%d\n", ans.first);
    int pos = (1<<ans.second.first) | (1<<ans.second.second);
    while(pos != (1<<N)-1) {
        printf("%d ", 1 + sig[pos]);
        pos |= adj[sig[pos]];
    }
    printf("\n");
}
