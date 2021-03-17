#include <bits/stdc++.h>
using namespace std;
typedef __int128 ll;
typedef long long ii;
const int LIM_N = 6;

ll gcd(ll a, ll b) { return __gcd(a, b); }

ll euclid(ll a, ll b, ll &x, ll &y) {
    if (b) { ll d = euclid(b, a % b, y, x);
        return y -= a/b * x, d; }
    return x = 1, y = 0, a;
}


const ll mod = 100000000003;
struct Mod {
    ll x;
    Mod(ll xx = 0) : x(xx) {}
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

void testCase(ii bas) {
    Mod a, b ;
    Mod nums[LIM_N];
    nums[0] = bas;
    for(int i=1; i < LIM_N; i++) {
        ii x ;
        scanf("%lld", &x);
        nums[i] = x;
    }
    b = nums[1];
    for(int i=2; i < LIM_N; i++) {
        if(nums[i-2].x == nums[i-1].x) continue;
        a = (nums[i] - nums[i-1]) / (nums[i-1] - nums[i-2]);
        b = nums[1] - nums[0] * a;
    }
    printf("%lld\n", (ii) (nums[LIM_N - 1] * a + b).x);
}

int main() {
    ii x ;
    while(scanf("%lld", &x) != EOF) {
        testCase(x);
    }
}
