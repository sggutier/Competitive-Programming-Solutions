#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std ;

int main() {
	int N ;
	char S[1000] ;
	int res  = 0 ;
	
	scanf("%d", &N ) ;
	scanf("%s", S ) ;
	
	res = 1 ;
	for( int i=0; i<N; i++ ) {
		if( S[i]=='L' )
			i ++ ;
		res ++ ;
	}
	
	printf("%d\n", min( res, N )  ) ;
	
	return 0 ;
}
