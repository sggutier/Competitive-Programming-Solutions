#include <cstdio>
#include <algorithm>
#include <queue>
#include <iostream>
#include <map>
#include <set>
#include <cmath>
#include <string>
#include <cstring>
#include <list>
using namespace std ;

int main() {
	int T ;
	int N, K ;

	scanf("%d", &T ) ;
	for( int i=0; i<T; i++ ) {
		scanf("%d%d", &N, &K ) ;
		int res ;
		if( N%2 )
			res = (N+1)*(N-1) + 2 ;
		else
			res = (N+1)*(N+1) - (N+1) ;
		res = res/2 +N+1 ;
		printf("%s\n", (res>=K)? "Yes":"No" ) ;
	}

	return 0 ;
}


