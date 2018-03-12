#include <cstdio>
#include <algorithm>
#include <iostream>
#include <utility>
#include <queue>
#include <string>
#include <cstring>
#include <map>
#include <set>
#include <cmath>
#include <list>
#include <stack>
using namespace std ;
const int lim = 100005 ;

int N ;
int arr[lim] ;
int W = 0, asc[lim], pA[lim] ;

int main() {
	int res = -(1<<30) ;

	scanf("%d", &N ) ;
	for( int i=0; i<N; i++ )
		scanf("%d", &arr[i] ) ;

	asc[W] = (1<<30) ;
	pA[W] = -1 ;
	W ++ ;
	for( int i=0; i<N; i++ ) {
		int ini=0, fin=W-1 ;
		while( ini<fin ) {
			int piv = (ini+fin)/2 +1 ;
			if( arr[i]<asc[piv] )
				ini = piv ;
			else
				fin = piv-1 ;
		}

		asc[ini+1] = arr[i] ;
		pA[ini+1] = i ;
		W = ini+2 ;

		if( pA[ini]!=-1 )
			res = max( res, arr[ pA[ini] ] ^ arr[i] ) ;
	}
	W = 1 ;
	for( int i=N-1; i>=0; i-- ) {
		int ini=0, fin=W-1 ;
		while( ini<fin ) {
			int piv = (ini+fin)/2 +1 ;
			if( arr[i]<asc[piv] )
				ini = piv ;
			else
				fin = piv-1 ;
		}

		asc[ini+1] = arr[i] ;
		pA[ini+1] = i ;
		W = ini+2 ;

		if( pA[ini]!=-1 )
			res = max( res, arr[ pA[ini] ] ^ arr[i] ) ;
	}

	printf("%d\n", res ) ;

	return 0 ;
}


