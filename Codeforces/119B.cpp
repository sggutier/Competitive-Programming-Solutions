#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std ;
#define lim 103

int main() {
	int N, K, W=0, Q, K2 ;
	int arr[lim], cpy[lim], usd[lim] ;
	double resMin=(1<<30)*1.0, resMax=-resMin ;
	
	scanf("%d%d", &N, &K ) ;
	for( int i=0; i<N; i++ ) {
		scanf("%d", &arr[i] ) ;
		usd[i] = 0 ;
	}
	K2 = K ;
	K = N/K ;
	
	scanf("%d", &Q ) ;
	for( int i=0; i<Q; i++ ) {
		int a ;
		double sum=1.0*0 ;
		for( int j=0; j<K; j++ ) {
			scanf("%d", &a ) ;
			sum += arr[a-1] ;
			usd[a-1] = 1 ;
		}
		sum /= K*1.0 ;
		resMin = min( resMin, sum ) ;
		resMax = max( resMax, sum ) ;
	}
	
	for( int i=0; i<N; i++ ) {
		if( !usd[i] ) {
			cpy[W++] = arr[i] ;
		}
	}
	
	sort( cpy, cpy+W ) ;
	if( W>=K && N%K2<W ) {
		double x = 1.0*0, y = 1.0*0 ;
		for( int i=0; i<K; i++ ) {
			x += cpy[i] ;
			y += cpy[W-i-1] ;
		}
		resMin = min( resMin, x/(K*1.0)  ) ;
		resMax = max( resMax, y/(K*1.0)  ) ;
	}
	
	printf("%.6lf %.6lf\n", resMin, resMax ) ;
	
	return 0 ;
}
