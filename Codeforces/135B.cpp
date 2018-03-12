#include <algorithm>
#include <cstdio>
#include <iostream>
#include <utility>
using namespace std ;
typedef pair<int,int> par;
#define x first
#define y second

bool rect( par A, par B, par C, par D ) {
	int sup = 0 ;
	par arr[4] ;
	arr[0] = A ;
	arr[1] = B ;
	arr[2] = C ;
	arr[3] = D ;
	
	for( int i=0; i<4; i++ ) {
		int P, Q, R ;
		P  = abs(arr[i].x-arr[(i+1)%4].x)*abs(arr[i].x-arr[(i+1)%4].x) ;
		P += abs(arr[i].y-arr[(i+1)%4].y)*abs(arr[i].y-arr[(i+1)%4].y) ;
		
		Q  = abs(arr[(i+2)%4].x-arr[(i+1)%4].x)*abs(arr[(i+2)%4].x-arr[(i+1)%4].x) ;
		Q += abs(arr[(i+2)%4].y-arr[(i+1)%4].y)*abs(arr[(i+2)%4].y-arr[(i+1)%4].y) ;
		
		R  = abs(arr[i].x-arr[(i+2)%4].x)*abs(arr[i].x-arr[(i+2)%4].x) ;
		R += abs(arr[i].y-arr[(i+2)%4].y)*abs(arr[i].y-arr[(i+2)%4].y) ;
		
	}
	
	for( int i=0; i<4; i++ ) {
		sup += arr[i].x*arr[(i+1)%4].y ;
		sup -= arr[i].y*arr[(i+1)%4].x ;
	}
	
	if( !sup )
		return 0 ;

	for( int i=0; i<4; i++ ) {
		int P, Q, R ;
		P  = abs(arr[i].x-arr[(i+1)%4].x)*abs(arr[i].x-arr[(i+1)%4].x) ;
		P += abs(arr[i].y-arr[(i+1)%4].y)*abs(arr[i].y-arr[(i+1)%4].y) ;
		
		Q  = abs(arr[(i+2)%4].x-arr[(i+1)%4].x)*abs(arr[(i+2)%4].x-arr[(i+1)%4].x) ;
		Q += abs(arr[(i+2)%4].y-arr[(i+1)%4].y)*abs(arr[(i+2)%4].y-arr[(i+1)%4].y) ;
		
		R  = abs(arr[i].x-arr[(i+2)%4].x)*abs(arr[i].x-arr[(i+2)%4].x) ;
		R += abs(arr[i].y-arr[(i+2)%4].y)*abs(arr[i].y-arr[(i+2)%4].y) ;
		
		if( P+Q != R  )
			return 0 ;
	}
	
	return 1 ;
}

bool cuad( par A, par B, par C, par D ) {
	par arr[4] ;
	arr[0] = A ;
	arr[1] = B ;
	arr[2] = C ;
	arr[3] = D ;
	int tam[4] ;
	
	for( int i=0; i<4; i++ ) {
		tam[i]  = abs(arr[i].x-arr[(i+1)%4].x)*abs(arr[i].x-arr[(i+1)%4].x) ;
		tam[i] += abs(arr[i].y-arr[(i+1)%4].y)*abs(arr[i].y-arr[(i+1)%4].y) ;
		if( i && tam[i]!=tam[i-1] )
			return 0 ;
	}
	
	return 1 ;
}

int main() {
	pair<int,par> arr[8] ;
	
	for( int i=0; i<8; i++ ) {
		scanf("%d%d", &arr[i].y.x, &arr[i].y.y ) ;
		arr[i].x = i ;
	}
	sort( arr, arr+8 ) ;
	
	do {
		if(   rect(arr[4].y,arr[5].y,arr[6].y,arr[7].y)   &&  cuad(arr[4].y,arr[5].y,arr[6].y,arr[7].y)  &&  rect(arr[0].y,arr[1].y,arr[2].y,arr[3].y)    ) {
			printf("YES\n" ) ;				
			for( int i=4; i<8; i++ )
				printf("%d ", arr[i].x+1 ) ;
			printf("\n" ) ;						
			for( int i=0; i<4; i++ )
				printf("%d ", arr[i].x+1 ) ;
			printf("\n" ) ;		
			return 0 ;
		}
	}while( next_permutation(arr,arr+8)  )  ;
	
	printf("NO\n" ) ;
	
	return 0 ;
}
