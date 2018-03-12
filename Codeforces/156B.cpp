#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std ;
#define lim 100005

int N, V ;
int conf[lim], acc[lim], bcc[lim], totB=0 ;
int verd[lim], totVerd = 0 ;

int main() {
	scanf("%d%d", &N, &V ) ;
	for( int i=1; i<=N; i++ ) {
		scanf("%d", &conf[i] ) ;
		if( conf[i]<0 ) {
			bcc[-conf[i]] ++ ;
			totB ++ ;
		}
		else {
			acc[ conf[i]] ++ ;
		}
	}
	
	for( int i=1; i<=N; i++ ) {
		int q = acc[i] + totB - bcc[i] ;
		if( q==V ) {
			verd[i] = 1 ;
			totVerd ++ ;
		}
	}
	
	for( int i=1; i<=N; i++ ) {
		if( conf[i]<0 ) {			
			if( totVerd-verd[-conf[i]]==totVerd ) 
				printf("Truth\n" ) ;
			else if( totVerd-verd[-conf[i]]==0 ) 
				printf("Lie\n" ) ;
			else
				printf("Not defined\n" ) ;
		}
		else {
			if( totVerd==verd[conf[i]] )
				printf("Truth\n" ) ;
			else if( 0==verd[conf[i]] )
				printf("Lie\n" ) ;
			else
				printf("Not defined\n" ) ;
		}
	}
	
	
	return 0 ;
}
