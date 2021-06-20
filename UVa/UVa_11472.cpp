#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const ll mod = 1000000007;
struct Mod {
    ll x;
    Mod(ll xx = 0) : x(xx) {}
    Mod operator+(Mod b) { return Mod((x + b.x) % mod); }
    Mod operator-(Mod b) { return Mod((x - b.x + mod) % mod); }
    Mod operator*(Mod b) { return Mod((x * b.x) % mod); }
    Mod operator^(ll e) {
        if (!e) return Mod(1);
        Mod r = *this ^ (e / 2); r = r * r;
        return e&1 ? *this * r : r;
    }
};

const int LIM_M = 105;
const int LIM_N = 10;
const int LIM_B = 1 << LIM_N;

int maxN, fullB ;
Mod dp[LIM_M][LIM_N][LIM_B];
bool usd[LIM_M][LIM_N][LIM_B];

int spOr(int x, int d) {
    return d >= maxN? x : x | (1 << d);
}

Mod memo(int rem, int pos, int msk) {
    if(usd[rem][pos][msk]) {
        return dp[rem][pos][msk];
    }
    usd[rem][pos][msk] = true;
    Mod &ans = dp[rem][pos][msk];
    if(rem == 0) {
        ans = msk == fullB? 1 : 0;
        // printf("%d %d %d %lld\n", rem, pos, msk, ans.x);
        return ans ;
    }
    ans = 0 ;
    if(pos)
        ans = ans + memo(rem-1, pos-1, spOr(msk, pos-1));
    if(pos != maxN - 1)
        ans = ans + memo(rem-1, pos+1, spOr(msk, pos+1));
    // printf("%d %d %d %lld\n", rem, pos, msk, ans.x);
    return ans;
}

void testCase() {
    memset(usd, 0, sizeof(usd));
    int M ;
    Mod ans = 0 ;
    scanf("%d%d", &maxN, &M);
    fullB = (1 << maxN) - 1;
    for(int i=1; i <= M; i++) {
        for(int d=1; d < maxN; d++) {
            ans = ans + memo(i-1, d, spOr(0, d));
        }
    }
    printf("%lld\n", ans.x);
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
    int tc ;
    for(scanf("%d", &tc); tc; tc--) {
        testCase();
    }
}
