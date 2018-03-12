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
#include <cctype>
using namespace std ;
#define par pair< int, int >
#define p1 first
#define p2 second
const int limA = 60000 ;
const int limB = 105 ;

bool dp[limB][limA*2] ;

void caso() {
    int N ;

    memset( dp, 0, sizeof(dp) ) ;
    dp[0][0] = 1 ;
    
    scanf("%d", &N ) ;
    for( int i=1; i<=N; i++ ) {
	int a ;
	scanf("%d", &a ) ;
	// printf("%d -> ", i ) ;
	for( int j=0; j<limA; j++ ) {
	    //if( dp[i-1][j] )
	    // printf("%d ", j ) ;
	    if( dp[i-1][j] )
		dp[i][j+a] = dp[i][abs(j-a)] = 1 ;
	}
	// printf("\n" ) ;
    }

    for( int i=0; i<limA; i++ ) {
	if( dp[N][i] ) {
	    printf("%d\n", i ) ;
	    return ;
	}
    }

    return ;
}

int main() {
    int T ;

    scanf("%d", &T ) ;
    for( int i=0; i<T; i++ )
	caso() ;
    
    return 0 ;
}
