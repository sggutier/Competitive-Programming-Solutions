#include <bits/stdc++.h>
using namespace std;
const int limN = 3e5 + 5;
typedef long long ll;

int N ;
int nms[limN][2];
int tips[limN];
vector <int> adj[limN];
ll tots[2];
int T[2] = {1, 1};
ll acum[2][limN];
ll aprs[2][limN];

int getMn(const int a, const int b) {
    return min(nms[a][0] + nms[b][1], nms[a][1] + nms[b][0]);
}

ll query(int pos) {
    int t = tips[pos];
    int r = 1-t;
    ll ans = tots[r] + (N-1LL) * nms[pos][t];
    
    for(const int s : adj[pos])
        ans -= getMn(pos, s);

    ll c = lower_bound(aprs[r], aprs[r] + T[r], abs(nms[pos][0] - nms[pos][1])) - aprs[r];

    ans += tots[t] - nms[pos][t] ;
    ans += acum[r][c-1] + (T[r]-c-1 ) * (nms[pos][r] - nms[pos][t]);
    
    return ans;
}

int main() {
    int E;
    
    scanf("%d%d", &N, &E);
    for(int i=0, t, r; i<N; i++) {
        scanf("%d%d", &nms[i][0], &nms[i][1]);
        t = tips[i] = nms[i][0] < nms[i][1]? 0 : 1;
        tots[t] += nms[i][ t ];
        r = 1-t;
        aprs[r][T[r]++] = nms[i][r] - nms[i][t];
    }
    for(int i=0, a, b; i<E; i++) {
        scanf("%d%d", &a, &b);
        a--, b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for(int w=0; w<2; w++) {
        sort(aprs[w], aprs[w] + T[w]);
        for(int i=1; i<T[w]; i++) {
            acum[w][i] = acum[w][i-1] + aprs[w][i];
            // printf("%lld ", aprs[w][i]);
        }
        // printf("\n");
    }

    for(int i=0; i<N; i++)
        printf("%lld ", query(i));
    printf("\n");
}
