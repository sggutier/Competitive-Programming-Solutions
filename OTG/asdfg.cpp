#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std ;

int main() {
	FILE *in = fopen("p1.txt", "r" ) ;
	FILE *in2 = fopen("p2.txt", "r" ) ;
	int i ;
	int a, b ;
	int w = 0;
	for( i=0; i<1000; i++ ) {
		fscanf( in, "%d", &a ) ;
		fscanf( in2, "%d", &b ) ;
		if( a!=b ) 
			w ++ ;
	}
	
	printf("%d\n",w ) ;
	
	return 0 ;
}
