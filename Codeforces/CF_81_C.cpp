#include <iostream>
#include <algorithm>
#include <cstdio>
#include <utility>
using namespace std ;
#define par pair<int,int>
#define f first
#define s second

bool menA( par A, par B ) {
	if( A.f!=B.f )
		return A.f > B.f ;
	return A.s < B.s ;
}

bool menB( par A, par B ) {
	if( A.f!=B.f )
		return A.f > B.f ;
	return A.s > B.s ;
}

int main() {
	int N ;
	int a, b ;
	par arr[100000] ;
	int col[100000] ;
	int i, j ;
	
	scanf("%d%d%d",&N,&a,&b ) ;
	for( i=0; i<N; i++ ) {
		scanf("%d",&arr[i].f ) ;
		arr[i].s = i ;
	}
	
	if( a==b ) {
		for( i=0; i<a; i++ )
			col[i] = 1 ;
		for( ; i<N; i++ )
			col[i] = 2 ;
	}
	else if( a<b ) {
		sort(  arr,  arr+N,  menA ) ;
		for( i=0; i<a; i++ ) 
			col[ arr[i].s ] = 1 ;
		for( ; i<N; i++ ) 
			col[ arr[i].s ] = 2 ;
	}
	else {
		sort(  arr,  arr+N,  menB ) ;
		for( i=0; i<b; i++ ) 
			col[ arr[i].s ] = 2 ;
		for( ; i<N; i++ ) 
			col[ arr[i].s ] = 1 ;
	}
	
	for( i=0; i<N; i++ )
		printf("%d ",col[i] ) ;
	cout << endl ;
	
	return 0 ;
}
