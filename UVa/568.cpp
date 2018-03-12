#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std ;

const int lim = 10005 ;
int fct[lim] ;

int main() {
    fct[0] = 1 ;
    for( int i=1; i<lim; i++ ) {
	fct[i] = fct[i-1]*i ;
	while( fct[i]%10==0 ) 
	    fct[i] /= 10 ;
	fct[i] = fct[i]%100000 ;
	// printf("%d - %d\n", i, fct[i] ) ;
    }

    int N ;
    while( scanf("%d",&N)!=EOF ) {
	printf("%5d -> %d\n", N, fct[N]%10 ) ;
    }
    
    return 0 ;
}
