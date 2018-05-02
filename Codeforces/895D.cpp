#include <bits/stdc++.h>
using namespace std;
typedef long long ll; 
const int limN = 1e6 + 5;
const ll mod = 1e9 + 7;

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


Mod facs[limN];
Mod invos[limN];
Mod invFacs[limN];
char A[limN], B[limN];
int N ;

Mod calca(char *a, char *b) {
    Mod ans = 0;
    vector <int> cnt(26);
    for(int i=0; i<N; i++)
        cnt[a[i]-'a']++;
    for(int i=0; i<N; i++) {
        Mod w = facs[N-1-i];
        int u = -1;
        for(int j=b[i]-'a'-1; j>=0; j--) {
            if(!cnt[j]) continue;
            cnt[j] --;
            // printf("%d => %d %d\n", j, cnt[j]+1, u==-1? -1 : cnt[u]);
            // printf("%d! / (", N-1-i);
            // for(int k=0; k<26; k++)
            //     if(cnt[k])
            //         printf("%d! ", cnt[k]);
            // printf(")\n");
            if(u==-1) {
                w = facs[N-1-i];
                for(int k=0; k<26; k++)
                    if(cnt[k])
                        w = w * invFacs[cnt[k]];
            }
            else {
                w = (w * Mod(cnt[j] + 1) ) * invos[cnt[u]];
            }
            // printf("    ===> %lld\n", w.x);
            u = j;
            cnt[j] ++;
            ans = ans + w;
        }
        if(!cnt[b[i]-'a'])
            break;
        cnt[b[i]-'a'] --;
    }
    return ans;
}

int main() {
    scanf("%s", A);
    scanf("%s", B);
    N = strlen(A);
    facs[0] = 1;
    for(int i=1; i<=N; i++) {
        facs[i] = facs[i-1] * Mod(i);
        invos[i] = Mod(1) / Mod(i);
        invFacs[i] = Mod(1) / facs[i];
    }

    printf("%lld\n", (calca(A, B) + Mod(mod -1) - calca(A, A)).x );
}
