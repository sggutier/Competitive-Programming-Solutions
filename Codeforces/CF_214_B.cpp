#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std ;

int main() {
    int N ;
    int arr[100000] ;
    int sum = 0, a=-1 ;

    scanf("%d", &N ) ;
    for( int i=0; i<N; i++ ) {
        scanf("%d", &arr[i] ) ;
        sum += arr[i] ;
    }
    sort( arr, arr+N ) ;

    if( arr[0]!=0 ) {
        printf("-1\n" ) ;
        return 0 ;
    }

    for( int i=0; i<N && sum%3; i++ ) {
        if( arr[i]%3==sum%3 ) {
            sum = 0 ;
            arr[i] = -1 ;
        }
    }
    for( int i=0; i<N && sum%3; i++ ) {
        if( arr[i]<0 || arr[i]%3==0 )
            continue ;
        sum -= arr[i] ;
        arr[i] = -1 ;
    }

    if( sum%3 ) {
        printf("-1\n" ) ;
        return 0 ;
    }

    for( int i=N-1; i>=0; i-- ) {
        if( arr[i]==-1 )
            continue ;
        if( arr[i]==0 ) {
            printf("0\n" ) ;
            return 0 ;
        }
        break ;
    }
    for( int i=N-1; i>=0; i-- ) {
        if( arr[i]>=0 )
            printf("%d", arr[i] ) ;
    }
    printf("\n" ) ;

    return 0 ;
}
