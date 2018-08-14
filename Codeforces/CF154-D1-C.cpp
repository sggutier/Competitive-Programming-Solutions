#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define f first
#define s second
const int limN = 1e6 + 5;

ll gcd(ll a, ll b) { return __gcd(a, b); }

ll euclid(ll a, ll b, ll &x, ll &y) {
	if (b) { ll d = euclid(b, a % b, y, x);
		return y -= a/b * x, d; }
	return x = 1, y = 0, a;
}


const ll mod = 1e9 + 7; // change to something else
struct Mod {
	ll x;
    Mod() {}
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

const ll mod2 = 970592641; // change to something else
struct Mod2 {
	ll x;
    Mod2() {}
	Mod2(ll xx) : x(xx) {}
	Mod2 operator+(Mod2 b) { return Mod2((x + b.x) % mod2); }
	Mod2 operator-(Mod2 b) { return Mod2((x - b.x + mod2) % mod2); }
	Mod2 operator*(Mod2 b) { return Mod2((x * b.x) % mod2); }
	Mod2 operator/(Mod2 b) { return *this * invert(b); }
	Mod2 invert(Mod2 a) {
		ll x, y, g = euclid(a.x, mod2, x, y);
		assert(g == 1); return Mod2((x + mod2) % mod2);
	}
	Mod2 operator^(ll e) {
		if (!e) return Mod2(1);
		Mod2 r = *this ^ (e / 2); r = r * r;
		return e&1 ? *this * r : r;
	}
};

pair<Mod, Mod2> hss[limN];
pair<Mod, Mod2> pot2[limN];
vector <int> adj[limN];
map < pair<ll, ll>, ll> cnt;

int main() {
    int N, E;
    ll ans = 0;

    scanf("%d%d", &N, &E);
    pot2[0] = {Mod(1), Mod2(1)};
    for(int i=1; i<=N; i++)
        pot2[i] = {Mod(2) * pot2[i-1].f,
                   Mod2(2) * pot2[i-1].s};
    for(int i=0, a, b; i<E; i++) {
        scanf("%d%d", &a, &b);
        a--, b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
        hss[a] = {hss[a].f + pot2[b].f,
                  hss[a].s + pot2[b].s};
        hss[b] = {hss[b].f + pot2[a].f,
                  hss[b].s + pot2[a].s};
    }
    for(int i=0; i<N; i++)
        cnt[{hss[i].f.x, hss[i].s.x}]++;

    for(auto &p : cnt) {
        ans += p.s*(p.s-1) ;
    }

    for(int i=0; i<N; i++) {
        for(const int & s : adj[i]) {
            if( (hss[i].f - pot2[s].f).x == (hss[s].f - pot2[i].f).x
                && (hss[i].s - pot2[s].s).x == (hss[s].s - pot2[i].s).x)
                ans ++;
        }
    }

    printf("%lld\n", ans / 2);
}
