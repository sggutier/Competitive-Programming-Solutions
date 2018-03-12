#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std ;
const int lim = 1<<15 ;

int P = 0 ;
int comp[lim], prim[lim] ;

void criba() {
    for( int i=2; i*i<lim; i++ )
	if( !comp[i] )
	    for( int j=i*i; j<lim; j+=i )
		comp[j] = 1 ;
    for( int i=2; i<lim; i++ )
	if( !comp[i] )
	    prim[P++] = i ;
}

void caso( int N ) {
    int res = 0 ;
    for( int i=0; i<P && prim[i]*2<=N; i++ )
	if( !comp[N-prim[i]] )
	    res ++ ;
    printf("%d\n", res ) ;
}

int main() {
    int N ;

    criba() ;

    while( scanf("%d", &N) != EOF && N )
	caso(N) ;
    
    return 0 ;
}
