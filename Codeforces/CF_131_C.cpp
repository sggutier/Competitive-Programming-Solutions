#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std ;
#define lim 31

long long trian[lim][lim] ;

void precarg() {
	trian[0][0] = 1LL ;
	for( int i=1; i<lim; i++ ) {
		trian[i][0] = 1LL ;
		for( int j=1; j<=i; j++ )
			trian[i][j] = trian[i-1][j] + trian[i-1][j-1] ;
	}
}

int main() {
	precarg() ;
	int A, B, C ;
	long long res = 0LL ;
	
	cin >> B >> A >> C ;
	
	for( int i=max(1,C-B); i<=A && i+4<=C; i++ ) 
		res += trian[A][i]*trian[B][C-i] ;
	
	cout << res << endl ;
	
	return 0 ;
}

