#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std ;
#define limP 7100
#define limN 50000001

int P=0 ;
int primos[limP] ;
bool comp[limP] ;
bool quak[limN] ;

void criba() {
	for( int i=2; i*i<limP; i++ )
		if( !comp[i] )
			for( int j=i*i; j<limP; j+=i )
				comp[j] = 1 ;
				
	for( int i=2; i<limP; i++ )
		if( !comp[i] )
			primos[P++] = i ;
}

int main() {
	criba() ;
	long long x, y, z ;
	long long N ;
	int i, j , k ;
	
	cout << primos[P-1] << endl ;
	
	cin >> N ;
	
	for( i=0; primos[i]*primos[i]<=N && i<P; i++ ) {
		x = primos[i]*primos[i] ;
		for( j=0; primos[j]*primos[j]*primos[j] +x<=N && j<P; j++ ) {
			y = primos[j]*primos[j]*primos[j] ;
			for( k=0; primos[k]*primos[k]*primos[k]*primos[k] +x+y<=N && k<P; k++ )  {
				z = primos[k]*primos[k]*primos[k]*primos[k] ;
				quak[x+y+z] = 1 ;
			}
		}
	}
	
	k = 0 ;
	for( int i=1; i<=N; i++ )
		if( quak[i] )
			k ++ ;
			
	printf("%d\n", k ) ;
	
	return 0 ;
}
