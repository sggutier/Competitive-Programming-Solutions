#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef double ld;
#include <valarray>
const int limN = 5e5 + 5;

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

int crg[limN];
vd A, B, C;
int N, M ;
char X[limN], Y[limN];

void calca(const char tp) {
    for(int i=0; i<N; i++) {
        A[i] = X[i]==tp? 1 : 0;
    }
    for(int i=0; i<M; i++) {
        B[i] = Y[M-1-i]==tp? 1 : 0;
    }
    C = conv(A, B);
    // printf("%c => ", tp);
    // for(const auto c : C)
    //     printf("%d ", (int) round(c));
    // printf("\n");
    for(int i=N-M; i>=0; i--) {
        crg[i] += (int) round(C[i+M-1]);
    }
}

int main() {
    fgets(X, limN, stdin);
    fgets(Y, limN, stdin);
    N = strlen(X);
    M = strlen(Y);
    N--, M--;
    X[N] = 0;
    Y[M] = 0;
    A.resize(N);
    B.resize(M);
    calca('A');
    calca('C');
    calca('G');
    calca('T');
    int ans = 0;
    for(int i=N-M; i>=0; i--) {
        ans = max(ans, crg[i]);
    }
    printf("%d\n", M-ans);
}
