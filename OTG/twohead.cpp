#include <iostream>
#include <algorithm>
#include <cstdio>
#include <utility>
#include <list>
using namespace std ;
#define lim 50007
typedef pair<int,bool> par ;
#define f first
#define s second


int N ;
int padre[lim] ;
int rang[lim] ;
bool paridad[lim] ;
list <par> odio[lim] ;


par raiz( int pos ) ;
void une( int a, int b, bool p  ) ;


int main() {
	int M, sesiones=1, start=0 ;
	int i, j ;
	char tmpA[5], tmpB[5] ;
	bool tmp ;
	list <par> :: iterator it ;
	int ult = 0 ;
	par w, a, b ;
	int p ;
	
	for( i=0; i<lim; i++ ) {
		padre[i] = i ;
		rang[i] = 0 ;
		paridad[i] = 0 ;
	}
	
	
	scanf("%d%d", &N, &M ) ;
	while( M ) {
		M -- ;
		scanf("%d%s%d%s", &i, tmpA, &j, tmpB  )  ;
		if( i==j )
			continue ;
		i--, j-- ;
		tmp = ( tmpA[0] == tmpB[0] ) ;
		if( i>j )
			swap( i, j ) ;
		odio[j].push_back( par(i,tmp)   )   ;
	}
	
	
	for( i=0; i<N; i++ ) {
		for( it=odio[i].begin(); it!=odio[i].end(); it++  )   {
			w = (*it)  ;
			if( w.f<ult ) 
				continue ;
			a = raiz( w.f ) ;
			b = raiz( i ) ;
			p = a.s ^ b.s ^ w.s ;
			if( a.f == b.f  )  {
				if( p ) {
					sesiones ++ ;
					ult = i ;
					break ;
				}
			}
			else {
				une( a.f, b.f, p ) ;
			}
		}
	}
	
	printf("%d\n", sesiones ) ;
	
	return 0 ;
}

par raiz( int pos ) {
	bool f = 0 ;
	while( padre[pos] != pos  )  {
		f ^= paridad[pos] ;
		pos = padre[pos] ;
	}
	return par( pos, f ) ;
}

void une( int a, int b, bool p  ) {
	a = raiz( a ).f, b = raiz( b ).f ;
	if( a == b ) {
		return ;
	}
	
	if( rang[a] > rang[b]  )  {
		paridad[b] = p ;
		padre[b] = a ;
	} 
	else if( rang[a] < rang[b] ) {
		paridad[a] = p ;
		padre[a] = b ;
	}
	else {
		paridad[a] = p ;
		padre[a] = b ;
		rang[b] ++ ;
	}
}
