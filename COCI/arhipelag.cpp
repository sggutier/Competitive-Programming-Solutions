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

int dr[] = { -1, 0, 1, 0 } ;
int dc[] = { 0, 1, 0, -1 } ;
string arr[100] ;
bool mrk[100][100] ;

int main() {
	int N, M ;
	int aX, bX, aY, bY ;

	cin >> N >> M ;
	for( int i=0; i<=M+1; i++ ) {
		arr[0] += "." ;
		arr[ N+1 ] += "." ;
	}
	for( int i=1; i<=N; i++ ) {
		string tmp ;
		cin >> tmp ;
		arr[i] = "." + tmp + "." ;
	}

	aX = N+1, bX=0 ;
	aY = M+1, bY = 0 ;
	for( int i=1; i<=N; i++ ) {
		for( int j=1; j<=M; j++ ) {
			if( arr[i][j]=='.' )
				continue ;
			int tmp = 0 ;
			for( int d=0; d<4; d++ )
				if( arr[ i+dr[d] ][ j+dc[d] ]=='.' )
					tmp ++ ;
			if( tmp<3 ) {
				mrk[i][j] = 1 ;
				aX = min( aX, i ) ;
				aY = min( aY, j ) ;
				bX = max( bX, i ) ;
				bY = max( bY, j ) ;
			}
		}
	}

	for( int i=aX; i<=bX; i++ ) {
		for( int j=aY; j<=bY; j++ )
			printf("%c", mrk[i][j]==1? 'X' : '.' ) ;
		printf("\n" ) ;
	}

	return 0 ;
}


