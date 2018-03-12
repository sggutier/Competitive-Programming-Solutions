#include <algorithm>
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
using namespace std ;

int N, K, Q ;
vector<int> pRep[26] ;
bool usd[300000] ;
string S ;

int main() {
    cin >> K ;
    cin >> S ;
    N = S.size() ;
    for( int i=0; i<K; i++ ) {
        for( int j=0; j<N; j++ ) {
            pRep[S[j]-'a'].push_back( i*N + j );
        }
    }

    cin >> Q ;
    for( int i=0; i<Q; i++ ) {
        int a ;
        char b[3] ;
        scanf("%d%s", &a, b ) ;

        usd[ pRep[ b[0]-'a' ][a-1] ] = 1 ;
        pRep[ b[0]-'a' ].erase( pRep[ b[0]-'a' ].begin() + a-1 );
    }

    for( int i=0; i<K; i++ )
        for( int j=0; j<N; j++ )
            if( !usd[ i*N+j  ] )
                printf("%c", S[j] ) ;
    printf("\n" ) ;

    return 0 ;
}
