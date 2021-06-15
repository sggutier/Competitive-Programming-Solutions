#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std ;

int main() {
    int N, K ;
    int res=(1<<30), pRes, cRes ;

    scanf("%d", &N ) ;
    for( int i=0; i<N; i++ ) {
        scanf("%d", &K ) ;
        if( K<res ) {
            res = K ;
            pRes = i+1 ;
            cRes = 1 ;
        }
        else if( K==res )
            cRes ++ ;
    }

    if( cRes>1 )
        printf("Still Rozdil\n" ) ;
    else
        printf("%d\n",  pRes ) ;

    return 0 ;
}
