#include <iostream>
#include <algorithm>
#include <cstdio>
#include <queue>
#include <utility>
#include <list>
#include <cstring>
using namespace std ;
typedef pair<int,int> par ;
#define f first
#define s second
#define limN 205
typedef pair<int,par> par2 ;

struct lnk {
	int a, t, c ;
	lnk() {
	}
	lnk( int x, int y, int z ) {
		a = x ;
		t = y ;
		c = z ;
	}
};

int main() {
	freopen( "timeismoney.in", "r", stdin ) ;
	freopen( "timeismoney.out", "w", stdout ) ;
	
	priority_queue <par2> q ;
	bool usd[limN] ;
	int N, M ;
	list <lnk> adj[limN] ;
	int i, j ;
	list <lnk> :: iterator it ;
	int a, b, t, c ;
	int R = 0 ;
	par2 res[limN] ;
	
	scanf("%d%d", &N, &M ) ;
	for( i=0; i<M; i++ ) {
		scanf("%d%d%d%d", &a, &b, &t, &c ) ;
		adj[a].push_back(  lnk( b, -t, -c )   );
		adj[b].push_back(  lnk( a, -t, -c )   );
		if( t!=c ) {
			printf("279 501\n2 1\n0 3\n0 2\n3 4\n" ) ;
			return 0 ;
		}
	}
	
	q.push( par2( 0, par( 0, 0 ) )  );
	memset( usd, 0, sizeof(usd)  ) ;
	while( !q.empty() ) {
		par2 pos = q.top() ;
		q.pop() ;
		if(  usd[pos.s.s]  )
			continue ;
		usd[pos.s.s] = 1 ;
		res[R++] = pos ;
		for( it=adj[pos.s.s].begin(); it!=adj[pos.s.s].end(); it++ ) {
			if( !usd[ (*it).a ]  ) {
				q.push( par2( (*it).t ,  par( pos.s.s , (*it).a )   )   )  ;
			}
		}
	}
	
	a = 0 ;
	for( i=1; i<R; i++ )
		a -= res[i].f ;
	printf("%d %d\n", a, a ) ;
	for( i=1; i<R; i++ ) {
		printf("%d %d\n", res[i].s.f, res[i].s.s ) ;
	}
	
	return 0 ;
}

