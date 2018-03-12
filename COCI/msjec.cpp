#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std ;
#define lim 2700

int N, W=0 ;
int pts[lim][2], rec[lim][2], vuelt[lim], vueltInv[lim] ;
int dir[lim] ;

bool pruebaInv( int K ) {
    for( int i=0; i<W; i++ ) {
        if( dir[i]!=vueltInv[(i+K)%W] ) {
            return 0 ;
        }
    }
    return 1 ;
}

bool prueba( int K ) {
    for( int i=0; i<W; i++ ) {
        if( dir[i]!=vuelt[(i+K)%W] ) {
            return 0 ;
        }
    }
    return 1 ;
}

int main() {
    scanf("%d", &N ) ;
    for( int i=0; i<N; i++ ) {
        scanf("%d%d", &pts[i][0], &pts[i][1] ) ;
    }

    for( int i=0; i<N; i++ ) {
        int x=pts[(i+1)%N][0]-pts[i][0], y=pts[(i+1)%N][1]-pts[i][1] ;
        if( x )
            x /= abs(x) ;
        if( y )
            y /= abs(y) ;
        for( int r=pts[i][0], c=pts[i][1];  r!=pts[(i+1)%N][0] || c!=pts[(i+1)%N][1];  r+=x, c+=y  ) {
            rec[W][0] = r ;
            rec[W][1] = c ;
            W ++ ;
        }
    }
    for( int i=0; i<W; i++ ) {
        int x=rec[(i+1)%W][0]-rec[i][0], y=rec[(i+1)%W][1]-rec[i][1] ;
        int x2=rec[i][0]-rec[(i+W-1)%W][0], y2=rec[i][1]-rec[(i+W-1)%W][1] ;
        if( x )
            x /= abs(x) ;
        if( y )
            y /= abs(y) ;
        if( x2 )
            x2 /= abs(x2) ;
        if( y2 )
            y2 /= abs(y2) ;

        if( x==x2 )
            continue ;

        if( x==0 ) {
            vuelt[i] = y/x2 ;
            vueltInv[i] = -y/x2 ;
        }
        else {
            vuelt[i] = x/y2 ;
            vueltInv[i] = -x/y2 ;
        }
    }

    for( int i=0; i<W; i++ ) {
        int a, b ;
        printf("move 1\n") ;
        scanf("%d%d", &a, &b ) ;
        if( a==1 )
            dir[i] = 1 ;
        else
            dir[i] = -1 ;
    }

    for( int i=0; i<W; i++ ) {
        if( prueba(i) || pruebaInv(i) ) {
            printf("stop %d %d\n", rec[i][0], rec[i][1] ) ;
            return 0 ;
        }
    }

    return 0 ;
}
