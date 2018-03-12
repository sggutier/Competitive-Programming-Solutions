#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std ;

int N ;
char usd[10] ;

void prueba( int pos, char res[10][10] ) {
	if( pos==N ) {
		for( int i=0; i<N; i++ ) {
			for( int j=0; j<N; j++ )
				printf("%c", res[i][j] ) ;
			printf("\n" ) ;
		}
		printf("\n" ) ;
		return ;
	}
	for( int i=0; i<N; i++  ) {
		if( usd[i] )
			continue ;
		usd[i] = 1 ;
		res[pos][i] = 'T' ;
		prueba( pos+1, res ) ;
		usd[i] = 0 ;
		res[pos][i] = '.' ;
	}
}

void caso() {
	char res[10][10] ;
	int a ;
	
	//a = scanf("%d", &N ) ;
	for( int i=0; i<N; i++ )
		for( int j=0; j<N; j++ )
			res[i][j] = '.' ;
	prueba(0,res) ;
	a = printf("----------\n" ) ;
	
	
}

int main() {
	int w ;
	
	for( w=scanf("%d", &N ); N; w=scanf("%d", &N ) )
		caso() ;
	
	return 0 ;
}
