#include <bits/stdc++.h>
using namespace std;
const int limN = 1e5 + 5;
typedef long long ll;
const ll inf = 1e18;
typedef pair<ll,ll> par;
#define x first
#define y second

ll dst(const par &A, const par &B) {
    return abs(A.x-B.x) + abs(A.y-B.y);
}

int N;
par pts[limN];
ll minDst[limN];

int main() {
    long long ans = 0LL;
    priority_queue <par> Q;

    scanf("%d", &N);
    for(int i=0; i<N; i++) {
        scanf("%lld%lld", &pts[i].x, &pts[i].y);
        minDst[i] = inf ;
    }

    Q.push(par(0, 0));
    minDst[0] = 0;
    while(!Q.empty()) {
        ll pos = Q.top().y, d = -Q.top().x; Q.pop();
        //printf("%d %d\n", pos, d);
        if(d > minDst[pos])
            continue;
        ans += d;
        for(int i=0; i<N; i++) {
            d = dst(pts[pos], pts[i]);
            if(i!=pos && minDst[i] > d) {
                minDst[i] = d;
                Q.push(par(-d, i));
            }
        }
    }

    printf("%lld\n", 2*ans);
    
    return 0;
}
