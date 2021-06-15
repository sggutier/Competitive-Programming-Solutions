#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std ;

int main() {
	int n, m ;
	
	scanf("%d%d",&n,&m ) ;
	
	if( n%2 == 0 && (m!=1 || n==2) ) {
		printf("0\n" ) ;
		printf("1 1\n" ) ;
		for( int i=1; i<=n; i++ ) {
			if( i%2==0 )
				for( int j=m; j>1; j-- )
					printf("%d %d\n", i, j ) ;
			else
				for( int j=2; j<=m; j++ )
					printf("%d %d\n", i, j ) ;
		}
		for( int i=n, j=1; i>=1; i-- )
			printf("%d %d\n", i, j ) ;
	}
	else  if( m%2 == 0  &&  (n!=1 || m==2)   ) {
		printf("0\n" ) ;
		printf("1 1\n" ) ;
		for( int j=1; j<=m; j++ ) {
			if( j%2==0 )
				for( int i=n; i>1; i-- )
					printf("%d %d\n", i, j ) ;
			else
				for( int i=2; i<=n; i++ )
					printf("%d %d\n", i, j ) ;
		}
		for( int j=m, i=1; j>=1; j-- )
			printf("%d %d\n", i, j ) ;
	}
	else {
		printf("1\n" ) ;
		printf("%d %d 1 1\n", n, m ) ;
		for( int i=1; i<=n; i++ ) {
			if( i%2==0 )
				for( int j=m; j>=1; j-- )
					printf("%d %d\n", i, j ) ;
			else
				for( int j=1; j<=m; j++ )
					printf("%d %d\n", i, j ) ;
		}
		printf("%d %d\n", 1, 1 ) ;
	}
	
	return 0 ;
}

