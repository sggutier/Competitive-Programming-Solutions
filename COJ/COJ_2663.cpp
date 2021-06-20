#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <string>
#include <cstring>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <vector>
#include <utility>
using namespace std ;

long long pasc[10][10] ;

void trian() {
	pasc[0][0] = 1LL ;
	for( int i=1; i<10; i++ ) {
		pasc[i][i] = pasc[i][0] = 1LL ;
		for( int j=1; j<i; j++ )
			pasc[i][j] = pasc[i-1][j] + pasc[i-1][j-1] ;
	}
}

int calc( char S[], int N ) {
	int res = 0, i, ult ;
	if( N==1 && S[0]!='0' )
		res ++ ;
	for( i=1; i<N; i++ ) {
		res += pasc[9][i] ;
		if( i==1 )
			res ++ ;
	}
	for( i=0, ult=0; i<N && (i==0 || S[i]>S[i-1]);  i++  ) {
		for( int j=ult+1; j<S[i]-'0'; j++ ) {
			//printf("%d %d -> %lld\n", ult, j, pasc[9-j][N-i-1]  ) ;
			res += pasc[9-j][N-i-1] ;
		}
		ult = max( ult, int(S[i]-'0') ) ;
	}
	if( i==N )
		res ++ ;
	return res ;
}

void caso() {
	char A[15], B[15] ;
	int X, Y, a, b ;
	scanf("%d%d", &a, &b ) ;
	if( a>b ) {
		swap( a, b ) ;
	}
	a -- ;
	a = min( a, 123456789 ) ;
	b = min( b, 123456789 ) ;
	sprintf( A, "%d", a ) ;
	sprintf( B, "%d", b ) ;
	X = strlen(A), Y=strlen(B) ;

	if( a==-1 )
		printf("%d\n", calc(B,Y) ) ;
	else
		printf("%d\n", calc(B,Y) - calc(A,X) ) ;
}

int main() {
	trian() ;

	int T ;

	scanf("%d", &T ) ;
	for( int i=0; i<T; i++ ) {
		caso() ;
	}

	return 0 ;
}

