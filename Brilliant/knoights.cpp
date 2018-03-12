#include <cstdio>
using namespace std ;

int king( int N, int r ) {
	if( N==1 ) 
		return 0 ;

	int res = king( N-1, r ), k=(r%N) ;

	return (k+res+1)%N ;
}

int main() {
	int x, y ;

	scanf("%d%d", &x, &y ) ;
	printf("%d\n", king(x,y-1)+1 ) ;

	return 0 ;
}


