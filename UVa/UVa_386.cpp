#include <cstdio>
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
#define parI pair <int,int>
#define p1 first
#define p2 second
#define mkp make_pair
const int inf = 1e9 ;
const int limA = 200 ;
const int limB = limA*limA*limA ;

int esCub[limB+ 5] ;
int lisCub[limA + 5] ;

int main() {
    for( int i=1; i<=limA; i++ ) {
	lisCub[i-1] = i*i*i ;
	esCub[i*i*i] = i ;
    }
    esCub[1] = 0 ;

    for( int a=6; a<=limA; a++ ) {
	int a3 = a*a*a ;
	for( int i=1; i<limA and lisCub[i]<a3; i++ ) {
	    for( int j=i; j<limA and lisCub[i] + lisCub[j]<a3; j++ ) {
		if( !esCub[ a3 - lisCub[i] - lisCub[j] ]
		    or a3 - lisCub[i] - lisCub[j] < lisCub[j] )
		    continue ;
		printf("Cube = %d, Triple = (%d,%d,%d)\n", a, i+1, j+1, esCub[ a3 - lisCub[i] - lisCub[j] ] ) ;
		// getchar() ;
	    }
	}
    }
    
    return 0 ;
}
