#include <cstdio>
#include <algorithm>
#include <iostream>
#include <utility>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <cmath>
#include <string>
#include <cstring>
#include <vector>
#include <list>
#include <cstdlib>
using namespace std ;
const int lim = 55 ;
#define par pair<int,int>

int R, C ;
char S[lim][lim] ;
int dr[] = { -1, -1, -1, 0, 0, 1, 1, 1 } ;
int dc[] = { -1, 0, 1, -1, 1, -1, 0, 1 } ;

void caso() {
    int Q, N ;
    char tmp[lim] ;
    
    scanf("%d%d", &R, &C ) ;
    for( int i=0; i<R; i++ ) {
	scanf("%s", S[i] ) ;
	for( int j=0; j<C; j++ )
	    S[i][j] = tolower( S[i][j] ) ;
    }
	    

    scanf("%d", &Q ) ;
    for( ; Q; Q-- ) {
	
	scanf("%s", tmp ) ;
	N = strlen(tmp) ;
	for( int i=0; i<N; i++ )
	    tmp[i] = tolower(tmp[i]) ;

	for( int i=0; i<R; i++ ) {
	    for( int j=0; j<C; j++ ) {
		for( int d=0; d<8; d++ ) {
		    bool fnd = 1 ;
		    for( int a=0; a<N; a++ ) {
			if( tmp[a] != S[ i+dr[d]*a ][ j+dc[d]*a ] ) {
			    fnd = 0 ;
			    break ;
			}
		    }
		    if( fnd ) {
			printf("%d %d\n", i+1, j+1 ) ;
			j = C ;
			i = R ;
			break ;
		    }
		}
	    }
	}
    }

    return ;
}

int main() {
    int T ;

    scanf("%d", &T ) ;
    for( int i=0; i<T; i++ ) {
	if( i )
	    printf("\n" ) ;
	caso() ;
    }
    
    return 0 ;
}
