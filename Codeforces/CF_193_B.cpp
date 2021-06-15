#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std ;
#define lim 105

int N ;
long long R ;
long long arr[lim][40], brr[lim], krr[lim], prr[lim] ;
long long res = -(1LL<<60) ;

void busca( int U ) {
    if( U%2==0 ) {
        long long w = 0LL ;
        for( int i=0; i<N; i++ ) {
            w += arr[i][U]*krr[i] ;
        }
        res = max( res, w ) ;
    }
    else {
        long long w = 0LL ;
        for( int i=0; i<N; i++ ) {
            w += (arr[i][U]^brr[i])*krr[i] ;
        }
        res = max( res, w ) ;
    }
    if( U==0 ) {
        return ;
    }

    for( int i=0; i<N; i++ )
        arr[i][U-1] = arr[ prr[i] ][U] +R;
    busca( U-1 ) ;

    for( int i=0; i<N; i++ )
        arr[i][U-1] = arr[i][U] ^ brr[i] ;
    if( U==1 ) {
        busca( U-1 ) ;
        return ;
    }
    for( int i=0; i<N; i++ )
        arr[i][U-2] = arr[ prr[i] ][U-1] +R;
    busca( U-2 ) ;
}

int main() {
    int U ;

    cin >> N >> U >> R ;
    for( int i=0; i<N; i++ )
        cin >> arr[i][U] ;
    for( int i=0; i<N; i++ )
        cin >> brr[i]  ;
    for( int i=0; i<N; i++ )
        cin >> krr[i] ;
    for( int i=0; i<N; i++ ) {
        cin >> prr[i] ;
        prr[i] -- ;
    }

    busca(U) ;

    cout << res << endl ;

    return 0 ;
}
