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
    int ult=0, N ;
    char filNam[10000], comnd[10000] ;
    int tG = 1 ;
    
    while( scanf("%d",&N)!=EOF ) {
	ult ++ ;
	for( int w=0; w<2; w++ ) {
	    sprintf( comnd, "./generator.bin %d %d %d > grupo%d.caso%d.in", ult, ult, w, tG, 1 ) ;
	    system( comnd )  ;
	    cout << comnd << endl ;
	    sprintf( comnd, "./gradient.bin < grupo%d.caso%d.in > grupo%d.caso%d.out", tG, 1, tG, 1 ) ;
	    system( comnd )  ;
	    for( int i=2; i<=6; i++ ) {
		sprintf( comnd, "./generator.bin %d %d %d > grupo%d.caso%d.in", ult, N, w, tG, i ) ;
		system( comnd )  ;
		cout << comnd << endl ;
		sprintf( comnd, "./gradient.bin < grupo%d.caso%d.in > grupo%d.caso%d.out", tG, i, tG, i ) ;
		system( comnd )  ;
	    }
	    sprintf( comnd, "./generator.bin %d %d %d > grupo%d.caso%d.in", N, N, w, tG, 7 ) ;
	    system( comnd )  ;
	    cout << comnd << endl ;
	    sprintf( comnd, "./gradient.bin < grupo%d.caso%d.in > grupo%d.caso%d.out", tG, 7, tG, 7 ) ;
	    system( comnd )  ;
	    tG ++ ;
	}
    }
}
