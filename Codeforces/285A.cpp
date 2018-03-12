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
	int N, K ;

	scanf("%d%d", &N, &K ) ;

	for( int i=1; N-K>i; i++ ) {
		printf("%d ", i ) ;
	}
	for( int i=0; i<=K; i++ ) {
		printf("%d ", (K-i)+N-K ) ;
	}
	printf("\n" ) ;


	return 0 ;
}


