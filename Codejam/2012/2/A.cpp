#include <algorithm>
#include <cstdio>
#include <iostream>
#include <utility>
using namespace std ;
#define lim 10005
#define par pair<int,int>
#define f first
#define s second

int N, W ;
par lia[lim] ;
int dp[lim] ;

bool caso() {
	scanf("%d", &N ) ;
	for( int i=0; i<N; i++ ) { 
		scanf("%d%d", &lia[i].f, &lia[i].s ) ;
		dp[i] = 0 ;
	}
	dp[N] = 0 ;
	scanf("%d", &W ) ;
	lia[N++] = par( W, 1<<30 ) ;
	
	sort( lia, lia+N ) ;
	dp[0] = lia[0].f ;
	for( int i=0; i<N; i++ ) {
		for( int j=i+1; j<N; j++ ) {
			if( lia[j].f-lia[i].f<=dp[i] ) {
				dp[j] = max( dp[j], min(lia[j].f-lia[i].f,lia[j].s)   ) ;
			}
		}
	}
	
	for( int i=0; i<N; i++ ) {
		if( lia[i].f==W ) 
			return dp[i]!=0 ;
	}
	
	return 0 ;
}

int main() {
	int T ;
	
	scanf("%d", &T ) ;
	for( int i=1; i<=T; i++ ) {
		printf("Case #%d: ", i ) ;
		if( caso() )
			printf("YES\n" ) ;
		else
			printf("NO\n" ) ;
	}
}
