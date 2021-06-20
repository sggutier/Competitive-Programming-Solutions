#include <cstdio>
#include <algorithm>
#include <iostream>
#include <utility>
using namespace std ;

int cnt[300] ;
pair < int, char > res[300] ;
int R = 0 ;

int main() {
    int T ;
    char tmp ;

    scanf("%d\n", &T ) ;
    while(  scanf("%c", &tmp) != EOF ) {
	if( tmp>='a' && tmp<='z' )
	    tmp = tmp-'a'+ 'A' ;
	cnt[tmp] ++ ;
    }

    for( int i='A'; i<='Z'; i++ ) {
	if( cnt[i] )
	    res[R++] = pair< int, char > (  -cnt[i], char(i) ) ;
    }

    sort( res, res+R ) ;
    for( int i=0; i<R; i++ )
	printf("%c %d\n", res[i].second, -res[i].first ) ;

    return 0 ;
}
