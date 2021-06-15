#include <bits/stdc++.h>
using namespace std;
const int limN = 1005;
const int limA = 30*600;

char noms[limN][5000];
int alc[limN], csts[limN];
//~ int minCst[limN][limA];
int prevo[limN][limA];
int tipo[limN][limA];

int leeNum(int dec) {
	int a, b ;
	scanf("%d.%d", &a, &b);
	dec = dec==1? 10 : 100;
	return a*dec + b;
}

int main() {
	int M, TD, D;
	M = leeNum(2);
	TD = leeNum(1)*60;
	scanf("%d", &D);
	//~ printf("TD = %d\n", TD);
	for(int i=1; i<=D; i++) {
		scanf("%s", noms[i]);
		scanf("%d", &alc[i]);
		int x, y;
		scanf("%d/%d", &x, &y);
		csts[i] = leeNum(2);
		alc[i] *= 600 / y;
		//~ printf("%s => %d %d %d\n", noms[i], alc[i], y, csts[i]);
	}
	
	tipo[0][0] = -1;
	for(int i=1; i<=D; i++) {
		for(int m=M; m; m--) {
			for(int j=TD; j; j--) {
				for(int k=1; k*alc[i] <= j && k * csts[i] <= m; k++) {
					int r = j - k*alc[i], w = m - k*csts[i];
					if(!tipo[w][r]) continue;
					tipo[m][j] = i;
					prevo[m][j] = k;
					//~ printf("%d %d posible con %d %d\n", m, j, i, k);
				}
			}
		}
	}
	
	if(!tipo[M][TD] ) {
		printf("IMPOSSIBLE\n");
		return 0;
	}
	
	for(int j=TD, m=M; j && m; ) {
		int i = tipo[m][j], k = prevo[m][j];
		printf("%s %d\n", noms[i], k);
		int r = j - k*alc[i], w = m - k*csts[i];
		m = w ;
		j = r; 
	}
}
