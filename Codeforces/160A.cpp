#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std ;

int main() {
    int N ;
    int arr[100000] ;
    int sum = 0, sum2 = 0 ;

    scanf("%d", &N ) ;
    for( int i=0; i<N; i++ ) {
        scanf("%d", &arr[i] ) ;
        sum += arr[i] ;
    }

    sort( arr, arr+N ) ;
    for( int i=N-1; i>=0; i--  ) {
        sum2 += arr[i] ;
        sum -= arr[i] ;
        if( sum2>sum ) {
            printf("%d\n", N-i ) ;
            break ;
        }
    }

    return 0 ;
}
