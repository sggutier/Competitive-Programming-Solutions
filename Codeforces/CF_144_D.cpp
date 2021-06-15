#include <algorithm>
#include <cstdio>
#include <iostream>
#include <utility>
#include <queue>
#include <list>
using namespace std ;
typedef pair<int,int> par ;
typedef list<par>::iterator ito ;
#define f first
#define s second
#define lim 100005
#define inf (1<<30)

int N, E, ini ;
list <par> adj[lim] ;
priority_queue <par> Q ;
queue <par> quer[lim] ;
int usd[lim] ;
int L ;

int main() {
	int res = 0 ;
	int w, x, y, z ;
	
	scanf("%d%d%d", &N, &E, &ini ) ;
	for( int i=0; i<E; i++ ) {
		int a, b , c ;
		scanf("%d%d%d", &a, &b, &c ) ;
		a--, b-- ;
		adj[b].push_back( par( c, a )  );
		adj[a].push_back( par( c, b )  );
	}
	scanf("%d", &L ) ;
	
	Q.push( par(0,ini-1)  ) ;
	
	while( !Q.empty() ) {
		par pos = Q.top() ;
		Q.pop() ;
		if( usd[pos.s] )
			continue ;
			
		usd[pos.s] = 1 ;
		
		
		if( -pos.f == L ) 
			res ++ ;
		while( !quer[pos.s].empty()  ) {
			
			w = quer[pos.s].front().f ;
			x = quer[pos.s].front().s ;
			y = -pos.f ;
			z = w+y-x ;
			quer[pos.s].pop() ;
			
			if( y>L ) {
				res ++ ;
			}
			else {
				if( z>0 && z>=2*(L-x) )
					res ++ ;
				if( z<w*2 && L-y && w*2-z>2*(L-y)   )
					res ++ ;
			}
		}
		
		for( ito it=adj[pos.s].begin(); it!=adj[pos.s].end(); it++ ) {
			if( usd[(*it).s] )
				continue ;
			if(  -pos.f<L &&  (*it).f-1>=L+pos.f  ) {
				quer[(*it).s].push( par( (*it).f, -pos.f )    ) ;
			}
			Q.push( par( pos.f-(*it).f, (*it).s )  ) ;
		}
	}
	
	printf("%d\n", res ) ;
	
	return 0 ;
}


