#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std ;

int main() {
	int N ;
	int minC=(1<<30), maxC=-(1<<30) ;
	int act, res=0 ;
	
	scanf("%d%d", &N, &act ) ;
	minC = act ;
	maxC = act ;
	for( int i=1; i<N; i++ ) {
		scanf("%d", &act ) ;
		if( act<minC ) {
			res ++ ;
			minC = act ;
		}
		if( act>maxC ) {
			res ++ ;
			maxC = act ;
		}
	}
	
	printf("%d\n", res ) ;
	
	return 0 ;
}
