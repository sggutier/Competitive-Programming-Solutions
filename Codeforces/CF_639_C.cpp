#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// const ll p1 = 1e9 + 7;
// const ll p2 = 98765;
//const ll p1 = 999119999LL;
const ll p1 = 1000000007LL;
const ll p2 = 1000992299LL;
// const ll p1 = 2000000011LL;
// const ll p2 = 2000000033LL;
const int limN = 2e5 + 5;
#define f first
#define s second

ll euclid(ll a, ll b, ll &x, ll &y) {
	if (b) { ll d = euclid(b, a % b, y, x);
		return y -= a/b * x, d; }
	return x = 1, y = 0, a;
}

ll gcd(ll a, ll b) { return __gcd(a, b); }


template <ll mod>
class Mod {
public:
	ll x;
	Mod(ll xx) {
        if(xx < 0)
            xx += mod;
        x = xx;
    }
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

typedef Mod<p1> M0;
typedef Mod<p2> M1;
typedef pair<M0, M1> MT;

int main() {
    int N;
    ll K;
    ll nums[limN];
    MT tot = {M0(0), M1(0)};
    MT pot = {M0(1), M1(1)};
    int ans = 0;
    // tot.

    scanf("%d%lld", &N, &K);
    for(int i=0; i<=N; i++) {
        scanf("%lld", &nums[i]);
        tot = {tot.f + M0(nums[i])*pot.f,
               tot.s + M1(nums[i])*pot.s};
        pot = {pot.f * M0(2), pot.s * M1(2)};
        // printf("%lld %lld\n", tot.f.x, tot.s.x);
        // printf("=> %lld %lld\n", pot.f.x, pot.s.x);
    }

    // printf("%lld %lld\n", tot.f.x, tot.s.x);

    pot = {M0(1), M1(1)};
    for(int i=0; i<=N; i++) {
        MT tmp = {tot.f - M0(nums[i])*pot.f,
                  tot.s - M1(nums[i])*pot.s};
        MT divo = {tmp.f / pot.f, tmp.s / pot.s};
        // printf("Sin %lld los nums son %lld %lld\n", nums[i] + 0LL, tmp.f.x, tmp.s.x);
        // printf("=> %lld %lld\n", pot.f.x, pot.s.x);
        // printf("<< %lld %lld\n", divo.f.x, divo.s.x);
        if((i!=N || divo.f.x != 0) && (divo.f.x == divo.s.x || p1 - divo.f.x == p2 - divo.s.x) ) {
            ll w = divo.f.x == divo.s.x? divo.f.x : divo.f.x - p1;
            // printf("Considerando %lld\n", w);
            if(abs(w) <= K) {
                ans ++;            
                // printf("Se puede reemplazar %lld con %lld\n", 0LL + nums[i], -w);
            }
        }
        pot = {pot.f * M0(2), pot.s * M1(2)};
    }

    printf("%d\n", ans);
}
