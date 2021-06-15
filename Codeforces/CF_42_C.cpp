#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std ;

int main() {
	int arr[4] ;
	int res[2000], R=0 ;
	
	for( int i=0; i<4; i++ ) 
		scanf("%d", &arr[i] ) ;
		
	while( 1 ) {
		int i ;
		
		for( i=0; i<4; i++ ) {
			if( (arr[i]+arr[(i+1)%4])%2 == 0  &&  ( arr[i]!=1 || arr[(i+1)%4]!=1 )  )
				break ;
		}
		if( i==4 ) {
			for( i=0; i<4 && arr[i]==1; i++ ) ;
			if( i==4 )
				break ;
			
			for( i=0; !(arr[i]%2==0 && arr[(i+3)%4]%2==1 && arr[(i+1)%4]%2==1); i++ ) ;
			
			res[R++] = i +1 ;
			res[R++] = (i+3)%4 +1 ;
			
			arr[i] ++ ;
			arr[(i+1)%4] ++ ;
			arr[i] ++ ;
			arr[(i+3)%4] ++ ;
		}
		else {
			if( arr[i]%2 ) {
				res[R++] = (i+1) ;
				arr[i] ++ ;
				arr[(i+1)%4] ++ ;
			}
			else {
				res[R++] = -(i+1) ;
				arr[i] /=2 ;
				arr[(i+1)%4] /=2 ;
			}
		}
	}
	
	for( int i=0; i<R; i++ ) {
		if( res[i] < 0 )
			printf("/") ;
		else
			printf("+") ;
		printf("%d\n", abs(res[i])  )  ;
	}
	
	return 0 ;
}

