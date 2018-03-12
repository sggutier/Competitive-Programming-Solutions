#include <algorithm>
#include <cstdio>
#include <iostream>
#include <list>
#include <cstring>
using namespace std ;
#define lim 31623
#define limN 100005

int P ;
bool comp[limN] ;
int primo[lim] ;

void criba() {
	for( int i=2; i<=lim; i++ ) {
		if( comp[i] )
			continue ;
		primo[P++] = i ;
		for( int j=i*i; j<=lim; j+=i  )  {
			comp[j] = 1 ;
		}
	}
}

void caso() {
	int a, b ;
	int i, j, w ;
	
	scanf("%d%d", &a, &b ) ;
	
	a = max( a, 2 ) ;
	for( i=a; i<=b; i++ )
		comp[i-a] = 0 ;
		
	for( i=0; i<P && primo[i]<=b; i++   )  {
		w = (a/primo[i])*primo[i] ;
		while( w<a || w==primo[i] )
			w +=  primo[i];
		for( j=w; j<=b;  j+=primo[i]  )
			comp[j-a] = 1 ;
	}
	
	for( int i=a; i<=b; i++  ) {
		if( !comp[i-a]  )
			printf("%d\n", i ) ;
	}
}

int main() {
	int T ;
	
	scanf("%d", &T ) ;
	
	criba() ;
	
	for( int i=0; i<T; i++  ) {
		caso() ;
		printf("\n" ) ;
	}
	
	return 0 ;
}
