#include <cstdio>
#include <algorithm>
#include <queue>
#include <iostream>
#include <map>
#include <set>
#include <cmath>
#include <string>
#include <cstring>
#include <list>
using namespace std ;
const int lim = 1000006 ;

int mcd( int a, int b ) {
	int c ;
	while( b!=0 ) {
		c = a%b ;
		a = b ;
		b = c ;
	}
	return a ;
}

int N, M ;
long long X, Y ;
char A[lim], B[lim] ;
int rep[26] ;
bool usd[lim], usd2[lim] ;

int main() {
	int Q ;
	long long res = 0LL ;
	long long gna ;


	cin >> X >> Y ;
	cin >> A ;
	cin >> B ;
	N = strlen(A) ;
	M = strlen(B) ;
	Q = mcd( N, M ) ;
	gna = N/Q ;

	X /= M/Q ;

	for( int i=0; i<Q; i++ ) {
		if( usd[i] )
			continue ;
		int pos = i ;
		memset( rep, 0, sizeof(rep) ) ;
		while( !usd[pos] ) {
			usd[pos] = 1 ;
			rep[ A[pos]-'a' ] ++ ;
			pos = (pos+M)%N ;
		}
		pos = i ;
		while( !usd2[pos] ) {
			usd2[pos] = 1 ;
			res += (gna-rep[B[pos]-'a'])*X ;
			pos = (pos+Q)%M ;
		}
	}

	cout << res << endl ;


	return 0 ;
}


