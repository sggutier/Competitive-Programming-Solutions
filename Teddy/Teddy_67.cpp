#include <stdio.h>

int main() {
	freopen( "data.in", "r", stdin ) ;
	freopen( "data.out", "w", stdout ) ;
	
	int a ;
	
	scanf("%d", &a ) ;
	while( a  )  {
		a %= 9 ;
		if( a )
			printf("%d\n", a ) ;
		else
			printf("9\n" ) ;
		scanf("%d", &a ) ;
	}
		
	return 0 ;
}

