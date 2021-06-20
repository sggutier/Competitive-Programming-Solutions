#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
#include <list>
#include <stack>
#include <utility>
#include <cmath>
using namespace std ;
typedef pair<int,int> par;
#define lim 200005
#define f first
#define s second

struct skiL {
	int tam ;
	int ro[lim], le[lim] ;
	par dat[lim] ;
	
};

long long dis[lim] ;
int O[lim] ;
par E[lim], comp[lim] ;
list <par> adj[lim] ;
map<int,int> idx ;
stack <par> P ;

void caso( int N ) {
	int R=0, W, r ;
	
	for( int i=0; i<N; i++ ) {
		O[i] = (1<<30) ;
		adj[i].clear() ;
		comp[i] = par( (1<<30), 0  ) ;
	}
	idx.clear() ;
	
	for( int i=1; i<N; i++ ) {
		int a, b ;
		
		scanf("%d%d", &a, &b ) ;
		adj[i].push_back( par(b,a) ) ;
		adj[a].push_back( par(b,i) ) ;
	}
	
	P.push(par(0,0)) ;
	while( !P.empty()  )  {
		par pos = P.top() ;
		P.pop() ;
		E[R++] = pos ;
		if( O[pos.s]<R ) 
			continue ;
			
		O[pos.s] = R-1 ;
		for( list<par>::iterator it=adj[pos.s].begin(); it!=adj[pos.s].end(); it++ ) {
			if(  O[(*it).s]==(1<<30)   ) {
				P.push( pos ) ;
				P.push( par( pos.f+1, (*it).s )  ) ;
			}
			else {
				dis[pos.s] = dis[ (*it).s ] + (*it).f  ;
			}
		}
	}
	r=max(  int(sqrt(R)),  1  ) ;
	
	for( int i=0 ; i<R; i++ ) {
		comp[i/r] = min( comp[i/r], E[i] ) ;
	}
	
	scanf("%d", &W ) ;
	for( int i=0; i<W; i++ ) {
		int a, b, x, y ;
		par c= par( (1<<30), 0  ) ;
		scanf("%d%d", &a, &b ) ;
		x = O[a], y=O[b] ;
		if( x>y )
			swap( x, y ) ;
		
		for( ; x%r && x<=y; x++ )  
			c = min( c, E[x] ) ;
		for( ; x+r-1<=y; x+=r )  
			c = min( c, comp[x/r] ) ;
		for( ; x<=y; x++ )  
			c = min( c, E[x] ) ;
		
		if( i )
			printf(" " ) ;
		printf("%lld", dis[a]+dis[b]-2LL*dis[c.s]  ) ;
	}
	printf("\n" ) ;
}

int main() {
	//freopen( "3390.in", "r", stdin ) ;
	
	int N ;
	
	while( 1  ) {
		scanf("%d", &N ) ;
		if( !N )
			break ;
		caso( N ) ;
	}
	
	return 0 ;
}


