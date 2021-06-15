#include <cstdio>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std ;
const int lim = 100005 ;

int N ;
vector<int> pts[lim] ;

int bsA( int pos, int W ) {
    int ini, fin, piv ;
    ini = 0 ;
    fin = pts[pos].size()-1 ;

    while( ini<fin ) {
        piv = (ini+fin)/2 ;
        if( pts[pos][piv]<W )
            ini = piv+1 ;
        else
            fin = piv ;
    }

    return ini ;
}

int bsB( int pos, int W ) {
    int ini, fin, piv ;
    ini = 0 ;
    fin = pts[pos].size()-1 ;

    while( ini<fin ) {
        piv = (ini+fin)/2 + 1 ;
        if( pts[pos][piv]>W )
            fin = piv-1 ;
        else
            ini = piv ;
    }

    return ini ;
}

int main() {
    int res = 0 ;

    scanf("%d", &N ) ;
    for( int i=0; i<N; i++ ) {
        int w = 0 ;
        scanf("%d", &w ) ;
        pts[i].push_back(-1) ;
        for( int j=0, tmp; j<w; j++ ) {
            scanf("%d", &tmp ) ;
            pts[i].push_back(tmp) ;
        }
        pts[i].push_back(lim) ;
        sort( pts[i].begin(), pts[i].end() ) ;
    }

    for( int i=0; i<N; i++ ) {
        for( int j=2; j+1<pts[i].size(); j++ ) {
            int a, b, x, y ;
            a = bsA( (i+1)%N, pts[i][j-1] ) ;
            b = bsB( (i+1)%N, pts[i][j] ) ;
            x = bsA( (i-1+N)%N, pts[i][j-1] ) ;
            y = bsB( (i-1+N)%N, pts[i][j] ) ;

            a = max( -1, b-a ) ;
            x = max( -1, y-x ) ;
            if( a!=x )
                res ++ ;
        }
    }

    printf("%d\n", res ) ;

    return 0 ;
}
