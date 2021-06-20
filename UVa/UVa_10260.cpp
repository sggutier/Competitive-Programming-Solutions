#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;

int rVal[300] ;

int main() {
    rVal['B'] = 1 ;
    rVal['F'] = 1 ;
    rVal['P'] = 1 ;
    rVal['V'] = 1 ;
    rVal['C'] = 2 ;
    rVal['G'] = 2 ;
    rVal['J'] = 2 ;
    rVal['K'] = 2 ;
    rVal['Q'] = 2 ;
    rVal['S'] = 2 ;
    rVal['X'] = 2 ;
    rVal['Z'] = 2 ;
    rVal['D'] = 3 ;
    rVal['T'] = 3 ;
    rVal['L'] = 4 ;
    rVal['M'] = 5 ;
    rVal['N'] = 5 ;
    rVal['R'] = 6 ;

    char tmp ;
    int ant = -1 ;
    while( scanf("%c", &tmp )!=EOF ) {
	if( tmp=='\n' )
	    printf("\n" ) ;
	else if( rVal[tmp]!=rVal[ant] and rVal[tmp] )
	    printf("%d", rVal[tmp] ) ;
	ant = tmp ;
    }
    if( tmp!='\n' )
	printf("\n" ) ;
    
    return 0 ;
}
