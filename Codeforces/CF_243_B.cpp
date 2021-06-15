#include <cstdio>
#include <algorithm>
#include <queue>
#include <iostream>
#include <map>
#include <set>
#include <cmath>
#include <string>
#include <cstring>
#include <list>
using namespace std ;
const int lim = 100005 ;

int N, E, reqH, reqT ;
list <int> adj[lim] ;
bool usd[lim] ;
int resA=-1, resB=-1 ;

void checa( int nod ) {
	for( list<int>::iterator it=adj[nod].begin();  it!=adj[nod].end();   it++   ) 
		usd[*it] = 1 ;



	for( list<int>::iterator it=adj[nod].begin();  it!=adj[nod].end();   it++   ) 
		usd[*it] = 0 ;
}

int main() {
	scanf("%d%d%d%d", &N, &E, &reqH, &reqT ) ;
	for( int i=0; i<E; i++ ) {
		int a, b ;
		scanf("%d%d", &a, &b ) ;
		a--, b-- ;
		adj[a].push_back( b ) ;
		adj[b].push_back( a ) ;
	}

	for( int i=0; i<N; i++ ) {
		checa( i ) ;
	}

	if( resA==-1 ) {
		printf("NO\n" ) ;
		return 0 ;
	}

	printf("YES\n" ) ;
	printf( "%d%d", &a, &b ) ;
	for( list<int>::iterator it=adj[reqH].begin();  it!=adj[reqH].end();   it++   ) 
		printf("%d ", *it ) ;
	printf("\n" ) ;
	for( list<int>::iterator it=adj[reqT].begin();  it!=adj[reqT].end();   it++   ) 
		printf("%d ", *it ) ;
	printf("\n" ) ;

	return 0 ;
}


