#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std ;
#define lim 10000

int N ;
int grad[lim], hijo[lim], dia[lim] ;
int R=0 ;
int ini[lim], fin[lim], dens[lim] ;

int main() {
	int E ;
	
	scanf("%d%d", &N, &E ) ;
	for( int i=0; i<E; i++ ) {
		int a, b, c ;
		scanf("%d%d%d", &a, &b, &c ) ;
		a--, b-- ;
		
		grad[a]++ ;
		grad[b] ++ ;
		hijo[a] = b ;
		dia[a] = c ;
	}
	
	for( int i=0; i<N; i++ ) {
		if( dia[i] && grad[i]==1 ) {
			ini[R] = i ;
			dens[R] = (1<<30) ;
			for( fin[R] = i;  dia[fin[R]]; dens[R]=min(dens[R],dia[fin[R]]), fin[R]=hijo[fin[R]]   )  ;
			R ++ ;
		}
	}
	
	printf("%d\n", R ) ;
	for( int i=0; i<R; i++ ) {
		printf("%d %d %d\n", ini[i]+1, fin[i]+1, dens[i] ) ;
	}
	
	return 0 ;
}
