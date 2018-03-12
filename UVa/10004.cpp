#include <cstdio>
#include <cstring>
#include <list>
#include <algorithm>
#include <utility>
#include <queue>
using namespace std ;
const int lim = 300 ;

int N, E ;
list <int> adj[lim] ;
queue <int> Q[2] ;
char col[lim] ;

void caso() {
    for( int i=0; i<N; i++ ) {
	adj[i].clear() ;
	col[i] = 3 ;
    }
    while( !Q[0].empty() )
	Q[0].pop() ;
    while( !Q[1].empty() )
	Q[1].pop() ;
    

    scanf("%d", &E ) ;
    for( int i=0; i<E; i++ ) {
	int a, b ;
	scanf("%d%d", &a,  &b ) ;
	adj[a].push_back( b ) ;
	adj[b].push_back( a ) ;
    }

    Q[0].push( 0 ) ;
    int act=0, sig=1 ;
    while( !Q[act].empty() ) {
	while( !Q[act].empty() ) {
	    int pos = Q[act].front() ;
	    Q[act].pop() ;
	    for( list<int>::iterator it=adj[pos].begin(); it!=adj[pos].end(); it++ ) {
		if( col[*it]==act ) {
		    printf("NOT BICOLORABLE.\n" ) ;
		    return ;
		}
		else if( col[*it]!=sig ) {
		    col[*it] = sig ;
		    Q[sig].push(*it) ;
		}
	    }
	}
		
	swap( act, sig ) ;
    }
    
    printf("BICOLORABLE.\n" ) ;
}

int main() {
    while( scanf("%d", &N) && N ) {
	caso() ;
    }
    
    return 0 ;
}
