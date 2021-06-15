#include <bits/stdc++.h>
using namespace std;

int N, M, ANS;
char MP[110][110];

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	
	scanf("%d %d", &N, &M);
	
	memset(MP, '0', sizeof(MP));
	
	for(int i=1;i<=N;i++) {
		scanf("%s", MP[i] + 1);
		MP[i][M+1] = '0';
	}
	
	for(int i=0;i<=N+1;i++) {
		for(int j=0;j<=M+1;j++) {
			if ( MP[i][j] != '0' )
				ANS += 2;
				
			if ( i > 0 ) 
				ANS += abs(MP[i][j] - MP[i-1][j]);
				
			if ( j > 0 )
				ANS += abs(MP[i][j] - MP[i][j-1]);
			//~ printf("%c", MP[i][j]);
		}
		//~ printf("\n");
	}
		
	printf("%d\n", ANS);
}
