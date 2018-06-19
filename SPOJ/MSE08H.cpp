// - This is not my idea, but somehow the solution is the product of the euler phi function
//   of all the numbers in the set
// - This is kinda easy to do since all the primes for all the numbers are already there.
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;
const int limN = 1005;

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

int nums[limN];
Mod phi[limN];
bool isComp[limN];

void testCase(int N) {
    Mod ans = 1, frac;
    for(int i=0; i<N; i++)
        scanf("%d", &nums[i]);
    sort(nums, nums+N);    
    for(int i=1; i<N; i++) {
        phi[i] = nums[i];
        isComp[i] = false;
    }
    for(int i=1; i<N; i++) {
        if(!isComp[i]) {
            // printf("%d  is prime\n", nums[i]);
            frac = Mod(nums[i]-1) / nums[i];
            for(int j=i; j<N; j++)
                if(nums[j] % nums[i] == 0) {
                    phi[j] = phi[j]*frac;
                    isComp[j] = true;
                }
        }
        ans = ans*phi[i];
    }
    printf("%lld\n", ans.x);
}

int main() {
    int n ;
    while(scanf("%d", &n) != EOF)
        testCase(n);
}
