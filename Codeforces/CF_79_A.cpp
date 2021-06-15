#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std ;

int main() {
	int X, Y ;
	int i = 0 ;
	
	scanf("%d%d",&X,&Y ) ;
	
	while(  1  )  {
		if( i ) {
			if( Y<2  || 10*X + Y < 22  ) {
				printf("Ciel\n");
				return 0 ;
			}
			if( Y>=22  )  
				Y -= 22 ;
			else if( Y>=12 )
				Y -= 12, X -= 1 ;
			else 
				Y -= 2, X -=2 ;
		}
		else  {
			if( Y<2  || 10*X + Y < 22  ) {
				printf("Hanako\n");
				return 0 ;
			}
			if( X>=2 )
				Y -= 2, X -=2 ;
			else if( X>=1 )
				Y -= 12, X -=1 ;
			else
				Y -= 22 ;
		}
		i = (i+1)%2 ;
	}
	
	return 0 ;
}
