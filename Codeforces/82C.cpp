#include <iostream>
#include <algorithm>
#include <cstdio>
#include <utility>
#include <list>
using namespace std ;
#define par pair<int,int>
#define f first
#define s second
#define lim 5000
#define par2 pair<par,int>


int N ;
par padre[lim] ;
list <par>  adj[lim] ;
int carg[lim][2*lim+5] ;
int res[lim] ;
par prior[lim] ;


void busca(  int  pos,  par  ant )  {
	list <par> :: iterator it ;
	padre[pos] = ant ;
	for( it=adj[pos].begin(); it!=adj[pos].end();  it++  )  {
		if(  (*it).f != ant.f  )
			busca(  (*it).f,  par(  pos,  (*it).s  )   )  ;
	}
}


int main() {
	int i, j, pos ;
	int A, B, C, t, t2 ;
	par tmp ;
	
	scanf("%d",&N ) ;
	for( i=0; i<N; i++ ) {
		scanf("%d",&prior[i].f ) ;
		prior[i].s = i ;
	}
	sort(  prior,  prior+N  ) ;
	for( i=1; i<N; i++  )  {
		scanf("%d%d%d",&A,&B,&C ) ;
		A --, B-- ;
		adj[A].push_back(  par(B,C)   ) ;
		adj[B].push_back(  par(A,C)   ) ;
	}
	
	busca( 0,  par( -1, -1 )   ) ;
	
	for( i=0; i<N; i++ ) {
		pos = prior[i].s ;
		t = 0 ;
		while( pos  )  {
			t2 = 1 ;
			for( j=t;   carg[pos][j]>=padre[pos].s;  j++  )  {
				t2  +=   carg[pos][j]/padre[pos].s   ;
			}
			carg[pos][j] ++ ;
			t += t2 ;
			pos = padre[pos].f ;
		}
		res[ prior[i].s ] = t ;
	}
	
	for( i=0; i<N; i++ ) 
		printf("%d ",res[i] ) ;
	printf("\n");
	
	return 0 ;
}
