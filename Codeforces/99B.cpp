#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std ;

int main() {
	int N ;
	int cups[1003] ;
	int i, j ;
	int v =0;
	int cnt = 0 ;
	
	scanf("%d",&N) ;
	for( i=0; i<N; i++ ) {
		scanf("%d", &cups[i] ) ;
		v += cups[i] ;
	}
	if( v%N ) {
		printf("Unrecoverable configuration.\n" ) ;
		return 0 ;
	}
	
	v /= N ;
	for( i=0; cups[i]==v && i<N; i++ ) ;
	if( i==N ) {
		printf("Exemplary pages.\n" ) ;
		return 0 ;
	}
	
	cnt = 0 ;
	for( i=0; i<N; i++ ) {
		for( j=i+1; j<N; j++ ) {
			if( cups[i] != v && cups[i]+cups[j] == 2*v )
				cnt ++ ;
		}
	}
	
	if( cnt!=1 ) {
		printf("Unrecoverable configuration.\n" ) ;
		return 0 ;
	}
	for( i=0; i<N; i++ ) {
		for( j=i+1; j<N; j++ ) {
			if( cups[i] != v && cups[i]+cups[j] == 2*v ) {
				if( cups[i]>cups[j] )
					swap( i, j ) ;
				printf("%d ml. from cup #%d to cup #%d.\n", v-cups[i], i+1, j+1 ) ;
				return 0 ;
			}
		}
	}
	
	return 0 ;
}
