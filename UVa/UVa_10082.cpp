#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <cstdio>
using namespace std ;

char norm[300] ;
string tabl[4]  = { "1234567890-=", "QWERTYUIOP[]\\", "ASDFGHJKL;\'", "ZXCVBNM,./" } ;

int main() {
    for( int i=0; i<4; i++ ) {
	int tmp = tabl[i].size() ;
	for( int j=1; j<tmp; j++ )
	    norm[ tabl[i][j] ] = tabl[i][j-1] ;
    }

    char quak ;
    while( scanf("%c", &quak ) != EOF) {
	if( norm[quak] )
	    printf("%c", norm[quak] ) ;
	else
	    printf("%c", quak ) ;
    }
    
    return 0 ;
}
