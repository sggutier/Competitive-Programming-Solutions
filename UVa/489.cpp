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

void caso() {
    char A[lim], B[lim] ;
    scanf("%s%s", A, B ) ;
    int N = strlen(A), M =strlen(B) ;
    bool usd[300], mks[300] ;
    int R = 0 ;

    memset( usd, 0, sizeof(usd) ) ;
    memset( mks, 0, sizeof(mks) ) ;

    for( int i=0; i<N; i++ )
	mks[A[i]] = 1 ;

    for( int i=0; i<300; i++ )
	if( mks[i] )
	    R ++ ;

    for( int i=0, w=0, k=0; i<M; i++ ) { 
	if( !mks[ B[i] ] ) {
	    w ++ ;
	    if( w==7 ) {
		printf("You lose.\n" ) ;
		return ;
	    }
	}
	else if( !usd[B[i]] ) {
	    k ++ ;
	    if( k==R ) {
		printf("You win.\n" ) ;
		return ;
	    }
	}
	usd[ B[i] ] = 1;
    }

    printf("You chickened out.\n" ) ;
}

int main() {
    int T ;
    
    while( scanf("%d", &T )!=EOF and T!=-1 ) {
	printf("Round %d\n", T ) ;
	caso() ;
    }
    
    return 0 ;
}
