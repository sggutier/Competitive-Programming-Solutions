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
#include <cctype>
using namespace std ;
#define par pair< int, int >
#define p1 first
#define p2 second
const int lim = 1000005 ;

int P ;
int primos[lim] ;
bool comp[lim] ;

int cFactores( int N ) ;
void criba() ;


int main() {
    int N ;

    criba() ;

    while( scanf("%d",&N)!=EOF  and  N!=0  ) 
	printf("%d : %d\n", N, cFactores(N) ) ;
    
    return 0 ;
}

int cFactores( int N ) {
    int res = 0 ;

    if( !comp[N] )
	return 1 ;

    for( int i=0; i<P; i++ ) {
	if( N%primos[i]==0 ) {
	    res ++ ;
	}
    }

    return res ;
}

void criba() {
    P = 0 ;
    for( int i=2; i*i<lim; i++ ) {
	if( !comp[i] ) {
	    for( int j=i*i; j<lim; j+=i )
		comp[j] = 1 ;
	}
    }
    for( int i=2; i<lim; i++ )
	if( !comp[i] ) 
	    primos[P++] = i ;
}

	
