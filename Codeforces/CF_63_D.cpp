#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std ;
#define limN 30
#define limT 100

int main() {
	int N ;
	int renA, renB, colA, colB ;
	int arr[limN] ;
	char mapa[limT][limT] ;
	int p, pos ;
	
	
	scanf("%d%d%d%d", &colA, &renA, &colB, &renB ) ;
	scanf("%d", &N ) ;
	for( int i=0; i<N; i++ ) {
		scanf("%d", &arr[i] ) ;
	}
	
	p = min(renA,renB) ;
	p += (renA<renB) ;
	p %= 2 ;
	pos = 0 ;
	for( int i=0; i<min(renA,renB); i++ ) {
		if( i%2==p ) {
			for( int j=0; j<colA+colB; j++ ) {
				if( arr[pos] == 0 )
					pos ++ ;
				mapa[i][j] = pos + 'a' ;
				arr[pos] -- ;
			}
		}
		else {
			for( int j=colA+colB-1; j>=0; j-- ) {
				if( arr[pos] == 0 )
					pos ++ ;
				mapa[i][j] = pos + 'a' ;
				arr[pos] -- ;
			}
		}
	}
	for( int i=min(renA,renB); i<max(renA,renB); i++ ) {
		int ini, fin ;
		if( renA<renB ) {
			for( int j=0; j<colA; j++ ) 
				mapa[i][j] = '.' ;
			ini = colA ;
			fin = colA+colB-1 ;
		}
		else {
			for( int j=colA; j<colA+colB; j++ ) 
				mapa[i][j] = '.' ;
			ini = 0 ;
			fin = colA-1 ;
		}
		if( i%2==p ) {
			for( int j=ini; j<=fin; j++ ) {
				if( arr[pos] == 0 )
					pos ++ ;
				mapa[i][j] = pos + 'a' ;
				arr[pos] -- ;
			}
		}
		else {
			for( int j=fin; j>=ini; j-- ) {
				if( arr[pos] == 0 )
					pos ++ ;
				mapa[i][j] = pos + 'a' ;
				arr[pos] -- ;
			}
		}
	}
	
	printf("YES\n" ) ;
	for( int i=0; i<max(renA,renB); i++ ) {
		for( int j=0; j<colA+colB; j++ )
			printf("%c", mapa[i][j] ) ;
		printf("\n" ) ;
	}
	
	
	return 0 ;
}

