#include "cmp.h"

void remember(int n) {
	int c=0, w ;
	for( w=0; w<12; w++ ) {
		if( n & (1<<w)  )
			c ++ ;
	}
	if( c>6 ) {
		bit_set(13) ;
		n = ( (1<<12)-1 ) - n ;
	}
	
	for( w=0; w<12; w++ ) 
		if( n & (1<<w)  )
			bit_set(w+1) ;
}

int compare(int b) {
	int a=0, w ;
	
	for( w=0; w<12; w++ ) {
		if( bit_get(w+1)  )
			a += (1<<w) ;
	}
	if( bit_get(13) )
		a = ( (1<<12)-1 ) - a ;
	
	if( b<a ) 
		return -1 ;
	if( b>a )
		return 1 ;
	return 0 ;
}

