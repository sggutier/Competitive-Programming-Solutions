#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
ll mod = 1e13 + 7;
const int LIM_N = 1e4 + 5;

struct Mod {
    ll x;
    Mod(ll xx) : x(xx) {}
    Mod operator+(Mod b) { return Mod((x + b.x) % mod); }
    Mod operator-(Mod b) { return Mod((x - b.x + mod) % mod); }
    Mod operator*(Mod b) { return Mod((x * b.x) % mod); }

    Mod operator^(ll e) {
        if (!e) return Mod(1);
        Mod r = *this ^ (e / 2); r = r * r;
        return e&1 ? *this * r : r;
    }
};

void testCase(ll N, int minD, int maxD) {
    Mod ans = 0;
    Mod p = 1;
    N *= N ;
    for(int i=0; i < minD; i++, N--) {
        p = p * N;
    }
    for(int i=minD; i <= maxD; i++, N--) {
        ans = ans + p;
        p=p*N;
    }
    printf("%lld\n", ans.x);
}


int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
    int a, b, c;
    int tc;
    scanf("%d", &tc);
    for(int i=1; i <= tc; i++) {
        scanf("%d%d%d", &a, &b, &c);
        printf("Case %d: ", i);
        testCase(a, b, c);
    }
}
