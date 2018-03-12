#include <cstdio>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cctype>
#include <string>
#include <vector>
#include <utility>
#include <map>
#include <set>
#include <stack>
#include <queue>
using namespace std ;

int main() {
    int ult=0, N, Q ;
    int K = 4 ;
    char filNam[100000], comnd[100000] ;
    int tG = 1 ;
    int W = 0 ;

    fgets( comnd, 100000, stdin ) ;
    sscanf( comnd, "%d", &W ) ;
    for( int i=1; i<=W; i++ ) {
	sprintf( filNam, "caso%d.in", i ) ;
	FILE *out = fopen( filNam, "w" ) ;
	int x, y ;
	fgets( comnd, 100000, stdin ) ;
	fprintf( out, "%s", comnd ) ;
	// printf( "%s", comnd ) ;
	sscanf( comnd, "%d%d", &x, &y ) ;
	for( int j=0; j<y; j++ ) {
	    fgets( comnd, 100000, stdin ) ;
	    fprintf( out, "%s", comnd ) ;
	    // printf( "%s", comnd ) ;
	}
	fclose(out) ;
	sprintf( comnd, "./gradient.bin < caso%d.in > caso%d.out", i, i ) ;
	system (comnd) ;
    }

    return 0 ;
    
    while( scanf("%d%d",&N, &Q)!=EOF ) {
	ult ++ ;

	sprintf( comnd, "./generator.bin %d %d %d %d > grupo%d.caso%d.in", ult, ult, ult, Q, tG, 1 ) ;
	system( comnd )  ;
	cout << comnd << endl ;
	sprintf( comnd, "./gradient.bin < grupo%d.caso%d.in > grupo%d.caso%d.out", tG, 1, tG, 1 ) ;
	system( comnd )  ;
	for( int i=2; i<=K; i++ ) {
	    sprintf( comnd, "./generator.bin %d %d %d %d > grupo%d.caso%d.in", ult, N, ult, Q, tG, i ) ;
	    system( comnd )  ;
	    cout << comnd << endl ;
	    sprintf( comnd, "./gradient.bin < grupo%d.caso%d.in > grupo%d.caso%d.out", tG, i, tG, i ) ;
	    system( comnd )  ;
	}
	sprintf( comnd, "./generator.bin %d %d %d %d > grupo%d.caso%d.in", N, N, N, Q, tG, K+1 ) ;
	system( comnd )  ;
	cout << comnd << endl ;
	sprintf( comnd, "./gradient.bin < grupo%d.caso%d.in > grupo%d.caso%d.out", tG, K+1, tG, K+1 ) ;
	system( comnd )  ;

	sprintf( comnd, "./generator.bin %d %d %d %d > grupo%d.caso%d.in", N, N, Q, Q, tG, K+2 ) ;
	system( comnd )  ;
	cout << comnd << endl ;
	sprintf( comnd, "./gradient.bin < grupo%d.caso%d.in > grupo%d.caso%d.out", tG, K+2, tG, K+2 ) ;
	system( comnd )  ;

	sprintf( comnd, "./generator.bin %d %d %d %d > grupo%d.caso%d.in", ult, ult, Q, Q, tG, K+3 ) ;
	system( comnd )  ;
	cout << comnd << endl ;
	sprintf( comnd, "./gradient.bin < grupo%d.caso%d.in > grupo%d.caso%d.out", tG, K+3, tG, K+3 ) ;
	system( comnd )  ;


	
	tG ++ ;
	
	ult = N ;
    }
}
