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
#include <stack>
using namespace std ;
const int lim = 35 ;

bool fin = false ; 
int R, C, T, G ;
char mapa[lim][lim] ;
list <int> adj[lim*lim*2] ;
stack <int> Q ;
int lowLink[lim*lim*2] ;
int grp[lim*lim*2], tamGrp[lim*lim*2] ;
bool usd[lim*lim*2] ;
int dr[] = { -2, -2, -1, -1, 1, 1, 2, 2 } ;
int dc[] = { -1, 1, -2, 2, -2, 2, -1, 1 } ;

void tarjan( int pos ) {
	grp[pos] = G ;
	lowLink[pos] = G ;
	usd[pos] = 1 ;
	Q.push(pos) ;
	G++ ;

	for( list<int>::iterator it=adj[pos].begin(); it!=adj[pos].end(); it++ ) {
		if( !grp[*it] ) {
			tarjan(*it) ;
			lowLink[pos] = min( lowLink[pos], lowLink[*it]  ) ;
		}
		else if( usd[*it] ) {
			lowLink[pos] = min( lowLink[pos], lowLink[*it]  ) ;
		}
	}

	if( grp[pos]==lowLink[pos] ) { // Si la madrola esta es su propia raiz (nadie estaba antes que ella)
		printf("------\n" ) ;
		while( Q.top()!=pos ) {
			usd[ Q.top() ] = 0 ;
			lowLink[ Q.top() ] = lowLink[pos] ;
			if( Q.top() >= T  )
				printf("-(%d %d) ", (Q.top()-T)/C, (Q.top()-T)%C ) ;
			else
				printf("+(%d %d) ", (Q.top())/C, (Q.top())%C ) ;
			if( Q.top()<T )
				tamGrp[grp[pos]] ++ ;
			Q.pop() ;
		}
		usd[ Q.top() ] = 0 ;
		if( Q.top() >= T  )
			printf("-(%d %d) ", (Q.top()-T)/C, (Q.top()-T)%C ) ;
		else
			printf("+(%d %d) ", (Q.top())/C, (Q.top())%C ) ;
		if( Q.top()<T )
			tamGrp[grp[pos]] ++ ;
		printf(" -- %d\n", tamGrp[grp[pos]] ) ;
		getchar() ;
		Q.pop() ;
	}
}

void caso() {
	int res = 0 ;

	scanf("%d%d", &R, &C ) ;
	for( int i=0; i<R; i++ ) 
		scanf("%s", mapa[i] ) ;
	T = R*C ;
	G = 1 ;
	for( int i=0; i<2*T; i++ ) 
		adj[i].clear() ;
	memset( grp, sizeof(grp), 0 ) ;
	memset( lowLink, sizeof(lowLink), 0 ) ;
	memset( tamGrp, sizeof(tamGrp), 0 ) ;
	memset( usd, sizeof(usd), 0 ) ;

	for( int i=0; i<R; i++ ) {
		for( int j=0; j<C; j++ ) {
			if( mapa[i][j]=='#' ) 
				continue ;
			for( int d=0, x, y, a=i*C + j, b; d<8; d++ ) {
				x = i + dr[d] ;
				y = j + dc[d] ;
				if( x<0 || x>=R || y<0 || y>=C || mapa[x][y]=='#' )
					continue ;
				b = x*C + y ;
				adj[a].push_back( b + T ) ;
				adj[a + T].push_back( b ) ;
			}
		}
	}

	for( int i=0; i<T; i++ ) {
		printf(" + %d -> ", i ) ;
		for( list<int>::iterator it=adj[i].begin(); it!=adj[i].end(); it++ )  {
			if( *it >= T  )
				printf("-%d ", (*it)-T ) ;
			else
				printf("+%d ", *it ) ;
		}
		printf("\n" ) ;
		printf(" - %d -> ", i ) ;
		for( list<int>::iterator it=adj[i+T].begin(); it!=adj[i+T].end(); it++ )  {
			if( *it >= T  )
				printf("-%d ", (*it)-T ) ;
			else
				printf("+%d ", *it ) ;
		}
		printf("\n" ) ;
	}

	for( int i=0; i<2*T; i++ ) {
		if( mapa[(i%T)/C][(i%T)%C]!='.' || grp[i] ) 
			continue ;
		tarjan(i) ;
	}

	for( int i=0; i<2*T; i++ ) 
		printf("-> %d %d \n", i%T, lowLink[i] ) ;
	printf("\n") ;

	for( int i=0; i<T; i++ ) {
		if( mapa[i/C][i%C]!='.' || usd[ lowLink[i] ] )
		       continue ;	
		usd[ lowLink[i] ] = 1 ;
		usd[ lowLink[i+T] ] = 1 ;
		printf(" *** %d %d -> %d %d ", tamGrp[lowLink[i]], tamGrp[lowLink[i+T]], lowLink[i], lowLink[i+T] ) ;
		printf(" -- %d\n", i ) ;
		res += max( tamGrp[lowLink[i]], tamGrp[lowLink[i+T]] ) ;
	}

	printf("%d\n", res ) ;
}

int main() {
	caso() ;

	return 0 ;
}


