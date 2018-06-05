#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int limN = 1e6 + 5;

typedef pair<ll, int> pli;
void count_sort(vector<pli> &b, int bits) { // (optional)
	//this is just 3 times faster than stl sort for N=10^6
	int mask = (1 << bits) - 1;
	rep(it,0,2) {
		int move = it * bits;
		vi q(1 << bits), w(sz(q) + 1);
		rep(i,0,sz(b))
			q[(b[i].first >> move) & mask]++;
		partial_sum(q.begin(), q.end(), w.begin() + 1);
		vector<pli> res(b.size());
		rep(i,0,sz(b))
			res[w[(b[i].first >> move) & mask]++] = b[i];
		swap(b, res);
	}
}
struct SuffixArray {
	vi a;
	string s;
	SuffixArray(const string& _s) : s(_s + '\0') {
		int N = sz(s);
		vector<pli> b(N);
		a.resize(N);
		rep(i,0,N) {
			b[i].first = s[i];
			b[i].second = i;
		}

		int q = 8;
		while ((1 << q) <= N) q++;
		for (int moc = 0;; moc++) {
			count_sort(b, q); // sort(all(b)) can be used as well
            // sort(all(b));
			a[b[0].second] = 0;
			rep(i,1,N)
				a[b[i].second] = a[b[i - 1].second] +
					(b[i - 1].first != b[i].first);

			if ((1 << moc) >= N) break;
			rep(i,0,N) {
				b[i].first = (ll)a[i] << q;
				if (i + (1 << moc) < N)
					b[i].first += a[i + (1 << moc)];
				b[i].second = i;
			}
		}
		rep(i,0,sz(a)) a[i] = b[i].second;
	}
	vi lcp() {
		// longest common prefixes: res[i] = lcp(a[i], a[i-1])
		int n = sz(a), h = 0;
		vi inv(n), res(n);
		rep(i,0,n) inv[a[i]] = i;
		rep(i,0,n) if (inv[i] > 0) {
			int p0 = a[inv[i] - 1];
			while (s[i + h] == s[p0 + h]) h++;
			res[inv[i]] = h;
			if(h > 0) h--;
		}
		return res;
	}
};

SuffixArray *SA;
int tams[limN];
long long tamsAcum[limN];
char* strs[limN];

int buscaPos(int ini, int fin, int dep) {
    char ref = strs[ini][dep];
    while(ini < fin) {
        int piv = (ini+fin)/2 + 1;
        if(dep < tams[piv] && ref == strs[piv][dep])
            ini = piv;
        else
            fin = piv-1;
    }
    return ini;
    // int ans = ini;
    // for(; ans<=fin && strs[ans][dep] == strs[ini][dep]; ans++);
    // return ans-1;
}

char ans[limN];
void calcaOrd(long long pos) {
    int ini = 1, fin = SA->s.size()-1;
    long long dep = 0;
    long long orgPos = pos;
    while(pos > 0 && ini <= fin) {
        // printf("%d %d %lld => %lld\n", ini, fin, dep, pos);
        int w = buscaPos(ini, fin, dep);
        if(w > limN || ini <= 0) {            
            printf("WTF mango\n");
            exit(0);
        }
        long long k = tamsAcum[w] - tamsAcum[ini-1] - dep*(w-ini+1LL);
        if( k < pos) {
            pos -= k;
            ini = w + 1;
        }
        else {
            if(dep >= tams[ini]) {
                printf("WTF mang\n");
                exit(0);
            }
            ans[dep] = strs[ini][dep];
            dep++;
            fin = w;
            pos -= (fin-ini+1);
        }
    }
    if(dep==0) {
        printf("Wat %lld\n", orgPos);
    }
    ans[dep] = 0;
    printf("%s\n", ans);
}

int main() {
	char str[limN];
    long long n ;
    int k ;

    scanf("%s", str);
    SA = new SuffixArray(str);
    n = SA->s.size()-1;

    for(int i=1; i<=n; i++) {
        // printf("%2d => %2d ---> %s\n", i, n - SA->a[i], str + SA->a[i]);
        tams[i] = n - SA->a[i];
        strs[i] = str + SA->a[i];
        tamsAcum[i] = tams[i] + tamsAcum[i-1];
        // printf("%d => %s\n", tams[i], strs[i]);
    }

    // for(int i=0, w=1; i<n; i++)
    //     for(int j=i; j<n; j++, w++) {
    //         printf("La %d-esima es ", w);
    //         calcaOrd(w);
    //     }
    // printf("%lld\n", (n*(n+1)) / 2);
    // return 0;

    scanf("%d", &k);
    if(k > (n*(n+1)) / 2)
        printf("No such line.\n");
    else
        calcaOrd(k);
}
