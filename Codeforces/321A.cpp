#include <cstdio>
#include <algorithm>
#include <queue>
#include <iostream>
#include <map>
#include <set>
#include <cmath>
#include <string>
#include <cstring>
#include <list>
using namespace std ;
#define par pair< int,int >
#define r first
#define c second

par paso( par pos, char dir ) {
	if( dir=='U' )
		pos.r ++ ;
	else if( dir=='D' )
		pos.r -- ;
	else if( dir=='R' )
		pos.c ++ ;
	else
		pos.c -- ;
	return pos ;
}

int main() {
	par fin, pos, bl=par(0,0) ;
	int K ;
	int a, b ;
	string S ;

	cin >> fin.c >> fin.r >> S ;
	for( int i=0; i<S.size(); i++ ) {
		bl = paso( bl, S[i] ) ;
	}

	for( int w=0; w<S.size(); w++ ) {
		par rd = par( 0, 0 ) ;

		for( int i=0; i<w; i++ ) {
			rd = paso( rd, S[i] ) ;
		}
		rd.r = fin.r-rd.r ;
		rd.c = fin.c-rd.c ;

		K = min( (bl.r!=0)? rd.r/bl.r : (1<<30), (bl.c!=0)? rd.c/bl.c : (1<<30) ) ;
		K %= (1<<30) ;
		if( K<0 ) {
			continue ;
		}


		pos = par( K*bl.r, K*bl.c ) ;

		if( pos==rd ) {
			printf("Yes\n" ) ;
			return 0 ;
		}

	}
	
	printf("No\n" ) ;

	return 0 ;
}


