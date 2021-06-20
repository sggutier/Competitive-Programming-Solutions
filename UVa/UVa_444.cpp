#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cctype>
#include <string>
#include <vector>
#include <utility>
#include <map>
#include <set>
#include <stack>
#include <queue>
using namespace std ;
#define parI pair <int,int>
#define p1 first
#define p2 second
#define mkp make_pair
const int inf = 1e9 ;
const int lim = 1e5 + 5 ;
const int dr[] = { -1, 0, 1, 0 } ;
const int dc[] = { 0, 1, 0, -1 } ;

void decodifica( char *S, int N ) {
    char *res = (char *) malloc( 2*sizeof(S) ) ;
    int K = 0 ;
    memset( res, 0, sizeof(res) ) ;
    for( int i=N-1; i>=0; i-- ) {
	if( S[i]!='1' ) {
	    res[K++] = (S[i]-'0')*10 + (S[i-1]-'0') ;
	    i -- ;
	}
	else {
	    res[K++] = (S[i]-'0')*100 + (S[i-1]-'0')*10 + (S[i-2]-'0') ;
	    i -= 2 ;
	}

    }
    for( int i=0; i<K; i++ )
	printf("%c", res[i] ) ;
    printf("\n" ) ;
}

void codifica( char *S, int N ) {
    char *res = (char *) malloc( 2*sizeof(S) ) ;
    int K = 0 ;
    memset( res, 0, sizeof(res) ) ;
    for( int i=N-1; i>=0; i-- ) {
	char tmp = S[i] ;
	while( tmp ) {
	    res[K++] = tmp%10 + '0' ;
	    tmp /= 10 ;
	    printf("%c", res[K-1] ) ;
	}
    }
    printf("\n" ) ;
    return ;
}

int main() {
    char S[lim] ;
    
    while( gets(S) ) {
	int N = strlen(S) ;
	if( !isdigit(S[0]) )
	    codifica( S, N ) ;
	else
	    decodifica( S, N ) ;
    }
    
    return 0 ;
}
