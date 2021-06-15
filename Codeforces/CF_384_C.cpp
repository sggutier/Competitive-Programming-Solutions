#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std ;
const int lim = 200005 ;

int N ;
int vacas[lim] ;

int main() {
    int ini, fin ;
    int cntL=0, cntR=0 ;
    long long res = 0LL ;
    
    scanf("%d", &N ) ;
    for( int i=0; i<N; i++ ) {
	scanf("%d", &vacas[i] ) ;
	cntL += 1 - vacas[i] ;
	cntR += vacas[i] ;
    }

    ini = 0, fin = N-1;
    while( ini<=fin ) {
	if( vacas[ini]==1 ) {
	    ini ++ ;
	    cntR -- ;
	    res += cntL ;
	}
	else if( vacas[fin]==0 ) {
	    fin -- ;
	    cntL -- ;
	    res += cntR ;
	}
	else if( cntR<cntL ) {
	    fin -- ;
	    res += cntR ;
	    cntR -- ;
	}
	else {
	    ini ++ ;
	    res += cntL ;
	    cntL -- ;
	}  
  }

    cout << res << endl ;
    
    return 0 ;
}
