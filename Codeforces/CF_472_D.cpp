#include <cstdio>
#include <algorithm>
#include <iostream>
#include <queue>
#include <map>
#include <set>
#include <string>
#include <cstring>
#include <utility>
#include <cmath>
#include <list>
using namespace std ;
const int lim = 2005 ;
#define f first
#define s second
typedef long long ll ;
typedef pair< ll, int> par;

int N ;
int adjM[lim][lim] ;
list < par > adjL[lim] ;
bool cDo[lim][lim] ;

bool mete( int pos, int nov ) {
    for( list< par >::iterator it=adjL[pos].begin(); it!=adjL[pos].end(); it++ ) {
	if( adjM[ it->s ][ nov ] + adjM[ it->s ][ pos ] == adjM[ nov ][ pos ] ) {
	    return mete( it->s, nov ) ;
	}
    }
    for( list< par >::iterator it=adjL[pos].begin(); !adjL[pos].empty() &&  it!=adjL[pos].end();  ) {
	if( adjM[ it->s ][ nov ] + adjM[ nov ][ pos ] == adjM[ it->s ][ pos ] ) {
	    par sig = *it ;
	    it = adjL[ pos ].erase( it ) ;
	    adjL[ nov ].push_back( par( adjM[nov][sig.s], sig.s) ) ;
	}
	else
	    it ++ ;
    }
    adjL[ pos ].push_back( par( adjM[pos][nov], nov ) ) ;
    //cout << "-- "  << pos << " " << nov << endl ;
    return 1 ;
}

bool checaR( int rt, int A, int B, ll disA, ll disB ) {
    if( cDo[A][B] )
	return 1 ;
    if( adjM[rt][A] + adjM[rt][B] != disA + disB || adjM[A][B]!=disA + disB )
	return 0 ;
    cDo[A][B] = 1 ;
    cDo[B][A] = 1 ;
    for( list < par >::iterator it=adjL[A].begin(); it!=adjL[A].end(); it++ ) {
	if( !checaR( rt, it->s, B, disA + it->f, disB ) )
	    return 0 ;
    }
    for( list < par >::iterator it=adjL[B].begin(); it!=adjL[B].end(); it++ ) {
	if( !checaR( rt, A, it->s, disA, disB + it->f ) )
	    return 0 ;
    }
    return 1 ;
}

bool checaArb( int pos, ll dis ) { 
    //cout << pos << " " << dis << " " << adjM[0][pos] << endl ;
    if( dis!= adjM[0][pos]  )
	return 0 ;
    for( list< par >::iterator it=adjL[pos].begin(); it!=adjL[pos].end(); it++ ) {
	for( list< par >::iterator it2=adjL[pos].begin(); it2!=adjL[pos].end(); it2++ ) {
	    if( it==it2 )
		continue ;
	    if( !checaR( pos, it->s, it2->s, it->f, it2->f ) ) {
		return 0 ;
	    }
	}
	if( !checaArb( it->s, dis + it->f ) )
	    return 0 ;
    }
    return 1 ;
}

void printaArb( int pos ) {
    printf("%d -> ", pos+1 ) ;
    for( list< par >::iterator it=adjL[pos].begin(); it!=adjL[pos].end(); it++ ) {
	printf("(%2d, %2lld)   ", it->s+1, it->f ) ;
    }
    printf("\n" ) ;
    for( list< par >::iterator it=adjL[pos].begin(); it!=adjL[pos].end(); it++ ) 
	printaArb( it->s ) ;
}

int main() {
    scanf("%d", &N ) ;
    for( int i=0; i<N; i++ ) {
	for( int j=0; j<N; j++ )
	    scanf("%d", &adjM[i][j] ) ;
	if( adjM[i][i]!=0 ) {
	    printf("NO\n" ) ;
	    return 0 ;
	}
    }

    for( int i=0; i<N; i++ ) {
	for( int j=i+1; j<N; j++ ) {
	    if( adjM[i][j]==0 || adjM[i][j] != adjM[j][i] ) {
		printf("NO\n" ) ;
		return 0 ;
	    }
	}
    }

    for( int i=1; i<N; i++ ) {
	if( !mete( 0, i )  ) {
	    printf("NO\n" ) ;
	    return 0 ;
	}
	//printaArb(0)  ;
    }

    //printaArb(0)  ;
    if( !checaArb( 0, 0LL ) )
	printf("NO\n" ) ;
    else
	printf("YES\n" ) ;
    
    return 0 ;
}
