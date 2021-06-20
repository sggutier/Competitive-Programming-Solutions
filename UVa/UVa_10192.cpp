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
const int lim = 1005 ;
int inf ;

int X, Y ;
char A[lim], B[lim] ;
int dp[lim][lim] ;

int memo( int a, int b ) {
    if( dp[a][b]!=inf )
	return dp[a][b] ;
    if( a==X or b==Y )
	return 0 ;

    if( A[a]==B[b] )
	return dp[a][b] = memo( a+1, b+1 ) +1 ;

    return dp[a][b] = max( memo(a+1,b), memo(a,b+1)  ) ;
}

void caso() {
    // scanf("%s", B ) ;
    fgets( B, lim, stdin ) ;
    X = strlen(A)-1 ;
    Y = strlen(B)-1 ;

    // cout << X << " " << Y << endl ;

    memset( dp, -1, sizeof(dp) ) ;
    inf = dp[0][0] ;

    printf("you can visit at most %d cities.\n", memo(0,0) ) ;
}

int main() {
    int t = 0 ;
    
    while( fgets( A, lim, stdin )  and A[0]!='#' ) {
	printf("Case #%d: ", ++t ) ;
	caso() ;
    }
    
    return 0 ;
}
