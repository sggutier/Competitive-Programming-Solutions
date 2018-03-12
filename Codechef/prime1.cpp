#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std ;
#define limC 40000
#define limW 3500

bool c[limC] ;
int P[limW] ;
int W = 0 ;

void criba( int N ) {
	int Q = limC ;
	int i, j ;
	
	for( i=2; i*i<=N; i++ ) {
		if( c[i] )
			continue ; 
		P[W++] = i ;
		for( j=i*i; j<Q; j+=i ) 
			c[j] = 1 ;
	}
}

void caso() {
	int a, b ;
	int i, j ;
	
	scanf("%d%d", &a, &b ) ;
	
	a = max( a, 2 ) ;
	for( i=a; i<=b; i++ ) {
		for( j=0; j<W && P[j]<i && i%P[j]!=0; j++  )  ;
		if( j>=W || P[j]>=i  )
			printf("%d\n", i ) ;
	}
}

int main() {
	criba( 1000000000 ) ; 
	
	int N ;
	
	scanf("%d", &N ) ;
	
	for( int i=0; i<N; i++ ) {
		if( i ) 
			printf("\n" ) ;
		caso() ;
	}
	
	return 0 ;
}
