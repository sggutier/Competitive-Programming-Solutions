#include <algorithm>
#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
#include <stack>
#include <list>
using namespace std ;
#define lim 1005
#define inf (1LL<<62)

int N, N2 ;
long long dis[lim][lim] ;
long long puntX[lim], puntY[lim] ;
list <int> adj[2*lim] ;

stack <int> Q ;
int C, idx ;
int ridx[2*lim] ;


bool dibuja( long long W ) {
	int i, j ;
	
	for( i=0; i<N2; i++ ) {
		adj[i].clear() ;
		adj[i+N2].clear() ;
	}
	
	for( i=0; i<N2; i++ ) {
		for( j=0; j<N2; j++ ) {
			if( i/2 == j/2 )
				continue ;
			if( dis[i][j] < W ) 
				adj[i].push_back( j+N2 ) ;
		}
		if( i%2 )
			j = -1 ;
		else
			j =  1 ;
		adj[i+N2].push_back( i+j ) ;
		adj[i].push_back( i+j+N2 ) ;
	}
}

void tarjan( int pos ) {
	int raiz = 1 ;
	list <int> :: iterator it ;
	ridx[pos] = idx++ ;
	
	for( it=adj[pos].begin(); it!=adj[pos].end(); it++ ) {
		if( !ridx[ *it ] )
			tarjan( *it ) ;
		if( ridx[pos] > ridx[*it] ) {
			ridx[pos] = ridx[*it] ;
			raiz = 0 ;
		}
	}
	
	if( raiz ) {
		idx -- ;
		while( !Q.empty()  &&  ridx[pos] <= ridx[Q.top()]  )  {
			idx -- ;
			ridx[Q.top()] = C ;
			Q.pop() ;
		}
		ridx[pos] = C-- ;
	}
	else {
		Q.push( pos ) ;
	}
}

bool revisa() {
	int i ;
	for( i=0; i<N2; i++ ) {
		if( ridx[i] == ridx[i+N2]  )
			return 0 ;
	}
	return 1 ;
}


int main() {
	int i, j ;
	long long ini=0LL, fin=(1LL<<30), piv ;
	
	scanf("%d", &N ) ;
	for( i=0; i<N; i++ ) {
		cin >> puntX[2*i] >> puntY[2*i] ;
		cin >> puntX[2*i+1] >> puntY[2*i+1] ;
	}
	N2 = 2*N ;
	
	for( i=0; i<N*2; i++ ) {
		for( j=0; j<N*2; j++ ) {
			dis[i][j] = (puntX[i]-puntX[j])*(puntX[i]-puntX[j])  +  (puntY[i]-puntY[j])*(puntY[i]-puntY[j])    ;
		}		
	}
	
	while( ini<fin ) {
		piv = (ini+fin)/2LL  +  (ini+fin)%2LL 	;
		dibuja(  piv*piv*4  )   ;
		
		C = N2*2 ;
		idx = 1 ;
		memset( ridx, 0, sizeof(ridx)  )  ;
		for( i=0; i<N2*2; i++ )
			if( ridx[i] == 0 )
				tarjan(i) ;
			
		if( revisa() )  
			ini = piv ;
		else
			fin = piv-1 ;
	}
	
	cout << ini << endl ;
	
	return 0 ;
}
