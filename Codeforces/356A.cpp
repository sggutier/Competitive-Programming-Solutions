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
const int lim = 300005 ;
#define par pair<int,int>
#define f first
#define s second

int N, K ;
int res[lim] ;
list <par> pon[lim], quita[lim] ;
set <par> actv ;

int main() {
	scanf("%d%d", &N, &K ) ;
	for( int i=0; i<N; i++ )
		res[i] = -1 ;
	for( int i=0; i<K; i++ ) {
		int a, b, c ;
		scanf("%d%d%d", &a, &b, &c ) ;
		a--, b--, c-- ;
		if( c!=a ) {
			pon[a].push_back( par( i, c ) ) ;
			quita[c].push_back( par( i, c ) ) ;
		}
		if( c!=b ) {
			pon[c+1].push_back( par( i, c ) ) ;
			quita[b+1].push_back( par( i, c ) ) ;
		}
	}

	for( int i=0; i<N; i++ ) {
		for( list<par>::iterator it=pon[i].begin(); it!=pon[i].end(); it++ ) 
			actv.insert(*it) ;
		for( list<par>::iterator it=quita[i].begin(); it!=quita[i].end(); it++ ) 
			actv.erase(*it) ;

		if( !actv.empty() ) 
			res[i] = actv.begin() -> s ;
	}

	for( int i=0; i<N; i++ ) 
		printf("%d ", res[i]+1 ) ;
	printf("\n" ) ;

	return 0 ;
}


