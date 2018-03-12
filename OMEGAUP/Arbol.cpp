#include <cstdio>
#include <algorithm>
#include <iostream>
#include <utility>
#include <queue>
#include <string>
#include <cstring>
using namespace std ;
const int limK = 51 ;
const int limN = 11 ;

struct foo {
	string S ;
};

foo lin[limK][limK][limK] ;
foo dp[limN][limK][limK][limK] ;
bool usd[limN][limK][limK][limK] ;

foo operator+( foo A, foo B ) {
	while( A.S.size()<B.S.size() ) {
		A.S += "0" ;
		A.S[A.S.size()] -= '0' ;
	}
	while( B.S.size()<A.S.size() ) {
		B.S += "0" ;
		B.S[B.S.size()] -= '0' ;
	}
	int carg = 0, W=A.S.size() ;
	for( int i=0; i<W; i++ ) {
		A.S[i] += B.S[i]+carg ;
		carg = A.S[i]/10 ;
		A.S[i] %= 10 ;
	}
	if( carg ) {
		A.S += "1" ;
		A.S[W] -= '0' ;
	}
	return A ;
}

foo operator*( foo A, int B ) {
	int carg=0, tmp, W=A.S.size() ;
	for( int i=0; i<W; i++ ) {
		tmp = (carg+A.S[i])*B ;
		A.S[i] = tmp%10 ;
		carg = tmp/10 ;
	}
	while( carg ) {
		A.S += "0" ;
		A.S[W++] = carg%10 ;
		carg /= 10 ;
	}
	return A ;
}

foo operator*( foo A, foo B ) {
	foo C, K ;

	C.S = "0" ;
	C.S[0] = 0 ;
	for( int i=0, W=B.S.size(); i<W; i++ ) {
		printf("%d\n", B.S[i] ) ;
		int tmp = B.S[i] ;
		K = (A*tmp) ;
		C = C+K ;
		A.S += "0" ;
		A.S[A.S.size()-1] = 0 ;
		printf("-> " ) ;
		for( int j=C.S.size()-1; j>=0; j-- )
			printf("%d ", C.S[j] ) ;
		printf("\n" ) ;
	}

	return C ;
}

foo memo( long long N, long long A,long long B, long long C ) {
	if( N==0 ) {
		foo tmp ;
		tmp.S = "1" ;
		tmp.S[0] -'0' ;
		return tmp ;
	}
	if( usd[N][A][B][C] )
		return dp[N][A][B][C] ;

	int x=N/2, y=N/3 ;

	usd[N][A][B][C] = true ;

	if( A>=N ) 
		dp[N][A][B][C] = dp[N][A][B][C] + memo( N-1, A-N, B, C )*lin[N][0][0] ;
	if( B>=N ) 
		dp[N][A][B][C] = dp[N][A][B][C] + memo( N-1, A, B-N, C )*lin[N][0][0] ;
	if( C>=N ) 
		dp[N][A][B][C] = dp[N][A][B][C] + memo( N-1, A, B, C-N )*lin[N][0][0] ;

	if( 2*x==N ) {
		if( A>=x && B>=x )
			dp[N][A][B][C] = dp[N][A][B][C] + memo( N-1, A-x, B-x, C )*lin[x][x][0] ;
		if( A>=x && C>=x )
			dp[N][A][B][C] = dp[N][A][B][C] + memo( N-1, A-x, B, C-x )*lin[x][x][0] ;
		if( C>=x && B>=x )
			dp[N][A][B][C] = dp[N][A][B][C] + memo( N-1, A, B-x, C-x )*lin[x][x][0] ;
	}

	if( 3*y==N && A>=y && B>=y && C>=y )
		dp[N][A][B][C] = dp[N][A][B][C] + memo( N-1, A-y, B-y, C-y )*lin[y][y][y] ;

	return dp[N][A][B][C] ;
}

int main() {
	foo X, Y ;
	int w, w2 ;

	cin >> X.S >> Y.S >> w >> w2 ;

	reverse( X.S.begin(), X.S.end() ) ;
	reverse( Y.S.begin(), Y.S.end() ) ;
	for( int i=0; i<X.S.size(); i++ )
		X.S[i] -= '0' ;
	for( int i=0; i<Y.S.size(); i++ )
		Y.S[i] -= '0' ;
	if( w )
		X = X*Y ;
	else
		X = X+Y ;
	Y = Y*w2 ;

	for( int i=X.S.size()-1; i>=0; i-- )
		printf("%c", X.S[i]+'0' ) ;
	printf("\n" ) ;
	for( int i=Y.S.size()-1; i>=0; i-- )
		printf("%c", Y.S[i]+'0' ) ;
	printf("\n" ) ;

	return 0 ;

	int N, A, B, C ;

	scanf("%d%d%d%d", &N, &A, &B, &C ) ;

	lin[0][0][0].S = "1" ;
	lin[0][0][0].S[0] = 0 ;
	for( int i=0; i<limK; i++ ) {
		for( int j=0; j<limK; j++ ) {
			for( int k=0; k<limK; k++ ) {
				if( i )
					lin[i][j][k] = lin[i][j][k] + lin[i-1][j][k] ;
				if( j )
					lin[i][j][k] = lin[i][j][k] + lin[i][j-1][k] ;
				if( k )
					lin[i][j][k] = lin[i][j][k] + lin[i][j][k-1] ;
			}
		}
	}

	foo res = memo( N, A, B, C ) ;

	for( int i=res.S.size()-1; i>=0; i-- )
		printf("%c", res.S[i]+'0' ) ;
	printf("\n" ) ;

	return 0 ;
}

