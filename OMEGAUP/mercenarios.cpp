#include <cstdio>
#include <algorithm>
#include <iostream>
#include <utility>
using namespace std ;
#define par pair<char,int>
#define f first
#define s second
const int lim = 42 ;
const int mit = 25 ;
const int lim2 = lim-mit ;

int N ;
int Q[lim] ;
char adj[lim][lim] ;
long long masc[lim] ;
par dp[lim2][1<<lim2] ;
bool usd[lim2][1<<lim2] ;

par memo( int pos, long long B ) {
	if( pos==N )
		return par( 0LL, 0LL ) ;
	if( usd[pos-mit][B>>mit] )
		return dp[pos-mit][B>>mit] ;
	
	usd[pos-mit][B>>mit] = 1 ;
	
	if( (1LL<<pos) & B ) {
		par a, b ;
		a = memo( pos+1, B ) ;
		b = memo( pos+1, B & masc[pos] ) ;
		b.f ++  ;
		b.s -= Q[pos] ;
		
		return dp[pos-mit][B>>mit] = max( a, b ) ;
	}
	else {		
		return dp[pos-mit][B>>mit] = memo( pos+1, B ) ;
	}
}

par busca( int pos, long long B ) {
	if( pos==N )
		return par( 0LL, 0LL ) ;
	if( pos>=mit )
		return memo( pos,  B  ) ;
	
	if( (1LL<<pos) & B ) {
		par a, b ;
		a = busca( pos+1, B ) ;
		b = busca( pos+1, B & masc[pos] ) ;
		b.f ++  ;
		b.s -= Q[pos] ;
		
		return max( a, b ) ;
	}
	else {	
		return busca( pos+1, B ) ;
	}
}

int main() {
	par res ;
	
	scanf("%d", &N ) ;
	for( int i=0; i<N; i++ ) {
		int M ;
		scanf("%d", &Q[i] );
		scanf("%d", &M ) ;
		for( int j=0; j<M; j++ ) {
			int tmp ;
			scanf("%d", &tmp ) ;
			adj[i][tmp-1] = 1 ;
			adj[tmp-1][i] = 1 ;
		}
	}
	for( int i=0; i<N; i++ ) {
		for( int j=0; j<N; j++ ) {
			if( !adj[i][j] ) 
				masc[i] += (1LL<<j) ;
		}
	}
	
	
	res = busca( 0, (1LL<<N)-1 ) ;
	
	
	printf("%d %d\n", res.f, -res.s ) ;
	
	
	return 0 ;
}
