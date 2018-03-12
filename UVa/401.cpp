#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;

char revr[300] ;

string res[2][2] = { { " -- is not a palindrome.", " -- is a mirrored string."},
		     { " -- is a regular palindrome.", " -- is a mirrored palindrome." 	} } ;

int flipo( char *S, int N ) {
    for( int i=0; i<N; i++ ) {
	if( revr[S[i]]!=S[N-1-i] )
	    return 0 ;
    }
    return 1 ;
}

int pal( char *S, int N ) {
    for( int i=0; i<N; i++ ) {
	if( S[i]!=S[N-1-i] )
	    return 0 ;
    }
    return 1 ;
}

int main() {
    revr['A'] = 'A' ;
    revr['B'] = ' ' ;
    revr['C'] = ' ' ;
    revr['D'] = ' ' ;
    revr['E'] = '3' ;
    revr['F'] = ' ' ;
    revr['G'] = ' ' ;
    revr['H'] = 'H' ;
    revr['I'] = 'I' ;
    revr['J'] = 'L' ;
    revr['K'] = ' ' ;
    revr['L'] = 'J' ;
    revr['M'] = 'M' ;
    revr['N'] = ' ' ;
    revr['O'] = 'O' ;
    revr['P'] = ' ' ;
    revr['Q'] = ' ' ;
    revr['R'] = ' ' ;
    revr['S'] = '2' ;
    revr['T'] = 'T' ;
    revr['U'] = 'U' ;
    revr['V'] = 'V' ;
    revr['W'] = 'W' ;
    revr['X'] = 'X' ;
    revr['Y'] = 'Y' ;
    revr['Z'] = '5' ;
    revr['1'] = '1' ;
    revr['2'] = 'S' ;
    revr['3'] = 'E' ;
    revr['4'] = ' ' ;
    revr['5'] = 'Z' ;
    revr['6'] = ' ' ;
    revr['7'] = ' ' ;
    revr['8'] = '8' ;
    revr['9'] = ' ' ;

    char tmp[500] ;
    while( scanf("%s",tmp) != EOF ) {
	int N = strlen(tmp) ;
	int a=pal(tmp,N), b=flipo(tmp,N) ;
	printf("%s%s\n\n", tmp, res[a][b].c_str() ) ;
    }
    return 0 ;
}
