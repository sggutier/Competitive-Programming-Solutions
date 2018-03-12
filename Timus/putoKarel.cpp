#include <cstdio>
#include <algorithm>
#include <queue>
#include <iostream>
#include <map>
#include <set>
#include <cmath>
#include <string>
#include <cstring>
#include <list>
using namespace std ;

int main() {
	for( int i=0; i<100; i++ ) {
		printf("void quiton%dV(x) { ", i ) ;
		printf("	if( iszero(x) ) { " ) ;
		printf("		while( notFacingSouth ) " ) ;
		printf("			turnleft() ; " ) ;
		printf("		turnoff(); " ) ;
		printf("	} " ) ;
		printf("	quiton%dV(x) ", i+1 ) ;
		printf("} " ) ;
		printf("\n" ) ;
	}

	for( int i=0; i<100; i++ ) {
		printf("void quiton%dH(x) { ", i ) ;
		printf("	if( iszero(x) ) { " ) ;
		printf("		while( notFacingSouth ) " ) ;
		printf("			turnleft() ; " ) ;
		printf("		turnoff(); " ) ;
		printf("	} " ) ;
		printf("	quiton%dH(x) ", i+1 ) ;
		printf("} " ) ;
		printf("\n" ) ;
	}

	return 0 ;
}


