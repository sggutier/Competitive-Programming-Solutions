#include <cstdio>
#include <algorithm>
#include <iostream>
#include <utility>
using namespace std ;
const int lim = 405 ;
#define par pair<int,int>
#define x first
#define y second

int R, C ;
char arr[lim][lim] ;
par numDia1[lim][lim], numDia2[lim][lim] ;
int sumH[lim][lim], sumV[lim][lim], sumDia1[lim*2][lim], sumDia2[lim*2][lim] ;

void carga() {
  int tmp = 0 ;
  for( int i=R-1; i>=0; i-- ) {
    int x=i, y=0;
    int q = 0 ;
    while( x<R && y<C ) {
      numDia1[x][y] = par( tmp, q )  ;
      if( q )
	sumDia1[tmp][q] = sumDia1[tmp][q-1] ;
      sumDia1[tmp][q++] += arr[x][y] ;
      x++, y++ ;
    }
    tmp ++ ;
  }
  for( int j=1; j<C; j++ ) {
    int x=0, y=j;
    int q = 0 ;
    while( x<R && y<C ) {
      numDia1[x][y] = par( tmp, q )  ;
      if( q )
	sumDia1[tmp][q] = sumDia1[tmp][q-1] ;
      sumDia1[tmp][q++] += arr[x][y] ;
      x++, y++ ;
    }
    tmp ++ ;
  }

  tmp = 0 ;
  for( int j=0; j<C; j++ ) {
    int x=0, y=j;
    int q = 0 ;
    while( x<R && y>=0 ) {
      numDia2[x][y] = par( tmp, q )  ;
      if( q )
	sumDia2[tmp][q] = sumDia2[tmp][q-1] ;
      sumDia2[tmp][q++] += arr[x][y] ;
      x++, y-- ;
    }
    tmp ++ ;
  }
  for( int i=1; i<R; i++ ) {
    int x=i, y=C-1 ;
    int q = 0 ;
    while( x<R && y>=0 ) {
      numDia2[x][y] = par( tmp, q )  ;
      if( q )
	sumDia2[tmp][q] = sumDia2[tmp][q-1] ;
      sumDia2[tmp][q++] += arr[x][y] ;
      x++, y-- ;
    }
    tmp ++ ;
  }

  for( int i=0; i<R; i++ ) {
    for( int j=0; j<C; j++ ) {
      if( j )
	sumH[i][j] += sumH[i][j-1] ;
      sumH[i][j] += arr[i][j] ;
    }
  }
  for( int j=0; j<C; j++ ) {
    for( int i=0; i<R; i++ ) {
      if( i )
	sumV[j][i] += sumV[j][i-1] ;
      sumV[j][i] += arr[i][j] ;
    }
  }
}

bool total( int mat[lim][lim], int x, int a, int b ) {
  if( a>b )
    swap( a, b ) ;
  return ( mat[x][b] - ( a==0? 0 : mat[x][a-1] ) ) == 0 ;
}

int main() {
  int res = 0 ;
  
  scanf("%d%d", &R, &C ) ;
  for( int i=0; i<R; i++ ) {
    scanf("%s", arr[i] ) ;
    for( int j=0; j<C; j++ ) {
      arr[i][j] -= '0' ;
    }
  }

  carga() ;

  for( int i=0; i<R; i++ ) {
    for( int j=0; j<C; j++ ) {
      for( int k=1; 2*k + j<C; k++ ) {
	int x, y, p, q ;
	x = i, y = j+k*2 ;
	p = i+k, q = j+k ;

	if( p<R && q<C && total( sumH, i, j, y) &&
	    total( sumDia1, numDia1[i][j].x, numDia1[i][j].y, numDia1[p][q].y ) &&
	    total( sumDia2, numDia2[x][y].x, numDia2[x][y].y, numDia2[p][q].y ) )
	  res++; // printf("%d %d, %d %d, %d %d\n", i, j, x, y, p, q ) ;

	p = i-k, q = j+k ;
	if( p>=0 && q<C && total( sumH, i, j, y) &&
	    total( sumDia2, numDia2[i][j].x, numDia2[i][j].y, numDia2[p][q].y ) &&
	    total( sumDia1, numDia1[x][y].x, numDia1[x][y].y, numDia1[p][q].y ) )
	  res++; // printf("%d %d, %d %d, %d %d\n", i, j, x, y, p, q ) ;
      }
      
      for( int k=1; 2*k + i<R; k++ ) {
	int x, y, p, q ;
	x = i+k*2, y = j ;
	p = i+k, q = j+k ;

	if( p<R && q<C && total( sumV, j, i, x) &&
	    total( sumDia1, numDia1[i][j].x, numDia1[i][j].y, numDia1[p][q].y ) &&
	    total( sumDia2, numDia2[x][y].x, numDia2[x][y].y, numDia2[p][q].y ) )
	  res++; // printf("%d %d, %d %d, %d %d\n", i, j, x, y, p, q ) ;

	p = i+k, q = j-k ;
	if( p<R && q>=0 && total( sumV, j, i, x) &&
	    total( sumDia2, numDia2[i][j].x, numDia2[i][j].y, numDia2[p][q].y ) &&
	    total( sumDia1, numDia1[x][y].x, numDia1[x][y].y, numDia1[p][q].y ) )
	  res++; // printf("%d %d, %d %d, %d %d\n", i, j, x, y, p, q ) ;
      }

      for( int k=1; i+k<R && j+k<C; k++ ) {
	int x, y, p, q, r, c ;
	x = i+k, y=j+k ;
	p = i, q=j+k ;
	r = i, c = j ;

	//printf("%d %d %d\n", total( sumDia1, numDia1[r][c].x, numDia1[r][c].y, numDia1[x][y].y ) ,
	//total( sumH, r, c, q ), 
	//total( sumV, y, x, p ) ) ;
	if( total( sumDia1, numDia1[r][c].x, numDia1[r][c].y, numDia1[x][y].y ) &&
	    total( sumH, r, c, q ) &&
	    total( sumV, y, x, p ) )
	  res ++; // printf("%d %d, %d %d, %d %d\n", r, c, p, q, x, y ) ;
	
	x = i, y=j ;
	p = i+k, q=j ;
	r = i+k, c = j+k ;

	if( total( sumDia1, numDia1[r][c].x, numDia1[r][c].y, numDia1[x][y].y ) &&
	    total( sumH, r, c, q ) &&
	    total( sumV, y, x, p ) )
	  res ++ ; // printf("%d %d, %d %d, %d %d\n", r, c, p, q, x, y )  ;
	
	x = i, y=j+k ;
	p = i+k, q=j+k ;
	r = i+k, c = j ;

	if( total( sumDia2, numDia2[r][c].x, numDia2[r][c].y, numDia2[x][y].y ) &&
	    total( sumH, r, c, q ) &&
	    total( sumV, y, x, p ) )
	  res ++ ; // printf("%d %d, %d %d, %d %d\n", r, c, p, q, x, y ) ; 
	
	x = i+k, y=j ;
	p = i, q=j ;
	r = i, c = j+k ;

	if( total( sumDia2, numDia2[r][c].x, numDia2[r][c].y, numDia2[x][y].y ) &&
	    total( sumH, r, c, q ) &&
	    total( sumV, y, x, p ) )
	  res ++; // printf("%d %d, %d %d, %d %d\n", r, c, p, q, x, y ) ;
      }
    }
  }

  printf("%d\n", res ) ;
  
  return 0 ;
}
