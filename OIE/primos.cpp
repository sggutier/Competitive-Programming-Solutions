#include <algorithm>
#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std ;
#define lim 32000

int P=0, E ;
int primos[lim] ;
char comp[lim] ;
int expon[lim] ;

void criba() {
    for( int i=2; i*i<lim; i++ )
        if( !comp[i] )
            for( int j=i*i; j<lim; j+=i )
                comp[j] = 1 ;
    for( int i=2; i<lim; i++ )
        if( !comp[i] )
            primos[P++] = i ;
}

void norm() {
    int N ;
    int a=0, b=0 ;
    int usd = 0 ;

    scanf("%d", &N ) ;

    E = 0 ;
    for( int i=0; i<P; i++ ) {
        expon[i] = 0 ;
        while( N%primos[i]==0 ) {
            expon[i] ++ ;
            N /= primos[i] ;
        }
    }

    if( N>1 ) {
        a = sqrt(N) ;
        if( a*a==N ) {
            b=2 ;
        }
        else {
            a = N ;
            b = 1 ;
        }
    }

    for( int i=0; i<P; i++ ) {
        for( int j=0; j<expon[i]; j++ ) {
            if( usd )
                printf(",") ;
            printf("%d", primos[i] ) ;
            usd = 1 ;
        }
    }
    for( int i=0; i<b; i++ ) {
        if( usd )
            printf(",") ;
        printf("%d", a ) ;
        usd = 1 ;
    }

    printf(".\n" ) ;
}

void pretty() {
    int N ;
    int a=0, b=0 ;
    int usd = 0 ;
    string resA = "", resB = "", S ;
    char tmp[1000] ;

    scanf("%d", &N ) ;

    sprintf( tmp, "%d =", N ) ;
    S = tmp ;
    resB += S ;
    for( int i=S.size(); i; i-- )
        resA += " " ;

    E = 0 ;
    for( int i=0; i<P; i++ ) {
        expon[i] = 0 ;
        while( N%primos[i]==0 ) {
            expon[i] ++ ;
            N /= primos[i] ;
        }
    }

    if( N>1 ) {
        a = sqrt(N) ;
        if( a*a==N ) {
            b=2 ;
        }
        else {
            a = N ;
            b = 1 ;
        }
    }

    if( a ) {
        if( usd ) {
            resA += "  " ;
            resB += " x" ;
        }
        usd = 1 ;
        sprintf( tmp, " %d", a ) ;
        S = tmp ;
        resB += S ;
        for( int i=S.size(); i; i-- )
            resA += " " ;
        if( b!=1 ) {
            sprintf( tmp, "%d", b ) ;
            S = tmp ;
            resA += S ;
            for( int i=S.size(); i; i-- )
                resB += " " ;
        }
    }
    for( int i=P-1; i>=0; i-- ) {
        if( !expon[i] )
            continue ;
        if( usd ) {
            resA += "  " ;
            resB += " x" ;
        }
        usd = 1 ;
        sprintf( tmp, " %d", primos[i] ) ;
        S = tmp ;
        resB += S ;
        for( int j=S.size(); j; j-- )
            resA += " " ;
        if( expon[i]==1 )
            continue ;
        sprintf( tmp, "%d", expon[i] ) ;
        S = tmp ;
        resA += S ;
        for( int j=S.size(); j; j-- )
            resB += " " ;
    }

    resA += "|" ;
    resB += "|" ;
    cout << resA << endl ;
    cout << resB << endl ;
}

int main() {
    int T ;
    char S[1000] ;
    string W ;
    criba() ;

    scanf("%d%s", &T, S ) ;
    for( W=S; T; T-- )  {
        if( W=="NORMAL" )
            norm() ;
        else
            pretty() ;
    }


    return 0 ;
}
