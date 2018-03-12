#include "encoder.h"
#include "encoderlib.h"
#include <cstdio>
using namespace std ;

void encode(int N, int D[]) {
	int i ;
	for( i=0; i<N; i++ ) {
		send_data( (D[i]/26) + 'a' ) ;
		send_data( (D[i]%26) + 'a' ) ;
	}
}
