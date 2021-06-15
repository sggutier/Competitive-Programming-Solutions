#include <cstdio>
#include <iostream>
#include <utility>
#include <algorithm>
using namespace std ;
#define par pair<int,int>
#define r first
#define c second

int main() {
	int N, M, B ;
	par black[10000] ;
	char S[3][15] = { "Carrots", "Kiwis", "Grapes" }  ;
	int i, j ;
	int ini, fin, piv ;
	int Q ;
	par pos ;
	
	scanf("%d%d%d%d",&N,&M,&B,&Q ) ;
	for( i=0; i<B; i++ ) 
		scanf("%d%d",&black[i].r,&black[i].c ) ;
	black[B++] = par( 100000, 100000 ) ;
	sort( black, black+B ) ;
	
	while( Q ) {
		scanf("%d%d",&pos.r,&pos.c ) ;
		
		ini = 0, fin = B-1 ;
		while( ini<fin ) {
			piv = (ini+fin)/2 ;
			if( black[piv]>=pos ) 
				fin = piv ;
			else
				ini = piv+1 ;
		}
		
		if( black[ini] == pos )  {
			printf("Waste\n");
		}
		else {
			printf("%s\n", S[  (   (  (pos.r-1)*M  )%3   + (pos.c-1)  -  ini  +  9000000   )%3  ] ) ;
		}
		
		Q -- ;
	}
	
	return 0 ;
}
