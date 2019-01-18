#include <bits/stdc++.h>
using namespace std;

int N, K;

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	scanf("%d %d", &N, &K);
	
	if ( N <= K ) {
		printf("2\n");
		return 0;
	}
	N *= 2;
	int ANS = N / K;
	if (N % K) ANS++;
	
	printf("%d\n", ANS);
	
}
