#include <algorithm>
#include <cstdio>
#include <iostream>
#include <string>
using namespace std ;

bool subSeq( string A, string B ) {
    int N = A.size(), M=B.size() ;
    int i=0, j=0 ;

    for( ; i<N; i++ ) {
        for( ; j<M && B[j]!=A[i]; j++ ) ;
        if( j==M )
            return 0 ;
        j ++ ;
    }

    return 1 ;
}

int main() {
    //freopen( "1028.in", "r", stdin ) ;

    char S[10000] ;
    string A, B ;

    while( scanf("%s", S ) != EOF ) {
        A = S ;
        cin >> B ;
        if( subSeq( A, B )  )
            printf("Yes\n" ) ;
        else
            printf("No\n" ) ;
    }

    return 0 ;
}
