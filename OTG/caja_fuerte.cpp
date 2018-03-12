#include <algorithm>
#include <cstdio>
#include <iostream>
#include <string>
using namespace std ;
#define lim 2005

int N, W ;
char S[lim][lim] ;
unsigned long long orgHash[lim] ;
string org[lim], sig[lim] ;
int dr[] = { 0, 1, 0, -1 } ;
int dc[] = { 1, 0, -1, 0 } ;

void norm( char arr[lim][lim], string res[lim] ) {
    for( int k=0; k<W; k++ ) {
        int r=k, c=k ;

        for( int d=0; d<4; d++ ) {
            for( int i=N-k*2-1; i>0; i-- ) {
                res[k] += S[r][c] ;
                r += dr[d] ;
                c += dc[d] ;
            }
        }
    }
}

unsigned long long hash( string &arr ) {
    int K = arr.size();
    unsigned long long res = 0ULL, pot=1ULL ;

    for( int i=0; i<K; i++, pot*=27ULL )
        res += (arr[i]-'a')*pot ;

    return res ;
}

int main() {
    int res = 0 ;

    scanf("%d", &N ) ;
    W = N/2 ;
    for( int i=0; i<N; i++ )
        scanf("%s", S[i] ) ;
    norm( S, org ) ;
    for( int i=0; i<N; i++ )
        scanf("%s", S[i] ) ;
    norm( S, sig ) ;

    for( int i=0; i<W; i++ )
        orgHash[i] = hash(org[i]) ;

    for( int i=0; i<W; i++ ) {
        int tmp = 0 ;
        while( 1 ) {
            if(  hash(sig[i]) == orgHash[i]   )   {
                if( org[i]==sig[i] )
                    break ;
            }
            tmp ++ ;
            sig[i] = sig[i].substr( 1, sig[i].size()-1 ) + sig[i][0] ;
        }
        res += min( tmp, int(sig[i].size()-tmp)  ) ;
    }

    printf("%d\n", res ) ;

    return 0 ;
}
