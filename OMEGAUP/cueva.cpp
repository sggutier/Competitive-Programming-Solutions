#include <cstdio>
#include <algorithm>
#include <iostream>
#include <stack>
#include <list>
using namespace std ;
const int lim = 1000006 ;

int N ;
list <int> adj[lim] ;
int ini[lim], fin[lim] ;
stack <int> ult ;

void marca() {
	int W=1, pos ;
	
	ult.push(0) ;
	while( !ult.empty() ) {
		pos = ult.top() ;
		if( ini[pos] ) {
			fin[pos] = W++ ;
			ult.pop() ;
		}
		else {
			ini[pos] = W++ ;
			for( list<int>::iterator it=adj[pos].begin(); it!=adj[pos].end(); it++ ) 
				if( !ini[*it] ) 
					ult.push(*it) ;
		}
	}
}

int main() {
	int Q ;
	
	scanf("%d%d", &N, &Q ) ;
	for( int i=1; i<N; i++ ) {
		int a, b ;
		scanf("%d%d", &a, &b ) ;
		a--, b-- ;
		adj[a].push_back(b) ;
		adj[b].push_back(a) ;
	}
	
	marca() ;
	
	for( int i=0; i<Q; i++ ) {
		int a, b ;
		scanf("%d%d", &a, &b ) ;
		a--, b-- ;
		
		if(ini[a]<=ini[b] && ini[b]<=fin[a]) 
			printf("0\n" ) ;
		else
			printf("1\n" ) ;
	}
	
	return 0 ;
}
