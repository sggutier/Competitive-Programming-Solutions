#include <algorithm>
#include <cstdio>
#include <iostream>
#include <utility>
#include <queue>
#include <map>
using namespace std ;
typedef pair<int,int> par ;
#define x first
#define y second
#define lim 100005

struct coor {
	par pos, edg ;
	int id ;
	coor() {
	}
	coor( par A, par B, int H ) {
		pos = A ;
		edg = B ;
		id = H ;
	}
};

bool operator<( coor A, coor B ) {
	return A.pos < B.pos ;
}

int N ;
int res[lim] ;
coor pts[lim] ;
map <par,int> esq ;

void caso() {
	int i, j, carg ;
	priority_queue <par> Q[lim] ;
	par tmp ;
	
	for( i=0; i<N; i++ ) {
		if( esq.find( pts[i].pos ) != esq.end()  ) {
			res[pts[i].id] += esq[pts[i].pos]  ;
		}
		
		Q[pts[i].pos.x-pts[i].edg.x].push( par( pts[i].pos.y-pts[i].edg.y-1 ,1)  ) ;
		Q[pts[i].pos.x-pts[i].edg.x].push( par( pts[i].pos.y+pts[i].edg.y ,2)  ) ;
		
		if( pts[i].edg.x ) {
			Q[pts[i].pos.x+pts[i].edg.x].push( par( pts[i].pos.y-pts[i].edg.y-1 ,1)  ) ;
			Q[pts[i].pos.x+pts[i].edg.x].push( par( pts[i].pos.y+pts[i].edg.y ,2)  ) ;
		}
		cout << i << endl ;
	}
	
	sort( pts, pts+N ) ;
	
	for( i=0; i<N; i=j ) {
		for( j=i; j<N && pts[j].pos.x == pts[i].pos.x; j++ ) {
			Q[ pts[i].pos.x ].push( par(pts[i].pos.y,-pts[i].id)  ) ;
		}
		carg = 0 ;
		while( !Q[pts[i].pos.x].empty()  ) {
			tmp = Q[pts[i].pos.x].top() ;
			Q[pts[i].pos.x].pop();
			if( tmp.y<=0 ) {
				res[tmp.y] += carg ;
			}
			else if( tmp.y==2 ) {
				carg ++ ;
			}
			else {
				carg -- ;
			}
		}
	}
}

int main() {
	int W = 0 ;
	
	scanf("%d", &N ) ;
	for( int i=0; i<N; i++ ) {
		scanf("%d%d", &pts[i].pos.x, &pts[i].pos.y ) ;
		scanf("%d%d", &pts[i].edg.x, &pts[i].edg.y ) ;
		pts[i].id = i ;
		res[i] = 0 ;
	}
	
	for( int i=0; i<N; i++ ) {
		for( int j=0; j<N; j++ ) {
			if(  ( pts[i].pos.x == pts[j].pos.x-pts[j].edg.x || pts[i].pos.x == pts[j].pos.x+pts[j].edg.x )  &&   (pts[i].pos.y >= pts[j].pos.y-pts[j].edg.y && pts[i].pos.y <= pts[j].pos.y+pts[j].edg.y)   )
				res[i] ++ ;
			else if(  ( pts[i].pos.y == pts[j].pos.y-pts[j].edg.y || pts[i].pos.y == pts[j].pos.y+pts[j].edg.y ) &&    (pts[i].pos.x >= pts[j].pos.x-pts[j].edg.x && pts[i].pos.x <= pts[j].pos.x+pts[j].edg.x)   )
				res[i] ++ ;
		}
	}
	
	for( int i=0; i<N; i++ ) {
		if( res[i]%2 )
			W ++ ;
	}
	
	cout << N-W << endl ;
	
	return 0 ;
}


