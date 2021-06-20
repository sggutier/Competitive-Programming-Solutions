#include <bits/stdc++.h>
using namespace std;
const int limN = 1005;

int mat[limN][limN];

int main() {
	int N ;
	scanf("%d", &N);
	for(int i=1; i<=N; i++) {
		for(int j=1; j<=N; j++) {
			scanf("%d", &mat[i][j]);
			mat[i][j] += mat[i][j-1];
		}
	}
	int ans = mat[1][1];
	for(int l=1; l<=N; l++) {
		for(int r=l; r<=N; r++) {
			int s = 0;
			for(int i=1; i<=N; i++) {
				//~ printf("%d %d %d => %d\n", l, r, i, mat[i][r] - mat[i][l-1]);
				s += mat[i][r] - mat[i][l-1];
				ans = max(ans, s);
				s = max(s, 0);
			}
		}
	}
	printf("%d\n", ans);
}
