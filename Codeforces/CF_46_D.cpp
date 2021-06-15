#include <iostream>
#include <algorithm>
#include <cstdio>
#include <list>
using namespace std ;
#define inf (1<<30)

int main() {
	int L, B, F ;
	int N ;
	list <int> ini, fin, id ;
	list <int> :: iterator a, b, c ;
	int r, t ;
	int x ;
	
	scanf("%d%d%d", &L, &B, &F ) ;
	ini.push_back( -B ) ;
	ini.push_back( L+F ) ;
	fin.push_back( -B ) ;
	fin.push_back( L+F ) ;
	id.push_back( -1 ) ;
	id.push_back( -1 ) ;
	scanf("%d", &N ) ;
	for( int i=1; i<=N; i++ ) {
		scanf("%d%d", &r, &t ) ;
		if( r==1 ) {
			a = fin.begin() ;
			b = ini.begin() ;
			c = id.begin() ;
			b ++, c++ ;
			for(  ; b!=ini.end(); a++, b++, c++ ) {
				if(  (*b)-(*a) >= B+F+t  )  
					break ;
			}
			if( b!=ini.end()  ) {
				x = *a ;
				a ++ ;
				ini.insert( b, x+B ) ;
				fin.insert( a, x+B+t ) ;
				id.insert( c, i ) ;
				printf("%d\n", x+B ) ;
			}
			else
				printf("-1\n" ) ;
		}
		else {
			a = ini.begin() ;
			b = fin.begin() ;
			c = id.begin() ;
			for(  ; b!=fin.end(); a++, b++, c++ ) {
				if(  *c == t  )  {
					ini.erase( a ) ;
					fin.erase( b ) ;
					id.erase(  c ) ;
					break ;
				}
			}
		}
	}
	
	return 0 ;
}
