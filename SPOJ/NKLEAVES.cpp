#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int limN = 2e5 + 5;
const int limK = 15;

int N, K;
ll wt[limN];
ll A[limN], B[limN];
ll dp[limK][limN];
int anso[limK][limN];

ll cost(int i, int n) {
	i --;
	//~ printf("pidiendo costo de %d %d\n", i+1, n);
	//~ printf("costo es %lld\n", (A[n]-A[i]) - i*(B[n]-B[i]));
	return (A[n]-A[i]) - i*(B[n]-B[i]);
}

void solve(int k, int b, int e, int optB, int optE) {
	if(b > e) return;
	if(k==1) return;
	int m = (b+e)/2;
	ll val = (1LL<<60), pos = -1;
	for(int i=optB; i<=min(optE, m); i++) {
		ll vdp = cost(i, m) + dp[k-1][i-1];
		if( vdp < val) {
			val = vdp;
			pos = i;
		}
	}
	dp[k][m] = val;
	solve(k, b, m-1, optB, pos);
	solve(k, m+1, e, pos, optE);
}

int main() {
	//~ N = 1000 ;
	//~ K = 11;
	//~ for(int i=1; i<=N; i++)
		//~ wt[i] = random() % 1000 + 1;
		//~ wt[i] = 1000;
	scanf("%d%d", &N, &K);
	for(int i=1; i<=N; i++) {
		scanf("%lld", &wt[i]);
	}
	for(int i=1; i<=N; i++) {
		A[i] = A[i-1] + (i-1)*wt[i];
		B[i] = B[i-1] + wt[i];
		dp[1][i] = A[i];
		//~ printf("%lld ", dp[1][i]);
	}
	//~ K = min(K, N);
	//~ printf("\n");
	//~ for(int k=2; k<=K; k++) {
		//~ printf("%d :: ", k);
		//~ anso[k][N+1] = N;
		//~ for(int i=1; i<=N; i++) {
		//~ for(int n=1; n<=N; n++) {
		//~ int ue = N;
		//~ for(int n=N; n; n --) {
			//~ dp[k][n] = A[n];
			//~ for(int i=anso[k-1][n]; i<=anso[k][n+1]; i++) {
			//~ for(int i=0; i<n; i++) {
				//~ if(!dp[k-1][i])
					//~ printf("Desde %d %d busque %d %d y no haylle nada\n", k, n, k-1, i);
				//~ ll cst = dp[k-1][i] + (A[n]-A[i]) - i*(B[n]-B[i]);
				//~ if(cst <= dp[k][n]) {
					//~ dp[k][n] = cst;
					//~ anso[k][n] = i;
				//~ }
			//~ }
			//~ ue = n;
		//~ }
		//~ for(int n=N; N-n+k <= K && n ; n-- ) {
			//~ ue = n;
		//~ }
		//~ for(int n=1; n<=N; n++) 
			//~ printf("%lld ", dp[k][n]);
			//~ printf("%3d ", anso[k][n]);
		//~ printf("\n");
		//~ printf("inito es %d\n", ue);
	//~ }
	//~ printf("%lld\n", dp[K][N]);
	
	for(int k=2; k<=K; k++)
		solve(k, 1, N, 1, N);
	printf("%lld\n", dp[K][N]);
}
