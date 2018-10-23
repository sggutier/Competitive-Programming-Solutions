#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int limN = 2e6 + 5;

ll gcd(ll a, ll b) { return __gcd(a, b); }

ll euclid(ll a, ll b, ll &x, ll &y) {
	if (b) { ll d = euclid(b, a % b, y, x);
		return y -= a/b * x, d; }
	return x = 1, y = 0, a;
}

const ll mod = 1e9 + 7;
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


Mod facs[limN];
Mod invF[limN];
int N ;
ll nums[limN];

void precarga() {
    invF[0] = facs[0] = 1;
    for(int i=1; i<limN; i++) {
        facs[i] = facs[i-1] * i;
        invF[i] = invF[i-1] / i;
    }
}

Mod nenk(int n, int k) {
    return facs[n] * invF[n-k] * invF[k];
}

void testCase() {
    int W = 0;
    int ucnt = 0;
    Mod sng ;
    scanf("%d", &N);
    ll a ;
    for(int i=0; i<N; i++) {
        scanf("%lld", &a);
        if(a==1)
            ucnt ++;
        else
            nums[W++] = a;
    }
    if(W == 0) {
        printf("%d\n", ucnt%2? 1 : 0);
        return ;
    }
    sort(nums, nums+W);
    sng = facs[W];
    nums[W] = -1;
    ll u = nums[0];
    for(int i=0, cnt=0; i<=W; i++) {
        if(nums[i] != u) {
            // printf("[%d %lld] ", cnt, nums[i-1]);
            sng = sng * invF[cnt];
            cnt = 0;
        }
        cnt ++;
        u = nums[i];
    }
    // printf("%lld\n", sng.x);

    Mod ans = 0;
    for(int i=0; i<=ucnt; i+=2) {
        int r = ucnt - i;
        // printf("[%d %d %lld]\n", W + r - 1, r, nenk(W -1 + r, r).x);
        ans = ans + sng * nenk(W-1 + r, r);
    }

    printf("%lld\n", ans.x);
}

int main() {
    precarga();
    int tc;
    scanf("%d", &tc);
    for(int i=0; i<tc; i++)
        testCase();
}
