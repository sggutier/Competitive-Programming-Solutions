#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std ;
#define lim 1000005

int main() {
	int N, P ;
	char S[lim] ;
	int x[lim], y[lim] ;
	long long dis = 0LL ;
	int a=0, b=0, ini, fin, piv, w ;
	
	scanf("%d%d", &P, &N ) ;
	for( int i=0; i<P; i++ ) {
		scanf("%d%d", &x[i], &y[i] ) ;
		dis += abs(x[i])+abs(y[i]) ;
	}
	scanf("%s", S ) ;
	
	sort( x, x+P ) ;
	sort( y, y+P ) ;
	x[P] = (1<<30) ;
	y[P] = (1<<30) ;
	
	for( int i=0; i<N; i++ ) {
		if( S[i]=='S' || S[i]=='J'  )  {
			if( S[i]=='S' ) {
				w = 1 ;
				b += w ;
				ini = 0 ; 
				fin = P ;
				while( ini<fin ) {
					piv = (ini+fin)/2 ;
					if( y[piv]<b ) 
						ini = piv+1 ;
					else
						fin = piv ;
				}
			}
			else if( S[i]=='J' ) {
				w = -1 ;
				b += w ;
				ini = 0 ; 
				fin = P ;
				while( ini<fin ) {
					piv = (ini+fin)/2 ;
					if( y[piv]<=b ) 
						ini = piv+1 ;
					else
						fin = piv ;
				}
			}
			dis += (ini-(P-ini))*w ;
		}
		else {
			if( S[i]=='I' ) {
				w = 1 ;
				a += w ;
				ini = 0 ; 
				fin = P ;
				while( ini<fin ) {
					piv = (ini+fin)/2 ;
					if( x[piv]<a ) 
						ini = piv+1 ;
					else
						fin = piv ;
				}
			}
			else if( S[i]=='Z' ) {
				w = -1 ;
				a += w ;
				ini = 0 ; 
				fin = P ;
				while( ini<fin ) {
					piv = (ini+fin)/2 ;
					if( x[piv]<=a ) 
						ini = piv+1 ;
					else
						fin = piv ;
				}
			}
			dis += (ini-(P-ini))*w ;
		}
		
		cout << dis << endl ;
	}
	
	return 0 ;
}
