#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std ;

int main() {
	int N ;
	int pts[1000][2] ;
	int res=0, a=0 ;
	
	scanf("%d", &N ) ;
	for( int i=0; i<N; i++ ) {
		scanf("%d%d", &pts[i][0], &pts[i][1] ) ;
	}
	
	for( int i=0; i<N; i++ ) {
		a = 0 ;
		for( int j=0; j<N; j++ ) {
			if( pts[i][0]==pts[j][0] && pts[i][1]<pts[j][1] )
				a |= (1<<0) ;
			if( pts[i][0]==pts[j][0] && pts[i][1]>pts[j][1] )
				a |= (1<<1) ;
			if( pts[i][0]<pts[j][0] && pts[i][1]==pts[j][1] )
				a |= (1<<2) ;
			if( pts[i][0]>pts[j][0] && pts[i][1]==pts[j][1] )
				a |= (1<<3) ;
		}
		if( a==(1<<4)-1 )
			res ++ ;
	}
	
	printf("%d\n", res ) ;
	
	return 0 ;
}
