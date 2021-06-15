#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std ;
const int lim = 100005 ;

int N ;
int arr[lim], difE[lim] ;
bool usd[lim] ;

int main() {
    int Q ;
    
    scanf("%d%d", &N, &Q ) ;
    for( int i=0; i<N; i++ )
	scanf("%d", &arr[i] ) ;

    difE[N] = 0 ;
    for( int i=N-1; i>=0; i-- ) {
	difE[i] = difE[i+1] ;
	if( !usd[ arr[i] ] )
	    difE[i] ++ ;
	usd[ arr[i] ] = 1 ;
    }

    for( int i=0; i<Q; i++ ) {
	int tmp ;
	scanf("%d", &tmp ) ;
	printf("%d\n", difE[tmp-1] ) ;
    }

    return 0 ;
}
