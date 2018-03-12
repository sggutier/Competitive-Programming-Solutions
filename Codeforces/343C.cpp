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
const int lim = 200005 ;

int D, L ;
long long dco[lim], lec[lim] ;

long long tpo( long long a, long long b, long long c ) {
	return c-a + min(c-b,b-a) ;
}

bool sePuede( long long K ) {
	long long ult = dco[0] ;
	int i, j ;
	for( i=0, j=0; i<L && j<D; i++ ) {
		long long dif = 0LL ;
		ult = min( lec[i], dco[j] ) ;
		dif= lec[i]-ult ;
		if( tpo( ult, lec[i], max(lec[i],dco[j]) ) <= K ) {
			do {
				j ++ ;
			} while( tpo( ult, lec[i], max(lec[i],dco[j]) ) <= K ) ;
			if(  tpo( ult, lec[i], max(lec[i],dco[j-1]) ) > K  ) {
				return 0 ;
			}
		}
		else {
			if(  tpo( ult, lec[i], lec[i]) > K  ) {
				return 0 ;
			}
		}
		//printf(" -> %lld %lld %lld\n", ult, lec[i], dco[j-1] ) ;
	}
	return j==D ;
}

int main() {
	long long ini=0LL, fin=(1LL<<35) ;

	cin >> L >> D ;
	for( int i=0; i<L; i++ ) 
		cin >> lec[i] ;
	for( int i=0; i<D; i++ )
		cin >> dco[i] ;
	dco[D] = (1LL<<60) ;

	while( ini<fin ) {
		long long piv = (ini+fin)/2LL ;
		//cout << ini << " " << fin << endl ;
		//getchar() ;
		if( sePuede(piv) )
			fin = piv ;
		else
			ini = piv +1 ;
	}

	cout << ini << endl ;

	return 0 ;
}

