#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll mod = 1e6 + 3;

ll euclid(ll a, ll b, ll &x, ll &y) {
    if (b) { ll d = euclid(b, a % b, y, x);
        return y -= a/b * x, d; }
    return x = 1, y = 0, a;
}

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

int main() {
    ll n, k;
    Mod p, den;
    scanf("%lld", &n);
    scanf("%lld", &k);
    if(n <= 60 && (1LL << n) + 1 <= k) {
        printf("1 1\n");
        return 0 ;
    }
    p = Mod(2)^n;
    Mod num = 1;
    den = p ^ k;
    for(int i=0; i < mod; i++) {
        ll x = (k/mod + (i < k % mod? 1 : 0));
        num = num * ((p - i) ^ x);
    }
    // printf("\n");
    ll gCnt = n;
    k -- ;
    for(ll i=60; i; i--) {
        gCnt += k / (1LL << i);
    }
    // cout << gCnt << endl;
    num = den - num;
    num = num / (Mod(2)^gCnt);
    den = den / (Mod(2)^gCnt);
    printf("%lld %lld\n", num.x, den.x);
}
