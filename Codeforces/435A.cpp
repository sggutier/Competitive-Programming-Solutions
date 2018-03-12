#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std ;

int main() {
  int N, M ;
  int arr[100] ;
  int res = 0 ;

  scanf("%d%d", &N, &M ) ;
  for( int i=0; i<N; i++ )
    scanf("%d", &arr[i] ) ;

  for( int i=0; i<N; i++ ) {
    int j = i, sum=0 ;
    while( j<N && sum+arr[j]<=M ) {
      sum += arr[j++] ;
    }
    i = j-1 ;
    res ++ ;
  }

  printf("%d\n", res ) ;
  return 0 ;

}
  
  
