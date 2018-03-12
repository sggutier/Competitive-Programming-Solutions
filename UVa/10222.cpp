#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std ;

string nrm[] = { "`1234567890-=", "qwertyuiop[]\\", "asdfghjkl;'", "zxcvbnm,./" } ;
char deco[300] ;

int main() {
    memset( deco, ' ', sizeof(deco) ) ;
    for( int i=0; i<4; i++ ) {
	for( int j=0; j+2<nrm[i].size(); j++ )
	    deco[nrm[i][j+2]] = nrm[i][j] ;
    }
    for( int i='A'; i<='Z'; i++)
	deco[i] = deco[i-'A'+'a'] ;
    deco['\n'] = '\n' ;
    char tmp[5006] ;
    gets(tmp) ;
    int K = strlen(tmp) ;
    for( int i=0; i<K; i++ ) 
	printf("%c", deco[tmp[i]] ) ;
    printf("\n" ) ;

    return 0 ;
}
