#include <cstdio>
#include <algorithm>
#include <iostream>
#include <utility>
#include <queue>
#include <string>
#include <cstring>
#include <map>
#include <set>
#include <cmath>
#include <stack>
using namespace std ;
const int lim = 105 ;

int N ;
int arr[lim][2] ;
int ant[lim], tam[lim] ;

int raiz( int pos ) {
	while( ant[pos]!=pos )
		pos = ant[pos] ;
	return pos ;
}

void une( int A, int B ) {
	A = raiz(A) ;
	B = raiz(B) ;
	if( tam[A]>tam[B] )
		swap( A, B ) ;
	ant[A] = B ;
	tam[B] = max( tam[B], tam[A]+1 ) ;
}

int main() {
	int res = 0 ;

	scanf("%d", &N ) ;
	for( int i=0; i<N; i++ )  {
		scanf("%d%d", &arr[i][0], &arr[i][1] ) ;
		ant[i] = i ;
		tam[i] = 1 ;
	}

	for( int i=0; i<N; i++ ) {
		for( int j=0; j<i; j++ ) {
			if( (arr[i][0]==arr[j][0] || arr[i][1]==arr[j][1]) ) {
				une( i, j ) ;
			}
		}
	}

	for( int i=0; i<N; i++ ) {
		if( ant[i]==i )
			res ++ ;
	}

	printf("%d\n", res-1 ) ;

	return 0 ;
}

