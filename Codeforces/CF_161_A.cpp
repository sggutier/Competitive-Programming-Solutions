#include <algorithm>
#include <cstdio>
#include <iostream>
#include <utility>
using namespace std ;
typedef pair<int,int> par ;
#define x first
#define y second
#define lim 100005

int main() {
	int N, M ;
	int p, q ;
	par sold[lim], vest[lim] ;
	int R=0 ;
	par res[lim] ;
	
	scanf("%d%d", &N, &M ) ;
	scanf("%d%d", &p, &q ) ;
	for( int i=0; i<N; i++ ) {
		scanf("%d", &sold[i].x ) ;
		sold[i].y = i ;
	}
	for( int j=0; j<M; j++ ) {
		scanf("%d", &vest[j].x ) ;
		vest[j].y = j ;
	}
		
	sort( sold,sold+N ) ;
	sort( vest,vest+M ) ;
	for( int i=0, j=0; i<N && j<M; i++ ) {
		for( ; j<M && sold[i].x-p>vest[j].x; j++ ) ;
		
		if( j==M )
			break ;
		
		if( vest[j].x>=sold[i].x-p  &&   vest[j].x<=sold[i].x+q  ) {
			res[R++] = par( i, j ) ;
			j ++ ;
		}
	}
	
	printf("%d\n", R ) ;
	for( int i=0; i<R; i++ )
		printf("%d %d\n", res[i].x+1, res[i].y+1 ) ;
	
	return 0 ;
}
