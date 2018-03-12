#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std ;
#define lim 1005

struct targ {
	int x, y ;
	long long t ;
	double p ;
};

bool operator<( targ A, targ B ) {
	return A.t < B.t ;
}

int dis( int x1, int y1, int x2, int y2 ) {
	return (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2) ;
}

int main() {
	int N ;
	targ gal[lim] ;
	double dp[lim] ;
	double res = 1.0 * 0 ;
	int i, j ;
	
	scanf("%d", &N ) ;
	for( i=0; i<N; i++ ) {
		scanf("%d%d%lld%lf", &gal[i].x, &gal[i].y, &gal[i].t, &gal[i].p ) ;
	}
	
	sort( gal, gal+N ) ;
	for( i=0; i<N; i++ ) {
		dp[i] = 1.0*0 ;
		for( j=0; j<i; j++ ) {
			if( dis( gal[i].x, gal[i].y, gal[j].x, gal[j].y ) <=   (gal[i].t-gal[j].t)*(gal[i].t-gal[j].t)    )   
				dp[i] = max( dp[i], dp[j] ) ;
		}
		dp[i] += gal[i].p ;
		res = max( res, dp[i] ) ;
	}
	
	printf("%0.9lf\n", res ) ;
	
	return 0 ;
}
