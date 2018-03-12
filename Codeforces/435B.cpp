#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
using namespace std ;


int main() {
  char S[55] ;
  int N, K ;

  scanf("%s%d", S, &K ) ;
  N = strlen(S) ;

  for( int i=0; i<N && K; i++ ) {
    int b=S[i], p=i ;
    for( int j=1; j<=K && i+j<N; j++ ) {
      if( S[i+j]>b ) {
	b = S[i+j] ;
	p = i+j ;
      }
    }
    for( int j=p; j>i; j-- )
      swap( S[j], S[j-1] ) ;
    K -= p-i ;
  }

  printf("%s\n", S ) ;
  
  return 0 ;
}
