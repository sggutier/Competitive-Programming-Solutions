#include <bits/stdc++.h>
using namespace std;
const int limN = 1e5 + 5;
typedef long long ll;
typedef pair<ll, int> par;
typedef tuple < ll, int, int> tri;
#define f first
#define s second

vector <par> adj[limN];
bool usd[limN];
ll minP[limN];

int main() {
    int ans = 0;
    int N, E1, E2;
    priority_queue < tri > Q ;

    scanf("%d%d%d", &N, &E1, &E2);
    for(int a, b, c; E1; E1--) {
        scanf("%d%d%d", &a, &b, &c);
        a--, b--;
        adj[a].push_back({c, b});
        adj[b].push_back({c, a});
    }
    for(int b, c; E2; E2--) {
        scanf("%d%d", &b, &c);
        b--;
        Q.push({-c, 0, b});
    }

    Q.push({0, 1, 0});
    while(!Q.empty()) {
        ll dst;
        int tip, pos;
        tie(dst, tip, pos) = Q.top(); Q.pop();
        if(usd[pos]) {
            ans += 1-tip;
            continue;
        }
        dst *= -1;
        usd[pos] = true;
        // printf("%d => %lld\n", pos, dst);
        for(const auto &s : adj[pos]) {
            // printf("\tcons %d con %d | %lld || %lld\n", s.s, usd[s.s], minP[s.s], dst + s.f);
            if(!usd[s.s] || minP[s.s] > dst + s.f) {
                minP[s.s] = dst + s.f;
                Q.push({-minP[s.s], 1, s.s});
            }
        }
    }

    printf("%d\n", ans);
}
