#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std ;

int main() {
	int comp[6] ;
	int res[2][2] ;
	int arr[9] ;
	
	for( int i=0; i<6; i++ )
		scanf("%d", &comp[i] ) ;
	for( int i=0; i<9; i++ ) 
		arr[i] = i+1 ;
	
	do {
		res[0][0] = arr[0] ;
		res[0][1] = arr[1] ;
		res[1][0] = arr[2] ;
		res[1][1] = arr[3] ;
		
		if( res[0][0]+res[0][1]==comp[0] && res[1][0]+res[1][1]==comp[1] )   {
			if( res[0][0]+res[1][0]==comp[2] && res[0][1]+res[1][1]==comp[3] )   {
				if( res[0][0]+res[1][1]==comp[4] && res[0][1]+res[1][0]==comp[5] )   {
					for( int i=0; i<2; i++ ) {
						for( int j=0; j<2; j++ )
							printf("%d ", res[i][j] ) ;
						printf("\n" ) ;
					}
					return 0 ;
				}
			}			
		}
		
	}while( next_permutation(arr,arr+9)  );
	
	printf("-1\n" ) ;
	
	return 0 ;
}
