#include <cstdio>
#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
using namespace std ;
const int lim = 1005 ;

int main() {
	int N ;
	int a=1, b=1, c=1 ;
	queue <int> A ;
	priority_queue <int> B ;
	stack <int> C ;
	
	scanf("%d", &N ) ;
	for( int i=0; i<N; i++ ) {
		int x, y ;
		scanf("%d%d", &y, &x ) ;
		if( y==1 ) {
			if( a )
				A.push(x) ;
			if( b )
				B.push(x) ;
			if( c )
				C.push(x) ; 
		}
		else {
			if( a ) {
				if( A.empty() )
					a = 0 ;
				else { 
					int tmp = A.front() ;
					A.pop() ;
					if( tmp!=x )
						a = 0 ;
				}
			}
			if( b ) {
				if( B.empty() )
					b = 0 ;
				else { 
					int tmp = B.top() ;
					B.pop() ;
					if( tmp!=x )
						b = 0 ;
				}
			}
			if( c ) {
				if( C.empty() )
					c = 0 ;
				else { 
					int tmp = C.top() ;
					C.pop() ;
					if( tmp!=x )
						c = 0 ;
				}
			}
		}
	}

	if( a && !b && !c )
		printf("Cola\n" ) ;
	else if( !a && b && !c )
		printf("Prioridad\n" ) ;
	else if( !a && !b && c )
		printf("Pila\n" ) ;
	else if( !a && !b && !c )
		printf("Imposible\n" ) ;
	else
		printf("Ambiguo\n" ) ;

	return 0 ;
}
