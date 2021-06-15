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
const int lim = 500 ;
const int foo = 250 ;

int arr[lim][lim] ;
int dx[] = { -1, 0, 1, 0 } ;
int dy[] = { 0, 1, 0, -1 } ;

void expand( int x, int y ) {
	if( arr[x][y]<4 )
		return ;
	int a=arr[x][y]/4 ;
	arr[x][y] %= 4 ;
	for( int d=0; d<4; d++ ) 
		arr[x+dx[d]][y+dy[d]] += a ;
	for( int d=0; d<4; d++ ) 
		expand( x+dx[d], y+dy[d] ) ;
}

int main() {
	int Q ;

	scanf("%d%d", &arr[foo][foo], &Q ) ;
	expand( foo, foo ) ;
	for( int i=0; i<Q; i++ ) {
		int a, b ;
		scanf("%d%d", &a, &b ) ;
		if( abs(a)>foo || abs(b)>foo )
			printf("0\n" );
		else
			printf("%d\n", arr[a+foo][b+foo] ) ;
	}

	return 0 ;
}


