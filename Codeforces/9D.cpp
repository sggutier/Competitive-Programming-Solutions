#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std ;
typedef long long ll ;
#define lim 40

ll numT[50][50] ;

ll memo( int n, int h ) {
	if( numT[n][h] != -1LL )
		return numT[n][h] ;
	if( h==0 )
		return numT[n][h] = 0LL  ;
	numT[n][h] = 0LL ;
	for( int i=0; i<n; i++  ) 
		numT[n][h] += memo( i, h-1 )*memo( n-i-1, h-1 ) ;
	return numT[n][h] ;
}


int main() {
	int n, h ;
	
	scanf("%d%d", &n, &h ) ;
	
	for( int i=0; i<lim; i++ )  {
		for( int j=0; j<lim; j++ )
			numT[i][j] = -1LL ;
		numT[0][i] = 1LL ;
	}
		
	cout << memo( n, n ) - memo( n, h-1 ) << endl; 
	
	return 0 ;
}

