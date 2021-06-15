#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
const int limN = 1e5 + 5;

int sums[limN];
int arr[limN];
ld c, d;

ld mina(int S, int a, int T) {
	ld w = (1.0/a) * c * d * d;
	//~ printf("w = %.9Lf, a = %d, d = %.3Lf, c = %.3Lf\n", w, a, c, d);
	w = sqrtl(w);
	ld t = w-T;
	//~ printf("%d %d %d => %.2Lf\n", S, a, T, t);
	return max(0.0L, min(t, 1.0L));
}

ld calca(int S, int a, int T) {
	ld t = T + (a? mina(S, a, T) : 0);
	//~ ld t = T;
	ld v = d / t;
	//~ printf("t = %.4Lf\n", t);
	//~ printf("%d %d %d => %.3Lf %.3Lf\n", S, a, T, S + a*(t-T) + c*v*v * t, t - T);
	return S + a*(t-T) + c*v*v * t;
}

int main() {
	int N ;
	long double ans = 1e100;
	scanf("%d%Lf%Lf", &N, &c, &d);
	d *= 60;
	for(int i=1; i<=N; i++) {
		scanf("%d", &arr[i]);
		sums[i] += arr[i] + sums[i-1];
		ans = min(ans, calca(0, arr[i], 0));
	}
	for(int l=0; l<N; l++) {
		for(int r=l+1; r<=N; r++) {
			ans = min(ans,
			calca(sums[r] - sums[l], 0, r-l));
			if(l)
				ans = min(ans, calca(sums[r] - sums[l], arr[l], r-l));
			if(r < N)
				ans = min(ans, calca(sums[r] - sums[l], arr[r+1], r-l));
		}
	}
	printf("%.9Lf\n", ans);
}

