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
    char filNam[10000], comnd[10000] ;
    int tG = 1 ;
    
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
