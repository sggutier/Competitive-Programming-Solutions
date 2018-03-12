#include <cstdio>
#include <algorithm>
#include <iostream>
#include <utility>
#include <queue>
#include <string>
#include <cstring>
#include <map>
#include <set>
#include <cmath>
#include <list>
#include <stack>
using namespace std ;
#define par pair<int,int>
#define f first
#define s second
const int lim = 106 ;

int N, M ;
int alt[lim][lim] ;
int maxR[lim], maxC[lim] ;
int minR[lim], minC[lim] ;
bool usd[lim][lim], usdR[lim], usdC[lim] ;

void caso() {
	int x=-1, t ;
	int W = 0 ;

	scanf("%d%d", &N, &M ) ;
	for( int i=0; i<lim; i++ ) {
		maxR[i] = maxC[i] = -(1<<30) ;
		minR[i] = minC[i] =  (1<<30) ;
		usdR[i] = usdC[i] = 0 ;
	}
	for( int i=0; i<N; i++ ) {
		for( int j=0; j<M; j++ ) {
			scanf("%d", &alt[i][j] ) ;
			usd[i][j] = 0 ;
			maxR[i] = max( maxR[i], alt[i][j] ) ;
			maxC[j] = max( maxC[j], alt[i][j] ) ;
			minR[i] = min( minR[i], alt[i][j] ) ;
			minC[j] = min( minC[j], alt[i][j] ) ;
		}
	}

	for( int i=0; i<N; i++ ) {
		if( minR[i]==maxR[i] ) {
			x = i ;
			t = 0 ;
		}
	}
	for( int i=0; i<M; i++ ) {
		if( minC[i]==maxC[i] ) {
			x = i ;
			t = 1 ;
		}
	}

	while( x!=-1 ) {

		if( t==0 ) {
			usdR[x] = 1 ;
			for( int i=0; i<M; i++ )  {
				alt[x][i] = maxC[i] ;
				usd[x][i] = 1 ;
			}
		}
		else {
			usdC[x] = 1 ;
			for( int i=0; i<N; i++ )  {
				alt[i][x] = maxR[i] ;
				usd[i][x] = 1 ;
			}
		}
		x = -1 ;

		for( int i=0; i<lim; i++ ) {
			maxR[i] = maxC[i] = -(1<<30) ;
			minR[i] = minC[i] =  (1<<30) ;
		}
		for( int i=0; i<N; i++ ) {
			for( int j=0; j<M; j++ ) {
				maxR[i] = max( maxR[i], alt[i][j] ) ;
				maxC[j] = max( maxC[j], alt[i][j] ) ;
				minR[i] = min( minR[i], alt[i][j] ) ;
				minC[j] = min( minC[j], alt[i][j] ) ;
			}
		}

		for( int i=0; i<N; i++ ) {
			if( minR[i]==maxR[i] && !usdR[i] ) {
				x = i ;
				t = 0 ;
			}
		}
		for( int i=0; i<M; i++ ) {
			if( minC[i]==maxC[i] && !usdC[i] ) {
				x = i ;
				t = 1 ;
			}
		}
	}

	for( int i=0; i<N; i++ ) {
		for( int j=0; j<M; j++ )  {
			if( !usd[i][j] ) {
				printf("NO\n" ) ;
				return ;
			}
		}
	}

	printf("YES\n" ) ;
}

int main() {
	int T ;

	scanf("%d", &T ) ;
	for( int i=1; i<=T; i++ ) {
		printf("Case #%d: ", i ) ;
		caso() ;
	}

	return 0 ;
}


