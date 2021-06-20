#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <utility>
using namespace std ;

void caso( char *S ) {
    int N = strlen(S), K=0, tot=0 ;
    pair < int, char > cnt[300] ;
    sort( S, S+N ) ;
    for( int i=0; i<N; i++ ) {
	if( i && S[i]!=S[i-1] ) {
	    if( !(S[i-1]>='a' && S[i-1]<='z') && !(S[i-1]>='A' && S[i-1]<='Z') ) {
		tot = 1 ;
		continue ;
	    }
	    cnt[K++] = make_pair( -tot, S[i-1] ) ;
	    tot = 0 ;
	}
	tot ++ ;
    }
    if( S[N-1]!=' ' )
	cnt[K++] = make_pair( -tot, S[N-1] ) ;
    sort( cnt, cnt+K ) ;
    for( int i=0; i<K; i++ ) {
	if( i && cnt[i].first!=cnt[i-1].first )
	    break ;
	printf("%c", cnt[i].second ) ;
    }
    printf(" %d\n", -cnt[0].first ) ;
}
	

int main() {
    char S[100005] ;

    while( gets(S) ) {
	caso( S ) ;
    }
    
    return 0 ;
}
