#include <algorithm>
#include <iostream>
#include <cstdio>
using namespace std;
#define limM (1<<10)
#define limN 50
#define limW 40

int N ;
long long dp[limN][limW][limM] ;
bool usd[limN][limW][limM] ;

long long memo( int N, int ult, int mask ) {
	if( usd[N][ult][mask] )
		return dp[N][ult][mask] ;
	usd[N][ult][mask] = 1 ;
	if( N==1 ) {
		if( mask==limM-1 )
			return dp[N][ult][mask] = 1LL ;
		else
			return dp[N][ult][mask] = 0LL ;
	}
	
	if( ult==0 )
		return dp[N][ult][mask] = memo( N-1, 1, (1<<1) | mask ) ;
	if( ult==9 )
		return dp[N][ult][mask] = memo( N-1, 8, (1<<8) | mask ) ;
		
	return dp[N][ult][mask] = memo( N-1, ult-1, (1<<(ult-1)) | mask )   +   memo( N-1, ult+1, (1<<(ult+1)) | mask )    ;
}

int main() {
	long long res = 0LL ;
	
	scanf("%d", &N ) ;
	for( int j=1; j<=N; j++ ) {
		for( int i=1; i<=9; i++ ) {
			res += memo( j, i, (1<<i) ) ;
		}
	}
	
	cout << res << endl ;
	
	return 0 ;
}
