#include <cstring>
#include <cstdio>
#include <iostream>
using namespace std ;

int main() {
    char tmp[70] ;

    while( scanf("%s", tmp )  != EOF ) {
	long long pot = 2LL ;
	int N=strlen(tmp), res = 0 ;
	for( int i=N-1; i>=0; i--, pot*=2LL ) 
	    res += (tmp[i]-'0')*(pot-1) ;

	if( res==0 )
	    break ;
	printf("%d\n", res ) ;
    }
    
    return 0 ;
}
