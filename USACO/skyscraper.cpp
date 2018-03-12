#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std ;

int N, P ;
int arr[20] ;
int R=(1<<30), T=0, F=1 ;
int res[20] ;
int quak[20], carg[20] ;

void prueba( int pos ) {
	if( pos==N ) {
		if( T<R ) 
			R = T ;
		return ;
	}
	for( int i=0; i<=T; i++ ) {
		if( carg[i]+arr[pos]<=P ) {
			carg[i] += arr[pos] ;
			prueba( pos+1 ) ;
			carg[i] -= arr[pos] ;
		}
	}
	
	T ++ ;
	carg[T] = arr[pos] ;
	prueba( pos+1 ) ;
	T -- ;
}

void fin( int pos ) {
	if( pos==N ) {
		if( T==R ) {
			F = 0 ;
			int tip[20][20], acum[20] ;
			for( int i=0; i<=T; i++ ) {
				acum[i] = 0 ;
			}
			for( int i=0; i<N; i++ ) {
				tip[ quak[i] ][acum[quak[i]]++ ] = i ;
			}
			
			printf("%d\n", T+1 ) ;
			for( int i=0; i<=T; i++ ) {
				printf("%d", acum[i] ) ;
				for( int j=0; j<acum[i]; j++ )
					printf(" %d", tip[i][j]+1 ) ;
				printf("\n" ) ;
			}
		}
		return ;
	}
	for( int i=0; F && i<=T; i++ ) {
		if( carg[i]+arr[pos]<=P ) {
			quak[pos] = i ;
			carg[i] += arr[pos] ;
			fin( pos+1 ) ;
			carg[i] -= arr[pos] ;
		}
	}
	
	if( F ) {
		T ++ ;
		quak[pos] = T ;
		carg[T] = arr[pos] ;
		fin( pos+1 ) ;
		T -- ;
	}
}

int main() {
	freopen( "skyscraper.in", "r", stdin ) ;
	freopen( "skyscraper.out", "w", stdout ) ;
	
	scanf("%d%d", &N, &P ) ;
	for( int i=0; i<N; i++ ) 
		scanf("%d", &arr[i] ) ;
		
	prueba( 0 ) ;
	fin(0) ;
	
	return 0 ;
}
