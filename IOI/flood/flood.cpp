#include <iostream>
#include <cstdio>
#include <algorithm>
#include <utility>
using namespace std ;
#define lim 200005
#define inf (1<<30)


struct coor {
	int x, y ;
	int con[4], id[4], ord[4] ;
	int miId ;
};

bool operator<( coor A, coor B ) {
	if( A.x != B.x )
		return A.x < B.x ;
	return A.y < B.y ;
}

int N, P ;
coor punt[lim] ;
int ref[lim] ;
int R ;
int res[lim*2] ;
int pendpos[lim*4], penddir[lim*4] ;


int main() {
	
	R = 0 ;
	scanf("%d", &N ) ;
	for( int i=0; i<N; i++ ) {
		scanf("%d%d", &punt[i].x, &punt[i].y ) ;
		for( int j=0; j<4; j++ )
			punt[i].ord[j] = -1 ;
		punt[i].miId = i ;
	}
	
	sort( punt, punt+N ) ;
	for( int i=0; i<N; i++ ) {
		ref[ punt[i].miId ] = i ;
	}
	
	scanf("%d", &P ) ;
	int x=-1, y=-1 ;
	for( int i=0; i<P; i++ ) {
		int a, b ;
		scanf("%d%d", &a, &b ) ;
		
		
		a = ref[a-1], b = ref[b-1] ;
		if( a<0 || b<0 || a>=N || b>=N ) {
			x = a, y= b ;
		}
		
		if( punt[b] < punt[a] )
			swap( a, b ) ;
		if( punt[a].x != punt[b].x ) {
			punt[a].id[3] = i ;
			punt[a].ord[3] = inf ;
			punt[a].con[3] = b ;
			punt[b].id[1] = i ;
			punt[b].ord[1] = inf ;
			punt[b].con[1] = a ;
		}
		else {
			punt[a].id[0] = i ;
			punt[a].ord[0] = inf ;
			punt[a].con[0] = b ;
			punt[b].id[2] = i ;
			punt[b].ord[2] = inf ;
			punt[b].con[2] = a ;
		}
	}
	
	
	for( int i=0; i<N; i++ ) {
		int pos, dir, dir2 ;
		
		pos = i, dir=1 ;
		
		for( dir2=(dir+1)%4; dir2!=dir && punt[pos].ord[dir2]<=i;  dir2=(dir2+1)%4  )  ;
		if( dir2==1 )
			continue ;
		
		P = 0 ;
		do {
			//printf("%d %d (%d %d),   ", punt[pos].miId+1, dir, punt[pos].x, punt[pos].y  ) ;
			for( dir2=(dir+1)%4; dir2!=dir && punt[pos].ord[dir2]<=i;  dir2=(dir2+1)%4  )  ;
			
			pendpos[P] = pos ;
			penddir[P] = dir ;
			P ++ ;
				
			punt[pos].ord[dir2] = i ;
			pos = punt[pos].con[dir2] ;
			dir = (dir2+2)%4 ;
			
			if( punt[pos].ord[dir] == i   ) 
				res[R++] = punt[pos].id[dir] ;
			
		} while( pos!= i ) ;
		//printf("\n----------\n" ) ;
		
		//return 0 ;
		
		for( int j=0; j<P; j++ ) {
			punt[ pendpos[j] ].ord[ penddir[j] ] = i ;
		}
		
	}
	
	sort( res, res+R ) ;
	printf("%d\n", R ) ;
	for( int i = 0; i<R; i++ ) {
		printf("%d\n", res[i]+1 ) ;
	}
	
	
	return 0 ;
}

