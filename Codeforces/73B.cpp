#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
using namespace std ;
#define lim 100005

struct rcr {
	int pts ;
	string id ;
	rcr() {
	}
	rcr( int a, string w ) {
		a = pts ;
		id = w ;
	}
};

bool men( rcr A, rcr B ) {
	if( A.pts != B.pts  )
		return A.pts > B.pts ;
	return A.id < B.id ;
}

int main() {
	int N ;
	rcr org[lim], cp[lim] ;
	int m ;
	int camb[lim] ;
	bool usd[lim] ;
	rcr yo ;
	
	cin >> N ;
	for( int i=0; i<N; i++ ) {
		cin >> org[i].id >> org[i].pts ;
	}
	cin >> m ;
	for( int i=0; i<N; i++ ) {
		camb[i] = 0 ;
	}
	for( int i=0; i<m; i++ )
		cin >> camb[i] ;
	cin >> yo.id ;	
	sort( camb, camb+N ) ;
	reverse( camb, camb+N ) ;
	
	
	sort( org, org+N, men ) ;
	for( int i=0; i<N; i++ )
		usd[i] = 0 ;
	for( int i=0; i<N; i++ ) {
		cp[i] = org[i] ;
		if( cp[i].id == yo.id ) {
			cp[i].pts += camb[0] ;
			usd[0] = 1 ;
			yo.pts = cp[i].pts ;
		}
	}
	for( int i=0; i<N; i++ ) {
		if( cp[i].id == miId )
			continue ;
		int res = -1 ;
		for( int j=0; j<N; j++ ) {
			if( usd[j] )
				continue ;
			res = j ;
			break ;
		}
		for( int j=0; j<N; j++ ) {
			if( usd[j] )
				continue ;
			if( cp[i].pts+camb[j]<
			break ;
		}
	}
	
		
	return 0 ;
}
