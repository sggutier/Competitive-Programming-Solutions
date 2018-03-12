#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std ;
#define lim 10000

int main() {
	int N, Q ;
	int sig[lim] ;
	int pos, res=0  ;
	
	scanf("%d%d", &N, &Q ) ;
	
	for( int i=1; i<N; i++ )
		sig[i] = i+1 ;
	sig[N] = 1 ;
	pos = N ;
	
	for( int w=0; w<Q; w++  )  {
		int a, r=0 ;
		scanf("%d", &a ) ;
		
		while( sig[pos]!=a ) {
			pos = sig[pos] ;
			r ++ ;
		} 
		
		sig[pos] = sig[ sig[pos] ] ;
		pos = a ;
		for( int i=N-w-1; i>0; i-- )
			pos = sig[pos] ;
		
		res += min( r, N-w-r ) ;
	}
	
	printf("%d\n", res ) ;
	
	return 0 ;
}
