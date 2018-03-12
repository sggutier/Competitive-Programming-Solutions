#include <algorithm>
#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>
#include <map>
#include <utility>
using namespace std ;
#define lim 100005
#define par pair<int,int>
#define f first
#define s second

long long A, B, X ;
int W ;
string S ;
bool marc[10], marc2[10] ;
long long dp[12][lim][2], pot[13] ;
bool usd[12][lim][2] ;

int num() {
    int res = 0 ;
    for( int i=(A/X) + ((A%X)!=0); i*X<=B; i++ ) {
        long long tmp = i*X, tmp2 ;
        int a=0 ;
        memset( marc2, 0, sizeof(marc2) ) ;
        while( tmp ) {
            tmp2 = tmp%10 ;
            if( !marc[tmp2] ) {
                if( !marc2[tmp2] ) {
                    a ++ ;
                    marc2[tmp2] = 1 ;
                }
            }
            tmp /= 10LL ;
        }
        if( a==0 )
            res ++ ;
    }
    return res ;
}

long long memo( int N, long long pref ) {
    long long le, ro ;
    le = pref*pot[N] ;
    ro = (pref+1LL)*pot[N] -1 ;

    if( ro<A || le>B )
        return 0LL ;

    if( N==0 ) {
        //cout << N << " " << pref*pot[N] << " " ;
        //cout << int(pref%X==0LL) << endl ;
        return pref%X==0LL ;
    }

    int grd = (A<=le && B>=ro) ;
    long long res = 0LL ;
    if( grd && usd[N][pref%X][pref==0] )
        return dp[N][pref%X][pref==0] ;

    for( int i=0; i<W; i++ )
        if( S[i]!='0' )
            res += memo( N-1, pref*10LL + S[i]-'0' ) ;
    if( pref==0 || S[0]=='0' )
        res += memo( N-1, pref*10LL ) ;

//cout << N << " " << pref*pot[N] << " " ;
    //cout << res << endl ;
    if( grd ) {
        usd[N][pref%X][pref==0] = 1 ;
        return dp[N][pref%X][pref==0] = res ;
    }

    return res ;
}

int main() {
    cin >> X >> A >> B ;
    cin >> S ;

    W = S.size() ;
    sort( S.begin(), S.end() ) ;

    pot[0] = 1LL ;
    for( int i=1; i<13; i++ )
        pot[i] = pot[i-1]*10LL ;

    if( X>=100000 ) {
        for( int i=0; i<W; i++ )
            marc[ S[i]-'0' ] = 1 ;
        printf("%d\n", num() ) ;
    }
    else {
        cout << memo(11,0) << endl ;
    }

    return 0 ;
}


