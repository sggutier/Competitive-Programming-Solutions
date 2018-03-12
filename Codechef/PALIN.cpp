#include <algorithm>
#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std ;
#define lim 1000006

int N ;
char S[lim] ;
int arr[lim] ;

void caso() ;

int main() {
	int T ;
	
	for( scanf("%d", &T );  T;  T-- ) 
		caso() ;
	
	return 0 ;
}

void caso() {
	scanf("%s", S ) ;
	N = strlen( S ) ;
	int carg = 1 ;
	
	for( int i=N-1; i>=0; i-- ) {
		arr[N-i-1] = S[i]-'0' + carg ;
		carg = arr[N-i-1]/10 ;
		arr[N-i-1] %= 10 ;
	}
	if( carg )
		arr[N++] = 1 ;
	
	carg = 0 ;
	for( int i=0; i<N/2; i++ ) {
		arr[i] += carg ;
		carg = 0 ;
		
		if( arr[i]>arr[N-i-1] )
			carg = 1 ;
		arr[i] = arr[N-i-1] ;
	}
	
	if( N%2==0 && carg ) {
		arr[N/2] ++ ;
		arr[N/2 -1] ++ ;
		for( int i=N/2-1; arr[i]==10; i-- ) {
			arr[i] = 0 ;
			arr[N-i-1] = 0 ;
			arr[i-1] ++ ;
			arr[N-i] ++ ;
		}
	}
	else if( carg ) {
		arr[N/2] ++ ;
		for( int i=N/2; arr[i]==10; i-- ) {
			arr[i] = 0 ;
			arr[N-i-1] = 0 ;
			arr[i-1] ++ ;
			arr[N-i] ++ ;
		}
	}
	
	for( int i=0; i<N; i++ )
		printf("%d", arr[i] ) ;
	printf("\n" ) ;
}
