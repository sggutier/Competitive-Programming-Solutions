#include <algorithm>
#include <cstdio>
#include <iostream>
#include <utility>
#include <set>
using namespace std ;
#define lim 100005
#define par pair<int,int>
#define f first
#define s second

int N ;
par vel[lim] ;
int carg[lim] ;
set <int> posArr ;

void actualiza( int le, int ro ) {
    ro ++ ;
    carg[le] ++ ;
    carg[ro] -- ;
    if( carg[le] )
        posArr.insert(le) ;
    else
        posArr.erase(le) ;
    if( carg[ro] )
        posArr.insert(ro) ;
    else
        posArr.erase(ro) ;
}

int main() {
    int mH = 0, pos ;
    long long res = 0LL, W=0LL ;

    scanf("%d", &N ) ;
    for( int i=0; i<N; i++ ) {
        scanf("%d%d", &vel[i].f, &vel[i].s ) ;
    }

    sort( vel, vel+N ) ;
    mH = vel[0].f ;
    actualiza( 0, vel[0].s-1 ) ;

    for( int i=1; i<N; i++ ) {
        /*for( int j=0; j<=mH; j++ )
            printf("%d ", carg[j] ) ;
        printf("\n" ) ;*/
        mH = max( mH, vel[i].f ) ;
        pos = mH-vel[i].s ;
        if( carg[pos]  ) {
            actualiza( pos, mH-1 ) ;
        }
        else {
            int ro=mH, le=0 ;
            set <int> :: iterator tmp ;
            tmp = posArr.lower_bound(pos) ;
            tmp -- ;
            le = *tmp ;
            if( posArr.upper_bound(pos)!=posArr.end()  )  {
                ro = *posArr.upper_bound(pos) ;
            }
            //cout << "-->  " << le << " " << ro << " " << pos << " " << le+ro-pos-1 << endl ;
            actualiza( le, le+ro-pos-1 ) ;
            if( ro<mH )
                actualiza( ro, mH-1 ) ;
        }
    }

    /*for( int j=0; j<=mH; j++ )
        printf("%d ", carg[j] ) ;
    printf("\n" ) ;*/
    for( int j=0; j<mH; j++ ) {
        W += carg[j] ;
        res += (W*(W-1LL))/2LL ;
    }
    cout << res << endl ;

    return 0 ;
}
