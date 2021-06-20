#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std ;

int main() {
    int T, N, tmp, res ;
    scanf("%d", &T ) ;
    for( int i=0; i<T; i++ ) {
	scanf("%d", &N ) ;
	res = -(1<<30) ;
	for( int i=0; i<N; i++) {
	    scanf("%d", &tmp ) ;
	    res = max( res, tmp ) ;
	}
	printf("Case %d: %d\n", i+1, res ) ;
    }
    return 0 ;
}
