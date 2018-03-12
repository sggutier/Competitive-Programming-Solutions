#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> par;
#define x first
#define y second
const int limN = 1e4 + 5;

ll dst(const par A, const par B) {
    ll x = A.x - B.x, y = A.y - B.y;
    return x*x + y*y;
}

void testCase(int N) {
    par pts[limN];
    ll ans = 1LL<<62;
    set <par> cands;

    for(int i=0; i<N; i++)
        scanf("%lld%lld", &pts[i].x, &pts[i].y);
    if( N <= 1) {
        printf("INFINITY\n");
        return;
    }

    sort(pts, pts+N, [] (par A, par B) { return A.y != B.y? A.y < B.y : A.x < B.y; });

    for(int i=0, j=0; i<N; i++) {
        while((pts[i].y - pts[j].y)*(pts[i].y - pts[j].y) > ans)
            cands.erase(pts[j++]);
        auto p = cands.lower_bound(pts[i]);
        for(auto it=p; it!=cands.end() && (it->x - pts[i].x)*(it->x - pts[i].x) <= ans; it++)
            ans = min(ans, dst(*it, pts[i]));
        for(auto it=p; it!=cands.begin(); ) {
            it --;
            if((it->x - pts[i].x)*(it->x - pts[i].x) > ans)
                break;
            ans = min(ans, dst(*it, pts[i]));
        }
        p = cands.begin();
        if(p != cands.end())
            ans = min(ans, dst(*p, pts[i]));
        cands.insert(pts[i]);
    }

    printf("%lld\n", ans);
}

int main() {
    int n ;
    int tc;

    scanf("%d", &tc);
    while(tc--) {
        scanf("%d", &n);
        testCase(n);
    }
}
