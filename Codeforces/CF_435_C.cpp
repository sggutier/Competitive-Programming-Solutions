#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
using namespace std ;

char res[2005][1005] ;

int main() {
  int N ;
  int r=1000, c=0 ;
  int tot=0, minH=1000, maxH=1000 ;
  int arr[1005] ;

  scanf("%d", &N ) ;
  for( int i=0, y=1000, dir=-1; i<N; i++, dir*=-1 ) {
    scanf("%d", &arr[i] ) ;
    y += (arr[i]-1)*dir ;
    minH = min( minH, y ) ;
    maxH = max( maxH, y ) ;
    c += arr[i] ;
  }

  for( int i=minH; i<=maxH; i++ )
    for( int j=0; j<c; j++ )
      res[i][j] = ' ' ;

  c = 0 ;
  for( int i=0, y=1000, dir=-1; i<N; i++, dir*=-1 ) {
    for( int j=1; j<arr[i]; j++, c++, y+=dir ) {
      if( dir==-1 )
	res[y][c] = '/' ;
      else
	res[y][c] = '\\' ;
    }
    if( dir==-1 ) 
      res[y][c++] = '/' ;
    else
      res[y][c++] = '\\' ;
  }

  for( int i=minH; i<=maxH; i++ )
    printf("%s\n", res[i] ) ;

  return 0 ;
}
