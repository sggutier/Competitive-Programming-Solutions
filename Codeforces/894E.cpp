#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, int> pli;
const int LIM_N = 1e6 + 5;

int dfsCnt = 1;
stack <int> stkT;
int dep[LIM_N], minDep[LIM_N];
vector <pli> adj[LIM_N];
int ldr[LIM_N];
vector <int> gp[LIM_N];

ll dp[LIM_N];
bool usd[LIM_N];

void tarjan(const int pos) {
    if(dep[pos])
        return ;
    dep[pos] = minDep[pos] = dfsCnt++ ;
    usd[pos] = true;
    stkT.push(pos);
    for(const auto &e : adj[pos]) {
        tarjan(e.second);
        if(usd[e.second])
            minDep[pos] = min(minDep[pos], minDep[e.second]);
    }
    if(dep[pos] != minDep[pos])
        return ;
    int cur ;
    do {
        cur = stkT.top(); stkT.pop();
        usd[cur] = false;
        ldr[cur] = pos;
        gp[pos].push_back(cur);
    }while(cur != pos);
}

ll getCrg(ll n) {
    ll k = (sqrtl(8*n + 1) - 1) / 2;
    k += 15;
    while((k*(k+1)) / 2 > n)
        k --;
    return n*(k+1) - (k*(k+1)*(k+2)) / 6;
}

ll memo(const int pos) {
    if(usd[pos])
        return dp[pos];
    usd[pos] = true;
    ll otr = 0 ;
    ll &acm = dp[pos] ;
    for(const int p : gp[pos]) {
        for(const auto &e : adj[p]) {
            if(ldr[e.second] != pos)
                otr = max(otr, e.first + memo(ldr[e.second]));
            else
                acm += getCrg(e.first);
        }
    }
    // printf("%d\n\t", pos);
    // for(const int p : gp[pos])
    //     printf("%d (%d) ", p, ldr[p]);
    // printf("\n");
    acm += otr;
    return acm;
}


int main() {
    int N, E;
    scanf("%d%d", &N, &E);
    for(int i=0, a, b, c; i < E; i++) {
        scanf("%d%d%d", &a, &b, &c);
        adj[a].push_back({c, b});
    }
    int pos ;
    scanf("%d", &pos);
    tarjan(pos);
    printf("%lld\n", memo(pos));
}
