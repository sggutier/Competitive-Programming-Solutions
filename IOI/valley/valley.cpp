#include "valley.h"
#include "graderlib.h"

int find(int N, int x) {
	int ini, fin, piv ;
	int k ;
	
	ini = 0 ;
	fin = N-2; 
	while( ini<fin ) {
		piv = ( ini+fin ) / 2 ;
		if( query(piv) < query( piv+1 )   )
			fin = piv ;
		else
			ini = piv+1 ;
	}	
	k = ini ;
	
	ini = 0 ;
	fin = k ;
	while( ini<fin ) {
		piv = (ini+fin) / 2 ;
		if( query(piv) > x )
			ini = piv+1 ;
		else 
			fin = piv ;
	}
	
	if( query(ini) == x )
		return 1 ;
	
	ini = k ;
	fin = N-1 ;
	while( ini<fin ) {
		piv = (ini+fin) / 2 ;
		if( query(piv) < x )
			ini = piv+1 ;
		else 
			fin = piv ;
	}
	
	return query(ini) == x ;
}
