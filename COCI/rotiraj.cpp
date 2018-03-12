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
#include <list>
#include <stack>
using namespace std ;
const int lim = 100005 ;

int N, K ;
int sct[lim][2] ;
int arr[lim], cpy[lim] ;

void rotaA( int W ) {
	while( W<0 )
		W += N ;

	for( int i=0; i<N; i++ )
		cpy[i] = arr[(i+W)%N] ;
	for( int i=0; i<N; i++ )
		arr[i] = cpy[i] ;
}

void rotaB( int W ) {
	while( W<0 )
		W += K ;

	for( int i=0; i<N; i++ ) {
		cpy[i] = arr[(i/K)*K + (i+W)%K] ;
	}
	for( int i=0; i<N; i++ )
		arr[i] = cpy[i] ;
}

int main() {
	int E ;

	scanf("%d%d%d", &N, &K, &E ) ;
	for( int i=0; i<E; i++ )
		scanf("%d%d", &sct[i][0], &sct[i][1] ) ;
	for( int i=0; i<N; i++ )
		scanf("%d", &arr[i] ) ;

	for( int i=E-1; i>=0; i-- )
		if( sct[i][0]==2 )
			rotaA( sct[i][1] ) ;
		else
			rotaB( sct[i][1] ) ;

	for( int i=0; i<N; i++ )
		printf("%d ", arr[i] ) ;
	printf("\n" ) ;

	return 0 ;
}


