#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std ;
#define lim 10005

int main() {
    int N ;
    int arr[lim] ;

    scanf("%d", &N ) ;
    for( int i=0; i<N; i++ )
        scanf("%d", &arr[i] ) ;
    arr[N] = 0 ;

    for( int i=N-2; i>=0; i-- )
        arr[i] = min( arr[i], max(arr[i+1], arr[i+2])  ) ;

    printf("%d\n", arr[0] ) ;

    return 0 ;
}
