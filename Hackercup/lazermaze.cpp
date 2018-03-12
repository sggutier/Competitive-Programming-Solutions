#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cctype>
#include <string>
#include <vector>
#include <utility>
#include <map>
#include <set>
#include <stack>
#include <queue>
using namespace std ;
#define parI pair <int,int>
#define cord pair < parI, int > 
#define p1 first
#define p2 second
#define mkp make_pair
const int inf = (1<<30) ;
const int lim = 105 ;
const int limB = 127 ;
const double eps = 1e-9 ;
const int dr[] = { -1, 0, 1, 0 } ;
const int dc[] = { 0, 1, 0, -1 } ;

char rep[limB] ;

bool valdLms( int R, int C, parI pos ) {
    return (pos.p1>=0
	    and pos.p1<R
	    and pos.p2>=0
	    and pos.p2<C) ;
}

bool valdPos( int R, int C, char S[lim][lim], parI pos ) {
    return valdLms(R,C,pos) and S[pos.p1][pos.p2]=='.' ;
}


bool lazr( int R, int C, char S[lim][lim], parI pos, int tDir ) {
    tDir = (tDir+2)%4 ;
    for( int d=0; d<4; d++ ) {
	parI tmp = pos ;
	while( valdPos(R,C,S,tmp) ) {
	    tmp.p1 += dr[d] ;
	    tmp.p2 += dc[d] ;
	}
	if( valdLms(R,C,tmp)
	    and S[tmp.p1][tmp.p2]!='#'
	    and (S[tmp.p1][tmp.p2]+tDir)%4==d )
	    return false ;
    }
    return true ;
}


void tCase() {
    int R, C ;
    char mapa[lim][lim] ;
    int minP[lim][lim][4] ;
    parI ini, fin ;
    queue <cord> Q ;

    scanf("%d%d", &R, &C ) ;
    for( int i=0; i<R; i++ ) {
	scanf("%s", mapa[i] ) ;
	for( int j=0; j<C; j++ ) {
	    mapa[i][j] = rep[mapa[i][j]] ;
	    if( mapa[i][j]=='S' ) {
		ini = mkp( i, j ) ;
		mapa[i][j] = '.' ;
	    }
	    else if( mapa[i][j]=='G' ) {
		fin = mkp( i, j ) ;
		mapa[i][j] = '.' ;
	    }
	}
    }

    /*
    if( !lazr( R, C, mapa, ini, 0) ) {
	printf("impossible\n" ) ;
	return ;
    }
    */
    memset( minP, 0, sizeof(minP) ) ;
    minP[ini.p1][ini.p2][0] = 1 ;
    Q.push( mkp(ini,0) ) ;

    while( !Q.empty() ) {
	parI pos = Q.front().p1 ;
	int lDir = Q.front().p2 +1 ;
	Q.pop() ;
	// printf("%d %d %d -> %d\n", pos.p1, pos.p2, lDir-1, minP[pos.p1][pos.p2][lDir-1] ) ;
	// getchar() ;
	if( pos==fin ) {
	    printf("%d\n", minP[fin.p1][fin.p2][lDir-1]-1 ) ;
	    return ;
	}
	for( int d=0; d<4; d++ ) {
	    parI pos2 = pos ;
	    pos2.p1 += dr[d] ;
	    pos2.p2 += dc[d] ;
	    if( valdPos(R,C,mapa,pos2)
		and !minP[pos2.p1][pos2.p2][lDir] 
		and lazr(R,C,mapa,pos2,lDir) ) {
		minP[pos2.p1][pos2.p2][lDir] = minP[pos.p1][pos.p2][lDir-1] +1  ;
		Q.push( mkp(pos2,lDir) ) ;
	    }
	}
    }
    printf("impossible\n" ) ;
}

void inicio() {
    for( int i=0; i<limB; i++ )
	rep[i] = i ;
    rep['^'] = 0 ;
    rep['>'] = 1 ;
    rep['v'] = 2 ;
    rep['<'] = 3 ;
}

int main() {
    inicio() ;
    int T ;

    scanf("%d",&T ) ;
    for( int i=1; i<=T; i++ )  {
	printf("Case #%d: ", i ) ;
	tCase() ;
    }
    
    return 0 ;
}
