#include <algorithm>
#include <iostream>
#include <cstdio>
using namespace std ;

int n, m ;
bool ap[102] ;

int main() {
	int i, a ;
	
	scanf("%d%d", &n, &m ) ;
	for( i=0; i<m; i++ ) {
		scanf("%d", &a ) ;
		ap[a] = 1 ;
		scanf("%d", &a ) ;
		ap[a] = 1 ;
	}
	
	a = 0 ;
	for( i=1; i<=n; i++ ) {
		if( ap[i] ) 
			a ++ ;
	}
	if( a == n && n==m ) 
		printf("FHTAGN!\n" ) ;
	else
		printf("NO\n" ) ;
	
	return 0 ;
}
