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
const int lim = 1006 ;

int R, C ;
char mapa[lim][lim] ;
int dr[] = { 1, 0, 1,  1 } ;
int dc[] = { 0, 1, 1, -1 } ;

void caso() {
	int cnt = 0, a=0, b=0 ;

	R = 0 ;
	for( ; R==0 || mapa[R-1][0]!=0; R++ ) {
		gets( mapa[R] ) ;
	}
	R -- ;
	C = strlen(mapa[0]) ;

	for( int i=0; i<R; i++ ) {
		for( int j=0; j<C; j++ ) {
			if( mapa[i][j]=='.' )
				continue ;
			cnt ++ ;
			int tmpA = 0, tmpB = 0 ;
			for( int d=0; d<4; d++ ) {
				if( i + dr[d]*3 >= R  ||   j+dc[d]*3 >= C  ||  j+dc[d]*3<0  )
					continue ;
				tmpA = 0 ;
				tmpB = 0 ;
				for( int k=0; k<4; k++ ) {
					int x = i + dr[d]*k,  y = j+dc[d]*k; 
					if( mapa[x][y]=='X' || mapa[x][y]=='T' )
						tmpA ++ ;
					if( mapa[x][y]=='O' || mapa[x][y]=='T' )
						tmpB ++ ;
				}
				if( tmpA == 4 )
					a ++ ;
				else if( tmpB==4 )
					b ++ ;
			}
		}
	}

	if( a )
		printf("X won\n" ) ;
	else if( b )
		printf("O won\n" ) ;
	else if( cnt == R*C )
		printf("Draw\n" ) ;
	else
		printf("Game has not completed\n" ) ;
}

int main() {
	int N ;
	char tmp[lim] ;

	scanf("%d", &N ) ;
	gets(tmp) ;
	for( int i=1; i<=N; i++ ) {
		printf("Case #%d: ", i ) ;
		caso() ;
	}

	return 0 ;
}


