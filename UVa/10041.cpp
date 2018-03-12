#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;

int N ;
int arr[50000] ;

void caso() {
    int res=(1<<30) ;

    scanf("%d", &N ) ;
    for( int i=0; i<N; i++ ){
	scanf("%d", &arr[i] );
    }
    sort( arr, arr+N) ;

    for( int i=0; i<N; i++ ) {
	int tot = 0 ;
	for( int j=0; j<N; j++ )
	    tot += abs( arr[i]-arr[j] ) ;
	res = min( res, tot ) ;
    }
    printf("%d\n", res ) ;
}
	

int main() {
    int T ;

    scanf("%d", &T ) ;
    for( int i=0; i<T; i++ )
	caso() ;
    
    return 0 ;
}
