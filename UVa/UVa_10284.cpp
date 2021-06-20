#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
using namespace std ;

int dr[] = { -1, -1, -1, 0, 1, 1, 1, 0 } ;
int dc[] = { -1, 0, 1, 1, 1, 0, -1, -1 } ;
int cr[] = { -2, -2, -1, -1, 1, 1, 2, 2 } ;
int cc[] = { -1, 1, -2, 2, -2, 2, -1, 1 } ;
bool usd[8][8] ;
char pts[8][10] ;

void peon( int r, int c, int tip ) {
    for( int i=0; i<2; i++ ) {
	int x, y ;
	x = r+dr[ 2*i + 4*tip] ;
	y = c+dc[ 2*i + 4*tip] ;
	if( x>=0 && x<=7 && y>=0 && y<=7  &&  pts[x][y]=='.' ) {
	    usd[x][y] = 1 ;
	}
    }
}

void alfil( int r, int c ) {
    for( int d=0; d<8; d+=2 ) {
	int x=r+dr[d], y=c+dc[d] ;
	while( x>=0 && x<=7 && y>=0 && y<=7  &&  pts[x][y]=='.' ) {
	    usd[x][y] = 1 ;
	    x += dr[d] ;
	    y += dc[d] ;
	}
    }
}

void torre( int r, int c ) {
    for( int d=1; d<8; d+=2 ) {
	int x=r+dr[d], y=c+dc[d] ;
	while( x>=0 && x<=7 && y>=0 && y<=7  &&  pts[x][y]=='.' ) {
	    usd[x][y] = 1 ;
	    x += dr[d] ;
	    y += dc[d] ;
	}
    }
}

void reina( int r, int c ) {
    for( int d=0; d<8; d++ ) {
	int x=r+dr[d], y=c+dc[d] ;
	while( x>=0 && x<=7 && y>=0 && y<=7  &&  pts[x][y]=='.' ) {
	    usd[x][y] = 1 ;
	    x += dr[d] ;
	    y += dc[d] ;
	}
    }
}

void rey( int r, int c ) {
    for( int d=0; d<8; d++ ) {
	int x=r+dr[d], y=c+dc[d] ;	
	if( x>=0 && x<=7 && y>=0 && y<=7  &&  pts[x][y]=='.' ) {
	    usd[x][y] = 1 ;
	    x += dr[d] ;
	    y += dc[d] ;
	}
    }
}

void caballo( int r, int c ) {
    for( int d=0; d<8; d++ ) {
	int x=r+cr[d], y=c+cc[d] ;
	if( x>=0 && x<=7 && y>=0 && y<=7  &&  pts[x][y]=='.' ) {
	    usd[x][y] = 1 ;
	}
    }
}

int main() {
    char S[5005] ;

    while( gets(S) ) {
	int R=0, C=0, N=strlen(S) ;
	memset( usd, 0, sizeof(usd) ) ;
	for( int i=0; i<8; i++ )
	    for( int j=0; j<8; j++ )
		pts[i][j] = '.' ;
	for( int i=0; i<N; i++ ) {
	    if( S[i]=='/' ) {
		R++, C=0 ;
		continue ;
	    }
	    else if( S[i]>='0' && S[i]<='9' ) {
		C += S[i]-'0' ;
		continue ;
	    }
	    else if( S[i]=='P' || S[i]=='p' ) {
		pts[R][C] = S[i] ;
	    }
	    else if( S[i]>='A' && S[i]<='Z' ) {
		pts[R][C] = S[i] -'A' + 'a' ;
	    }
	    else {
		pts[R][C] = S[i] ;
	    }
	    usd[R][C++] = 1 ;
	}
	for( int i=0; i<8; i++ ) {
	    for( int j=0; j<8; j++ ) {
		if( pts[i][j]=='.' )
		    continue ;
		switch( pts[i][j] ) {
		case 'r' :
		    torre(i,j) ;
		    break ;
		case 'n' :
		    caballo(i,j) ;
		    break ;
		case 'b' :
		    alfil(i,j) ;
		    break ;
		case 'k' :
		    rey(i,j ) ;
		    break ;
		case 'q' :
		    reina(i,j) ;
		    break ;
		default:
		    peon(i,j, pts[i][j]=='p' ) ;
		}
	    }
	}
	int bnk = 0 ;
	for( int i=0; i<8; i++ ) {
	    for( int j=0; j<8; j++ ) {
		if( !usd[i][j] ) {
		    bnk ++ ;
		}
	    }
	}
	printf("%d\n", bnk ) ;
    }
    
    return 0 ;
}
