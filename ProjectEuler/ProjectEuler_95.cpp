#include <algorithm>
#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std ;
#define lim 1000006

int usd[lim] ;

int main() {
    int pRes, tamRes = 0 ;
    int N ;
    int pos, carg, tam, r ;

    scanf("%d", &N ) ;
    for( int i=i; i<=N; i++ ) {
        pos = i ;
        tam = 0 ;

        while( pos<lim && usd[pos]!=i ) {
            //cout << pos << " " ;
            usd[pos] = i ;
            tam ++ ;
            carg = 1 ;
            for( int j=2; j*j<pos; j++ )
                if( pos%j==0 )
                    carg += j + pos/j ;
            r = int(sqrt(pos) ) ;
            if( r*r == pos )
                carg += r ;

            pos = carg ;
        }
        //cout << endl ;
        cout << i << endl ;

        if( pos==i && tam>tamRes ) {
            pRes = i ;
            tamRes = tam ;
        }
    }


    printf("%d %d\n", tamRes, pRes ) ;


    return 0 ;
}
