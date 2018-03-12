#include <algorithm>
#include <iostream>
#include <cstdio>
#include <stack>
using namespace std ;
#define lim 500005

int N, K ;
int elim[lim] ;
char arr[lim] ;
stack <int> Q ;

int main() {
	scanf("%d%d", &N, &K ) ;
	scanf("%s", arr ) ;
		
	for( int i=0; i<N && K; i++ ) {
		while( !Q.empty() && arr[Q.top()]<arr[i] && K ) {
			K -- ;
			elim[Q.top()] = 1 ;
			Q.pop() ;
		}
		Q.push( i ) ;
	}
	for( int i=N-1; i>=0 && K; i-- ) {
		if( !elim[i] ) {
			elim[i] = 1 ;
			K -- ;
		}
	}
	
	for( int i=0; i<N; i++ ) {
		if( !elim[i] )
			printf("%c", arr[i] ) ;
	}
	printf("\n" ) ;
	
	return 0 ;
}


