#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define f first
#define s second
const int limN = 3e5 + 10;

ll gcd(ll a, ll b) { return __gcd(a, b); }

ll euclid(ll a, ll b, ll &x, ll &y) {
	if (b) { ll d = euclid(b, a % b, y, x);
		return y -= a/b * x, d; }
	return x = 1, y = 0, a;
}

const ll mod = 1e9 + 9;
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
typedef pair<Mod, Mod> pmm;

int N ;
Mod arb[limN*6];
pmm crg[limN*6];
Mod fibs[limN];

Mod val(pmm w, const int k) {
    if(k < 2)
        return k==0? w.f : w.s;
    return w.f*fibs[k-1] + w.s*fibs[k] ;
}

Mod sumo(pmm w, const int k) {
    return w.s * (fibs[k+2] - 1) + w.f * fibs[k+1] ;
}

void push(const int pos, const int len, const int mt) {
    if(crg[pos].f.x==0 && crg[pos].s.x==0)
        return ;
    arb[pos] = arb[pos] + sumo(crg[pos], len);
    crg[pos*2 + 1] =
        {crg[pos*2 + 1].f + crg[pos].f,
         crg[pos*2 + 1].s + crg[pos].s} ;
    crg[pos*2 + 2] =
        {crg[pos*2 + 2].f + val(crg[pos], mt),
         crg[pos*2 + 2].s + val(crg[pos], mt+1)} ;
    crg[pos] = {0, 0};
}

void insprev(const int x, const int t, const int pos = 0, const int l = 0, const int r = N-1) {
    arb[pos] = arb[pos] + x;
    if(l == r)
        return;
    int piv = (l+r) / 2;
    if(t <= piv)
        insprev(x, t, pos*2 + 1, l, piv);
    else
        insprev(x, t, pos*2 + 2, piv+1, r);
}

void insert(const int tl, const int tr, const int pos = 0, const int L = 0, const int R = N-1) {
    int piv = (L + R) / 2;
    if(tr < L || R < tl) {
        push(pos, R-L, piv-L + 1);
        return ;
    }
    if(tl <= L && R <= tr) {
        crg[pos] = {crg[pos].f + fibs[L-tl + 1],
                    crg[pos].s + fibs[L-tl + 2]};
        push(pos, R-L, piv-L + 1);
        return ;
    }   
    push(pos, R-L, piv-L + 1);
    insert(tl, tr, pos*2 + 1, L, piv);
    insert(tl, tr, pos*2 + 2, piv+1, R);
    arb[pos] = arb[pos*2 + 1] + arb[pos*2 + 2];
}

Mod query(const int tl, const int tr, const int pos = 0, const int L = 0, const int R = N-1) {
    if(tr < L || R < tl)
        return Mod(0) ;    
    int piv = (L + R) / 2;
    push(pos, R-L, piv-L + 1);
    if(tl <= L && R <= tr)
        return arb[pos];
    return  query(tl, tr, pos*2 + 1, L, piv)
          + query(tl, tr, pos*2 + 2, piv+1, R);
}

void parb(const int pos = 0, const int L = 0, const int R = N-1, bool fg = false)  {
    int piv = (L + R) / 2;
    if(fg)
        push(pos, R-L, piv-L + 1);
    // printf("[%d %d || %lld {%lld %lld}] ", L, R, arb[pos].x, crg[pos].f.x, crg[pos].s.x);
    if(L == R)
        return ;
    parb(pos*2 + 1, L, piv, fg);
    parb(pos*2 + 2, piv+1, R, fg);
}

int main() {
    int Q ;
    scanf("%d%d", &N, &Q);
    for(int i=0, w; i<N; i++) {
        scanf("%d", &w);
        insprev(w, i);
    }

    fibs[0] = Mod(0);
    fibs[1] = Mod(1);
    for(int i=2; i<=N+5; i++)
        fibs[i] = fibs[i-1] + fibs[i-2];

    for(int q = 0, t, l, r; q<Q; q++) {
        scanf("%d%d%d", &t, &l, &r);
        l--, r--;
        if(t==1)
            insert(l, r);            
        else
            printf("%lld\n", query(l, r).x);
        // parb(0,0, N-1, true);
    }
}
