#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int limN = 1e5 + 5;
const int limP = 105;

int d[limN], h[limN];
ll t[limN];
ll dp[limN][limP];
int fk[limN][limP];
ll tots[limN];
ll m[limN];
deque <int> Q;

long double pend(int p, int q) {
    return ((long double) (m[p] - m[q]) ) / (-p + q) ; 
}

int main() {
    int H, N, F ;
    scanf("%d%d%d", &H, &N, &F);
    for(int i=2; i<=H; i++) {
        scanf("%d", &d[i]);
        d[i] += d[i-1];
    }
    for(int i=1; i<=N; i++) {
        scanf("%d%lld", &h[i], &t[i]);
        t[i] -= d[h[i]];
    }

    sort(t+1, t+N+1);
    for(int i=1; i<=N; i++)
        tots[i] = t[i] + tots[i-1];

    for(int c=1; c<=N; c++)
        m[c] = dp[c][0] = (1LL<<60);

    Q.push_back(0);
    for(int f=1; f<=F; f++) {
        dp[1][f] = 0;
        for(int c=1; c<=N; c++) {
            dp[c][f] = (1LL<<60);
            // ll sumo = 0;
            // for(int k=c-1; k>=0; k--) {
            //     // sumo += -t[k+1];
            //     dp[c][f] = min(dp[c][f], -t[c]*k + m[k]);
            // }
            while(Q.size() >= 2) {
                int p = Q.back(); Q.pop_back();
                int q = Q.back();
                if(m[p] - p * t[c] < m[q]  - q * t[c]) {
                    Q.push_back(p);
                    break;
                }
            }
            int w = Q.back();
            dp[c][f] = m[w] - w * t[c];
            dp[c][f] += t[c]*c - tots[c];
        }
        for(int c=1; c<=N; c++) {
            m[c] = tots[c] + dp[c][f];
        }
        Q.clear();
        for(int i=0; i<=N; i++) {
            while(Q.size() >= 2) {
                int p = Q.front(); Q.pop_front();
                int q = Q.front();
                // if( pend(q, p) >= pend(p, i) ) {
                if( (m[q] - m[p]) * (-p + i) >= (m[p] - m[i]) * (-q + p) ) {
                    Q.push_front(p);
                    break;
                }
            }
            Q.push_front(i);
        }
    }

    printf("%lld\n", dp[N][F]);
}
