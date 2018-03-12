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
const int inf = (1<<30) ;
const int lim = 1e5 + 5 ;
const double eps = 1e-9 ;
const int dr[] = { -1, 0, 1, 0 } ;
const int dc[] = { 0, 1, 0, -1 } ;

void tCase() {
    char S[15] ;
    int N ;
    int minRes, maxRes ;
    pair < char, int > minDig, maxDig ;
    
    scanf("%s", S ) ;
    N = strlen(S) ;
    
    sscanf( S, "%d", &minRes ) ;
    maxRes = minRes ;

    maxDig = minDig = mkp( S[0], 0 ) ;
    for( int i=1; i<N; i++ ) {
	minDig = min( minDig, mkp(S[i],i) ) ;
	maxDig = max( maxDig, mkp(S[i],i) ) ;
    }

    for( int i=0; i<minDig.p2; i++ ) {
	if( S[i]>minDig.p1 and (minDig.p1!='0' or i!=0) ) {
	    swap( S[i], S[minDig.p2] ) ;
	    sscanf( S, "%d", &minRes ) ;
	    swap( S[i], S[minDig.p2] ) ;
	    break ;
	}
    }

    for( int i=0; i<maxDig.p2; i++ ) {
	if( S[i]<maxDig.p1 ) {
	    swap( S[i], S[maxDig.p2] ) ;
	    sscanf( S, "%d", &maxRes ) ;
	    swap( S[i], S[maxDig.p2] ) ;
	    break ;
	}
    }

    printf("%d %d\n", minRes, maxRes ) ;
}

int main() {
    int N ;

    scanf("%d",&N ) ;
    for( int i=1; i<=N; i++ ) {
	printf("Case #%d: ", i ) ;
	tCase() ;
    }
    
    return 0 ;
}
