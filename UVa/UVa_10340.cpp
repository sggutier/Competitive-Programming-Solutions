#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
using namespace std ;

char A[1000005], B[1000005] ;

int main() {

    int X, Y ;

    while( scanf("%s%s", A, B ) != EOF  ) {
	X = strlen(A) ;
	Y = strlen(B) ;
	int a=0, b=0;
	while( a<X ) {
	    while( b<Y && B[b]!=A[a] )
		b ++ ;
	    if( b==Y )
		break ;
	    a ++, b++ ;
	}
	if( a==X )
	    printf("Yes\n" ) ;
	else
	    printf("No\n" ) ;
    }
    
    
    return 0 ;
}
