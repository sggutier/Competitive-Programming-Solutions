#include <algorithm>
#include <cstdio>
#include <iostream>
#include <utility>
using namespace std ;
#define lim 100005
#define par pair<int,int>
#define f first
#define s second

struct edg {
    int a, b, c ;
    edg() {
    }
    edg( int x, int y, int z ) {
        a = x ;
        b = y ;
        c = z ;
    }
};

bool operator<( edg A, edg B ) {
    return A.c < B.c ;
}

int N, W ;
edg conct[lim] ;
int padre[lim], carg[lim] ;

int raiz( int pos ) {
    while( padre[pos]!=pos )
        pos = padre[pos] ;
    return pos ;
}

int une( int ini, int fin, int cost ) {
    ini = raiz(ini) ;
    fin = raiz(fin) ;
    if( ini==fin )
        return 0 ;
    if( carg[ini]<carg[fin] )
        swap( ini, fin ) ;

    carg[ini] = max( carg[ini], carg[fin]+1 ) ;
    padre[fin] = ini ;

    return cost ;
}

void caso() {
    char S[lim] ;
    int res = 0 ;

    W = 0 ;
    scanf("%d", &N ) ;
    for( int i=0; i<N; i++ ) {
        int E, a, b ;
        scanf("%s", S ) ;
        scanf("%d", &E ) ;
        padre[i] = i ;
        carg[i] = 0 ;
        for( int j=0; j<E; j++ ) {
            scanf("%d%d", &a, &b ) ;
            a-- ;
            conct[W++] = edg(i,a,b) ;
        }
    }

    sort( conct, conct+W ) ;
    for( int i=0; i<W; i++ ) {
        res += une( conct[i].a, conct[i].b, conct[i].c ) ;
    }

    printf("%d\n", res ) ;
}

int main() {
    int T ;

    for( scanf("%d",&T); T; T-- )
        caso() ;

    return 0 ;
}
