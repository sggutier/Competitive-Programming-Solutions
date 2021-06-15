#include <algorithm>
#include <cstdio>
#include <iostream>
#include <utility>
using namespace std ;
typedef long long ll ;
typedef pair<ll,ll> par ;
#define f first
#define s second

par may( par A, par B ) {
	if( A.f * B.s < B.f * A.s  )
		return B ;
	return A ;
}

ll mcd( ll a, ll b ) {
	ll c ;
	while( b ) {
		c = b ;
		b = a%b ;
		a = c ;
	}
	return a ;
}

int main() {
	int N ;
	int arr[1005] ;
	int i, j ;
	int res = 0 ;
	par w, v ;
	
	scanf("%d", &N ) ;
	for( i=0; i<N; i++ ) {
		scanf("%d", &arr[i] ) ;
	}
	
	arr[N] = arr[N-1] + arr[0] ;
	w = par( 1LL, 1LL ) ;
	for( i=0; i<=N; i++ ) {
		j = mcd( i+1, arr[i] ) ;
		w = may( w, par( 0LL + arr[i]/j, 0LL + (i+1)/j )   );
	}
	for( i=0; i<=N; i++ ) {
		if( arr[i] !=  ( (i+1LL)*w.f )/w.s   )   
			break ;
	}
	if( i>N )
		res ++ ;
		
	arr[N] = arr[N-1] + arr[0] +1 ;
	w = par( 1LL, 1LL ) ;
	for( i=0; i<=N; i++ ) {
		j = mcd( i+1, arr[i] ) ;
		w = may( w, par( 0LL + arr[i]/j, 0LL + (i+1)/j )   );
	}
	for( i=0; i<=N; i++ ) {
		if( arr[i] !=  ( (i+1LL)*w.f )/w.s   )   
			break ;
	}
	if( i>N )
		res +=2 ;
		
	if( res!=3 ) {
		printf("unique\n" ) ;
		if( res==1 )
			printf("%d\n", arr[N-1] + arr[0] ) ;
		else
			printf("%d\n", arr[N-1] + arr[0] +1 ) ;
	}
	else {
		printf("not unique\n" ) ;
	}
	
	return 0 ;
}
