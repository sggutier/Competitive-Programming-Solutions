#include <algorithm>
#include <cstdio>
#include <iostream>
#include <utility>
using namespace std ;
#define par pair<int,int>
#define par2 pair< par, int > 
#define x first
#define y second
#define limT 10005
#define limS 200005

int dis( par A, par B ) {
	return (A.x-B.x)*(A.x-B.x)  +   (A.y-B.y)*(A.y-B.y)   ;
}

int main() {
	int T, S ;
	par2 tar[limT] ;
	par sho[limS] ;
	int res[limT] ;
	int i, j ;
	int ini, fin, piv ;
	
	scanf("%d",&T ) ;
	for( i=0; i<T; i++ ) {
		scanf("%d%d", &tar[i].x.x ,& tar[i].x.y ) ;
		tar[i].x.y *= tar[i].x.y ;
		tar[i].y = i ;
		res[i] = -1 ;
	}
	scanf("%d",&S ) ;
	for( i=0; i<S; i++ ) {
		scanf("%d%d", &sho[i].x , &sho[i].y ) ;
	}
	
	sort( tar, tar+T ) ;
	tar[T] = par2( par(tar[T-1].x.x+1,0),  T  )  ;
	for( i=S-1; i>=0; i-- ) {
		ini = 0, fin=T-1 ;
		while( ini<fin ) {
			piv = (ini+fin)/2 ;
			if( dis( par( tar[piv].x.x, 0 ),  sho[i]  )   <=  dis( par( tar[piv+1].x.x, 0 ),  sho[i]  )      )
				fin = piv ;
			else 
				ini = piv+1 ;
		}
		if( dis( par( tar[ini].x.x, 0 ),  sho[i]  )  <=  tar[ini].x.y   )
			res[ tar[ini].y ] = i+1 ;
		ini ++ ;
		if( dis( par( tar[ini].x.x, 0 ),  sho[i]  )  <=  tar[ini].x.y   )
			res[ tar[ini].y ] = i+1 ;
		ini -= 2 ;
		if( ini>=0 &&  dis( par( tar[ini].x.x, 0 ),  sho[i]  )  <=  tar[ini].x.y   )
			res[ tar[ini].y ] = i+1 ;
	}
	
	j = 0 ;
	for( i=0; i<T; i++ ) 
		if( res[i] != -1 )
			j ++ ;
	printf("%d\n",j ) ;
	for( i=0; i<T; i++ ) 
		printf("%d ", res[i] ) ;
	printf( "\n" ) ;
	
	return 0 ;
}
