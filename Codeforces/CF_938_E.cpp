#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;
const int limN = 1e6 + 5;

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

Mod prods[limN];
Mod facs[limN];
int nums[limN];
int cnt[limN];

void precargaFacs(int n) {
    facs[0] = Mod(1);
    for(int i=1; i<=n; i++)
        facs[i] = facs[i-1] * Mod(i);    
    for(int i=0; i<n; i++)
        prods[i] = facs[n] / Mod(n-i);
    return;
}

Mod calcNenku(int n, int k) {
    return facs[n] / (facs[k] * facs[n-k]);
}

int main() {
    int N ;
    Mod ans = 0;

    scanf("%d", &N);
    for(int i=0; i<N; i++)
        scanf("%d", &nums[i]);
    sort(nums, nums+N);
    for(int i=1; i<N; i++) {
        if(nums[i]==nums[i-1])
            cnt[i] = cnt[i-1];
        else
            cnt[i] = i;
    }

    precargaFacs(N);

    for(int i=0; i<N; i++) {
        if(nums[i]==nums[N-1]) break;
        int c = cnt[i];
        ans = ans + prods[c] * Mod(nums[i]);
    }

    printf("%lld\n", ans.x);
}
