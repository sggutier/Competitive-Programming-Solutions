#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std ;

void caso() {
    int N, res=0 ;
    int arr[55];

    scanf("%d", &N );
    for( int i=0; i<N; i++ ) {
	scanf("%d", &arr[i] ) ;
	for( int j=i; j; j-- ) {
	    if( arr[j]>=arr[j-1] )
		continue ;
	    swap( arr[j], arr[j-1] ) ;
	    res ++ ;
	}
    }
    printf("Optimal train swapping takes %d swaps.\n", res ) ;
}

int main() {
    int T ;

    scanf("%d", &T ) ;
    for( int i=0; i<T; i++ )
	caso() ;
    
    return 0 ;
}
