#include <cstdio>
#include <algorithm>
#include <iostream>
#include <utility>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <cmath>
#include <string>
#include <cstring>
#include <vector>
#include <list>
#include <cstdlib>
using namespace std ;
const int lim = 100005 ;

int P=0 ;
int comp[lim] ;
int primos[lim] ;

void criba() ;
void caso( int N ) ;

int main() {
    criba() ;
    int N ;

    while( scanf("%d",&N)!=EOF  and  N ) {
	caso(N ) ;
    }
    
    return 0 ;
}

void criba() {
    for( int i=2; i*i<lim; i++ )
	if( !comp[i] ) 
	    for( int j=i*i; j<lim; j+=i )
		comp[j] = 1 ;
    for( int i=2; i<lim; i++ )
	if( !comp[i] )
	    primos[P++] = i ;
}

void caso(int N ) {
    int cnt = 0 ;
    printf("%d =", N ) ;
    if( N<0 ) {
	printf(" -1" ) ;
	cnt ++ ;
	N *= -1 ;
    }

    for( int i=0; i<P and N>1; i++ ) {
	while( N%primos[i]==0 ) {
	    if( cnt )
		printf(" x" ) ;
	    printf(" %d", primos[i] ) ;
	    N /= primos[i]  ;
	    cnt ++ ;
	}
    }
    if( N>1 ) {
	if( cnt )
	    printf(" x" ) ;
	printf(" %d", N ) ;
    }
    printf("\n" ) ;
}
	
