#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std ;

int N ;
int cnt[105] ;

void caso() {
    int tmp ;
    
    memset( cnt, 0, sizeof(cnt) ) ;
    
    for( int i=0; i<N; i++ ){
	scanf("%d", &tmp ) ;
	cnt[tmp] ++ ;
    }
    tmp = 0 ;
    for( int i=0; i<105; i++ ) {
	for( int j=0; j<cnt[i]; j++ ) {
	    if( tmp )
		printf(" " );
	    tmp = 1 ;
	    printf("%d", i ) ;
	}
    }
    printf("\n" ) ;
}

int main() {
    while( scanf("%d",&N)!=EOF && N )
	caso() ;
    
    return 0 ;
}
