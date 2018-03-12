#include "decoder.h"
#include "decoderlib.h"
#include <cstdio>
using namespace std ;

void decode(int M) {
	int a, b ;
	for( int i=0; i<M; i+=2 ) {
		a = (read_data()-'a')*26 ;
		b = read_data()-'a' ;
		output_data( a+b ) ;
	}
}
