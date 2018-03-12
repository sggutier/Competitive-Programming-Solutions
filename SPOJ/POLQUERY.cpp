#include <algorithm>
#include <cstdio>
#include <iostream>
#include <list>
#include <map>
#include <utility>
#include <stack>
#include <cmath>
using namespace std ;
#define par pair<int,int>
#define f first
#define s second
#define lim 200005
typedef list<int>::iterator ITO;

int N, R, S ;
list<int> adj[lim],  dir[lim]  ;
map<int,int> uni[lim] ;
int prof[lim], O[lim*2] ;
par L[lim*2], seg[lim*2] ;
bool art[lim] ;

int dfs( int pos, int p, int ant ) {
	if( prof[pos] ) {
		return prof[pos] ;
	}
	if( ant>0 ) 
		dir[ant].push_back(pos) ;
	prof[pos] = p ;
	for( ITO it=adj[pos].begin(); it!=adj[pos].end(); it++ ) {
		if( *it!=ant ) 
			prof[pos] = min( prof[pos], dfs(*it,p+1,pos)   ) ;
	}
	if( prof[pos]==p ) {
		prof[pos] = -1 ;
		art[pos] = 1 ;
	}
	return prof[pos] ;
}

void parte() {
	S = int(sqrt(R)) ;
	for( int i=0; i<R; i++ ) 
		seg[i/S] = min( seg[i/S], L[i] ) ;
}

int lco( int a, int b ) {
	a = O[a] ;
	b = O[b] ;
	par res ;
	res.f = (1<<30) ;
	for( ; a%S; a++ ) 
		res = min( res, L[a] ) ;
	for( ; (b+1)%S && b>=0; b-- ) 
		res = min( res, L[b] ) ;
	for( ; a<b; a+=S ) 
		res = min( res, seg[a/S] ) ;
	return res.s ;
}

void genlco(int M) {
	int pos=0, p=0 ;
	stack <int> Q ;
	R = 0 ;	
	for( int i=0; i<M; i++ ) 
		O[i] = (1<<30) ;
	
	Q.push(0) ;
	while( !Q.empty()  )  {
		pos = Q.top() ;
		Q.pop() ;		
		if( R<O[pos] ) {
			p ++ ;
			O[pos] = R ;
			for( ITO it=dir[pos].begin(); it!=dir[pos].end(); it++ ) {
				Q.push(pos) ;
				Q.push(*it) ;
			}
		}
		else {
			p -- ;
		}		
		L[R] = par( p, pos ) ;
		seg[R].f = (1<<30) ;
		R ++ ;
	}
}

int main() {
	int E, T ;
	
	scanf("%d%d", &N, &E ) ;
	for( int i=0; i<E; i++ ) {
		int a, b ;
		scanf("%d%d", &a, &b ) ;
		a--, b-- ;
		
		adj[a].push_back( i+N ) ;
		uni[a][b] = i+N ;		
		adj[b].push_back( i+N ) ;
		uni[b][a] = i+N ;		
		adj[i+N].push_back( b ) ;
		adj[i+N].push_back( a ) ;
	}
	
	
	return 0 ;
}
