#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
#include <utility>
#include <vector>
using namespace std ;
#define lim 100005
#define par pair<int,int>
#define f first
#define s second

int N, W=0   ;
int tam[lim] ;
vector <par> carg[lim] ;
map <int,int> M ;
par res[lim][2], arr[lim] ;

int main() {
    long long tamRes = 0LL ;
    int posRes, posRes2, tamRes, tamRes2 ;

    scanf("%d", &N ) ;
    for( int i=0; i<N; i++ ) {
        int a, b ;
        scanf("%d%d", &a, &b ) ;
        if( M.find(a)==M.end() )
            M[a] = W++ ;
        a = M[a] ;
        arr[tam[a]++] = par(a,b) ;
    }

    for( int i=0; i<W; i++ ) {
        carg[i].resize( tam[i] ) ;
        tam[i] = 0 ;
    }
    for( int i=0; i<lim; i++ ) {
        carg[ arr[i].f ][ tam[arr[i].f]++ ]   =   par( arr[i].s, i)    ;
    }
    for( int i=0; i<W; i++ ) {
        long long tmp = 0LL ;
        sort( carg[i].begin(), carg[i].end() ) ;
        reverse( carg[i].begin(), carg[i].end() ) ;
        for( int j=0; j<tam[i]; j++ ) {
            tmp += carg[i][j] ;
            if( tmp>res[j][1].s ) {
                res[j] = par( tmp, i ) ;
                if( res[j][1]>res[j][0]  )
                    swap( res[j][0], res[j][1] ) ;
            }
        }
    }


    for( int i=lim-1; i>=0; i-- ) {
        if( !res[i][0].f )
            continue ;
        if( res[i][1].f ) {
            if( res[i][0].f + res[i][1].f > tamRes ) {
                tamRes = res[i][0].f + res[i][1].f ;
                posRes = res[i].s ;
                posRes2 = res[i].s ;
                tamRes = i ;
                tamRes2 = i ;
            }
        }
        if( i && res[i-1][{
            if( res[i][0].f + res[i][1].f > tamRes ) {
                tamRes = res[i][0].f + res[i][1].f ;
                posRes = res[i].s ;
                posRes2 = res[i].s ;
                tamRes = i ;
                tamRes2 = i ;
            }
        }
    }


    return 0 ;
}
