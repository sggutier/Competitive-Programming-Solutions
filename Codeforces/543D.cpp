#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int limN = 2e5 +5;

const ll mod = 1e9 + 7;

ll gcd(ll a, ll b) { return __gcd(a, b); }

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


vector <int> adj[limN];
Mod ways[limN];
Mod ans[limN];
int zeroCnt[limN];

Mod inita(int pos = 0) {
	ways[pos] = 1;
	for(const int sig : adj[pos]) {
		Mod tmp = (inita(sig) + 1);
		if(tmp.x == 0)
			zeroCnt[pos] ++;
		else
			ways[pos] = ways[pos] * tmp;
	}
	if(zeroCnt[pos])
		return 0;
	return ways[pos];
}

void calca(int pos = 0, Mod pv = 1) {
	ans[pos] = ways[pos] ;
	if(pv.x == 0)
		zeroCnt[pos] ++;
	else
		ans[pos] = ans[pos] * pv ;
	//~ printf("%d\n", pos);
	//~ for(const int sig : adj[pos])
		//~ printf("\t%d >> %lld %lld\n", sig, ans[pos].x, (ways[sig] + 1).x);
	for(const int sig : adj[pos]) {
		if(zeroCnt[pos] == 0) {
			calca(sig, ans[pos] / (ways[sig] + 1) + Mod(1));
		}
		else if(zeroCnt[pos] == 1 && (ways[sig] + 1).x == 0) {
			calca(sig, ans[pos] + Mod(1));
		}
		else {
			calca(sig, Mod(1));
		}
	}
	if(zeroCnt[pos])
		ans[pos] = 0;
}

int main() {
	int N ;
	scanf("%d", &N);
	for(int i=1, a; i<N; i++) {
		scanf("%d", &a);
		adj[a-1].push_back(i);
	}
	inita();
	calca();
	for(int i=0; i<N; i++)
		printf("%lld ", ans[i].x);
	printf("\n");
}
