#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std ;

struct caja {
  int D, id ;
  int arr[10] ;
};

bool operator<( caja A, caja B )  {
  for( int i=0; i<A.D; i++ )
    if( A.arr[i] >= B.arr[i] )
      return 0 ;
  return 1 ;
}

int main() {
  int N, M ;
  int i, j ;
  caja C[30] ;
  int res[30], sig[30] ;
  
  while( scanf("%d%d",&N,&M)  !=  EOF  )   {
    for( i=0; i<N; i++ ) {
      for( j=0; j<M; j++ )
	scanf("%d",&C[i].arr[j]  )  ;
      C[i].D = M ;
      C[i].id = i ;
      sort(  C[i].arr, C[i].arr+M )  ;
    }
    sort(  C,  C+N ) ;
    for( i=N-1; i>=0; i-- ) {
      res[i] = 0 ;
      sig[i] = -1 ;
      for( j=i+1; j<N; j++  )  {
	if(  C[i] < C[j]  &&  res[j]>res[i] )   {
	  res[i] = res[j] ;
	  sig[i] = j ;
	}
      }
      res[i] ++ ;
    }
    j = 0 ;
    for( i=0; i<N; i++ )
      j = max( j, res[i] ) ;
    for( i=0; i<N && res[i]!=j;  i++  )  ;
    printf("%d\n",res[i] ) ;
    printf("%d",C[i].id+1 ) ;
    for( i=sig[i]; i!=-1; i=sig[i] )
      printf(" %d",C[i].id+1 ) ;
    printf("\n");
  }
  
  return 0 ;
}