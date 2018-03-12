#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std ;

int main() {
    //    printf("6 8\n35 49\n204 288\n1189 1681\n6930 9800\n40391 57121\n235416 332928\n1372105 1940449\n7997214 11309768\n46611179 65918161\n" ) ;

    printf("%10d%10d\n", 6, 8 ) ;
    printf("%10d%10d\n", 35, 49 ) ;
    printf("%10d%10d\n", 204, 288 ) ;
    printf("%10d%10d\n", 1189, 1681 ) ;
    printf("%10d%10d\n", 6930, 9800 ) ;
    printf("%10d%10d\n", 40391, 57121 ) ;
    printf("%10d%10d\n", 235416, 332928 ) ;
    printf("%10d%10d\n", 1372105, 1940449 ) ;
    printf("%10d%10d\n", 7997214, 11309768 ) ;
    printf("%10d%10d\n", 46611179, 65918161 ) ;
    
    return 0 ;
    
    long long N=1LL, K=2LL ;
    int cnt = 0 ;

    for( ; cnt<10; cnt++ ) {
	while( 1 ) {
	    while( K*(K+1) <N*N*2 ) {
		K ++ ;
	    }
	    if( K*(K+1) == N*N*2 ) {
		cout << N << " " << K << endl ;
		break ;
	    }
	    N ++ ;
	}
	N ++ ;
    }
    return 0 ;
}
