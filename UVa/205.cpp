#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std ;
#define lim 40

int carg[lim] ;

int main() {
	double x=0*1.0, y=0*1.0 ;
	
	for( int a=1; a<=4; a++ ) 
		for( int b=1; b<=4; b++ ) 
			for( int c=1; c<=4; c++ ) 
				for( int d=1; d<=4; d++ ) 
					for( int e=1; e<=4; e++ ) 
						for( int g=1; g<=4; g++ ) 
							for( int h=1; h<=4; h++ ) 
								for( int i=1; i<=4; i++ ) 
									for( int k=1; k<=4; k++ )
										carg[a+b+c+d+e+g+h+i+k] ++ ;
	
	for( int a=1; a<=6; a++ ) {
		for( int b=1; b<=6; b++ ) {
			for( int c=1; c<=6; c++ ) {
				for( int d=1; d<=6; d++ ) {
					for( int e=1; e<=6; e++ ) {
						for( int f=1; f<=6; f++ ) {
						
							for( int i=0; i<lim; i++ ) {
								y += carg[i] ;
								if( i>a+b+c+d+e+f )
									x += carg[i] ;						
							}
						
						}
					}
				}
			}
		}
	}
	
	
	cout << x << " " << y << endl ;
	printf("%0.7f\n", x/y ) ;
	
	return 0 ;
}
