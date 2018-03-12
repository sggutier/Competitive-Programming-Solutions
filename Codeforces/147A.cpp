#include <algorithm>
#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std ;
#define lim 100005

int main() {
	char S[lim] ;
	bool a=0, b=0 ;
	int N ;
	
	gets(S) ;
	N = strlen(S) ;
	
	for( int i=0; i<N; i++ ) {
		if( S[i]==' ' ) {
			a = 1 ;
			continue ;
		}
		if( S[i]>='a' && S[i]<='z' ) {
			if( a && b )
				printf(" ") ;
			a = 0 ;
			b = 1 ;
			printf("%c", S[i] ) ;
		}
		else {
			printf("%c ", S[i] ) ;
			b = 0 ;
		}
	}
	printf("\n" ) ;
	
	return 0 ;
}
