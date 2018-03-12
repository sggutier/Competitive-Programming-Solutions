#include <algorithm>
#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std ;
#define lim 300005

int N, W ;
int arr[lim] ;
int le[lim], ro[lim] ;
int tipLe[lim], tipRo[lim] ;
int ado[lim] ;

void calcSegm( int ini ) {
	int fin = min( N-1, ini+W-1 ) ;
	int i, j ;
	le[ini/W] = 0 ;
	ro[ini/W] = 0 ;
	ado[ini/W] = 0 ;
	
	for( i=ini; i<=fin; i++ ) {
		for( j=i+1; j<=fin && arr[j]==arr[i]; j++ ) ;
		ado[ini/W] = max( ado[ini/W], j-i ) ;
	}
	for( i=ini; i<=fin && arr[i]==arr[ini]; i++ ) ;
	le[ini/W] = i-ini ;
	for( i=fin; i>=ini && arr[fin]==arr[i]; i-- ) ;
	ro[ini/W] = fin-i ;
	tipLe[ini/W] = arr[ini] ;
	tipRo[ini/W] = arr[fin] ;
}

int query( int ini, int fin ) {
	int res = 0 ;
	int i=ini, carg = 0 ;
	int tipUlt = -1 ;
	
	for( ; i<=fin && i%W; i++ ) {
		if( arr[i]!=tipUlt ) 
			carg = 0 ;
		carg ++ ;
		res = max( res, carg ) ;
		tipUlt = arr[i] ;
	}
	for( ; i+W-1<=fin; i+=W ) {
		res = max( res, ado[i/W] ) ;
		if( tipLe[i/W] == tipUlt ) 
			res = max( res, carg + le[i/W] ) ;
			
		if( ro[i/W] == W && tipUlt == tipRo[i/W] ) {
			carg += ro[i/W] ;
		}
		else {
			carg = ro[i/W] ;
			tipUlt = tipRo[i/W] ;
		}
	}
	for( ; i<=fin; i++ ) {
		if( arr[i]!=tipUlt ) 
			carg = 0 ;
		carg ++ ;
		res = max( res, carg ) ;
		tipUlt = arr[i] ;
	}
	
	return res ;
}

int main() {
	int P ;
	
	scanf("%d%d", &N, &P ) ;
	for( int i=0; i<N; i++ )
		scanf("%d", &arr[i] ) ;
	
	W = int (sqrt(N) ) ;
	for( int i=0; i<N; i+=W )
		calcSegm(i) ;
	
	for( int i=0; i<P; i++ ) {
		int a, b ;
		scanf("%d%d", &a, &b ) ;
		printf("%d\n", query( a-1, b-1 )   ) ;
	}
	
	return 0 ;
	
}
