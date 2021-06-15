#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std ;
#define lim 1000007

int N, R ;
int org[lim] ;
int ref[lim] ;
int res[lim] ;

int main() {
	int i, j ;
	int tmp ;
	int ini, fin, piv ;
	
	scanf("%d", &N ) ;
	for( i=0; i<N; i++ ) {
		scanf("%d", &tmp ) ;
		org[tmp-1] = i ;
	}
	for( i=0; i<N; i++ ) {
		scanf("%d", &tmp ) ;
		ref[i] = org[tmp-1] ;
	}
	
	res[0] = ref[0] ;
	R = 1 ;
	for( i=1; i<N; i++ ) {
		if( res[R-1] > ref[i] ) {
			res[R++] = ref[i] ;
			continue ;
		}
		
		ini = 0, fin=R-1 ;
		while( ini<fin ) {
			piv = (ini+fin)/2 ;
			if( res[piv] > ref[i] ) 
				ini = piv+1 ;
			else
				fin = piv ;
		}
		
		if( res[ini] < ref[i] ) 
			res[ini] = ref[i] ;
	}
	
	printf("%d\n", R ) ;
	
	return 0 ;
}
