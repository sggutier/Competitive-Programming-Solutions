#include <cstdio>
#include <algorithm>
#include <iostream>
#include <utility>
#include <queue>
using namespace std ;
const int lim = 21 ;
const int mod = 12 ;
const int limK = 1000006 ;

int dr[] = { -1, 0, 1, 0 } ;
int dc[] = { 0, 1, 0, -1 } ;
char nom[] = "NESW" ;

struct mapa {
    int R, C, G ;
    char mapa[lim][lim+4] ;
    int grdX[lim], grdY[lim], grdD[lim], grdT[lim] ;
	int clc[lim][mod] ;

	void calc() {
		for( int z=0; z<mod; z++ ) {
        for( int i=0; i<G; i++ ) {
            int c=z%(grdT[i]*2) ;
            c = min(c,grdT[i]) - max(0, c-grdT[i]) ;
			clc[i][z] = c ;
		}
		}
	}

    bool sePuedeEsp( int x, int y, int x2, int y2, int z, int z2 ) {
        if( x>=R )
            return 1 ;
        for( int i=0; i<G; i++ ) {
            int a=grdX[i] + clc[i][z]*dr[grdD[i]], b=grdY[i] + clc[i][z]*dc[grdD[i]] ;
			int a2=grdX[i] + clc[i][z2]*dr[grdD[i]], b2=grdY[i] + clc[i][z2]*dc[grdD[i]] ;
            if( a==x2 && b==y2 && a2==x && b2==y )
                return 0 ;
        }
        return 1 ;
    }
    bool sePuede( int x, int y, int z ) {
        if( x>=R )
            return 1 ;
        for( int i=0; i<G; i++ ) {
            int a=grdX[i] + clc[i][z]*dr[grdD[i]], b=grdY[i] + clc[i][z]*dc[grdD[i]] ;
            if( a==x && b==y )
                return 0 ;
        }
        return 1 ;
    }
};

int toNum( int r1, int c1, int r2, int c2, int z ) {
	return c1 + r1*lim + c2*lim*lim + r2*lim*lim*lim + z*lim*lim*lim*lim ;
}

void numTo( int &r1, int &c1, int &r2, int &c2, int &z, int W ) {
	c1 = W%lim ;
	W /= lim ;
	r1 = W%lim ;
	W /= lim ;
	c2 = W%lim ;
	W /= lim ;
	r2 = W%lim ;
	W /= lim ;
	z = W%lim ;
}

struct cola {
	int arr[limK], ini, fin ;
	cola() {
		ini = 0 ;
		fin = 0 ;
	}
	void push( int W ) {
		arr[fin] = W ;
		fin = (fin+1)%limK ;
	}
	void pop() {
		ini = (ini+1)%limK ;
	}
	int front() {
		return arr[ini] ;
	}
	bool empty() {
		return ini==fin ;
	}
};

int minP[lim*lim*lim*lim*mod + limK ] ;
int ant[lim*lim*lim*lim*mod + limK ] ;
char tipAnt[lim*lim*lim*lim*mod + limK ] ;
cola Q ;

int main() {
	mapa foo[2] ;
	int posX[2], posY[2] ;
	int tRes = 0 ;
	int res[10005] ;

	for( int w=0; w<2; w++ ) {
		scanf("%d%d", &foo[w].R, &foo[w].C ) ;
		for( int i=0; i<foo[w].R; i++ ) {
			scanf("%s", foo[w].mapa[i] ) ;
			for( int j=0; j<foo[w].C; j++ ) {
				if( foo[w].mapa[i][j] == 'X' ) {
					foo[w].mapa[i][j] = '.' ;
					posX[w] = i ;
					posY[w] = j ;
				}
			}
		}
		scanf("%d", &foo[w].G ) ;
		for( int i=0; i<foo[w].G; i++ ) {
			char tmp[lim+5] ;
			scanf("%d%d%d", &foo[w].grdX[i], &foo[w].grdY[i], &foo[w].grdT[i] ) ;
			scanf("%s", tmp ) ;
			foo[w].grdX[i] -- ;
			foo[w].grdY[i] -- ;
			foo[w].grdT[i] -- ;
			for( int j=0; j<4; j++ )
				if( tmp[0]==nom[j] )
					foo[w].grdD[i] = j ;
		}
	}

	foo[0].calc() ;
	foo[1].calc() ;

	minP[toNum(posX[0], posY[0], posX[1], posY[1],0)] = 1  ;
	ant[toNum(posX[0], posY[0], posX[1], posY[1],0)] = -1 ;
	Q.push( toNum(posX[0], posY[0], posX[1], posY[1],0)  ) ;
	while( !Q.empty() ) {
		int a, b, x, y, w ;
		int pos = Q.front() ;
		numTo( a, b, x, y, w, pos ) ;
		Q.pop() ;
		if( minP[pos]>10000 ) {
			printf("-1\n" ) ;
			return 0 ;
		}
		if( x==foo[1].R && a==foo[0].R ) {
			printf("%d\n", minP[pos]-1 ) ;
			while( ant[pos]!=-1 ) {
				res[tRes++] = tipAnt[pos] ;
				pos = ant[pos] ;
			}
			for( int i=tRes-1; i>=0; i-- )
				printf("%c\n", res[i] ) ;
			return 0 ;
		}

		for( int d=0; d<4; d++ ) {
			int a2=a, b2=b, x2=x, y2=y, w2=(w+1)%mod ; 
			if( a2>=foo[0].R ) {
			}
			else {
				a2 += dr[d] ;
				b2 += dc[d] ;
				if( a2<0 || a2>=foo[0].R || b2<0 || b2>=foo[0].C ) {
					a2 = foo[0].R ;
					b2 = 0 ;
				}
				else if( foo[0].mapa[a2][b2]=='#' ) {
					a2 = a ;
					b2 = b ;
				}
			}
			if( x2>=foo[1].R ) {
			}
			else {
				x2 += dr[d] ;
				y2 += dc[d] ;
				if( x2<0 || x2>=foo[1].R || y2<0 || y2>=foo[1].C ) {
					x2 = foo[1].R ;
					y2 = 0 ;
				}
				else if( foo[1].mapa[x2][y2]=='#' ) {
					x2 = x ;
					y2 = y ;
				}
			}

			if(  foo[0].sePuede(a2,b2,w2) && foo[1].sePuede(x2,y2,w2)   ) {
				if( foo[0].sePuedeEsp(a,b,a2,b2,w,w2) && foo[1].sePuedeEsp(x,y,x2,y2,w,w2) ) {
					int tmp = toNum( a2, b2, x2, y2, w2 ) ;
					if( minP[tmp] )
						continue ;
					minP[tmp] = minP[pos] +1 ;
					ant[tmp] = pos ;
					tipAnt[tmp] = nom[d] ;
					Q.push(tmp) ;
				}	
			}
		}
	}

	printf("-1\n" ) ;

    return 0 ;
}
