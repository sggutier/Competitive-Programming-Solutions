#include <stdio.h>
#include <stdlib.h>
const int lim = 100005 ;

void caso( int N ) {
    int *res = malloc( 25*sizeof(int) ) ;
    int tam = 0 ;

    do {
	res[tam++] = N%3 ;
	N /= 3 ;
    }   while( N ) ;

    int i ;
    for( i=tam-1; i>=0; i-- )
	printf("%d", res[i] ) ;
    printf("\n") ;

    free(res) ;
}

int main() {
    int N ;

    while( scanf("%d",&N)!=EOF && N>=0 )
	caso(N) ;
    
    return 0 ;
}
