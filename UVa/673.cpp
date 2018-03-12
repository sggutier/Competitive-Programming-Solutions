#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std ;

void caso() {
    char S[500] ;
    stack <char> Q ;
    int N ;
    gets(S) ;
    N = strlen(S) ;
    if( N==0 ) {
	printf("Yes\n" ) ;
	return ;
    }
    for( int i=0; i<N; i++ ) {
	if( S[i]=='(' || S[i]=='[' ) {
	    Q.push( S[i] ) ;
	}
	else if( !Q.empty() && abs(Q.top()-S[i])<3 ) {
	    Q.pop() ;
	}
	else {
	    printf("No\n" ) ;
	    return ;
	}
    }
    printf("%s\n", Q.empty()? "Yes":"No" ) ;
}

int main() {
    int T ;
    char tmp[500] ;

    gets(tmp) ;
    sscanf(tmp, "%d", &T ) ;
    for( int i=0; i<T; i++ )
	caso() ;

    return 0 ;
}
