#include <algorithm>
#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int N ;
    int arr[100000] ;
    int res[2] = {0,0} ;

    scanf("%d", &N ) ;
    for( int i=0; i<N; i++ )
        scanf("%d", &arr[i] ) ;

    sort( arr, arr+N ) ;
    for( int i=0; i<N; i++ ) {
        res[i%2] += arr[i]*arr[i] ;
        if( i )
            res[i%2] -= arr[i-1]*arr[i-1] ;
    }

    printf("%0.9lf\n", M_PI*res[(N+1)%2] ) ;

    return 0 ;
}
