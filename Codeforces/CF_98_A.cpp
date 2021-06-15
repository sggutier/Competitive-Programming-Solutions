#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std ;

struct cub {
	char arr[10] ;
};

bool operator==( cub B, cub A ) {
	int i, w, r ;
	
	for( int k=0; k<6; k++ ) {
				
		for( r=0; r<2; r++ ) {
			for( w=0; w<6; w++ ) {
				for( i=0; i<6 && A.arr[i] == B.arr[(i+w)%6]; i++  )  ;
				if( i==6 )
					return 1 ;
			}
			swap( A.arr[1], A.arr[2] ) ;
			swap( A.arr[4], A.arr[5] ) ;
			for( w=0; w<6; w++ ) {
				for( i=0; i<6 && A.arr[i] == B.arr[(i+w)%6]; i++  )  ;
				if( i==6 )
					return 1 ;
			}
			swap( A.arr[1], A.arr[2] ) ;
			swap( A.arr[4], A.arr[5] ) ;
			
			swap( A.arr[1], A.arr[4] ) ;
			swap( A.arr[2], A.arr[5] ) ;
		}
		
		w = A.arr[0] ;
		for( i=0; i<5; i++ )
			A.arr[i] = A.arr[i+1] ;
		A.arr[5] = w ;
	}
	return 0 ;
}

int main() {
	cub tmp ;
	int R = 0 ;
	cub res[1000] ;
	
	scanf("%s", tmp.arr ) ;
		
	sort( tmp.arr, tmp.arr+6 ) ;
	do {
		int i ;
		for( i=0; i<R; i++ ) {
			if( tmp == res[i] )
				break ;
		}
		if( i==R ) 
			res[R++] = tmp ;
	}while( next_permutation( tmp.arr, tmp.arr+6 )  )  ;
	
	printf("%d\n", R ) ;
	
	return 0 ;
}
