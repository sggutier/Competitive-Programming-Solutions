#include <bits/stdc++.h>
using namespace std;
const int limN = 1e5 + 5;

int maxo[limN];
vector <int> adj[limN];
vector <int> posb;
int cnt[limN];

void marca(int pos, int acum = 0, int pv = -1) {
    acum = __gcd(acum, maxo[pos]);
    if(!cnt[acum]++)
        posb.push_back(acum);
    
    maxo[pos] = max(bstb, bsta);
    for(const int sig : adj[pos])
        if(sig != pv)
            marca(sig, bsta, bstb, pos);
}

int divCnt(int n) {
    int k ;
    int ans = 0;
    for(k=1; k*k<n; k++) {
        if(n % k == 0)
            ans += 2;
    }
    if(n % k == 0)
        ans ++;
    return ans;
}

int main() {
    int N ;
    scanf("%d", &N);
    for(int i=0; i<N; i++)
        scanf("%d", &maxo[i]);
    for(int i=1, a, b; i<N; i++) {
        scanf("%d%d", &a, &b);
        a--, b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    marca(0);
    for(int i=0; i<N; i++)
        printf("%d ", maxo[i]);
    printf("\n");
}
