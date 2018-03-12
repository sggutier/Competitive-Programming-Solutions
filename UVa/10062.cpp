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
#define par pair< int, int >
#define p1 first
#define p2 second
const int lim = 100005 ;
const int limB = 300 ;

int main() {
    char S[lim] ;
    bool fst = true ;

    while( fgets(S, lim, stdin) ) {
	int N=strlen(S) ;
	par cCnt[limB] ;

	memset( cCnt, 0, sizeof(cCnt) ) ;
	for( int i=0; i<limB; i++ )
	    cCnt[i].p2 = -i ;
	for( int i=0; i<N; i++ )
	    if( S[i]>=32 and S[i]<=128 )
		cCnt[ S[i] ].p1 ++ ;

	if( !fst )
	    printf("\n" ) ;
	fst = false ;
	sort( cCnt, cCnt+limB ) ;
	for( int i=0; i<limB; i++ )
	    if( cCnt[i].p1 )
		printf("%d %d\n", -cCnt[i].p2, cCnt[i].p1 ) ;
    }
    
    return 0 ;
}
