#include <iostream>
#include <algorithm>
#include <cstdio>
#include <list>
#include <queue>
using namespace std ;
#define lim 5000

int N ;
list <int> adj[lim] ;
bool usd[lim] ;
int dis[lim], cicl[lim] ;
queue <int> Q ;

void buscaCiclo( int pos, int ant, int prof ) {
	if( cicl[pos] ) {
		for( int i=0; i<N; i++ ) {
			if( cicl[i]>=cicl[pos] ) {
				dis[i] = 0 ;
				Q.push(i) ;
			}
		}
		return ;
	}
	if( usd[pos] )
		return ;
	usd[pos] = 1 ;
	cicl[pos] = prof ;
	for( list<int> :: iterator  it=adj[pos].begin();   it!=adj[pos].end();   it++  )
		if( *it!=ant )
			buscaCiclo(*it,pos,prof+1) ;
	cicl[pos] = 0 ;
}

int main() {
	scanf("%d", &N ) ;
	for( int i=0; i<N; i++ ) {
		int a, b ;
		scanf("%d%d", &a, &b ) ;
		a--, b-- ;
		adj[a].push_back(b) ;
		adj[b].push_back(a) ;
		dis[i] = (1<<30) ;
	}
	
	buscaCiclo( 0, -1, 1 ) ;
	
	while( !Q.empty()  )  {
		int pos = Q.front() ;
		Q.pop() ;
		for( list<int>::iterator  it=adj[pos].begin();  it!=adj[pos].end();   it++  )  {
			if( dis[pos]+1<dis[*it]  ) {
				dis[*it] = dis[pos]+1 ;
				Q.push(*it) ;
			}
		}
	}
	
	for( int i=0; i<N; i++ )
		printf("%d ", dis[i] ) ;
	printf("\n" ) ;
	
	return  0 ;
}

