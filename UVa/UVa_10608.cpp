#include <cstdio>
#include <algorithm>
#include <iostream>
#include <utility>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <cmath>
#include <string>
#include <cstring>
#include <vector>
#include <list>
#include <cstdlib>
#include <cctype>
using namespace std ;
#define par pair< int, int >
#define p1 first
#define p2 second
const int lim = 500005 ;

int N ;
bool usd[lim] ;
list <int> adj[lim] ;

int cuentaG( int pos ) {
    if( usd[pos] )
	return 0 ;
    stack <int> Q ;
    int res = 0 ;
    
    usd[pos] = 1 ;
    Q.push(pos) ;

    while( !Q.empty() ) {
	res ++ ;
	pos = Q.top() ;
	Q.pop() ;
	for( list<int>::iterator it=adj[pos].begin(); it!=adj[pos].end(); it++ ) {
	    if( usd[*it] )
		continue ;
	    usd[*it] = 1 ;
	    Q.push( *it ) ;
	}
    }

    return res ;
}

void caso() {
    int E ;
    int res = 0 ;

    scanf("%d%d", &N, &E ) ;

    for( int i=0; i<N; i++ )
	adj[i].clear() ;
    memset( usd, 0, sizeof(usd) ) ;

    for( int i=0; i<E; i++ ) {
	int a, b ;
	scanf("%d%d", &a, &b ) ;
	a--, b-- ;
	adj[a].push_back( b) ;
	adj[b].push_back(a) ;
    }

    for( int i=0; i<N; i++ )
	res = max( res, cuentaG(i) ) ;

    printf("%d\n", res ) ;
}

int main() {
    int T ;

    scanf("%d", &T ) ;
    for( int i=0; i<T; i++ )
	caso() ;
    
    return 0 ;
}
