#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std ;

int main() {
	int N ;
	char S[] = "RGBYIOV" ;
	int i ;
	
	scanf("%d",&N ) ;
	for( i=0; i<3; i++ )
		printf("%c",S[i+4] ) ;
	N -= 3 ;
	for( i=0; i<N; i++ )
		printf("%c",S[i%4] ) ;
	printf("\n");
	
	return 0 ;
}
