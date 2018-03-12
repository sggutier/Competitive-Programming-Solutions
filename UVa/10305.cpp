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
using namespace std ;
const int lim = 1000005 ;

int N, E ;
list<int> adj[lim] ;
int cntL[lim] ;
queue <int> Q ;

void caso() ;

int main() {
    while( scanf("%d%d",&N,&E)!=EOF and ( N or E ) ) {
	caso() ;
    }
    
    return 0 ;
}

void caso() {
    for( int i=0; i<N; i++ ) {
	cntL[i] = 0 ;
	adj[i].clear() ;
    }

    for( int i=0; i<E; i++ ) {
	int a, b ;
	scanf("%d%d", &a, &b ) ;
	a--, b-- ;
	adj[a].push_back( b ) ;
	cntL[b] ++ ;
    }

    for( int i=0; i<N; i++ )
	if( cntL[i]==0 )
	    Q.push(i) ;

    bool fst = 1 ;
    while( !Q.empty() ) {
	int pos = Q.front() ;
	Q.pop() ;
	if( !fst )
	    printf(" " ) ;
	fst = 0 ;
	printf("%d", pos+1 ) ;
	for( list<int>::iterator it=adj[pos].begin(); it!=adj[pos].end();  it++ ) {
	    cntL[*it] -- ;
	    if( !cntL[*it] )
		Q.push(*it) ;
	}
    }
    printf("\n" ) ;
}
