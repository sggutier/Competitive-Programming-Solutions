#include <bits/stdc++.h>
using namespace std;
const int limN = 105;

int N ;
int nums[limN];
bool usd[limN];
bool esp[limN];

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	
	int f ;
	scanf("%d%d", &N, &f);
	for(int i=0; i<N; i++) {
		scanf("%d", &nums[i]);
		esp[nums[i]] = true;
	}
	
	for(int i=0, t; i<N; i++) {
		t = nums[i];
		if(usd[t]) continue ;
		for(int d=(t-f) / abs(t-f); f != t; f += d) {
			if(!usd[f] && esp[f])
				printf("%d ", f);
			usd[f] = true;
		}
		usd[f] = true;
		printf("%d%c", f, i==N-1? '\n' : ' ');
	}
}

