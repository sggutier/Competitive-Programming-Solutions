#include <cstdio>
#include <algorithm>
#include <iostream>
#include <utility>
#include <queue>
#include <string>
#include <cstring>
using namespace std ;
const int lim = 255 ;

int N, B, Q ;
int arr[lim][lim], horMin[lim][lim] ,horMax[lim][lim], verMin[lim][lim], verMax[lim][lim] ;
int tmpMin[lim], tmpMax[lim] ;

int main() {
	scanf("%d%d%d", &N, &B, &Q ) ;
	for( int i=0; i<N; i++ )
		for( int j=0; j<N; j++ )
			scanf("%d", &arr[i][j] ) ;

	for( int i=0; i<N; i++ ) {
		for( int j=0; j<N; j+=B ) {
			tmpMin[B] =  (1<<30) ;
			tmpMax[B] = -(1<<30) ;
			for( int k=B-1; k>=0; k-- ) {
				tmpMin[k] = tmpMin[k+1] ;
				tmpMax[k] = tmpMax[k+1] ;
				if( j+k<N ) {
					tmpMin[k] = min( tmpMin[k], arr[i][j+k] ) ;
					tmpMax[k] = max( tmpMax[k], arr[i][j+k] ) ;
				}
			}
			for( int wMin=(1<<30), wMax=-wMin, k=0; k<B && k+j<N; k++ ) {
				if( j+k+B-1<N ) {
					wMin = min( wMin, arr[i][j+k+B-1] ) ;
					wMax = max( wMax, arr[i][j+k+B-1] ) ;
				}
				horMin[i][j+k] = min( tmpMin[k], wMin ) ;
				horMax[i][j+k] = max( tmpMax[k], wMax ) ;
			}
		}
	}

	for( int j=0; j<N; j++ ) {
		for( int i=0; i<N; i+=B ) {
			tmpMin[B] =  (1<<30) ;
			tmpMax[B] = -(1<<30) ;
			for( int k=B-1; k>=0; k-- ) {
				tmpMin[k] = tmpMin[k+1] ;
				tmpMax[k] = tmpMax[k+1] ;
				if( k+i<N ) {
					tmpMin[k] = min( tmpMin[k], horMin[i+k][j] ) ;
					tmpMax[k] = max( tmpMax[k], horMax[i+k][j] ) ;
				}
			}
			for( int wMin=(1<<30), wMax=-wMin, k=0; k<B && k+i<N; k++ ) {
				if( i+k+B-1<N ) {
					wMin = min( wMin, horMin[i+k+B-1][j] ) ;
					wMax = max( wMax, horMax[i+k+B-1][j] ) ;
				}
				verMin[i+k][j] = min( tmpMin[k], wMin ) ;
				verMax[i+k][j] = max( tmpMax[k], wMax ) ;
			}
		}
	}

	for( int i=0; i<Q; i++ ) {
		int a, b ;
		scanf("%d%d", &a, &b ) ;
		a--, b-- ;
		printf("%d\n", verMax[a][b]-verMin[a][b] ) ;
	}

	return 0 ;
}

