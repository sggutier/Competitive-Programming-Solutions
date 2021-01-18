#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

ll getN(ll N) {
    N *= 2 ;
    return ((ll) (sqrtl(4 * N + 1) - 1)) / 2;
}

int main() {
    ll N ;
    int tc ;
    for(scanf("%d", &tc); tc; tc--) {
        scanf("%lld", &N);
        printf("%lld\n", getN(N));
    }
}
