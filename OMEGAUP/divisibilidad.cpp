#include <cstdio>
#include <algorithm>
#include <iostream>
#include <utility>
#include <queue>
#include <string>
#include <cstring>
using namespace std ;

int main() {
	int N, P ;
	int ult = 1, a, b ;
	int res[100] ;

	scanf( "%d%d", &N, &P ) ;

	res[0] = 1 ;
	if( P>10 ) {
		a = P/10 ;
		b = P%10 ;
	}
	else {
		int tmp = (19/P)*P ;
		a = tmp/10 ;
		b = tmp%10 ;
	}

	for( int i=1; i<N; i++ ) {
		for( int j=P-1; j>=0; j-- ) {
			if( (a*j + b*ult)%P==0 ) {
				ult = j ;
				break ;
			}
		}
		res[i] = ult ;
	}

	for( int i=N-1; i>=0; i-- )
		printf("%d ", res[i] ) ;
	printf("\n" ) ;

	return 0 ;
}
