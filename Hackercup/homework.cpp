#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cctype>
#include <string>
#include <vector>
#include <utility>
#include <map>
#include <set>
#include <stack>
#include <queue>
using namespace std ;
#define parI pair <int,int>
#define p1 first
#define p2 second
#define mkp make_pair
const int inf = (1<<30) ;
const int lim = 1e7 + 5 ;
const double eps = 1e-9 ;
const int dr[] = { -1, 0, 1, 0 } ;
const int dc[] = { 0, 1, 0, -1 } ;

bool comp[lim] ;
int P = 0 ;
int primes[lim] ;
int primpty[lim][20] ;
int numP[lim] ;


void sieve() ;
void initialize() ;
int calc_primpty(int N) ;
int calc_rang( int a, int b, int c  ) ;


int main() {
    initialize() ;
    
    int T ;
    int a, b, c ;

    scanf("%d", &T ) ;
    for( int i=1; i<=T; i++ ) {
	scanf("%d%d%d", &a,&b,&c ) ;
	printf("Case #%d: %d\n", i, calc_rang(a,b,c) ) ;
    }
    
    return 0 ;
}

void sieve() {
    for( int i=2; i*i<lim; i++ ) {
	if( !comp[i] )  {
	    for( int j=i; j<lim; j+=i ) {
		comp[j] = 1 ;
		numP[j] ++ ;
	    }
	}
    }
    for( int i=2; i<lim; i++ ) 
	if( !comp[i] )
	    primes[P++] = i ;
}

int calc_primpty( int N ) {
    return numP[N] ;
    int res = 0 ;
    int k = 0 ;

    while( N>1 ) {
	if( N%primes[k] ) {
	    k ++ ;
	    continue ;
	}
	res ++ ;
	while( N%primes[k]==0 )
	    N /= primes[k] ;
    }

    return res ;
}

void initialize() {
    sieve() ;
    for( int i=2; i<lim; i++ ) {
	primpty[i][ calc_primpty(i) ] = 1 ;
	for( int j=0; j<20; j++ )
	    primpty[i][j] += primpty[i-1][j] ;
	//cout << i << endl ;
    }
}

int calc_rang( int A, int B, int K ) {
    A -- ;
    K = min( K, 19 ) ;
    return primpty[B][K] - primpty[A][K] ;
}
