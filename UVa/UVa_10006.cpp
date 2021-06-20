#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std ;

int R  ;
int res[] = { 561, 1105, 1729, 2465, 2821, 6601, 8911, 10585, 15841, 29341, 41041, 46657, 52633, 62745, 63973 } ;

int main() {
    int N ;
    int ini, fin, piv ;
    R = sizeof(res)/sizeof(int) ;

    while( scanf("%d",&N)!=EOF && N ) {
	int ini=0, fin=R-1, piv ;
	while( ini<fin ) {
	    piv = (ini+fin)/2 ;
	    if( res[piv]>=N )
		fin = piv ;
	    else
		ini = piv+1 ;
	}
	if( N==res[ini] )
	    printf("The number %d is a Carmichael number.\n", N ) ;
	else
	    printf("%d is normal.\n", N ) ;
    }
    
    return 0 ;
}
