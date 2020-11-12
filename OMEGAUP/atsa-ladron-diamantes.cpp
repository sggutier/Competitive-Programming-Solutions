#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
#define f first
#define s second
const int LIM_N = 1e5 + 5;

int main() {
    int N ;
    pll rans[LIM_N] ;
    scanf("%d", &N);
    scanf("%d", &N);
    for(int i=0; i < N; i++) {
        scanf("%lld%lld", &rans[i].f, &rans[i].s);
    }
    sort(rans, rans+N);

    int ans = 0;
    for(ll i = 0, r=0; i < N; i++) {
        if(rans[i].f > r) {
            r = rans[i].s;
            ans ++;
        }
        r = min(r, rans[i].s);
    }

    printf("%d\n", ans);
}
