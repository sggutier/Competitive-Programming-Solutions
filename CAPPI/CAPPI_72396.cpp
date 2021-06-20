#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std ;
#define lim 100005
#define inf (1<<30)

int N, A ;
int arr[lim] ;

bool sePuede( int W ) {
	int Q = A ;
	int i, ini, fin, piv ;
	for( i=0; i<N && Q; Q-- ) {
		ini = i+1 ;
		fin = N ;
		while( ini<fin ) {
			piv = (ini+fin)/2 ;
			if( arr[piv]-arr[i] <= W  )
				ini = piv+1 ;
			else
				fin = piv ;
		}
		i = ini ;
	}
	return i==N ;
}

int main() {
	int ini, fin, piv ;
	
	scanf("%d%d", &N, &A ) ;
	for( int i=0; i<N; i++ ) 
		scanf("%d", &arr[i] ) ;
		
	arr[N] = inf ;
	sort( arr, arr+N ) ;
	ini = 0 ;
	fin = 1000000 ;
	while( ini<fin ) {
		piv = (ini+fin)/2  ;
		if( sePuede( piv )   )
			fin = piv ;
		else
			ini = piv+1 ;
	}
	
	printf("%d\n", ini/2 ) ;
	
	return 0 ;
}
