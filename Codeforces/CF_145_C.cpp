#include <algorithm>
#include <cstdio>
#include <iostream>
#include <utility>
using namespace std ;
typedef pair<long long,long long> par ;
#define f first
#define s second
#define mod 1000000007LL
#define limN 100005
#define limL 2000

long long exGCD( long long a, long long b ) {
	par x=par(0LL,1LL) ;
	long long c, q, z=b ;
	while( b ) {
		q = a/b ;
		c = a%b ;
		a = b ;
		b = c ;
		x = par( x.s - q*x.f, x.f ) ;
	}
	if( x.s<0 )
		x.s = z+x.s ;
	return x.s ;
}

int N, K, L=0, R=0 ;
long long dp[limL] ;
int luc[limN], rep[limL] ;
long long fact[limN] ;

int main() {
	//Variables
	long long res = 0LL, W=0LL ;
	
	//Lectura y precarga
	scanf("%d%d", &N, &K ) ;
	for( int i=0; i<N; i++ ) {
		int a ;
		scanf("%d", &a ) ;
		luc[L] = a ;
		while( a ) {
			if( a%10!=7 && a%10!=4 )
				break ;
			a /= 10 ;
		}
		if( a )
			W ++ ;
		else
			L ++ ;
	}
	fact[0] = 1LL ;
	for( int i=1; i<limN; i++ ) 
		fact[i] = (fact[i-1]*i)%mod ;
	
	//Una vez que se tiene una lista con los luckys, contamos hay de 
	//cada uno
	sort( luc, luc+L ) ;
	for( int i=0, j; i<L; i=j ) {
		for( j=i+1; j<L && luc[i]==luc[j]; j++ ) ;
		rep[R++] = j-i ;
	}
	
	//Hacer una dp para calcular el numero de combinaciones en las que
	//se usan i luckys
	dp[0] = 1LL ;
	for( int i=0; i<R; i++ ) {
		for( int j=i+1; j; j-- ) {
			dp[j] += (dp[j-1]*rep[i])%mod ;
			dp[j] %= mod ;
		}
	}
	
	//Para cada 0<=i<=min(K,R) agregar el numero de combinaciones al usar i
	//luckys y K-i normales
	for( int i=min(K,R); i>=0; i-- ) {
		if( K-i>W )
			continue ;
		long long a, b ;
		a = fact[W] ;
		b = (fact[K-i]*fact[W-K+i])%mod ;		
		a = (a*exGCD( b, mod ) )%mod; 
		
		res += (dp[i]*a)%mod ;
		res %= mod ;
	}
	
	cout << res << endl ;
	
	return 0 ;
}
