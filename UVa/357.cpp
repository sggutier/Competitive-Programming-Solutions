#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std ;
const int lim = 30005 ;

int M ;
int movs[] = { 1, 5, 10, 25, 50 } ;
long long cnt[lim][5] ;

int main() {
    M = sizeof(movs)/sizeof(int) ;
    for( int i=0; i<M; i++ )
	cnt[0][i] = 1LL ;
    for( int i=1; i<lim; i++ ) {
	for( int j=0; j<M; j++ ) {
	    if( i-movs[j]>=0 )
		cnt[i][j] += cnt[i-movs[j]][j] ;
	    if( j+1<M )
		cnt[i][j+1] += cnt[i][j] ;
	}
    }

    int X ;

    while( scanf("%d", &X)!=EOF ) {
	if( cnt[X][M-1]!=1LL )
	    printf("There are %lld ways to produce %d cents change.\n", cnt[X][M-1], X ) ;
	else
	    printf("There is only 1 way to produce %d cents change.\n", X ) ;
    }
    
    return 0 ;
}
