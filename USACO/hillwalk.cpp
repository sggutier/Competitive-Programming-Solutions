#include <cstdio>
#include <algorithm>
#include <iostream>
#include <utility>
#include <queue>
#include <string>
#include <cstring>
#include <map>
#include <set>
#include <cmath>
#include <list>
#include <stack>
using namespace std ;
const int lim = 100005 ;
#define par pair< int , int >
#define x first
#define y second
#define foo pair< par , par >

int N, W=0 ;
foo arr[lim] ;
priority_queue <foo> Q ;

int main() {
	freopen( "hillwalk.in", "r", stdin ) ;
	freopen( "hillwalk.out", "w", stdout ) ;

	int res = 0 ;
	foo pos ;

	scanf("%d", &N ) ;
	for( int i=0; i<N; i++ ) 
		scanf("%d%d%d%d", &arr[i].x.x, &arr[i].x.y, &arr[i].y.x, &arr[i].y.y ) ;

	sort( arr, arr+N ) ;

	pos = arr[0] ;
	res ++ ;
	//printf("%d %d %d %d\n", pos.x.x, pos.x.y, pos.y.x, pos.y.y ) ;
	for( int i=1; i<N; i++ ) {
		if( arr[i].x.x<=pos.y.x ) {
			Q.push( foo( par(arr[i].x.y,arr[i].x.x),  par( arr[i].y.y, arr[i].y.x)  )   ) ;
			continue ;
		}

		while( !Q.empty() && (Q.top().y.y<=pos.y.x || Q.top().x.x>pos.y.y)   ) 
			Q.pop() ;

		if( Q.empty() )
			break ;

		pos = Q.top() ;
		Q.pop() ;
		pos = foo( par(pos.x.y,pos.x.x),  par(pos.y.y,pos.y.x)  ) ;
		//printf("%d %d %d %d\n", pos.x.x, pos.x.y, pos.y.x, pos.y.y ) ;
		res ++ ;
		i -- ;
	}

	while( !Q.empty() ) {
		//printf("-- %d %d %d %d\n", Q.top().x.x, Q.top().x.y, Q.top().y.x, Q.top().y.y ) ;
		while( !Q.empty() && (Q.top().y.y<=pos.y.x || Q.top().x.x>pos.y.y)   ) 
			Q.pop() ;

		if( Q.empty() )
			break ;

		pos = Q.top() ;
		Q.pop() ;
		pos = foo( par(pos.x.y,pos.x.x),  par(pos.y.y,pos.y.x)  ) ;
		res ++ ;
		//printf("%d %d %d %d\n", pos.x.x, pos.x.y, pos.y.x, pos.y.y ) ;
	}

	printf("%d\n", res ) ;

	return 0 ;
}


