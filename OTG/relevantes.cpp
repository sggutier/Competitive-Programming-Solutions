#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std ;
#define lim 1000005
#define inf (1LL<<60)

int N ;
long long alt[lim], rel[lim] ;
long long res[lim] ;
int W ;
long long visA[lim], visR[lim], visO[lim] ;

int main() {
	int i, j ;
	long long mh ;
	
	scanf("%d", &N ) ;
	for( i=0; i<N; i++ ) {
		cin >> alt[i] >> rel[i] ;
		res[i] = rel[i] ;
	}
	
	visA[0] = inf ;
	visO[0] = -inf ;
	visR[0] = -inf ;
	W = 0 ;
	for( i=0; i<N; i++ ) {
		mh = -inf ;
		for( ; visA[W]<alt[i]; W-- ) {
			mh = max( visR[W], mh ) ;
		}
		res[i] = max( res[i], mh ) ;
		res[i] = max( res[i], visO[W] ) ;
		W ++ ;
		visA[W] = alt[i] ;
		visO[W] = rel[i] ;
		visR[W] = max( rel[i], mh )  ;
	}
		
	W = 0 ;
	for( i=N-1; i>=0; i-- ) {
		mh = -inf ;
		for( ; visA[W]<alt[i]; W-- ) {
			mh = max( visR[W], mh ) ;
		}
		res[i] = max( res[i], mh ) ;
		res[i] = max( res[i], visO[W] ) ;
		W ++ ;
		visA[W] = alt[i] ;
		visO[W] = rel[i] ;
		visR[W] = max( rel[i], mh )  ;
	}
	
	for( i=0; i<N; i++ ) {
		cout << res[i] << " " ;
	}
	printf("\n" ) ;
	
	return 0 ;
}
