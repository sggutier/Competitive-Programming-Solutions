#include <cstdio>
#include <algorithm>
#include <iostream>
#include <queue>
#include <map>
#include <set>
#include <string>
#include <cstring>
#include <utility>
#include <cmath>
using namespace std ;
const int lim = 100005 ;
#define f first
#define s second
typedef long long ll ;
typedef pair<int, int> par;

int arr[lim] ;
int dp[lim] ;

int main() {
    int N, C ;
    int res = 0 ;

    scanf("%d%d", &N, &C ) ;
    for( int i=0; i<N; i++ ) {
	scanf("%d", &arr[i] ) ;
	arr[i] -- ;
    }

    sort( arr, arr+N ) ;

    for( int i=0; i<N; i++ ) {
	dp[i] = (1<<30) ;
 	for( int j=0; j<C && i-j-1>=0; j++ ) {
	    dp[i] = min( dp[i],  dp[i-j-1] ) ;
	}
	if( i<C )
	    dp[i] = 0 ;
	dp[i] += 2*arr[i] ;
    }

    printf("%d\n", dp[N-1] ) ;
    
    return 0 ;
}
