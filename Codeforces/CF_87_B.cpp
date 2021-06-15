#include <iostream>
#include <cstdio>
#include <algorithm>
#include <map>
#include <string>
using namespace std ;

map <string,int> val ;

int main() {
	int N ;
	string A, B, C ;
	int w, v ;
	
	val[ "void" ] = 0 ;
	val[ "errtype" ] = -1 ;
	
	scanf("%d", &N ) ;
	while( N ) {
		N -- ;
		cin >> A >> B ;
		if( A=="typedef" ) {
			cin >> C ;
			w = 0 ;
			
			while( B[0] == '&' ) {
				w -- ;
				B = B.substr( 1, B.size()-1 ) ;
			}
			while( B[ B.size()-1 ] == '*' ) {
				w ++ ;
				B = B.substr( 0, B.size()-1 ) ;
			}
			
			if( val.find( B ) == val.end()  )  {
				val[C] = -1 ;
				continue ;
			}
			v = val[B] ;
			if( v<0 ) {
				val[C] = -1 ;
				continue ;
			}
			
			
			w = max( w+v, -1 ) ;
			val[C] = w ;
		}
		else {
			w = 0 ;
			while( B[0] == '&' ) {
				w -- ;
				B = B.substr( 1, B.size()-1 ) ;
			}
			while( B[ B.size()-1 ] == '*' ) {
				w ++ ;
				B = B.substr( 0, B.size()-1 ) ;
			}
			
			if( val.find( B ) == val.end()  )  
				v = -1 ;
			else
				v = val[B] ;
			if( v<0 ) {
				printf("errtype\n" ) ;
				continue ;
			}
			
			w = max( w+v, -1 ) ;
			if( w<0 ) {
				printf("errtype\n" ) ;
				continue ;
			}
			
			printf("void" ) ;
			while( w ) {
				w -- ;
				printf("*") ;
			}
			printf("\n" ) ;
		}
	}
	
	return 0 ;
}
