#include <iostream>
using namespace std ;
#define mod 98765431LL
#define lim 2005

int N ;
int trian[lim][lim] ;
long long dp[lim][lim] ;
bool usd[lim][lim] ;

void pasc() {
	for( int i=0; i<lim; i++ ) {
		trian[i][0] = 1 ;
		trian[i][i] = 1 ;
		for( int j=1; j<i; j++ ) {
			trian[i][j] = trian[i-1][j] + trian[i-1][j-1] ;
			trian[i][j] %= mod ;
		}
	}
}

long long memo( int pos, int carg ) {
	if( pos==N ) {
		if( carg==1 )
			return 1LL ;
		return 0LL ;
	}
	if( usd[pos][carg] )
		return dp[pos][carg] ;
	
	usd[pos][carg] = 1 ;
	return dp[pos][carg] = ( memo(pos+1,carg+1)  +  memo(pos+1,1)*trian[N-(pos-carg+1)][carg]   )%mod  ;
	
	//cout << pos << " " << carg << " " << dp[pos][carg] << endl ;
	
	//return dp[pos][carg] ;
}

int main() {
	pasc() ;
	
	cin >> N ;
		
	dp[N][1] = 1LL ;
	for( int i=N-1; i>=0; i-- ) {
		for( int j=1; j<=i+1; j++ ) {
			dp[i][j] = ( dp[i+1][j+1]  +  dp[i+1][1]*trian[N-(i-j+1)][j]   )%mod  ;
		}
	}
		
	cout << dp[0][1] << endl ;
	
	return 0 ;
}
