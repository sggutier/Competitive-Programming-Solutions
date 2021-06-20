#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std ;

long long mod = 3000000000LL ;
long long trian[101][101] ;

int main() {
    for( int i=0; i<101; i++ ) {
	trian[i][0] = trian[i][i] = 1LL ;
	for( int j=1; j<i; j++ )
	    trian[i][j] = (trian[i-1][j] + trian[i-1][j-1])%mod ;
    }
    int A, B ;

    while( scanf("%d%d", &A, &B) != EOF && (A||B) ) {
	printf("%d things taken %d at a time is %lld exactly.\n", A, B, trian[A][B] ) ;
    }
    
    return 0 ;
}
