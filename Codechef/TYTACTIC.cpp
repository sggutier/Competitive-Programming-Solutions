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
#include <stack>
using namespace std ;
const int lim = 100005 ;

int N ;
list <int> adj[lim] ;
int wds[lim], bit[lim*5] ;
int numIni[lim], numFin[lim] ;
stack <int> ultPos ;
stack < list<int>::iterator > ultRam ;
bool usd[lim] ;

void updBit( int pos, int nov ) {
	for( ; pos<lim*2; pos+=(pos & -pos)  )
		bit[pos] += nov ;
}

int qryBit( int pos ) {
	int res = 0 ;
	for( ; pos; pos-=(pos & -pos)  )
		res += bit[pos] ;
	return res ;
}

void numera() {
	int num = 1 ;

	ultPos.push(0) ;
	ultRam.push(adj[0].begin()) ;
	usd[0] = 1 ;

	while( !ultPos.empty() ) {
		int pos = ultPos.top(), sig ;
		list<int>::iterator it = ultRam.top() ;
		ultRam.pop() ;

		if( !numIni[pos] )
			numIni[pos] = num ;
		if( it==adj[pos].end() ) {
			numFin[pos] = num++ ;
			usd[pos] = 0 ;
			ultPos.pop() ;
			continue ;
		}

		sig = *it ;
		it ++ ;
		ultRam.push(it) ;
		if( !usd[sig] ) {
			numFin[pos] = num++ ;
			usd[sig] = 1 ;
			ultPos.push( sig ) ;
			ultRam.push( adj[sig].begin() ) ;
		}

	}
}

int main() {
	int Q ;

	scanf("%d%d", &N, &Q ) ;
	for( int i=0; i<N; i++ ) 
		scanf("%d", &wds[i] ) ;
	for( int i=1; i<N; i++ ) {
		int a, b ;
		scanf("%d%d", &a, &b ) ;
		a--, b-- ;
		adj[a].push_back(b) ;
		adj[b].push_back(a) ;
	}

	numera() ;
	for( int i=0; i<N; i++ ) {
		updBit( numIni[i], wds[i] ) ;
	}

	for( int i=0; i<Q; i++ ) {
		char S[5] ;
		scanf("%s", S ) ;
		if( S[0]=='Q' ) {
			int a ;
			scanf("%d", &a ) ;
			printf("%d\n", qryBit(numFin[a-1]) - qryBit(numIni[a-1]-1)   ) ;
		}
		else {
			int a, b ;
			scanf("%d%d", &a, &b ) ;
			updBit( numIni[a-1], b-wds[a-1] ) ;
			wds[a-1] = b ;
		}
	}

	return 0 ;
}


