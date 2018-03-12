#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
    int N ;
    int mapa[100][100] ;
    bool usd[100] ;
    int q[101] ;
    int I, J ;
    int pos ;

    for( I=0; I<100; I++ ) {
        for( J=0; J<100; J++ ) {
            mapa[I][J] = -1 ;
        }
        usd[I] = 0 ;
    }

    cin >> N ;
    for( I=0; I<N; I++ ) {
        int a, b, c ;
        cin >> a >> b >> c ;
        a--, b-- ;
        mapa[a][b] = 0 ;
        mapa[b][a] = c ;
    }

    pos = 0 ;
    for( I=0; I<N ;I++ ) {
        q[I] = pos ;
        usd[pos] = 1 ;
        for( J=0; J<N; J++ ) {
            if( !usd[J] && mapa[pos][J] != -1 ) {
                pos = J ;
                break ;
            }
        }
    }
    q[I] = 0 ;

    int tmp, tmp2 ;
    tmp = 0 ;
    tmp2 = 0 ;
    for( I=0; I<N; I++ ) {
        tmp += mapa[ q[I] ][ q[I+1] ] ;
    }
    for( I=N; I>0; I-- ) {
        tmp2 += mapa[ q[I] ][ q[I-1] ] ;
    }

    cout <<  min( tmp, tmp2 ) << endl ;
    
    //aoensuhuhtsa

    return 0 ;
}
