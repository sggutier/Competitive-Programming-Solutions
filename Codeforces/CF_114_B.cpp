#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string>
#include <map>
using namespace std ;
#define lim 20

int N ;
map <string,int> M ;
int adj[lim][lim] ;
string S[lim], W[lim] ;

int main() {
	int E ;
	int res=-1, posRes ;
	
	scanf("%d%d", &N, &E ) ;
	for( int i=0; i<N; i++ ) {
		cin >> S[i] ;
		M[S[i]] = i ;
	}
	for( ; E; E-- ) {
		string a, b ;
		cin >> a >> b ;
		adj[ M[b] ][ M[a] ] = 1 ;
		adj[ M[a] ][ M[b] ] = 1 ;
	}
	
	for( int b=0; b<(1<<N); b++  ) {
		int i, j ;
		int rep = 0 ;
		for( i=0; i<N; i++ ) {
			if( !((1<<i)&b)  )
				continue ;
			rep ++ ;
			for( j=i+1; j<N; j++  ) 
				if( adj[i][j] && (1<<j)&b   )
					break ;
			if( j!=N )
				break ;
		}
		if( i!=N )
			continue ;
		if( rep>res ) {
			res = rep ;
			posRes = b ;
		}
	}
	
	printf("%d\n", res ) ;
	res = 0 ;
	for( int i=0; i<N; i++ ) {
		if( (1<<i)&posRes  )
			W[res++] = S[i] ;
	}
	sort( W, W+res ) ;
	for( int i=0; i<res; i++ )
		cout << W[i] << endl ;
	
	return 0 ;
}
