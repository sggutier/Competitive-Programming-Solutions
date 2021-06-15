#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std ;
const int limN = 1005 ;
const int limM = 105 ;

int N, M, D ;
int arr[limN][limM] ;


int main() {
    int sRes = 0 ;
    int res[limM*limM][2] ;
    
    scanf("%d%d%d", &N, &M, &D ) ;
    for( int i=0; i<N; i++ )
	for( int j=0; j<M; j++ )
	    scanf("%d", &arr[i][j] ) ;

    if( D==1 )
	D *=-1 ;
    else
	D = 1 ;
    
    for( int i=0; i<M; i++ ) {
	for( int j=0; j<N; j++ ) {
	    int pMin = i ;
	    for( int k=i+1; k<M; k++ )
		if( D*( arr[j][k] - arr[j][pMin] )  <  0 )
		    pMin = k ;
	    if( pMin != i )  {
		res[sRes][0] = i ;
		res[sRes][1] = pMin ;
		sRes ++ ;
		for( int k=0; k<N; k++ )
		    if( D*( arr[k][pMin] - arr[k][i] )  <  0 )
			swap( arr[k][i], arr[k][pMin] ) ;

	    }

	}
    }

    printf("%d\n", sRes ) ;
    for( int i=0; i<sRes; i++ ) {
	if( D==1 )
	    printf("%d %d\n", res[i][0]+1, res[i][1]+1  )  ;
	else
	    printf("%d %d\n", res[i][1]+1, res[i][0]+1  )  ;
    }
    
    return 0 ;
}
