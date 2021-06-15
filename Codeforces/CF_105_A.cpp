#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <utility>
using namespace std ;
#define par pair<string,int>
#define f first
#define s second
#define lim 1000

int main() {
	int N, M ;
	int K ;
	int R = 0 ;
	par res[lim] ;
	
	scanf("%d %d 0.%d", &N, &M, &K ) ;
	for( int i=0; i<N; i++ ) {
		string a ;
		int b ;
		cin >> a >> b ;
		b = ( b*K )/100 ;
		if( b>=100 ) {
			res[R++] = par( a, b ) ;
		}
	}
	
	for( int i=0; i<M; i++ ) {
		string a ;
		cin >> a ;
		int j ;
		for( j=0; j<R && res[j].f!=a; j++ ) ;
		if( j==R ) 
			res[R++] = par( a, 0 ) ;
	}
	
	sort( res, res+R ) ;
	cout << R << endl ;
	for( int i=0; i<R; i++ ) {
		cout << res[i].f << " " << res[i].s << endl ;
	}
	
	return 0 ;
}
