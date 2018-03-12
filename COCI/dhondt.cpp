#include <algorithm>
#include <cstdio>
#include <iostream>
#include <utility>
using namespace std ;
#define lim 30
#define par pair<double,int>
#define f first
#define s second

int X, N, W=0 ;
int rep[lim] ;
par zon[lim*14] ;
pair<int,int> ans[lim] ;

int main() {
	char S[lim] ;

	cin >> X >> N ;
	for( int i=0; i<N; i++ ) {
		int a ;
		cin >> S >> a ;
		if( a*20>=X )
			rep[S[0]-'A'] = a ;
	}
	
	for( int i=0; i<lim; i++ ) {
		if( !rep[i] )
			continue ;
		for( int j=1; j<=14; j++ ) {
			zon[W++] = par( rep[i]/(j*1.0),  i   )  ;
		}
	}
	sort( zon, zon+W ) ;
	
	for( int i=0; i<lim; i++ )
		rep[i] = 0 ;
	for( int i=1; i<=14; i++ ) {
		rep[ zon[W-i].s ] ++ ;
	}
	
	W = 0 ;
	for( int i=0; i<lim; i++ ) {
		if( rep[i] )
			ans[W++] = pair <int,int> ( rep[i], lim-i ) ;
	}	
	sort( ans, ans+W ) ;
	
	for( int i=1; i<=W; i++ ) {
		printf("%c %d\n", lim-ans[W-i].s+'A', ans[W-i].f   ) ;
	}

	return 0 ;
}
