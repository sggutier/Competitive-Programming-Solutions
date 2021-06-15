#include <algorithm>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <list>
#include <stack>
using namespace std ;
#define lim 100005

int N ;
list<int> adj[lim] ;
vector <int> niv[lim] ;
int prof[lim], apIni[lim], apFin[lim] ;

void numera() {
    int W = 1 ;
    stack <int> nod ;
    list <int> :: iterator  itos[lim] ;

    nod.push(0) ;
    prof[0] = 0 ;
    while( !nod.empty() ) {
        int pos = nod.top() ;

        if( !apIni[pos] ) {
            niv[ prof[pos] ] .push_back( pos ) ;
            apIni[pos] = W ;
            itos[pos] = adj[pos].begin() ;
        }
        apFin[pos] = W++ ;

        if( itos[pos]==adj[pos].end() ) {
            nod.pop() ;
        }
        else {
            prof[ *itos[pos] ] = prof[pos]+1 ;
            nod.push( *itos[pos] ) ;
            itos[pos] ++ ;
        }
    }
}

int buscaRaiz( int prof, int pos ) {
    int ini=0, fin=niv[prof].size()-1, piv ;

    while( ini<fin ) {
        piv = (ini+fin)/2 ;
        if( apFin[ niv[prof][piv] ] < apIni[pos] )
            ini = piv+1 ;
        else
            fin = piv ;
    }

    return niv[prof][ini] ;
}

int buscaIzq( int prof, int pos ) {
    int ini=0, fin=niv[prof].size()-1, piv ;

    while( ini<fin ) {
        piv = (ini+fin)/2 ;
        if( apIni[ niv[prof][piv] ] < apIni[pos] )
            ini = piv+1 ;
        else
            fin = piv ;
    }

    return ini ;
}

int buscaDer( int prof, int pos ) {
    int ini=0, fin=niv[prof].size()-1, piv ;

    while( ini<fin ) {
        piv = (ini+fin)/2 + (ini+fin)%2 ;
        if( apFin[ niv[prof][piv] ] > apFin[pos] )
            fin = piv-1 ;
        else
            ini = piv ;
    }

    return ini ;
}

int main() {
    int Q ;

    scanf("%d", &N ) ;
    for( int i=1; i<=N; i++ ) {
        int tmp ;
        scanf("%d", &tmp ) ;
        adj[tmp].push_back(i) ;
    }

    numera() ;

    scanf("%d", &Q ) ;
    for( int i=0; i<Q; i++ ) {
        int pos, alt, ro, x, y ;
        scanf("%d%d", &pos, &alt ) ;
        if( prof[pos]<=alt ) {
            printf("0\n" ) ;
        }
        else {
            ro = buscaRaiz( prof[pos]-alt, pos ) ;
            x = buscaIzq( prof[pos], ro ) ;
            y = buscaDer( prof[pos], ro ) ;
            printf("%d\n", y-x ) ;
        }
    }

    return 0 ;
}
