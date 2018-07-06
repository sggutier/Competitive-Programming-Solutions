#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

#include <valarray>
typedef long double ld;
const int limN = 1e5 + 5;
const int limK = 30000 + 5;

typedef valarray<complex<ld> > carray;
void fft(carray& x, carray& roots) {
	int N = sz(x);
	if (N <= 1) return;
	carray even = x[slice(0, N/2, 2)];
	carray odd = x[slice(1, N/2, 2)];
	carray rs = roots[slice(0, N/2, 2)];
	fft(even, rs);
	fft(odd, rs);
	rep(k,0,N/2) {
		auto t = roots[k] * odd[k];
		x[k    ] = even[k] + t;
		x[k+N/2] = even[k] - t;
	}
}

typedef vector<ld> vd;
vd conv(const vd& a, const vd& b) {
	int s = sz(a) + sz(b) - 1, L = 32-__builtin_clz(s), n = 1<<L;
	if (s <= 0) return {};
	carray av(n), bv(n), roots(n);
	rep(i,0,n) roots[i] = polar(1.0, -2 * M_PI * i / n);
	copy(all(a), begin(av)); fft(av, roots);
	copy(all(b), begin(bv)); fft(bv, roots);
	roots = roots.apply(conj);
	carray cv = av * bv; fft(cv, roots);
	vd c(s); rep(i,0,s) c[i] = cv[i].real() / n;
	return c;
}

vd izq, der;
int arr[limN];

ll calca(int l, int r) {
    ll ans = 0;
    vd c;
    for(int i=l; i<=r; i++)
        der[arr[i]]-=1.0;
    c = conv(izq, der);
    for(int i=l; i<=r; i++) {
        ans += ((ll) roundl(c[2*arr[i]])) ;
        for(int j=i+1, s; j<=r; j++) {
            s = 2*arr[j] - arr[i];
            if(s >= 0 && s < 2*limK)
                ans += (ll) der[s];
            s = 2*arr[i] - arr[j];
            if(s >= 0 && s < 2*limK)
                ans += (ll) izq[s];
        }
        izq[arr[i]]+=1.0;
    }
    return ans;
}

int main() {
    int N ;
    ll ans = 0;
    int rt ;
    scanf("%d", &N);
    if(N >= limN) {
        printf("-1\n");
        return 0;
    }
    izq.resize(limK);
    der.resize(limK);
    for(int i=0; i<N; i++) {
        scanf("%d", &arr[i]);
        if(arr[i] <= 0 || arr[i] > 30000) {
            printf("-1\n");
            return 0;
        }
        // arr[i] = min(i, 30000);
        der[arr[i]]+=1.0;
    }
    
    // rt = 2;
    rt = max(1.0, sqrt(N));
    for(int i=0; i<N; i+=rt) {
        ans += calca(i, min(i+rt-1, N-1));
        // printf("%d %d\n", i, min(i+rt-1, N-1));
    }

    printf("%lld\n", ans);
}
