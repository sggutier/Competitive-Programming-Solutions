#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std ;
const int lim = 100005 ;

int dp[lim] ;

int main() {
		int N, M ;
		int arr[10000], W=0 ;
		int nRes=0, res=0 ;

		scanf("%d%d", &N, &M ) ;
		for( int i=0; i<N; i++ ) 
				scanf("%d", &arr[i] ) ;
		for( int i=0; i<M; i++ ) {
				int tmp ;
				scanf("%d", &tmp ) ;
				W += tmp ;
		}

		sort( arr, arr+N ) ;
		for( int i=0; i<N; i++ ) {
				if( res+arr[i]<=W ) {
						res += arr[i] ;
						nRes ++ ;
				}
				else
						break ;
		}

		dp[0] = 1 ;
				for( int k=0; k<N; k++ ) 
						for( int j=W-arr[k]; j>=0; j-- ) 
								if( dp[j] )
									dp[j+arr[k]] = max( dp[j+arr[k]], dp[j]+1 ) ;	
		for( int i=W; i>=0; i-- ) {
				if( dp[i]!=nRes+1 )
						continue ;
				res = i ;
				break ;	
		}

		printf("%d %d\n", nRes, res  ) ;

		return 0 ;
}
