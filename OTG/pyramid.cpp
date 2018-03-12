#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std ;
#define lim 1005
#define inf (1<<30)

int N, M ;
int A, B ;
int X, Y ;
int mapa[lim][lim]  ;
int sumP[lim][lim], sumW[lim][lim] ;
int resR[lim][lim], resC[lim][lim] ;

int calc( int iR, int iC, int fR, int fC ) {
	if( iR<0 || fR>=N || iC<0 || fC>=M )
		return inf ;
	iR --, iC-- ;
	int res = mapa[fR][fC]  ;
	if( iR>=0 )
		res -= mapa[iR][fC] ;
	if( iC>=0 )
		res -= mapa[fR][iC] ;
	if( iR>=0 && iC>=0 )
		res += mapa[iR][iC] ;
	return res ;
}

int main() {
	int i, j, k ;
	int L[lim], R[lim] ;
	int resX, resY ;
	int res = 0 ;
	
	scanf("%d%d",&M,&N ) ;
	scanf("%d%d",&B,&A ) ;
	scanf("%d%d",&Y,&X ) ;
	for( i=0; i<N; i++ ) {
		for( j=0; j<M; j++ ) {
			scanf("%d",&mapa[i][j] ) ;
			if( i )
				mapa[i][j] += mapa[i-1][j] ;
			if( j )
				mapa[i][j] += mapa[i][j-1] ;
			if( i && j )
				mapa[i][j] -= mapa[i-1][j-1] ;
		}
	}
	
	for( i=0; i<N; i++ ) {
		for( j=0; j<M; j++ ) {
			sumP[i][j] = calc( i, j, i+A-1, j+B-1 ) ;
			sumW[i][j] = calc( i, j, i+X-1, j+Y-1 ) ;
		}
	}
	
	A -= 1+X, B -= 1+Y ;
	for( i=0; i<N; i++ ) {
		for( j=0; j<M; j+=B ) {
			L[B] = inf ;
			for( k=B-1; k>=0; k-- ) {
				L[k] = L[k+1] ;
				if( j+k<M )
					L[k] = min( L[k], sumW[i][j+k]  )  ;
			}
			for( k=0; k<B && j+k<M; k++ ) {
				if( k )
					R[k] = R[k-1] ;
				else
					R[k] = inf ;
				if( k+j+B-1<M )
					R[k] = min( R[k], sumW[i][j+k+B-1] )  ;
				resR[i][j+k] = min( L[k], R[k] ) ;
			}
		}
	}
	for( j=0; j<M; j++ ) {
		for( i=0; i<N; i+=A ) {
			L[A] = inf ;
			for( k=A-1; k>=0; k-- ) {
				L[k] = L[k+1] ;
				if( i+k<N )
					L[k] = min( L[k], resR[i+k][j]  )  ;
			}
			for( k=0; k<A && i+k<N; k++ ) {
				if( k )
					R[k] = R[k-1] ;
				else
					R[k] = inf ;
				if( i+k+A-1<N )
					R[k] = min( R[k], resR[i+k+A-1][j] )  ;
				resC[i+k][j] = min( R[k], L[k] ) ;
			}
		}
	}
	A += 1+X ;
	B += 1+Y ;
	
	for( i=N-A; i>=0; i-- ) 
		for( j=M-B; j>=0; j-- )
			res = max( res, sumP[i][j] - resC[i+1][j+1] )  ;
	for( i=N-A; i>=0; i-- ) {
		for( j=M-B; j>=0; j-- ) {
			if( sumP[i][j] - resC[i+1][j+1] == res ) {
				resX = i ;
				resY = j ;
				i = -1 ;
				j = -1 ;
			}
		}
	}
	
	printf("%d %d\n",resY+1,resX+1 ) ;
	res = resC[resX+1][resY+1]  ;
	A -= 1+X, B -= 1+Y ;
	resX ++, resY++ ;	
	for( j=0; j<B; j++ ) {
		for( i=0; i<A; i++ ) {
			if(  res == sumW[i+resX][j+resY]   )   {
				printf("%d %d\n",resY+j+1,resX+i+1 )  ;
				i = A, j = B ;
			}
		}
	}
	
	return 0 ;
}
