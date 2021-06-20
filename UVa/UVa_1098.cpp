#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std ;
const int lim = 8 ;

int N, M, K ;
int kX[4], kY[4], dk[4] ;
bool usd[lim][lim] ;
bool usd2[lim][lim] ;
int res ;
int ult = 1 ;
int dr[] = { -1, 0, 1, 0 } ;
int dc[] = { 0, 1, 0, -1 } ;

int rem( int r, int c ) {
    if( r<0 || r>=N || c<0 || c>=M )
	return 0 ;
    if( usd[r][c] || usd2[r][c] )
	return 0 ;
    usd2[r][c] = 1 ;
    return 1 + rem( r-1, c ) + rem(r, c+1) + rem(r+1, c) + rem(r,c-1) ;
}

void busca( int r, int c, int stps, int nObj ) {
    if( r<0 || r>=N || c<0 || c>=M ) {
	return ;
    }
    if( usd[r][c] ) {
	return ;
    }
    if( r==0 && c==1 ) {
	if( stps==K )
	    res ++ ;
	return ;
    }
    if( r==kX[nObj] && c==kY[nObj] ) {
	if( stps!=dk[nObj] )
	    return ;
	nObj ++ ;
    }
    else if( dk[nObj]<=stps ) {
	return ;
    }
    else if( abs(kX[nObj]-r) + abs(kY[nObj]-c) + stps > dk[nObj] ) {
	return ;
    }
    else {
	for( int i=nObj+1; i<3; i++ ) {
	    if( kX[i]==r && kY[i]==c )
		return ;
	}
    }
    usd[r][c] = 1 ;
    memset( usd2, 0, sizeof(usd2) ) ;
    if( rem( 0, 1 ) < K-stps ) {
	usd[r][c] = 0 ;
	return ;
    }

    busca( r, c-1, stps+1, nObj ) ;
    busca( r-1, c, stps+1, nObj ) ;
    busca( r, c+1, stps+1, nObj ) ;
    busca( r+1, c, stps+1, nObj ) ;
    usd[r][c] = 0 ;

}

int main() {
    kX[3] = 0 ;
    kY[3] = 1 ;
    int T = 1 ;
    while( scanf("%d%d", &N, &M)!=EOF && (N||M) ) {
	memset( usd, 0, sizeof(usd) ) ;
	res = 0 ;
	K = N*M ;
	for( int i=0; i<3; i++ ) {
	    dk[i] = ((i+1)*K)/4 ;
	    scanf("%d%d", &kX[i], &kY[i] ) ;
	}
	dk[3] = K ;
	busca( 0, 0, 1, 0 ) ;
	printf("Case %d: %d\n", T++, res ) ;
    }
    return 0 ;
}
