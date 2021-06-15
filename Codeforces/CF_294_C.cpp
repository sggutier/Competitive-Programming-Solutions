#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll euclid(ll a, ll b, ll &x, ll &y) {
	if (b) { ll d = euclid(b, a % b, y, x);
		return y -= a/b * x, d; }
	return x = 1, y = 0, a;
}

const ll mod = 1e9 + 7;
struct Mod {
	ll x;
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

bool mdo[1005];

int main() {
	int N, D;
    Mod ans (1);
    int pt = 0;
    
    scanf("%d%d", &N, &D);
    for(int i=0; i<D; i++) {
        int a ;
        scanf("%d", &a);
        mdo[a] = true;
    }
    mdo[N+1] = true;
    
    for(int i=2; i<=N-D; i++)
        ans = ans*Mod(i);
    N++;
    for(int i=1, u=0; i<=N; i++) {
        if(!mdo[i])
            continue;
        if(u!=i-1) {
            int k = i-u-1;
            if(u!=0 && i!=N)
                pt += k-1;
            Mod ft(1);
            for(int j=2; j<=k; j++)
                ft = ft*Mod(j);
            ans = ans/ft;
        }
        u = i;
    }
    while(pt--)
        ans = ans*Mod(2);

    printf("%lld\n", ans.x);
}

