#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;
const int limN = 1e6 + 5;
const int lim10N = 1e7;

ll euclid(ll a, ll b, ll &x, ll &y) {
	if (b) { ll d = euclid(b, a % b, y, x);
		return y -= a/b * x, d; }
	return x = 1, y = 0, a;
}

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

int a, b ;
bitset <lim10N> excSum;
Mod facs[limN];

void marca(int sum=0) {
    if(sum > lim10N) return;
    excSum[sum] = true;
    marca(sum*10 + a);
    marca(sum*10 + b);
}

int main() {
    int n ;
    scanf("%d%d%d", &a, &b, &n);
    marca();
    facs[0] = {1};
    for(int i=1; i<=n; i++)
        facs[i] = facs[i-1]*i;
    Mod ans = 0;
    for(int i=0, j=n; i<=n; i++, j--)
        if(excSum[i*a + j*b])
            ans = ans + facs[n]/(facs[i]*facs[j]);
    printf("%lld\n", ans.x);
}
