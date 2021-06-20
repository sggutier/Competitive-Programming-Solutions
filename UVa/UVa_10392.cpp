#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef unsigned long long ull;
#define rep(i, a, b) for(int i=a; i < (b); ++i)
#define all(x) x.begin(), x.end()
#define sz(x) (int) (x).size()

const int MAX_PR = 5000000;
bitset<MAX_PR> isprime;
vi eratosthenes_sieve(int lim) {
	isprime.set(); isprime[0] = isprime[1] = 0;
	for (int i = 4; i < lim; i += 2) isprime[i] = 0;
	for (int i = 3; i*i < lim; i += 2) if (isprime[i])
		for (int j = i*i; j < lim; j += i*2) isprime[j] = 0;
	vi pr;
	rep(i,2,lim) if (isprime[i]) pr.push_back(i);
	return pr;
}


const int bits = 1;
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
	vi p = eratosthenes_sieve(1 << ((bits + 2) / 3));
	pr.assign(all(p));
}

void testCase(ull n) {
    auto ans = factor(n);
    sort(ans.begin(), ans.end());
    for(const ull &x:ans) {
        while(n%x==0) {
            printf("    %llu\n", x);
            n /= x;
        }
    }
    printf("\n");
}

int main() {
    init(63);
    long long n ;
    while(scanf("%lld", &n)!=EOF && n!=-1) {
        testCase(n);
    }
}
