#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std ;
#define lim 100005

int N, M ;
int T, W=0 ;
int x[lim], y[lim], c[lim] ;

long long carga( int rI, int rF, int cI, int cF ) {
	long long res = 0LL ;
	for( int i=0; i<W; i++ ) 
		if( x[i]>=rI && x[i]<=rF && y[i]>=cI && y[i]<=cF ) 
			res += c[i] ;
			
	return res ;
}

int main() {
	char S[100] ;
	
	scanf("%d%d", &N, &M ) ;
	scanf("%d", &T ) ;
	
	for( int i=0; i<T; i++ ) {
		
		scanf("%s", S ) ;
		if( S[0] == 'D' ) {
			scanf("%d%d%d", &x[W], &y[W], &c[W] ) ;
			W ++ ;
		}
		else {
			int rI, rF, cI, cF ;
			scanf("%d%d%d%d", &rI, &cI, &rF, &cF ) ;
			cout << carga(rI,rF,cI,cF) << endl ;
		}
	}
	
	return 0 ;
}
