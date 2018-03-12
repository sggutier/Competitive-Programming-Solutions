#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std ;

int main() {
    int N ;
    int arr[20000] ;
    int carg[20000], res=-(1<<30) ;

    scanf("%d", &N ) ;
    for( int i=0; i<N; i++ )
        scanf("%d", &arr[i] ) ;

    for( int i=1; i*3<=N; i++ ) {
        if( N%i )
            continue ;
        for( int j=0; j<i; j++ )
            carg[j] = 0 ;
        for( int j=0; j<N; j++ )
            carg[j%i] += arr[j] ;
        for( int j=0; j<i; j++ )
            res = max( res, carg[j] ) ;
    }

    printf("%d\n", res ) ;

    return 0 ;
}
