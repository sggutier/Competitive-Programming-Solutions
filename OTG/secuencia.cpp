#include <algorithm>
#include <iostream>
#include <cstdio>
using namespace std ;
#define lim 30005
#define inf (1<<30)

int main() {
	int N ;
	int arr[lim] ;
	int sumL[lim], minSL[lim], maxSL[lim] ;
	int sumR[lim], minSR[lim], maxSR[lim] ;
	int i ;
	int res = inf, posRes ;
	int a, b ;
	
	
	scanf("%d", &N ) ;
	for( i=0; i<N; i++ ) {
		scanf("%d", &arr[i] ) ;
	}
	
	for( i=0; i<N; i++ ) {
		sumL[i] = arr[i] ;
		if( i ) {
			sumL[i] += sumL[i-1] ;
		}
		minSL[i] = min( sumL[i], 0 ) ;
		maxSL[i] = max( sumL[i], 0 ) ;
		if( i ) {
			minSL[i] = min( minSL[i], minSL[i-1]  )  ;
			maxSL[i] = max( maxSL[i], maxSL[i-1]  )  ;
		}
	}
	for( i=N-1; i>=0; i-- ) {
		sumR[i] = arr[i] ;
		if( i+1<N ) {
			sumR[i] += sumR[i+1] ;
		}
		minSR[i] = min( sumR[i], 0 ) ;
		maxSR[i] = max( sumR[i], 0 ) ;
		if( i+1<N ) {
			minSR[i] = min( minSR[i], minSR[i+1]  )  ;
			maxSR[i] = max( maxSR[i], maxSR[i+1]  )  ;
		}
	}
	
	for( i=0; i<N; i++ ) {
		
		
		a = arr[i] ;
		b = arr[i] ;
		if( i+1<N ) {
			a = max( a, sumR[i] - minSR[i+1] ) ;
			b = min( b, sumR[i] - maxSR[i+1] ) ;
		}
		if( i ) {
			a = max( a, sumR[i] + maxSL[i-1] ) ;
			b = min( b, sumR[i] + minSL[i-1] ) ;
		}
		
		if( abs(a+b) < res  )  {
			res = abs( a+b ) ;
			posRes = i ;
		}
		
	}
	
	
	printf("%d\n", posRes+1 ) ;
	
	return 0 ;
}
