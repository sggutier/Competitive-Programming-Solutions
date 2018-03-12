#include <cstdio>
#include <algorithm>
#include <iostream>
#include <utility>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <cmath>
#include <string>
#include <cstring>
#include <vector>
#include <list>
#include <cstdlib>
#include <cctype>
using namespace std ;
#define par pair< int, int >
#define p1 first
#define p2 second
const int limA = 14 ;
const int limB = (1<<limA) ;

int N ;
int arr[limA] ;
int btCnt[limB] ;

void precarga() ;

void caso() ;

int main() {
    precarga() ;
    int fst = 1 ;

    while( scanf("%d",&N)!=EOF and N ) {
	if( !fst )
	    printf("\n" ) ;
	fst = 0 ;
	caso() ;
    }
    
    return 0 ;
}

void caso() {
    for( int i=0; i<N; i++ )
	scanf("%d", &arr[i] ) ;

    for( int b=0; b<(1<<N); b++ ) {
	if( btCnt[b]!=N-6 )
	    continue ;
	for( int i=N-1, fst=1; i>=0; i-- ) {
	    if( (1<<i) & b ) {
		continue ;
	    }
	    if( !fst )
		printf( " " ) ;
	    fst = 0 ;
	    printf("%d", arr[N-1-i] ) ;
	}
	printf("\n" ) ;
    }
}

void precarga() {
    for( int i=0; i<limB; i++ ) {
	int cnt = 0 ;
	for( int j=0; j<limA; j++ )
	    if( (1<<j) & i )
		cnt ++ ;
	btCnt[i] = cnt ;
    }
}
