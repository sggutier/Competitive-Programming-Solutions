#include <cstdio>
#include <algorithm>
#include <iostream>
#include <utility>
#include <queue>
#include <string>
#include <cstring>
#include <map>
#include <set>
#include <cmath>
#include <list>
#include <stack>
using namespace std ;
const int lim = 105 ;

int main() {
	int N, M, X, Y ;
	char A[lim], B[lim] ;
	int fin[lim], sta[lim] ;
	int res = 0 ;

	scanf("%d%d%s%s", &X, &Y, A, B ) ;

	N = strlen(A) ;
	M = strlen(B) ;

	for( int i=0; i<M; i++ ) {
		fin[i] = i ;
		for( int j=0; j<N; j++ )  
			if( A[j] == B[fin[i]%M] ) 
				fin[i] ++ ;
		sta[i] = fin[i]/M ;
		fin[i] %= M ;
	}

	for( int i=0, w=0; i<X; i++ ) {
		res += sta[w] ;
		w = fin[w] ;
	}

	printf("%d\n", res/Y ) ;

	return 0 ;
}


