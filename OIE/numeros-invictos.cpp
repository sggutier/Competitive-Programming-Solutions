#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std ;
#define lim 1000006

int P ;
int invictos[lim] ;
char comp[lim] ;

void criba() {
	P = 0 ;
	comp[0] = 1 ;
	comp[1] = 1 ;
	for( int i=2; i*i<lim; i++ ) 
		if( !comp[i] )
			for( int j=i*i; j<lim; j+=i )
				comp[j] = 1 ;
}

int quak(int W) {
	int pot=1, res=0 ;
	while( W ) {
		if( !comp[W%10] ) {
			res += pot*(W%10) ;
			pot *= 10 ;
		}
		W /= 10 ;
	}
	return comp[res]==0 ;
}

int main() {
	int W ;
	
	criba() ;
	for( int i=2; i<lim; i++ ) 
		invictos[i] = invictos[i-1] + quak(i) ;
		
	while( scanf("%d",&W) != EOF  ) {
		printf("%d\n", invictos[W] ) ;
	}
	
	return 0 ;
}
