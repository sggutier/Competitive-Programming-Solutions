#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

ll gcd(ll a, ll b) { return __gcd(a, b); }

ll euclid(ll a, ll b, ll &x, ll &y) {
    if (b) { ll d = euclid(b, a % b, y, x);
        return y -= a/b * x, d; }
    return x = 1, y = 0, a;
}

const ll mod = 1e9 + 7 ;
struct Mod {
    ll x;
    Mod(ll xx) : x(xx % mod) {}
    Mod operator+(Mod b) { return Mod((x + b.x) % mod); }
    Mod operator-(Mod b) { return Mod((x - b.x + mod) % mod); }
    Mod operator*(Mod b) { return Mod((x * b.x) % mod); }
    Mod operator/(Mod b) { return *this * invert(b); }
    Mod invert(Mod a) {
        ll x, y, g = euclid(a.x, mod, x, y);
        assert(g == 1); return Mod((x + mod) % mod);
    }
    Mod operator^(ll e) {
        if (!e) return Mod(1);
        Mod r = *this ^ (e / 2); r = r * r;
        return e&1 ? *this * r : r;
    }
};

//
const int LIM_N = 1e5 + 5;

ll M ;
int N ;
ll A[LIM_N];
ll B[LIM_N];

inline ll gauss(ll x) {
    return (x * (x+1)) / 2 ;
}

Mod calcProb(ll x, ll y) {
    if(x) return Mod(x-1) / M ;
    if(y) return Mod(M - y) / M;
    return Mod(gauss(M-1)) / Mod(M * M);
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
    cin >> N >> M ;
    for(int i=0; i < N; i++)
        cin >> A[i];
    for(int i=0; i < N; i++)
        cin >> B[i];

    Mod ans = 0 ;
    Mod probIg = 1;

    for(int i=0; i < N; i++) {
        if(A[i] && B[i]) {
            if(A[i] == B[i]) continue;
            if(A[i] > B[i])
                ans = ans + probIg;
            break;
        }
        ans = ans + probIg * calcProb(A[i], B[i]);
        probIg = probIg / M ;
    }

    printf("%lld\n", ans.x);
}
