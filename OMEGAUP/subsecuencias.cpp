#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std ;
const int lim = 20005 ;

int posb[lim][2] ;

int main() {
		int N ;
		int act=0, sig=1 ;
		int arr[lim] ;

		scanf("%d", &N) ;
		for( int i=0; i<N; i++ )
				scanf("%d", &arr[i] ) ;

		posb[0][1] = 1 ;
		for( int i=0; i<N; i++, swap(act,sig)  ) {
				for( int j=0; j<lim; j++ ) 
						posb[j][act] = 0 ;
				for( int j=0; j<lim; j++ ) {
						if( posb[j][sig] ) {
								posb[j+arr[i]][act] = 1 ;
								posb[abs(j-arr[i])][act] = 1 ;
						}
				}
		}

		for( int i=0; i<lim; i++ ) {
				if( posb[i][sig] ) {
						printf("%d\n", i ) ;
						return 0 ;
				}
		}


		return 0 ;
}
