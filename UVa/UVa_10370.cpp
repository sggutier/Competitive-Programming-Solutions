#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std ;

void caso() {
    int N ;
    int arr[1005], sum=0, cnt=0 ;

    scanf("%d", &N) ;
    for( int i=0; i<N; i++ ) {
	scanf("%d", &arr[i] ) ;
	sum += arr[i] ;
    }

    for( int i=0; i<N; i++ ) {
	if( arr[i]*N > sum )
	    cnt ++ ;
    }

    printf("%.3lf%%\n", (cnt*100.0)/N ) ;
}
    

int main() {
    int T ;

    scanf("%d", &T ) ;
    for( int i=0; i<T; i++ )
	caso() ;
    
    return 0 ;
}
