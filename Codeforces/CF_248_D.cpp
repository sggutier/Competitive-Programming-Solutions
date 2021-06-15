#include <cstdio>
#include <algorithm>
#include <queue>
#include <iostream>
#include <map>
#include <set>
#include <cmath>
#include <string>
#include <cstring>
#include <list>
using namespace std ;
const int lim = 500005 ;

int N, W, F, T ;
char arr[lim] ;

bool sePuede( int K ) {
	int Q=0, L=0, ini, ult=0 ;
	int x=K, y=0 ;

	for( int i=0; i<N && (y<W || x<W); i++ ) {
		if( arr[i]=='.' )
			continue ;
		ult = i ;
		if( arr[i]=='H' )
			y ++; 
		else
			x ++ ;
	}

	if( x<W )
		return 0 ;

	for( int i=0, j=0; i<N && (j<W || Q>0); i++ ) {
		L ++ ;
		if( arr[i]=='.' )
			continue ;
		if( arr[i]=='S' ) {
			if( Q==1 ) {
				Q -- ;
				if( ult-ini+ult-i+L <= T )
					return 1 ;
				L += (i-ini)*2 ;
			}
			else if( Q>1 ) 
				Q -- ;
			else
				K ++ ;
		}
		else if( arr[i]=='H' ) {
			j ++ ;
			if( K>0 ) 
				K -- ;
			else {
				if( Q==0 ) 
					ini = i ;
				Q ++ ;
			}
		}
	}

	return Q==0 && L<=T ;
}

int main() {
	scanf("%d", &N ) ;
	scanf("%d", &T ) ;
	scanf("%s", arr ) ;

	W = 0 ;
	for( int i=0; i<N; i++ ) {
		if( arr[i]=='H' ) {
			W ++ ;
			F = i+1 ;
		}
	}

	if( T<F ) {
		printf("-1\n" ) ;
		return 0 ; 
	}

	int ini=0, fin=W ;
	while( ini<fin ) {
		int piv = (ini+fin)/2 ;
		if( sePuede(piv) )
			fin = piv ;
		else
			ini = piv+1 ;
	}

	printf("%d\n", ini ) ;

	return 0 ;
}


