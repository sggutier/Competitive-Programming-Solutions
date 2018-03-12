#include <cstdio>
#include <stack>
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
const int lim4 = 4005 ;
const int lim = 1005 ;

int n, n2, n3, n4 ;
bool arr[lim][lim] ;
bool adj[lim4][lim4], usd[lim4] ;
int col[lim4], prof[lim4] ;
list <int> crg[lim4], ver, hor ;
stack <int> S ;
int id ;

void tarjan( int pos ) {
	col[pos] = prof[pos] = id++ ;
	S.push(pos) ;
	usd[pos] = 1 ;

	for( int i=0; i<n4; i++ ) {
		if( adj[pos][i] ) {
			if( !col[i] ) {
				tarjan(i) ;
				prof[pos] = min( prof[pos], prof[i] ) ;
			}
			else if( usd[i] ) {
				prof[pos] = min( prof[pos], col[i] ) ;
			}
		}
	}

	if( prof[pos]!=col[pos] )
		return ;

	while( S.top()!=pos ) {
		usd[S.top()] = 0 ;
		if( S.top()>=n2 ) {
			crg[pos].push_back( S.top() ) ;
			prof[S.top()] = prof[pos] ;
		}
		S.pop() ;	
	}
	usd[pos] = 0 ;
	if( pos>=n2 ) {
		crg[pos].push_back( pos ) ;
	}
	S.pop() ;
}

void caso() {
	int tmp ;
	int res = 0 ;

	id = 1 ;
	memset( adj, 0, sizeof(adj) ) ;
	memset( usd, 0, sizeof(usd) ) ;
	memset( col, 0, sizeof(col) ) ;
	memset( prof, 0, sizeof(prof) ) ;
	for( int i=0; i<lim4; i++ ) 
		crg[i].clear() ;
	hor.clear() ;
	ver.clear() ;

	scanf("%d", &n ) ;
	n2 = n*2 ;
	n3 = n*3 ;
	n4 = n*4 ;
	for( int i=0; i<n; i++ ) {
		for( int j=0; j<n; j++ ) {
			scanf("%d", &tmp ) ;
			arr[i][j] = (tmp==1) ;
		}
	}
	for( int i=0; i<n; i++ ) {
		for( int j=0; j<n; j++ ) {
			scanf("%d", &tmp ) ;
			if( tmp==arr[i][j] ) {
				adj[i+ 0][j+n ] = 1 ;
				adj[i+n2][j+n3] = 1 ;
				adj[j+n ][i+ 0] = 1 ;
				adj[j+n3][i+n2] = 1 ;
			}
			else {
				adj[i+ 0][j+n3] = 1 ;
				adj[i+n2][j+n ] = 1 ;
				adj[j+n3][i+ 0] = 1 ;
				adj[j+n ][i+n2] = 1 ;
			}
		}
	}

	for( int i=0; i<n2; i++ ) {
		if( !col[i] ) 
			tarjan(i) ;
		if( !col[i+n2] )
			tarjan(i+n2) ;
		if( prof[i]==prof[i+n2] ) {
			printf("-1\n" ) ;
			return ;
		}
		if( crg[i].size()<=crg[i+n2].size() ) {
			for( list<int>::iterator it=crg[i].begin(); it!=crg[i].end(); it++ ) {
				if( *it<n3 )
					hor.push_back(*it-n2) ;
				else
					ver.push_back(*it-n3) ;
			}
		}
		else {
			for( list<int>::iterator it=crg[i+n2].begin(); it!=crg[i+n2].end(); it++ ) {
				if( *it<n3 )
					hor.push_back(*it-n2) ;
				else
					ver.push_back(*it-n3) ;
			}
		}
	}

	printf("%d\n", hor.size() ) ;
	for( list<int>::iterator it=hor.begin(); it!=hor.end(); it++ ) 
		printf("%d ", *it ) ;
	printf("\n" ) ;
	printf("%d\n", ver.size() ) ;
	for( list<int>::iterator it=ver.begin(); it!=ver.end(); it++ ) 
		printf("%d ", *it ) ;
	printf("\n" ) ;
}

int main() {
	int T ;

	scanf("%d", &T ) ;
	for( int i=0; i<T; i++ ) 
		caso() ;

	return 0 ;
}


