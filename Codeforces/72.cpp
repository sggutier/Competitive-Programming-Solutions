#include <algorithm>
#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std ;
#define lim 2000

int P=0 ;
long long primos[lim] ;
int comp[lim] ;

void criba() {
	for( int i=2; i*i<lim; i++ ) 
		if( !comp[i] )
			for( int j=i*i; j<=lim; j+=i )
				comp[j] = 1 ;
	
	for( int i=2; i<lim; i++ )
		if( !comp[i] )
			primos[P++] = 0LL + i ;
}

int phi( int N ) {
	long long res = N +0LL ;
	int q = N ;
	
	for( int i=0; i<P; i++ ) {
		if( N%primos[i] )
			continue ;
		res *= primos[i]-1LL ;
		res /= primos[i] ;
		while( N%primos[i]==0 )
			N /= primos[i] ;
	}
	
	if( N>1 ) {
		long long w = (long long)(sqrt(N)) ;
		cout << q << " " << N << " " << w << endl ;
		if( w*w!=N ) {
			res *= N-1LL ;
			res /= N ;
		}
		else {
			res *= w-1LL ;
			res /= w ;
		}
	}
	
	return res ;
}

int main() {
	long long res = 0LL, N ;
	
	criba() ;
	
	cin >> N ;
	for( int i=2; i<=N; i++ )	
		res += phi(i) ;
		
	cout << res << endl ;
	
	return 0 ;
}
