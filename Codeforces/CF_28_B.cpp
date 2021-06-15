#include <iostream>
#include <algorithm>
#include <cstdio>
#include <list>
#include <queue>
using namespace std ;
#define lim 105

list <int> adj[lim] ;
int ant[lim][lim] ;

void amp( int ini ) {
	int pos, pos2 ;
	queue <int> Q ;
	list <int> :: iterator it ;
	
	Q.push( ini ) ;
	ant[ini][ini] = -1 ;
	while( !Q.empty() ) {
		pos = Q.front()  ;
		Q.pop() ;
		for( it=adj[pos].begin(); it!=adj[pos].end(); it++ ) {
			if( ant[ini][*it] != -2 )
				continue ;
			ant[ini][*it] = pos ;
			Q.push( *it ) ;
		}
	}
}

int main() {
	int N ;
	int arr[lim] ;
	int tmp ;
	int i, j ;
	
	scanf("%d",&N ) ;
	for( i=0; i<N; i++ ) {
		scanf("%d",&arr[i] ) ;
		arr[i] -- ;
		for( j=0; j<N; j++  )
			ant[i][j] = -2 ;
	}
	for( i=0; i<N; i++ ) {
		scanf("%d", &tmp ) ;
		if( i-tmp>=0 ) {
			adj[i].push_back(i-tmp) ;
			adj[i-tmp].push_back(i) ;
		}
		if( i+tmp<N ) {
			adj[i].push_back(i+tmp) ;
			adj[tmp+i].push_back(i) ;
		}
	}
	
	for( i=0; i<N; i++ ) 
		amp(i) ;
	for( i=0; i<N; i++ ) {
		
		for( j=0; arr[j] != i; j++ ) ;
		if( ant[i][j] == -2 )  {
			cout << "NO" << endl ;
			return 0 ;
		}
		while( ant[i][j] != -1 ) {
			swap( arr[j], arr[ ant[i][j]  ]   )  ;
			j = ant[i][j] ;
		}
	}
	
	cout << "YES" << endl ;
	
	return 0 ;
}
