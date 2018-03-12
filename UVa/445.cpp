#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std ;

int main() {
    int crg=0 ;
    char tmp ;

    while( scanf("%c",&tmp)!=EOF ) {
	if( tmp>='0' && tmp<='9' )
	    crg += tmp-'0' ;
	else if( tmp=='b' ) {
	    for( ; crg; crg-- )
		printf(" " ) ;
	}
	else if( tmp=='!' || tmp=='\n' ) {
	    printf("\n" ) ;
	    crg = 0 ;
	}
	else {
	    for( ; crg; crg-- )
		printf("%c", tmp ) ;
	}
    }
    
    return 0 ;
}
