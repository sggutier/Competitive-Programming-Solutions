#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;
#define lim 100005

int P=0, Q=0, N=0 ;
long long pon[lim], quita[lim], neut[lim] ;

void insertionSort( int &W, long long arr[], long long nov ) {
    arr[W++] = nov ;
    for( int i=W-1; i>0 && arr[i]<arr[i-1]; i-- )
        swap( arr[i], arr[i-1] ) ;
}

long long costoAct() {
    long long res = 0LL ;

    for( int i=0; i<Q; i++ )
        res += quita[Q-i-1]*i ;
    for( int i=0; i<P; i++ )
        res += pon[P-i-1]*(i+1) ;
    for( int i=0; i<N; i++ )
        res += neut[i]*(Q+P) ;

    return res ;
}

int main() {
    int W ;
    char S[lim], S2[lim] ;
    long long res = (1LL<<60) ;

    scanf("%d", &W ) ;
    scanf("%s", S ) ;
    scanf("%s", S2 ) ;
    for( int i=0, tmp; i<W; i++ ) {
        scanf("%d", &tmp ) ;
        if( S[i]=='0' && S2[i]=='1' )
            pon[P++] = tmp ;
        else if( S[i]=='1' && S2[i]=='0' )
            quita[Q++] = tmp ;
        else if( S[i]=='1' && S2[i]=='1' )
            neut[N++] = tmp ;
    }

    sort( pon, pon+P ) ;
    sort( quita, quita+Q ) ;
    sort( neut, neut+N ) ;

    for( ; N>=0; N-- ) {
        //cout << costoAct() << endl ;
        res = min( res, costoAct() ) ;
        if( N ) {
            insertionSort(P,pon,neut[N-1]) ;
            insertionSort(Q,quita,neut[N-1]) ;
        }
    }

    cout << res << endl ;

    return 0 ;
}
