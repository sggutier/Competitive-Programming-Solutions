#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std ;
const int lim = 32000 ;

bool comp[lim] ;
int P = 0 ;
int primo[lim] ;

void criba() {
    for( int i=2; i*i<lim; i++ )
	if( !comp[i] ) 
	    for( int j=i*i; j<lim; j+=i )
		comp[j] = 1 ;
    for( int i=2; i<lim; i++ ) 
	if( !comp[i] )
	    primo[P++] = i ;
}

int div( int K ) {
    int res = 1, i=0 ;
    while( K && i<P ) {
	int tmp = 1 ;
	while( K%primo[i]==0 ) {
	    K /= primo[i] ;
	    tmp ++ ;
	}
	res *= tmp ;
	i ++ ;
    }
    if( K!=1 )
	res *= 2 ;
    return res ;
}

void caso() {
    int L, R ;
    int res, mRes=-(1<<30)  ;

    scanf("%d%d", &L, &R ) ;
    for( int i=L; i<=R; i++ ) {
	int tmp = div(i) ;
	if( tmp>mRes ) {
	    mRes = tmp ;
	    res = i ;
	}
    }

    printf("Between %d and %d, %d has a maximum of %d divisors.\n", L, R, res, mRes ) ;
}

int main() {
    int T ;

    criba() ;

    scanf("%d", &T ) ;
    for( int i=0; i<T; i++ )
	caso() ;
    
    return 0 ;
}
