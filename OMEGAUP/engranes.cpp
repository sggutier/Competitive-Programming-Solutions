#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std ;
const int lim = 1000006 ;

int N ;
int arr[lim] ;
bool ig[lim], usd[lim] ;

int main() {
    int N, K ;
    long long W ;
    int mod ;

    scanf("%d", &N ) ;
    scanf("%lld", &W ) ;
    scanf("%d", &K ) ;
    for( int i=0; i<N; i++ )
        scanf("%d", &arr[i] ) ;

    mod = W%N ;
    for( int i=0; i<mod; i++ ) {
        if( usd[i] )
            continue ;
        bool tmp = 1 ;
        for( int j=(i+mod)%N; j!=i; j=(j+mod)%N  ) {
            if( arr[j]!=arr[i] )
                tmp = 0 ;
        }
        for( int j=(i+mod)%N; j!=i; j=(j+mod)%N  ) {
            usd[j] = 1 ;
            ig[j] = tmp ;
        }
        usd[i] = 1 ;
        ig[i] = tmp ;
    }

    scanf("%d", &K ) ;
    for( int i=0; i<K; i++ ) {
        long long tmp ;
        scanf("%lld", &tmp ) ;
        printf("%d", ig[tmp%N] ) ;
    }
    printf("\n" ) ;

    return 0 ;
}
