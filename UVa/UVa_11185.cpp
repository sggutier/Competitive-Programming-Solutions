#include <cstdio>
#include <algorithm>
#include <iostream>
#include <utility>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <cmath>
#include <string>
#include <cstring>
#include <vector>
#include <list>
#include <cstdlib>
using namespace std ;
const int lim = 100 ;

void caso( int N ) {
    int *res = (int*) malloc( 25*sizeof(int) ) ;
    int tam = 0 ;

    int **matro = (int**) malloc( lim*sizeof( int* ) ) ;
    for( int i=0; i<lim; i++ )
	matro[i] = (int*) malloc( lim*sizeof(int) ) ;

    do {
	res[tam++] = N%3 ;
	N /= 3 ;
    }   while( N ) ;

    for( int i=tam-1; i>=0; i-- )
	printf("%d", res[i] ) ;
    printf("\n") ;

    free(res) ;
    for( int i=0; i<N; i++ )
	free( matro[i] ) ;
    free( matro) ;
}

int main() {
    int N ;

    while( scanf("%d",&N)!=EOF and N>=0 )
	caso(N) ;
    
    return 0 ;
}
