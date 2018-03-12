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

int N ;
char *S ;
int *tam ;

void caso() {
	char tmp ;

	S = new char[N] ;
	tam = new int[N+1] ;
	scanf("%c", &S[0] ) ;
	for( int i=0; i<N; i++ ) 
		scanf("%c", &S[i] ) ;

	tam[0] = -1 ;
	for( int i=0, j=-1; i<N; i++ ) {
		while( j>=0 && S[i]!=S[j] )
			j = tam[j] ;
		j++ ;
		tam[i+1] = j ;
	}

	scanf("%c", &tmp ) ;
	scanf("%c", &tmp ) ;
	for( int i=0, j=-1; tmp!='\n'; scanf("%c", &tmp ), i++  ) {
		while( j>=0 && tmp!=S[j] )
			j = tam[j] ;
		j ++ ;
		if( j==N ) {
			printf("%d\n", i-N+1 ) ;
			j = tam[j] ;
		}
	}

	delete [] S ;
}

int main() {
	int i = 0 ;

	while( scanf("%d", &N )!=EOF ) {
		if( i )
			printf("\n" ) ;
		caso() ;
		i ++ ;
	}

	return 0 ;
}


