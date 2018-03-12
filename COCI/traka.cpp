#include <algorithm>
#include <cstdio>
#include <iostream>
#include <utility>
using namespace std ;
#define lim 100005
#define par pair< long long , long long >
#define A first
#define B second

int N, M ;
int W=0 ;
par lin[lim], cnvx[lim] ;
long long F[lim], T[lim] ;

bool intersec( par Z, par Y, par X ) {
    return 0 > (Z.B-X.B)*(X.A-Y.A) - (Y.B-X.B)*(X.A-Z.A) ;
}

long long valY( long long F2, long long F, par T ) {
    return F2*T.B + F*T.A ;
}

int main() {
    long long res = 0LL ;
    int K ;

    cin >> N >> M ;
    for( int i=0; i<N; i++ ) {
        cin >> T[i] ;
        if( i ) {
            T[i] += T[i-1] ;
            lin[i] = par( T[i], -T[i-1] ) ;
        }
    }
    for( int i=0; i<M; i++ )
        cin >> F[i] ;

    if( N==1 ) {
        for( int i=1; i<M; i++ ) {
            long long tmp = max(0LL,F[i-1]*T[0]) ;
            for( int j=0; j+1<N; j++ ) {
                //tmp = max( tmp, F[i-1]*T[j+1] - F[i]*T[j] ) ;
                tmp = max( tmp, valY( F[i-1], F[i], lin[j+1] ) );
            }
            res += tmp ;
        }
        cout << res + T[N-1]*F[M-1] << endl ;
        return 0 ;
    }

    sort( lin+1, lin+N ) ;
    cnvx[W++] = lin[1] ;
    for( K=2; K<N && lin[K]==lin[K-1]; K++ ) ;
    if( K<N )
        cnvx[W++] = lin[K] ;
    for( int i=K+1; i<N; i++ ) {
        if( lin[i]==lin[i-1] )
            continue ;
        cnvx[W++] = lin[i] ;
        while(  W>2 && intersec( cnvx[W-1], cnvx[W-2], cnvx[W-3] )  ) {
            W -- ;
            cnvx[W-1] = cnvx[W] ;
        }
    }

    for( int i=1; i<M; i++ ) {
        int ini, fin, piv ;
        long long tmp = max( 0LL, F[i-1]*T[0] ) ;
        ini = 0 ;
        fin = W-1 ;
        while( ini<fin ) {
            piv = (ini+fin)/2 ;
            if(   valY(F[i], F[i-1], cnvx[piv]) < valY(F[i], F[i-1], cnvx[piv+1])     )
                ini = piv+1 ;
            else
                fin = piv ;
        }
        tmp = max( tmp, valY(F[i], F[i-1], cnvx[ini]) ) ;
        res += tmp ;
    }

    cout << res + T[N-1]*F[M-1] << endl ;

    return 0 ;
}
