#include <algorithm>
#include <cstdio>
#include <iostream>
#include <string>
#include <cmath>
using namespace std ;
#define par pair<string,string>
#define f first
#define s second
#define lim 3000

par arr[lim] ;
bool dig[30] ;
long long remp[300] ;
long long res = 0LL ;

void prueba( const string &S, const string &X, const string &Y, int pos ) {
    while( pos<S.size() && pos && S[pos]==S[pos-1] )
        pos ++ ;

    if( pos==S.size()  ) {

        long long pot=1LL, a=0LL, b=0LL, a2, b2 ;
        for( int i=X.size()-1; i>=0; i--, pot*=10LL ) {
            if( i==0 && remp[X[i]]==0LL )
                return ;
            if( i==0 && remp[Y[i]]==0LL )
                return ;
            a += remp[X[i]]*pot ;
            b += remp[Y[i]]*pot ;
        }
        a2 = (long long) ( sqrt(a) ) ;
        b2 = (long long) ( sqrt(b) ) ;
        if( a2*a2 == a &&  b2*b2==b ) {
            res = max( res, a ) ;
            res = max( res, b ) ;
        }
        return ;
    }

    for( int i=0; i<=9; i++ ) {
        if( dig[i] )
            continue ;
        dig[i] = 1 ;
        remp[ S[pos] ] = i + 0LL ;
        prueba( S, X, Y, pos+1 ) ;
        dig[i] = 0 ;
    }
}

string simplifica( string S ) {

    sort( S.begin(), S.end() ) ;


    return S ;
}

int main() {
    freopen( "words.txt", "r", stdin ) ;

    int N ;

    cin >> N ;
    for( int i=0; i<N; i++ ) {
        cin >> arr[i].s ;
        arr[i].f = simplifica( arr[i].s ) ;
        for( int j=0; j<i; j++ ) {
            if( arr[i].f == arr[j].f ) {
                prueba( arr[i].f, arr[i].s, arr[j].s, 0 ) ;
            }
        }
    }

    cout << res << endl ;

    return 0 ;
}
