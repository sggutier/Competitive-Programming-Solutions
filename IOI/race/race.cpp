#include "race.h"
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <utility>
#include <stack>
#include <list>
using namespace std ;
typedef pair<int,int>  par ;
#define f first
#define s second
#define limN 200005
#define limK 1000005


int N, K ;
list <par> adj[limN] ;
int padre[limN], numHijos[limN] ;
int minProf[limK], idBusc[limK] ;
int marcW[limN] ;
bool usd[limN] ;


void dfsMarc( int raiz, int pos, int dis ) {		
	stack <par> Q ;
	stack <int> QD ;
	int cam ;
	
	Q.push( par(dis,pos)  ) ;
	QD.push( 1 ) ;
	while( !Q.empty() ) {
		pos = Q.top().s ;
		dis = Q.top().f ;
		cam = QD.top() ;
		Q.pop() ;
		QD.pop() ;
		
		if( dis>K )
			continue ;
		
		if( idBusc[dis]!=raiz  ||  minProf[dis]>cam  ) {
			minProf[dis] = cam ;
			idBusc[dis] = raiz ;
		}
			
		for( list<par>::iterator it=adj[pos].begin(); it!=adj[pos].end(); it++   )  {
			if( it->s == padre[pos]  ||  usd[it->s]  )
				continue ;
			Q.push( par( it->f + dis, it->s )  ) ;
			QD.push(cam+1) ;
		}
	}
	
	
	return ;
}

int dfs( int raiz, int pos, int dis ) {		
	stack <par> Q ;
	stack <int> QD ;
	int res = (1<<30), cam ;
	
	Q.push( par(dis,pos)  ) ;
	QD.push( 1 ) ;
	while( !Q.empty() ) {
		pos = Q.top().s ;
		dis = Q.top().f ;
		cam = QD.top() ;
		Q.pop() ;
		QD.pop() ;
		
		if( dis>K )
			continue ;
			
		if( idBusc[K-dis]==raiz )
			res = min( res, minProf[K-dis] + cam ) ;
			
		for( list<par>::iterator it=adj[pos].begin(); it!=adj[pos].end(); it++   )  {
			if( it->s == padre[pos]  ||  usd[it->s]  )
				continue ;
			Q.push( par( it->f + dis, it->s )  ) ;
			QD.push(cam+1) ;
		}
	}
	
	
	return res ;
}

void buscaCentro( int &raiz ) {
	int n2 = numHijos[raiz] ;
	
	while( 1 ) {
		int maxH=-1, posH ;
		for( list<par>::iterator it=adj[raiz].begin(); it!=adj[raiz].end(); it++ ) {
			if(  !usd[it->s]   &&  (it->s)!=padre[raiz]   &&   numHijos[it->s]+1>maxH  ) {
				maxH = numHijos[it->s]+1 ;
				posH = it -> s ;
			}
		}
		if( maxH*2<=n2 )
			break ;
		raiz = posH ;
	}
}

void armaArbol( int raiz ) {
	stack <par> Q ;
	
	Q.push( par(-1,raiz)  ) ;
	while( !Q.empty() ) {
		int pos = Q.top().s, ant=Q.top().f ;
		
		if( marcW[pos]!=raiz ) {
			numHijos[pos] = 0 ;
			padre[pos] = ant ;
			marcW[pos] = raiz ;
			for( list<par>::iterator it=adj[pos].begin(); it!=adj[pos].end(); it++  )  {
				if( !usd[it->s]  &&  it->s !=ant )
					Q.push( par(pos,it -> s) ) ;
			}
		}
		else {
			Q.pop() ;
			if( ant!=-1 )
				numHijos[ant] += numHijos[pos]+1 ;
		}
	}
}


int bajaArbol(int raiz) {
	stack <int> Q ;
	int res = (1<<30), pos ;
	
	minProf[0] = 0 ;
	Q.push( raiz ) ;
	while( !Q.empty() ) {
		pos = Q.top() ;
		Q.pop() ;
		
		armaArbol( pos ) ;
		buscaCentro(pos) ;
		armaArbol( pos ) ;
		usd[pos] = 1 ;
		idBusc[0] = pos ;
		for( list<par>::iterator it=adj[pos].begin(); it!=adj[pos].end(); it++  ) {
			if(  !usd[it->s]   ) {
				res = min( res,  dfs(pos, it->s, it->f)  ) ;
				dfsMarc( pos, it->s, it->f ) ;
				Q.push( it -> s  ) ;
			}
		}
	}
	
	return res ;
}


int best_path(int n, int k, int H[][2], int L[]) {
	int raiz = 0, res ;
	
	N = n ;
	K = k ;
	
	for( int i=0; i<N-1; i++ ) {
		adj[ H[i][0] ].push_back( par(L[i], H[i][1] )  );
		adj[ H[i][1] ].push_back( par(L[i], H[i][0] )  );
	}
	
	for( int i=0; i<N; i++ ) {
		padre[i] = -2 ;
		numHijos[i] = 0 ;
		marcW[i] = -1 ;
	}	
	for( int i=0; i<=K; i++ )
		idBusc[i] = -1 ;
		
	res = bajaArbol(raiz) ;
	if( res==(1<<30) )
		res = -1 ;
		
	return res ;
}
