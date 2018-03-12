#include <cstdio>
#include <iostream>
#include <algorithm>
#include <utility>
#include <list>
using namespace std ;
typedef pair<int,int> par ;
#define f first
#define s second
const int lim = 200 ;

int N, Q ;
int res = 0 ;
int sPos[lim], iPos[lim] ;
int sNum[lim], iNum[lim] ;
list <int> posVal[lim] ;
int aRes[lim] ;
bool usd[lim] ;
par arr[lim] ;

void busca( int i ) {
	if( i==N ) {
		res = 1 ;
		for( int i=0; i<N; i++ )
			printf("%d ", aRes[i]+1 ) ;
		printf("\n" ) ;
		return ;
	}
	
	int pos = arr[i].s ;
	for( list<int>::iterator it=posVal[pos].begin(); it!=posVal[pos].end() && !res; it++ ) {
		if( usd[*it] )
			continue ;
		usd[*it] = 1 ;
		aRes[*it] = pos ;
		busca( i+1 ) ;
		usd[*it] = 0 ;
	}
}

int main() {
	scanf("%d%d", &N, &Q ) ;
	
	for( int i=0; i<N; i++ ) {
		sPos[i] = N-1 ;
		iPos[i] = 0 ;
		sNum[i] = N-1 ;
		iNum[i] = 0 ;
	}
	
	for( int i=0; i<Q; i++ ) {
		int t, x, y, v ;
		scanf("%d%d%d%d", &t, &x, &y, &v ) ;
		v -- ;
		x--, y-- ;
		sNum[v] = min( sNum[v], y ) ;
		iNum[v] = max( iNum[v], x ) ;
		if( t==1 ) {
			for( int j=x; j<=y; j++ ) 
				sPos[j] = min( sPos[j], v ) ;
		}
		else {
			for( int j=x; j<=y; j++ ) 
				iPos[j] = max( iPos[j], v ) ;
		}
	}
	
	for( int i=0; i<N; i++ ) {
		for( int j=iPos[i]; j<=sPos[i]; j++ ) {
			if(  iNum[j]<=i && i<=sNum[j] )
				posVal[j].push_back(i) ;
		}
	}
	
	for( int i=0; i<N; i++ ) {
		arr[i] = par( posVal[i].size(), i ) ;
	}
	sort( arr, arr+N ) ;
	
	busca( 0 ) ;
	
	if( res==0 ) {
		printf("-1\n" ) ;
	}
	
	return 0 ;
}
