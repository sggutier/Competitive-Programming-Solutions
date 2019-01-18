#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll N, K, A[100005], T[100005], G, iG;

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	scanf("%lld %lld", &N, &K);
	
	for(int i=0; i < N; i++) {
		scanf("%lld", &A[i]);
		if (A[i] > G) G = A[i], iG = i;
		T[i] = A[i] + (i ? T[i-1] : 0);
	}
	
	ll MN = iG, MX = T[iG] - G;
	
	while(true) {
		if ( K - MN < 0 ) {
			printf("KEK\n");
			break;
		}
		if ( K - MX <= 0 ) {
			printf("YES\n");
			break;
		}
		if ( K - MN <= G ) {
			printf("KEK\n");
			break;
		}
		if ( K - MX <= G ) {
			MX = K - G - 1;
		}
		K  -= G;
		MN += N - 1;
		MX += T[N - 1] - G;
	}
	
}
