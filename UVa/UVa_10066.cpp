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
const int lim = 105 ;

int A, B ;
int arrA[lim], arrB[lim] ;
int dp[lim][lim] ;

int memo( int a, int b ) {
    if( dp[a][b]!=-1 )
	return dp[a][b] ;
    if( a==A or b==B )
	return dp[a][b] = A-a + B-b ;
    if( arrA[a] == arrB[b] )
	return dp[a][b] = memo( a+1, b+1 ) ;
    return dp[a][b] = min(  memo(a+1,b), memo(a,b+1) ) + 1 ;
}

void caso() {
    for( int i=0; i<A; i++ )
	scanf("%d", &arrA[i] ) ;
    for( int i=0; i<B; i++ )
	scanf("%d", &arrB[i] ) ;

    memset( dp, -1, sizeof(dp) ) ;
    
    printf("%d\n\n", ( A + B - memo(0,0))/2 ) ;
}

int main() {
    int t = 0 ;
    
    while( scanf("%d%d",&A,&B)!=EOF  and  (A or B)  ) {
	printf("Twin Towers #%d\nNumber of Tiles : ", ++t ) ;
	caso() ;
    }
    
    return 0 ;
}
