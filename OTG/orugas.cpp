#include <iostream>
#include <algorithm>
#include <cstdio>
#include <utility>
#include <list>
using namespace std ;
#define lim 1000005


list <int> adj[lim] ;
int id[lim] ;
int cad[lim] ;
int usd[lim] ;


int main() {
	int N, C=0 ;
	int i, j ;
	list <int> :: iterator it, it2 ;
	int a, b ;
	int tam = 0 ;
	int pos, dir=-1 ;
	
	
	scanf( "%d", &N ) ;
	for( i=1; i<N; i++ ) {
		scanf("%d%d", &a, &b ) ;
		a--, b-- ;
		adj[a].push_back( b ) ;
		adj[b].push_back( a ) ;
		id[i] = -1 ;
	}
	id[0] = -1 ;
	
	if( N==2 ) {
		printf("2 1 2\n1 2\n" ) ;
		return 0 ;
	}
	
	b = 0 ;
	for( i=0; i<N; i++ ) {
		if( adj[i].size() > 1 ) {
			a = 0 ;
			b ++ ;
			for( it=adj[i].begin(); it!=adj[i].end(); it ++ )  {
				if(   adj[*it	].size()!=1   )  
					a ++ ;
			}
			if( a==1  ) 
				break ;
		}
	}
	
	
	pos = i%=N ;
	a = 1 ;
	b = N ;
	dir = -1 ;	
	for( it=adj[pos].begin(); it!=adj[pos].end(); it++ ) {
		if( id[*it] != -1 ) 
			continue ;
		if( adj[*it].size() == 1  ) {
			cad[C++] = (*it)+1 ;
			break ;
		}
	}
	while( pos!=-1 ) {
		cad[C++] = pos+1 ;
		
		id[pos] = a ;
		for( it=adj[pos].begin(); it!=adj[pos].end(); it++ ) {
			if( id[*it] != -1 ) 
				continue ;
			if( adj[*it].size() == 1  ) {
				id[*it] = b ;
				b += dir ;
			}
			else 
				it2 = it ;
		}
		
		swap( a, b ) ;
		dir *= -1 ;
		b += dir ;	
		
		if( (*it2)  !=  pos  )
			pos = (*it2) ;
		else 
			pos = -1 ;
	}
	pos = cad[C-1]-1 ;
	for( it=adj[pos].begin(); it!=adj[pos].end(); it++ ) {
		if( adj[*it].size() == 1  ) {
			cad[C++] = (*it)+1 ;
			break ;
		}
	}
	
	for( i=0; i<N; i++ ) {
		for( it=adj[i].begin(); it!=adj[i].end(); it ++ )  {
			usd[ abs(  id[*it]-id[i]   )   ] ++ ;
		}
	}
	
	printf("%d", C ) ;
	for( i=0; i<C; i++ ) 
		printf(" %d", cad[i] ) ;
	printf("\n" ) ;
	for( i=0; i<N; i++ ) {
		printf("%d ", id[i] ) ;
	}
	printf("\n" ) ;
	
	return 0 ;
}
