#include <bits/stdc++.h>
using namespace std;
const int limL = 8005;
const int limG = 805;
typedef long long ll;

int L, G;
ll crz[limL];
ll dp[limG][limL];
int anso[limG][limL];

int main() {
	scanf("%d%d", &L, &G);
	for(int i=1; i<=L; i++) {
		scanf("%lld", &crz[i]);
		crz[i] += crz[i-1];
	}
	for(int l=1; l<=L; l++) {
		dp[1][l] = crz[l]*l;
	}
	for(int g=2; g<=G; g++) {
		anso[g][L+1] = L;
		//~ printf("g: %2d || ", g);
		for(int l=L; l>=1; l--) {
			dp[g][l] = crz[l]*l;
			for(int i=anso[g-1][l]; i<=anso[g][l+1]; i++) {
				ll nov = dp[g-1][i] + (crz[l]-crz[i])*(l-i);
				if(nov < dp[g][l]) {
					dp[g][l] = nov;
					anso[g][l] = i;
				}
			}
			//~ printf("%d ", anso[g][l]);
		}
		//~ printf("\n");
	}
	printf("%lld\n", dp[G][L]);
}
