#include <algorithm>
#include <cstdio>
#include <iostream>
#include <list>
#include <utility>
using namespace std ;
#define lim 40005
#define par pair<int,int>
#define x first
#define y second

int N, M, K ;
par carg[lim] ;
int edg[lim][4] ;
int padre[lim], tam[lim] ;
int dx[] = {-1,0,1,0} ;
int dy[] = {0,1,0,-1} ;
int res[lim] ;
list < int > query[lim][3] ;

int raiz( int pos ) {
    while( padre[pos]!=pos )
        pos = padre[pos] ;
    return pos ;
}

par buscaPos( int &pos ) {
    par res = par( 0, 0 ) ;
    while( padre[pos]!=pos ) {
        res.x += carg[pos].x ;
        res.y += carg[pos].y ;
        pos = padre[pos] ;
    }
    return res ;
}

void une( int A, int B, int S, int D ) {
	par posIni, posFin ;
    //cout << "-->> " << A+1 << " " << B+1 << endl ;

	posIni = buscaPos(A) ;
	posFin = buscaPos(B) ;

    //cout << "     " << posIni.x << " " << posIni.y << endl ;
    //cout << "     " << posFin.x << " " << posFin.y << endl ;
	if( A==B )
        return ;
	if( tam[A]<tam[B] ) {
		swap( A, B ) ;
		D = (D+2)%4 ;
		swap( posIni, posFin ) ;
	}
    //cout << "<<-- " << A+1 << " " << B+1 << endl ;
	posIni.x += dx[D]*S ;
	posIni.y += dy[D]*S ;

    padre[B] = A ;
    tam[A] = max( tam[A], tam[B]+1 ) ;
    carg[B] = posIni ;
    //carg[A] = par( dx[D]*S, dy[D]*S ) ;
}


int main() {
	char S[5] ;

	scanf("%d", &N ) ;
	scanf("%d", &M ) ;
	for( int i=0; i<M; i++ ) {
		scanf("%d%d%d", &edg[i][0], &edg[i][1], &edg[i][2] ) ;
		scanf("%s", S ) ;
		edg[i][0] -- ;
		edg[i][1] -- ;
		if( S[0] == 'W' )
			edg[i][3] = 0 ;
		else if( S[0] == 'N' )
			edg[i][3] = 1 ;
		else if( S[0] == 'E' )
			edg[i][3] = 2 ;
		else
			edg[i][3] = 3 ;
	}
	scanf("%d", &K ) ;
	for( int i=0; i<K; i++ ) {
		int a, b, c ;
		scanf("%d%d%d", &a, &b, &c ) ;
		a--, b--, c-- ;
		query[c][2].push_back( i ) ;
		query[c][0].push_back( a ) ;
		query[c][1].push_back( b ) ;
	}
	for( int i=0; i<N; i++ )
		padre[i] = i ;

	for( int i=0; i<M; i++ ) {
		une( edg[i][0], edg[i][1], edg[i][2], edg[i][3] ) ;
		//une( edg[i][0], edg[i][1], edg[i][2], edg[i][3] ) ;
		for( list<int>::iterator    it=query[i][0].begin(),it2=query[i][1].begin(),it3=query[i][2].begin();      it!=query[i][0].end();     it++, it2++, it3++    ) {
		    int ini, fin, id ;
		    ini = *it ;
		    fin = *it2 ;
		    id = *it3 ;
            par A, B ;
		    //cout << ini+1 << " " << fin+1 << endl ;
            A = buscaPos(ini) ;
            B = buscaPos(fin) ;
			if( ini==fin )
				//res[ id ] = abs( posX[ini]-posX[fin] )   +   abs( posY[ini]-posY[fin] ) ;
				//cout << "     " << A.x << " " << A.y << endl ;
				//cout << "     " << B.x << " " << B.y << endl ;
				res[ id ] = abs( A.x-B.x ) + abs( A.y-B.y ) ;
			else
				res[ id ] = -1 ;
		}
	}

	for( int i=0; i<K; i++ ) {
		printf("%d\n", res[i] ) ;
	}

	return 0 ;
}
