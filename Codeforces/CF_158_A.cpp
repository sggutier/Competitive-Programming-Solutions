#include <algorithm>
#include <cstdio>
using namespace std ;

int main() {
    int N, K ;
    int arr[1000] ;

    scanf("%d%d", &N, &K  ) ;
    for( int i=0; i<N; i++ )
        scanf("%d", &arr[i] ) ;

    sort( arr, arr+N  ) ;
    K = arr[N-K] ;
    K = max( K, 1 ) ;
    for( int i=0; i<N; i++ ) {
        if( arr[i]>=K )  {
            printf("%d\n", N-i ) ;
            return 0 ;
        }
    }

    printf("0\n"  ) ;

    return 0 ;
}
