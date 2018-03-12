#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std ;
#define lim 1000001

bool gana[lim] ;
bool val[lim] ;

int main() {
	int N, M ;
	int arr[22] ;
	int res = 0 ;
	int i, j ;
	
	
	scanf("%d%d",&N,&M ) ;
	for( i=0; i<M; i++ )
		scanf("%d",&arr[i] ) ;
	
		
	gana[0] = 0 ;
	val[0] = 1 ;
	for(  i=1; i<=N; i++   )  {
		for( j=0; j<M; j++ )  {
			if(  i-arr[j]>=0  &&  val[ i-arr[j] ]   )  {
				val[ i ] = 1  ;
				if( !gana[i-arr[j]]  )
					gana[i] = 1 ;
			}
		}
		if(  val[i]   &&   !gana[i]   )
			res ++ ;
	}
	
	printf("%d\n",res ) ;
	
	return 0 ;
}
