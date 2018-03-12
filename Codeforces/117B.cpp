#include <algorithm>
#include <iostream>
#include <cstdio>
using namespace std ;

int main() {
	int a, b, mod ;
	int pot=1, sum ;
	int fin ;

	scanf("%d%d", &a, &b ) ;
	scanf("%d", &mod ) ;

	if( b>=mod-1 ) {
		printf("2\n" ) ;
		return 0 ;
	}

	for( int i=0; i<9; i++, pot=(pot*10)%mod    )   ;

	if( a )   {
		sum = pot ;
		fin = 1 ;
		do {
			if( (mod-sum)%mod>b  ) {
				printf("1 ") ;
				for( int i=100000000; i>fin; i/=10  )
					 printf("0") ;
				printf("%d\n", fin  ) ;
				return 0 ;
			}
			sum = (sum+pot)%mod ;
			fin ++ ;
		} while( sum!=pot  &&  fin<=a  )  ;
	}

	printf("2\n" ) ;

	return 0 ;
}
