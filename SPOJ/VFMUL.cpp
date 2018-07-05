#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i=a; i< (b); ++i)
#define trav(a, x) for(auto &a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int) (x).size()
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
const int limN = 300005;

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
	int s = sz(a) + sz(b) - 1, L = 32-__builtin_clz(s), n = 1<<L;
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

char A[limN], B[limN];
int anso[limN*5];

void testCase() {
	scanf("%s", A);
	scanf("%s", B);
	int N = strlen(A), M=strlen(B) ;
	vd x(N), y(M), z;
	for(int i=0; i<N; i++)
		x[i] = A[N-1-i]-'0';
	for(int i=0; i<M; i++)
		y[i] = B[M-1-i]-'0';
	//~ printf("x = ");
	//~ for(int i=0; i<N; i++)
		//~ printf("%d", (int) round(x[i]));
	//~ printf("\n");
	//~ printf("y = ");
	//~ for(int i=0; i<M; i++)
		//~ printf("%d", (int) round(y[i]));
	//~ printf("\n");
	z = conv(x, y);
	//~ return ;
	N = z.size();
	long long crg=0, a=0 ;
	for(int i=0; i<N; i++) {
		a = crg + (long long) round(z[i]);
		anso[i] = a%10;
		crg = a/10;
	}
	while(crg) {
		anso[N++] = crg%10;
		crg /= 10;
	}
	for(int i=N-1, fst=0; i>=0; i--) {
		if(anso[i]!=0) {
			printf("%d", anso[i]);
			fst = 1;
		}
		else if(fst || i==0)
			printf("0");
	}
	printf("\n");
}

int main() {
	int tc;
	scanf("%d", &tc);
	while(tc--)
		testCase();
}
