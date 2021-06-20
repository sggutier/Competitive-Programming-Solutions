#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std ;
#define lim 100005

struct li {
	int ro[lim], le[lim] ;
	li() {
	}
	li( int N ) {
		for( int i=0; i<=N; i++ ) {
			ro[i] = i+1 ;
			le[i] = i-1 ;
		}
		ro[N] = 0 ;
		le[0] = N ;
	}
	void borra( int ini, int fin ) {
		ini = le[ini] ;
		fin = ro[fin] ;
		ro[ini] = fin ;
		le[fin] = ini ;
	}
};

void caso( int N, int Q ) {
	li L(N) ;
	
	for( int i=0; i<Q; i++ ) {
		int a, b ;
		scanf("%d%d", &a, &b ) ;
		if( L.le[a]==0 )
			printf("* ") ;
		else
			printf("%d ", L.le[a] ) ;		
			
		if( L.ro[b]==0 )
			printf("*\n" ) ;
		else
			printf("%d\n", L.ro[b] ) ;
			
		L.borra( a, b ) ;
	}
	printf("-\n" ) ;
}

int main() {
	int N, S ;
	
	while( 1 ) {
		scanf("%d%d", &N, &S ) ;
		if( N && S )
			caso( N, S ) ;
		else 
			break ;
	}
}
