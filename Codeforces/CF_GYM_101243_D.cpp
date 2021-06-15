#include <bits/stdc++.h>
using namespace std;
const int limN = 1e5 + 5;
const int mod = 1e9 + 7;

char lin[limN];
bool valdSg[300][300];
int ans[limN];

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	
	string dirs[] = {"NW", "NE", "SW", "SE"};
	for(auto d : dirs) {
		valdSg[(int) d[0]][(int) d[1]] = 1;
	}
	
	int N ;
	scanf("%s", lin);
	N = strlen(lin);
	ans[N] = 1;
	for(int i=N-1; i>=0; i--) {
		int c = lin[i], d = lin[i+1];
		ans[i] = ans[i+1];
		if(valdSg[c][d])
			ans[i] = (ans[i] + ans[i+2]) % mod;
	}
	
	printf("%d\n", ans[0]);
}
