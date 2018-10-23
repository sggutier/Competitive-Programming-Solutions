#include <bits/stdc++.h>
using namespace std;
// n -> fila
// f-1 -> columna
typedef long long ll;
const ll mod = 1e9 + 7;
const int limN = 1e5 ;

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


vector<int> divs[limN + 5];
Mod facs[limN + 5];
Mod finv[limN + 5];
int F ;
int usd[limN + 5];
int ans[limN + 5];
vector < pair<int, int> > qrs[limN + 5] ;
Mod dp[limN + 5];

Mod memo(int n) {
    if(n < F)
        return 0 ;
    if(usd[n] == F)
        return dp[n] ;
    usd[n] = F ;
    Mod &ans = dp[n];
    ans = facs[n-1] * finv[F-1] * finv[(n-1) - (F-1)] ;
    for(const int d : divs[n])
        ans = ans - memo(d) ;
    return ans; 
}

void precarga() {
    int N = limN ;
    for(int i=2; i<=N; i++)
        for(int j=2*i; j<=N; j+=i)
            divs[j].push_back(i);
    facs[0] = finv[0] = 1;
    for(int i=1; i<=N; i++) {
        facs[i] = facs[i-1] * i;
        finv[i] = finv[i-1] / i;
    }
}

int main() {
    int Q ;
    precarga();

    scanf("%d", &Q);
    for(int i=0, a, b; i<Q; i++) {
        scanf("%d%d", &b, &a);
        qrs[a].push_back({b, i});
    }

    for(F = 1; F <= limN; F++) {
        for(const auto &p : qrs[F]) {
            int ap = p.second, n = p.first ;
            ans[ap] = memo(n).x ;
        }
    }

    for(int i=0; i<Q; i++)
        printf("%d\n", ans[i]);
}
