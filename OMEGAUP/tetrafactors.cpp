#include <cstdio>
#include <algorithm>
#include <iostream>
#include <utility>
#include <queue>
#include <string>
#include <cstring>
#include <cmath>
using namespace std ;
const int lim = 6000006 ;
const long long moo = lim ;

int P ;
int primos[lim/10] ;
bool comp[lim] ;
int R = 0 ;
int res[lim/2] ;

void criba() {
	P = 0 ;
	int N = lim ;
	for( int i=2; i*i<N; i++ ) {
		if( comp[i] )
			continue ;
		for( int j=i*i; j<N; j+=i )
			comp[j] = 1 ;
	}
	for( int i=2; i<N; i++ )
		if( !comp[i] )
			primos[P++] = i ;
}

int main() {
	criba() ;
	int N ;
	long long W = pow( moo, 1.0/3.0 ) ;

	for( int i=P-1; i>=0; i-- ) {
		for( int j=0; j<i && primos[i]*primos[j]<moo; j++ ) {
			res[R++] = primos[i]*primos[j] ;
		}
		if( primos[i]<=W ) 
			res[R++] = primos[i]*primos[i]*primos[i] ;
	}

	sort( res, res+R ) ;

	scanf("%d", &N ) ;
	printf("%d\n", res[N-1] ) ;

	return 0 ;
}

