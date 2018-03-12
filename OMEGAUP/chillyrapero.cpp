#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std ;

int N, R ;
string S[300] ;
int minP[300][300] ;

int cmprt( string A, string B ) {
    if( A.size()>B.size() )
        swap( A, B ) ;
    if( A.size()==B.size() ) {
        int d= 0 ;
        for( int i=0; i<A.size(); i++ )
            if( A[i]!=B[i] )
                d++ ;
        return d==1? 1:(1<<29) ;
    }

    return (B.substr(0,A.size())==A || B.substr(B.size()-A.size(),A.size())==A)? 1:(1<<29) ;
}

int main() {
    char tmp[105] ;
    int res = 0 ;

    scanf("%d%d", &N, &R ) ;
    for( int i=0; i<N; i++ ) {
        scanf("%s", tmp ) ;
        S[i] = tmp ;
    }
    for( int i=0; i<N; i++ ) {
        for( int j=0; j<N; j++ ) {
            if( S[i]==S[j] ) {
                minP[i][j] = 0 ;
                continue ;
            }
            minP[i][j] = cmprt( S[i], S[j] ) ;
        }
    }

    for( int k=0; k<N; k++ ) {
        for( int i=0; i<N; i++ ) {
            for( int j=0; j<N; j++ ) {
                minP[i][j] = min( minP[i][j], minP[i][k] + minP[j][k] ) ;
            }
        }
    }

    for( int i=0, pos=-1; i<R; i++ ) {
        int tmp ;
        scanf("%d", &tmp ) ;
        tmp -- ;
        if( pos==-1 )
            pos = tmp ;
        res += minP[pos][tmp] ;
        pos = tmp ;
    }

    printf("%d.%d\n", (res*2)/10, (res*2)%10 ) ;

    return 0 ;
}
