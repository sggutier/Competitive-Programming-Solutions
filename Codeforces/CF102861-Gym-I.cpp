#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const ll mod = 1e9 + 7 ;
const int LIM_N = 1e5 + 5 ;

ll gcd(ll a, ll b) { return __gcd(a, b); }

ll euclid(ll a, ll b, ll &x, ll &y) {
    if (b) { ll d = euclid(b, a % b, y, x);
        return y -= a/b * x, d; }
    return x = 1, y = 0, a;
}

struct Mod {
    ll x;
    Mod() : x(0LL) {}
    Mod(ll xx) : x(xx) {}
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

vector <int> adj[LIM_N];
Mod ways[LIM_N], xtr[LIM_N];

void dfs(const int pos = 1) {
    if(adj[pos].empty()) {
        ways[pos] = 1 ;
        xtr[pos] = 1 ;
        return ;
    }
    Mod prod = 1 ;
    Mod &otr = xtr[pos];
    int zeroCnt = 0 ;
    for(const int sig : adj[pos]) {
        dfs(sig);
        if(ways[sig].x == 0) {
            zeroCnt ++;
        }
        else {
            prod = prod * ways[sig];
        }
    }
    if(zeroCnt > 1) {
        xtr[pos] = ways[pos] = 0 ;
        return ;
    }
    if(zeroCnt == 0) {
        for(const int sig : adj[pos]) {
            otr = otr + (prod / ways[sig]) * xtr[sig];
        }
    }
    else {
        for(const int sig : adj[pos]) {
            if(ways[sig].x) continue;
            otr = otr + prod * xtr[sig];
        }
        prod = 0 ;
    }
    ways[pos] = prod + xtr[pos];
}

int main() {
    int N ;
    scanf("%d", &N);
    for(int i=2, j; i <= N; i++) {
        scanf("%d", &j);
        adj[j].push_back(i);
    }
    dfs();
    printf("%lld\n", ways[1].x);
}
