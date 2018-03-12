#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std ;
const int lim = 100005 ;

int N ;
long long W ;
long long arr[lim] ;

bool sePuede( long long K ) {
	long long T = W ;
	
	for( int i=0; i<N && T>=0LL; i++ ) {
		T -= K/arr[i] ;
	}
	
	return T<=0LL ;
}

int main() {
	long long ini=0LL, fin=(1LL<<60) ;
	
	cin >> N >> W ;
	for( int i=0; i<N; i++ ) 
		cin >> arr[i] ;
		
	while( ini<fin ) {
		long long piv = (ini+fin)/2LL ;
		if( sePuede(piv) )
			fin = piv ;
		else
			ini = piv+1 ;
	}
	
	cout << ini << endl ;
	
	return 0 ;
}
