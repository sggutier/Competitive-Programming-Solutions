#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std ;

int main() {
    int N=9 ;
    int arr[10] ;

    for( int i=0; i<N; i++ )
        scanf("%d", &arr[i] ) ;

    sort( arr, arr+N ) ;
    for( int b=0; b<(1<<N); b++ ) {
        int sum = 0, k=0 ;
        for( int i=0; i<N; i++ ) {
            if( (1<<i) & b ) {
                sum += arr[i] ;
                k ++ ;
            }
        }
        if( sum==100 && k==7 ) {
            for( int i=0; i<N; i++ )
                if( (1<<i) & b )
                    cout << arr[i] << endl ;
            break ;
        }
    }

    return 0 ;
}
