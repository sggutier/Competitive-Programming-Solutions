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
#include <stack>
using namespace std ;
const int lim = 505 ;
#define par pair<int,int>
#define r first
#define c second

int R, C ;
char arr[lim][lim] ;
bool usd[lim][lim][4] ;
int dr[] = { -1, 0, 1, 0 } ;
int dc[] = { 0, 1, 0, -1 } ;
char dir[] = "URDL" ;

int main() {
	par ini ;
	int dRes = 0, res=-1 ;

	scanf("%d%d", &R, &C ) ;
	for( int i=0; i<R; i++ ) {
		scanf("%s", arr[i] ) ;
	}
	scanf("%d%d", &ini.r, &ini.c )  ;
	ini.r -- ;
	ini.c -- ;

	for( int d=0; d<4; d++ ) {
		par pos = ini ;
		int w = d, k=0 ;
		memset( usd, 0, sizeof(usd) ) ;
		while( pos.r>=0 && pos.r<R && pos.c>=0 && pos.c<C && !usd[pos.r][pos.c][w] && arr[pos.r][pos.c]!='C' ) {
			usd[pos.r][pos.c][w] = 1 ;
			if( arr[pos.r][pos.c]=='/' ) {
				w = (5-w)%4 ;
			}
			else if( arr[pos.r][pos.c]!='.' ) {
				w = 3-w ;
			}
			pos.r += dr[w] ;
			pos.c += dc[w] ;
			k ++ ;
		}
		if( pos.r<0 || pos.r>=R || pos.c<0 || pos.c>=C || arr[pos.r][pos.c]=='C' ) {
		}
		else {
			k = (1<<30) ;
		}
		if( k>res ) {
			res = k ;
			dRes = d ;
		}
	}

	printf("%c\n", dir[dRes] ) ;
	if( res==(1<<30) )
		printf("Voyager\n" ) ;
	else
		printf("%d\n", res ) ;

	return 0 ;
}

