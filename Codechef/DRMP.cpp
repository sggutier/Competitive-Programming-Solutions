// AB = MA + MB
// AB = M(A + B)
// AB / (A + B) = M
// AB - MB = MA
// B(A - M) = MA
// B = MA / (A - M)
//
// B = M(M + k) / k = (M^2 + Mk)
#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int MAXN = 5000;
bitset <MAXN> is_composite;
bitset <MAXN> isprime;

vector<int> sieve (int n) {
    vector <int> prime;
    for (int i = 2; i < n; ++i) {
        isprime[i] = !is_composite[i];
        if (!is_composite[i]) prime.push_back (i);
        for (int j = 0; j < (int) prime.size () && i * prime[j] < n; ++j) {
            is_composite[i * prime[j]] = true;
            if (i % prime[j] == 0) break;
        }
    }
    return prime;
}


typedef unsigned long long ull;
const int bits = 10;
// if all numbers are less than 2^k, set bits = 64-k
const ull po = 1 << bits;
ull mod_mul(ull a, ull b, ull &c) {
    ull x = a * (b & (po - 1)) % c;
    while ((b >>= bits) > 0) {
        a = (a << bits) % c;
        x += (a * (b & (po - 1))) % c;
    }
    return x % c;
}
ull mod_pow(ull a, ull b, ull mod) {
    if (b == 0) return 1;
    ull res = mod_pow(a, b / 2, mod);
    res = mod_mul(res, res, mod);
    if (b & 1) return mod_mul(res, a, mod);
    return res;
}

bool prime(ull p) {
    if (p == 2) return true;
    if (p == 1 || p % 2 == 0) return false;
    ull s = p - 1;
    while (s % 2 == 0) s /= 2;
    rep(i,0,15) {
        ull a = rand() % (p - 1) + 1, tmp = s;
        ull mod = mod_pow(a, tmp, p);
        while (tmp != p - 1 && mod != 1 && mod != p - 1) {
            mod = mod_mul(mod, mod, p);
            tmp *= 2;
        }
        if (mod != p - 1 && tmp % 2 == 0) return false;
    }
    return true;
}

vector<ull> pr;
ull f(ull a, ull n, ull &has) {
    return (mod_mul(a, a, n) + has) % n;
}
vector<ull> factor(ull d) {
    vector<ull> res;
    for (int i = 0; i < sz(pr) && pr[i]*pr[i] <= d; i++)
        if (d % pr[i] == 0) {
            while (d % pr[i] == 0) d /= pr[i];
            res.push_back(pr[i]);
        }
    //d is now a product of at most 2 primes.
    if (d > 1) {
        if (prime(d))
            res.push_back(d);
        else while (true) {
            ull has = rand() % 2321 + 47;
            ull x = 2, y = 2, c = 1;
            for (; c==1; c = __gcd((y > x ? y - x : x - y), d)) {
                x = f(x, d, has);
                y = f(f(y, d, has), d, has);
            }
            if (c != d) {
                res.push_back(c); d /= c;
                if (d != c) res.push_back(d);
                break;
            }
        }
    }
    return res;
}
void init(int bits) {//how many bits do we use?
    vi p = sieve(1 << ((bits + 2) / 3));
    pr.assign(all(p));
}

const int LIM_A = 3e5 + 5 ;

int A = 0 ;
ll ans[LIM_A];
__int128 maxM ;
__int128 M2 ;
vector<ull> fcs;

void genDivs(const int pos, const __int128 prod = 1) {
    // cout << pos << " " << (ll) prod << endl;
    if(prod > maxM || M2 % prod) return ;
    if(pos == -1) {
        ans[A++] = prod;
        return ;
    }
    genDivs(pos-1, prod);
    genDivs(pos, prod * fcs[pos]);
}

void testCase() {
    A = 0 ;
    ll M = maxM ;
    fcs = factor(maxM);
    M2 = maxM * maxM;
    genDivs(fcs.size() - 1);
    // printf("------\n");
    sort(ans, ans+A);
    printf("%d\n", A);
    for(int i=0; i < A; i++)
        printf("%lld\n", ans[i] + M);
}

int main() {
    init(36);
    int tc ;
    ll a ;
    scanf("%d", &tc);
    for(int i=0; i < tc; i++) {
        scanf("%lld", &a);
        maxM = a;
        testCase();
    }
}
