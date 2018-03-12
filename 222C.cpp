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
const int lim = 100005 ;

int N, X ;
int A[lim], B[lim] ;

int main() {
	int res = 1 ;

	scanf("%d%d", &N, &X ) ;
	for( int i=0; i<N; i++ ) 
		scanf("%d", &A[i] ) ;
	for( int i=0; i<N; i++ ) 
		scanf("%d", &B[i] ) ;

	sort( A, A+N ) ;
	sort( B, B+N ) ;
	
	for( int i=0; i<N; i++ ) {
		if( A[i]+B[i]>=X ) {
			res = N-i ;
			break ;
		}
	}

	printf("%d %d\n", 1, res ) ;

	return 0 ;
}


