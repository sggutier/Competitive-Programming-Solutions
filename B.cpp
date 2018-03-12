#include <cstdio>
#include <algorithm>
#include <iostream>
#include <queue>
#include <utility>
#include <cmath>
#include <set>
#include <map>
using namespace std ;

double dp[100][100] ;

int main() {
	int N ;
	double arr[100], res=1.0*0 ;
	double le[100], test=res, w=1.0*0, Q=w ;
	
	cin >> N ;
	for( int i=1; i<=N; i++ )
		Q += i*i ;
	for( int i=1; i<=N; i++ )
		cin >> arr[i] ;
	N ++ ;
	arr[N] = 1.0*0 ;
	
	
	dp[0][0] = 1.0 ;
	le[0] = 1.0*0 ;
	for( int i=1; i<=N; i++ ) {
		double a=1.0*0, b=a ;
		dp[i][0] = 1.0*0 ;
		le[i] = (le[i-1]+1.0)*arr[i] ;
		w += le[i-1] ;
		test += w*(1-arr[i]) ;
		for( int j=1; j<=N; j++ ) {
			dp[i][j] = dp[i-1][j-1]*arr[i] ;
			dp[i][0] += dp[i-1][j-1]*(1-arr[i]) ;
			res += dp[i-1][j-1]*(j-1)*(j-1)*(1-arr[i]) ;
		}		
		for( int j=0; j<=N; j++ ) {
			b += dp[i-1][j]*j*j ;
			a += dp[i-1][j] ;
		}
		cout << le[i-1] << " " << b  << " " << a << endl ;
	}
		
	cout << res << endl ;
	cout << test << endl ;
	
	return 0 ;
}
