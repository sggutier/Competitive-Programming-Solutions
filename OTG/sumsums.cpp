#include <iostream>
#include <cstdio>
#include <algorithm>
#include <utility>
using namespace std ;
typedef long long LL ;
typedef pair<LL,LL> par ;
#define f first
#define s second
#define lim 50005
#define mod 98765431LL

long long n ;

par mult( par a, par b ) {
	par res ;
	res.f = (  (a.f*b.f)%mod + (    ((a.s*b.s)%mod)*(n-1LL)     )%mod  )  %  mod ;
	res.s = (  (a.f*b.s)%mod + (a.s*b.f)%mod + (    ((a.s*b.s)%mod)*(n-2LL)     )%mod   )  % mod;
	return res ;
}

par expBin( LL t ) {
	if( t==1LL )
		return par( 0LL, 1LL ) ;
	par tmp = expBin( t/2LL )  ;
	if( t%2LL==0LL )  {
		return mult( tmp, tmp )  ;
	}
	return mult(   mult( tmp, tmp ),  par(0LL,1LL)    )    ;
}

int main() {
	LL T ;
	LL arr[lim] ;
	par w ;
	int i, j ;
	LL a, b, sum = 0LL ;
	
	cin >> n >> T ;
	w = expBin( T ) ;
	for( i=0; i<n; i++ ) {
		cin >> arr[i] ;
		sum += (arr[i]*w.s)%mod ;
		sum %= mod ;
	}
	
	for( i=0; i<n; i++ ) {
		printf("%lld\n",  ( sum + ( arr[i]*(w.f-w.s+ mod ) % mod  ) )  %  mod   )    ;
	}
	
	return 0 ;
}
