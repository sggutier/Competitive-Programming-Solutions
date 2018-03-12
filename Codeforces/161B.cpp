#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std ;

int main() {
	int N, K ;
	int penc[lim], tab[lim] ;
	int A=0, B=0 ;
	double res = 1.0*0 ;
	
	scanf("%d%d", &N, &K ) ;
	for( int i=0; i<N; i++ ) {
		int x, y ;
		scanf("%d%d", &x, &y ) ;
		if( y==1 )
			penc[A++] = x ;
		else
			tab[B++] = x ;
	}
	
	sort( penc, penc+A ) ;
	for( int i=0; i<K && i<A; i++ ) {
		for( int j=B-1; j>=0; j-- ) {
			if( tab[j]!=0 && tab[j]<=penc[i] ) {
				res += tab[j]/2.0 ;
				res += penc[i] ;
				penc[i] = 0 ;
				tab[j] = 0 ;
			}
		}
		res += penc[i]/2.0 ;
		penc[i] = 0 ;
	}
	for( int i=0; i<A; i++ )
		res += penc[i] ;
	for( int i=0; i<B; i++ )
		res += tab[i] ;
		
	printf("%
	
	return 0 ;
}
