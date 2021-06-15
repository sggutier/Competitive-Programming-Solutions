#include <bits/stdc++.h>
using namespace std;
const int limN = 4005;
const int limK = 805;

int dp[limK][limN];
int anso[limK][limN];
int mat[limN][limN];
char buf[limN*3];

int solve(int N, int K){
	for(int n=1; n<=N; n++)
		dp[1][n] = mat[n][n];
    for(int k=2; k<=K; k++) {
		//~ printf("%d :: ", k);
		anso[k][N+1] = N;
		for(int n=N; n; n-- ) {
		//~ for(int n=1; n<=N; n++) {
			dp[k][n] = mat[n][n] ;
			for(int i=anso[k-1][n]; i<=anso[k][n+1]; i++) {
			//~ for(int i=0; i<n; i++) {
				int cst = dp[k-1][i]
				+ mat[n][n] - mat[i][n] - mat[n][i] + mat[i][i] ;
				if(cst < dp[k][n]) {
					dp[k][n] = cst;
					anso[k][n] = i;
				}
			}
			//~ printf("%d ", anso[k][n]);
		}
		//~ printf("\n");
	}
	return dp[K][N] / 2;
}

int main(){
    // Read Input
    int n, k;
    scanf("%d%d", &n, &k);
    getchar();

    for (int i = 1; i <= n; ++i){
        fgets(buf, limN*3, stdin);

        for (int j = 1; j <= n; ++j){
            mat[i][j] = buf[(j - 1) * 2] - '0';
			mat[i][j] += mat[i][j-1] + mat[i-1][j] - mat[i-1][j-1];
        }
    }

    // Solve the problem
    int answer = solve(n, k);

    // Write output
    printf("%d\n", answer);

    return 0;
}
