#include <algorithm>
#include <cstdio>
#include <iostream>
#include <queue>
#include <utility>
#include <list>
using namespace std ;
#define lim 100005
#define f first
#define s second
typedef pair<long long,int> par ;

priority_queue <par> Q ;
int N, E ;
char tip[lim] ;
list <par> adj[lim] ;

void caso() {
	long long res = 0LL ;
	
	scanf("%d%d", &N, &E ) ;
	scanf("%s", tip ) ;
	for( int i=0; i<N; i++ ) {
		if( tip[i]=='H' )	
			tip[i] = 1 ;
		else
			tip[i] = 0 ;
		adj[i].clear() ;
	}
	
	for( int i=0; i<E; i++ ) {
		int a, b, d ;
		long long c ;
		scanf("%d%d%d", &a, &b, &d ) ;
		a--, b-- ;
		c = 0LL + d ;
		if( tip[a]==1 && tip[b]==1 ) {
			adj[a].push_back( par(c,b)  ) ;
			adj[b].push_back( par(c,a)  ) ;
		}
		else if( tip[a]!=tip[b] ) {
			if( tip[b] )
				swap( a, b ) ;
			Q.push( par(-c,a) ) ;
		}
		else if( c<0 ) {
			res += c ;
		}
	}
	
	while( !Q.empty()  )  {
		par pos = Q.top() ;
		Q.pop() ;
		if( !tip[pos.s] ) {
			if( pos.f>0 )
				res -= pos.f ;
			continue ;		
		}
			
		res -= pos.f ;
		tip[pos.s] = 0 ;
		for( list<par>::iterator it=adj[pos.s].begin(); it!=adj[pos.s].end(); it++ ) {
			if( tip[(*it).s] )
				Q.push( par( -(*it).f, (*it).s  )   );
		}
	}
	
	cout << res << endl ;
	
	return ;
}

int main() {
	
	int T ;
	
	for( scanf("%d", &T ); T; T-- )	
		caso() ;
	
	return 0 ;
}
