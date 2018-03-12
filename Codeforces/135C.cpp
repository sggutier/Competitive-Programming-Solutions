#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string>
#include <cstring>
using namespace std ;
#define lim 100005

int N ;
char S[lim] ;
bool res[4] ;

int evalCarg() {
    int a, b ;

    if( S[N-1]=='1' )
        a = 1 ;
    else if( S[N-1]=='0' )
        a = 0 ;
    else
        a = 2 ;
    for( int i=N-2; i>=0; i-- ) {
        if( S[i] != S[i+1] || S[i]=='?' ) {
            if( S[i]=='1' )
                b = 1 ;
            else if( S[i]=='0' )
                b = 0 ;
            else
                b = 2 ;
            break ;
        }
    }

    //cout << a << " " << b << endl ;

    if( b==0 || b==1 ) {
        if( a==0 || a==1 ) {
            res[ (b<<1) + a ] = 1 ;
        }
        else {
            if( (b<<1)+0 == 1 || (b<<1)+0 == 2 )
                res[ (b<<1) + 0 ] = 1 ;
            if( (b<<1)+1 == 1 || (b<<1)+1 == 2 )
                res[ (b<<1) + 1 ] = 1 ;
        }
    }
    else {
        if( a==0 || a==1 ) {
            if( 0+a == 1 || 0+a == 2 )
                res[ 0 + a ] = 1 ;
            if( 2+a == 1 || 2+a == 2 )
                res[ 2 + a ] = 1 ;
        }
        else {
            res[1] = 1 ;
            res[2] = 1 ;
        }
    }
}

int main() {
    int op=0, carg=0 ;
    string strRes[4] = { "00", "01", "10", "11" } ;

    scanf("%s", S ) ;
    N = strlen(S) ;

    for( int i=0; i<N; i++ ) {
        if( S[i]=='0' )
            carg -- ;
        else if( S[i]=='1' )
            carg ++ ;
        else
            op ++ ;
    }

    if( carg-op<=-1 )
        res[0] = 1 ;
    if( carg+op>=2 )
        res[3] = 1 ;
    if( abs(carg)-1<=op )
        evalCarg() ;

    for( int i=0; i<4; i++ )
        if( res[i] )
            cout << strRes[i] << endl ;

    return 0 ;
}
