#include <stdio.h>

int main() {
	freopen( "data.in", "r", stdin ) ;
	freopen( "data.out", "w", stdout ) ;
	
	int a, b ;
	
	while( scanf("%d%d", &a, &b ) != EOF  )  
		printf("%d\n", a+b ) ;
		
	return 0 ;
}
