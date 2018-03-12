#include <iostream>
#include <algorithm>
#include <string>
#include <cstdio>
#include <map>
using namespace std ;
const int lim = 1003 ;

int N ;
bool mapa[lim][lim] ;
map <string,int> num ;

int main() {
    int P ;

    scanf("%d", &N ) ;
    for( int i=0; i<N; i++ ) {
        char tmp[20] ;
        scanf("%s", tmp ) ;
        num[tmp] = i ;
    }
    for( int i=0; i<N; i++ )
        for( int j=0; j<N; j++ )
            scanf("%d", &mapa[i][j] ) ;

    scanf("%d", &P ) ;
    for( int i=0; i<P; i++ ) {
        int a, b ;
        char tmp[20] ;
        scanf("%s", tmp ) ;
        a = num[tmp] ;
        scanf("%s", tmp ) ;
        b = num[tmp] ;
        printf("%d\n", mapa[a][b] ) ;
    }

    return 0 ;
}
