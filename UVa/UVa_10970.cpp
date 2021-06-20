#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std ;
const int lim = 305 ;

int DP[305][305] ;

int main() {
    for( int i=1; i<lim; i++ )
	DP[i][1] = DP[1][i] = i-1 ;

    for( int i=2; i<lim; i++ ) {
	for( int j=2; j<lim; j++ ) {
	    DP[i][j] = (1<<30) ;
	    for( int a=1; a<i; a++ ) {
		DP[i][j] = min( DP[i][j],
				DP[a][j] + DP[i-a][j] +1 ) ;
	    }
	    for( int a=1; a<j; a++ ) {
		DP[i][j] = min( DP[i][j],
				DP[i][a] + DP[i][j-a] +1 ) ;
	    }
	}
    }

    int a, b ;

    while( scanf("%d%d",&a,&b)!=EOF ) {
	printf("%d\n", DP[a][b] ) ;
    }
    
    return 0 ;
}
