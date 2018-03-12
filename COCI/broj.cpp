#include <algorithm>
#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std ;
#define lim 100005
#define limP 35000000
#define mucho 1000000000LL

int P=0 ;
int primos[lim] ;
bool comp[lim] ;
char usd[limP] ;

void criba() {
	for( int i=2; i*i<lim; i++ ) {
		if( comp[i] )
			continue ;
		for( int j=i*i; j<lim; j+=i ) 
			comp[j] = 1 ;
	}
	for( int i=2; i<lim; i++ ) {
		if( !comp[i] )
			primos[P++] = i ;
	}
}

void procA( int N, int K, long long prod ) {
	long long W=0LL, res=0LL ;
	
	usd[0] = 1 ;
	for( int i=0; primos[i]<K; i++ ) {
		usd[primos[i]] = 1 ;
		for( int j=primos[i]*primos[i]; j<=prod; j+=primos[i] ) {
			usd[j] = 1 ;
		}
	}
	
	for( int i=0; i<prod; i++ ) {
		if( !usd[i] )
			W ++ ;
	}
	
	if( W && N%W ) {
		res += (N/W)*(prod) ;
		N %= W ;
	}
	else if(W) {
		res += ((N/W)-1)*(prod) ;
		N = W ;
	}
	else {
		res = N ;
		N = 0 ;
	}
	
	if( N>mucho ) {
		cout << 0 << endl ;
		return ;
	}
	
	for( int i=0; i<prod && N; i++ ) {
		if( !usd[i] ) {
			N -- ;
			if( N==0 ) 
				res += i ;
		}
	}
	
	if( res*K>mucho )
		cout << 0 << endl ;
	else
		cout << res*K << endl ;
}

int main() {	
	criba() ;
	
	int N, K ;
	
	scanf("%d%d", &N, &K ) ;
	
	if( K<=23 ) {
		long long prod = 1LL ;
		for( int i=0; primos[i]<K; prod*=primos[i], i++ ) ;
		procA(N,K,prod ) ;
	}
	else if( K<=100000 ) {
		procA(N,K,mucho/K) ;
	}
	else {
		if( N==1 ) 
			cout << K << endl ;
		else
			cout << 0 << endl ;
	}
	
	return 0 ;
}
