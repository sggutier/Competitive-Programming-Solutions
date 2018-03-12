#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std ;

int main() {
	long long N, M ;
	int V ;
	int i, j ;
	
	cin >> N >> M >> V ;
	
	if( M> ((N-1LL)*(N-2LL))/2LL+1LL || M<N-1LL ) {
		printf("-1\n" ) ;
		return 0 ;
	}
	
	if( V==N ) 
		printf("%d %d\n", 1, int (N) ) ;
	else
		printf("%d %d\n", V, int (N) ) ;
	M -- ;
	for( i=1; i<N && M; i++ ) {
		for( j=i+1; j<N && M; j++, M-- ) {
			if( i==1 )
				printf("%d ", V ) ;
			else if( i==V )
				printf("%d ", 1 ) ;
			else
				printf("%d ", i ) ;
				
			if( j==V )
				printf("%d\n", 1 ) ;
			else
				printf("%d\n", j ) ;
		}
	}
	
	return 0 ;
}
