#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <utility>
#include <list>
using namespace std ;
typedef long long ll ;
typedef pair<ll,int> par ;
#define f first
#define s second
#define inf (1LL<<60)
#define lim 1003

void dijkstra(  list <par> adj[], int ini, ll res[], int tam ) {
	priority_queue <par> q ;
	int pos ;
	par tmp ;
	ll cos ;
	list <par> :: iterator it ;
	
	fill( res, res+tam, -inf ) ;
	q.push( par(0LL,ini)  ) ;
	res[ini] = 0LL ;
	while( !q.empty()  ) {
		tmp = q.top() ;
		q.pop() ;
		if( tmp.f < res[tmp.s] )	
			continue ;
		pos = tmp.s ;
		cos = tmp.f ;
		for( it=adj[pos].begin(); it!=adj[pos].end(); it++  ) {
			if(  (*it).f + cos > res[(*it).s]    )  {
				res[(*it).s] = (*it).f + cos ;
				q.push(   par( res[(*it).s],  (*it).s )   ) ;
			}
		}
	}
}

int main() {
	//freopen( "95C.in", "r", stdin ) ;
	
	int N, M ;
	list <par>  dis[lim] ;
	list <par>  adj[lim] ;
	int ini, fin ;
	ll minP[lim] ;
	int i, j ;
	
	
	
	scanf("%d%d", &N, &M ) ;
	scanf("%d%d", &ini, &fin ) ;
	ini--, fin-- ;
	for( i=0; i<M; i++ ) {
		int a, b, c ;
		scanf("%d%d%d", &a, &b, &c ) ;
		a--, b-- ;
		dis[a].push_back( par(-c+0LL, b) ) ;
		dis[b].push_back( par(-c+0LL, a) ) ;
	}	
	for( i=0; i<N; i++ ) {
		int t, c ;
		scanf("%d%d", &t, &c ) ;
		dijkstra( dis, i, minP, N ) ;
		for( j=0; j<N; j++ ) {
			if( -minP[j] <= t && i!=j )  {
				adj[i].push_back( par(-c+0LL,j)  )  ;
			}
		}
	}
	
	dijkstra( adj, ini, minP, N ) ;
	if( minP[fin] == -inf )
		cout << -1 << endl ;
	else
		cout << -minP[fin] << endl ;
	
	return 0 ;
}

