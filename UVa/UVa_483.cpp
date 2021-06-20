#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std ;

char tmp[1000006] ;

int main() {
    while( gets(tmp) ) {
	int N = strlen(tmp), ult=0 ;
	for( int i=0; i<N; i++ ) {
	    if( tmp[i]==' ' ) {
		reverse( tmp+ult, tmp+i ) ;
		ult = i+1 ;
	    }
	}
	reverse( tmp+ult, tmp+N ) ;
	printf("%s\n", tmp ) ;
    }
    return 0 ;
}
