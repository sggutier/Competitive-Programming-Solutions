#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std ;

int marc[40000][200] ;
bool usd[200] ;
int W[200] ;
int K[200] ;

int main() {
	int N,  M ;
	int i, j, k ;
	int A, B ;
	
	scanf("%d",&N ) ;
	M = (N*(N-1))/2  ;
	for( i=0; i<M; i++ ) {
		scanf("%d",&A ) ;
		while( A ) {
			scanf("%d",&B ) ;
			marc[i][B-1]  =  1 ;
			K[B-1] = 1 ;
			A -- ;
		}
	}
	
	if( N==2 ) {
		for( j=0; j<200;  j++  )  {
			if(  marc[0][j]  ) {
				printf("%d %d\n",1,j+1 ) ;
				break ;
			}
		}
		B = 0 ;
		for( i=0; i<200;  i++  )  
			if(  marc[0][i]  )
				B ++ ;
		printf("%d ",B-1 ) ;
		for( j++; j<200; j++ )
			if( marc[0][j] )
				printf("%d ",j+1 ) ;
		cout << endl ;
		return 0 ;
	}
	
	for( i=0; i<M; i++ ) {
		for( j=0; j<200; j++ )  {
			if(  !usd[j]  &&  marc[i][j] )
				break ;
		}
		if( j==200 )
			continue ;
		A = j ;
		for( j=0; j<200; j++ )
			W[j] = marc[i][j] ;
		for( k=0;  k<M;  k++  )  {
			if( k!=i  && marc[k][A]  )  {
				for( j=0;  j<200;  j++  )
					W[j] &= marc[k][j] ;
				k = M ;
			}
		}
		for( j=0; j<200; j++ )  {
			if(  W[j]  &&  usd[j]  )
				break ;
		}
		if( j!=200 )
			continue ;
		B = 0 ;
		for( j=0; j<200; j++ )   {
			if(  W[j]  ) {
				B ++ ;
				usd[j] = 1 ;
				K[j] -- ;
			}
		}
		printf("%d ",B ) ;
		for( j=0; j<200; j++ )
			if( W[j] )
				printf("%d ",j+1 ) ;
		printf("\n");
	}
	for( i=0; i<M; i++ ) {
		for( j=0; j<200; j++ )  {
			if(  !usd[j]  &&  marc[i][j] )
				break ;
		}
		if( j==200 )
			continue ;
		A = j ;
		for( j=0; j<200; j++ )
			W[j] = marc[i][j] ;
		for( k=0;  k<M;  k++  )  {
			if( k!=i  && marc[k][A]  )  {
				for( j=0;  j<200;  j++  )
					W[j] &= marc[k][j] ;
				k = M ;
			}
		}
		for( j=0; j<200; j++ )  {
			if(  W[j]  &&  usd[j]  )
				break ;
		}
		if( j!=200 )
			continue ;
		B = 0 ;
		for( j=0; j<200; j++ )   {
			if(  W[j]  ) {
				B ++ ;
				usd[j] = 1 ;
				K[j] -- ;
			}
		}
		printf("%d ",B ) ;
		for( j=0; j<200; j++ )
			if( W[j] )
				printf("%d ",j+1 ) ;
		printf("\n");
	}
	
	return 0 ;
}
