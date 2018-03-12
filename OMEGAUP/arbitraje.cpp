#include <algorithm>
#include <cstdio>
#include <iostream>
#include <list>
#include <queue>
using namespace std ;
#define par pair<double,int>
#define f first
#define s second
#define lim 1000

int N ;
list<par> adj[lim] ;
double res = -(1<<30)*1.0 ;

void busca( int ini ) {
	bool usd[lim] ;
	double maxP[lim] ;
	priority_queue<par> Q ;
	
	for( int i=0; i<N; i++)  {
		maxP[i] = 1.0*0 ;
		usd[i] = 0 ;
	}
	
	Q.push( par(1.0,ini)  )  ;
	maxP[ini] = 1.0 ;
	
	while( !Q.empty() ) {
		par pos = Q.top() ;
		Q.pop() ;
		if( usd[pos.s]  )
			continue ;
		usd[pos.s] = 1 ;
		
		for( list<par>::iterator it=adj[pos.s].begin(); it!=adj[pos.s].end(); it++ ) {
			if( (*it).s==ini ) {
				res = max( res, pos.f*(*it).f  )  ;
			}
			else {
				Q.push( par(pos.f*(*it).f, (*it).s)   )  ;
			}
		}
	}
}

int main() {
	int E ;
	
	scanf("%d%d", &N, &E ) ;
	for( int i=0; i<E; i++ ) {
		int a, b ;
		double c ;
		scanf("%d%d%lf", &a, &b, &c ) ;
		a--, b-- ;
		adj[a].push_back( par(c,b) ) ;
	}
	
	for( int i=0; i<N; i++ ) {
		busca(i) ;
	}
	
	if( res<0 ) 
		printf("-1\n" ) ;
	else
		printf("%.2lf\n", res ) ;
	
	return 0 ;
}
