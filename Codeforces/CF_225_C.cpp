#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std ;
const int lim = 1005 ; 

int res[lim][2], carg[lim][2] ;

int main() {
    int N, M, A, B ;
    char arr[lim] ;
    int foo = 1 ;

    scanf("%d%d%d%d", &N,&M,&A,&B) ;
    for( int i=0; i<N; i++ ) {
        scanf("%s", arr ) ;
        for( int j=0; j<M; j++ ) 
            carg[j][0] += (arr[j]=='.') ;
    }

    for( int j=M-1; j>=0; j-- ) {
        carg[j][1] = N-carg[j][0] ;
        for( int d=0, d2=1; d<2; d++, d2=(d+1)%2 ) {
        res[j][d] = (1<<30) ;
        for( int k=0, tmp=0; k+j<M && k<B; k++ ) {
            tmp += carg[k+j][d] ;
            if( k+1>=A ) 
                res[j][d] = min( res[j][d], tmp + res[j+k+1][d2] ) ;
        }
        }
    }

    printf("%d\n", min( res[0][0], res[0][1] ) ) ;

    return 0 ;
}
