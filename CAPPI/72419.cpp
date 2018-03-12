#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std ;
#define lim 40

int N ;
bool usd[lim] ;
int mat[lim][lim] ;

int main() {
	int M ;
	int a, b, i, x ;
	long long W = 0LL ;
	int res = (1<<30) ;
	
	scanf("%d%d", &N, &M ) ;
	for( i=0; i<M; i++ ) {
		scanf("%d%d", &a, &b ) ;
		a--, b-- ;
		if( a!=b ) {
			mat[a][b] = 1 ;
			mat[b][a] = 1 ;
		}
	}
	
	
	for( W=0LL; W<(1LL<<N); W++ ) {
		a = 0 ;
		x = 0 ;
		for( i=0; i<N; i++ ) 
			usd[i] = 0 ;
			
		for( i=0; i<N; i++ ) {
			if( (1LL<<i)&W   )  {
				x ++ ;
				if( !usd[i] ) {
					usd[i] = 1 ;
					a ++ ;
				}
				for( b=0; b<N; b++ ) {
					if( mat[i][b] && !usd[b] ) {
						usd[b] = 1 ;
						a ++ ;
					}
				}
			}
		}
		
		if( a==N ) {
			res = min( res, x ) ;
		}
	}
	
	
	printf("%d\n", res ) ;
	
	return 0 ;
}
