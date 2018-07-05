#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i=a; i< (b); ++i)
#define trav(a, x) for(auto &a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int) (x).size()
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
const int limN = 200001;

typedef valarray<complex<double> > carray;
void fft(carray& x, carray& roots) {
	int N = sz(x);
	if(N <= 1) return;
	carray even = x[slice(0, N/2, 2)];
	carray odd = x[slice(1, N/2, 2)];
	carray rs = roots[slice(0, N/2, 2)];
	fft(even, rs);
	fft(odd, rs);
	rep(k, 0, N/2) {
		auto t = roots[k] * odd[k];
		x[k] = even[k] + t;
		x[k+N/2] = even[k] - t;
	}
}

typedef vector<double> vd;
vd conv(const vd& a, const vd& b) {
	int s = 2*limN - 1, L = 32-__builtin_clz(s), n = 1<<L;
	if(s  <= 0) return {};
	carray av(n), bv(n), roots(n);
	rep(i, 0, n) roots[i] = polar(1.0, -2 * M_PI * i/n);
	copy(all(a), begin(av)); fft(av, roots);
	copy(all(b), begin(bv)); fft(bv, roots);
	roots = roots.apply(conj);
	carray cv = av * bv; fft(cv, roots);
	vd c(s); rep(i, 0, s) c[i] = cv[i].real() / n;
	return c;
}

vd A(limN), anso;

void testCase(int N) {
	for(int i=0; i<limN; i++)
		A[i] = 0;
	for(int i=0, a; i<N; i++) {
		scanf("%d", &a);
		A[a] = 1;
	}
	anso = conv(A, A);
	int K = sz(anso);
	int Q ;
	int ans = 0;
	//~ for(int i=0; i<20; i++)
		//~ printf("%d => %d\n", i, (int) round(anso[i]));
	//~ printf("\n");
	for(scanf("%d", &Q); Q; Q--) {
		int w ;
		scanf("%d", &w);
		if(w<K && ((int) round(anso[w])) )
			ans ++;
		else if(w < limN && ((int) round(A[w])) )
			ans ++;
	}
	printf("%d\n", ans);
}

int main() {
	int N ;
	while(scanf("%d", &N)!=EOF) {
		testCase(N);
		//~ break;
	}
}
