#include <iostream>
#include <cstdio>
#include <algorithm>
#include <utility>
using namespace std ;
const int lim = 105 ;
#define r first
#define c second
#define par pair<int,int>

int mcd( int a, int b ) {
    int c ;
    while( b ) {
        c = a%b ;
        a = b ;
        b = c ;
    }
    return a ;
}

int main() {
    int N, W=0 ;
    char S[lim][lim] ;
    par cord[lim] ;
    int res = 0 ;

    scanf("%d", &N ) ;
    for( int i=0; i<N; i++ )
        scanf("%s", S[i] ) ;

    for( int i=0; i<N; i++ ) {
        for( int j=0; j<N; j++ ) {
            if( S[i][j]=='.' )
                continue ;
            cord[W++] = par( i, j ) ;
        }
    }

    sort( cord, cord+W ) ;
    for( int i=0; i<W; i++ ) {
        for( int j=i+1; j<W; j++ ) {
            for( int k=j+1; k<W; k++ ) {
                int x=cord[j].r-cord[i].r, y=cord[j].c-cord[i].c, z=mcd(abs(x),abs(y)) ;
                int a=cord[k].r-cord[j].r, b=cord[k].c-cord[j].c, c=mcd(abs(a),abs(b)) ;
                x /= z ;
                y /= z ;
                a /= c ;
                b /= c ;
                if( a==x && y==b )
                    res ++ ;
            }
        }
    }

    printf("%d\n", res ) ;

    return 0 ;
}
