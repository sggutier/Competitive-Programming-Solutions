#include <cstdio>
#include <string>
#include <algorithm>
#include <iostream>
using namespace std ;

int T=0 ;
int arr[500], maxLen = 0 ;

int taman( int N ) {
    int res = 0 ;
    while( N ) {
	res ++ ;
	N /= 10 ;
    }
    return res ;
}

int numDiv( int N ) {
    if( N==1 )
	return 0 ;
    int res = 1, i=2 ;
    for( ; i*i<N; i++ ) {
	if( N%i==0  ) 
	    res += N/i + i ;
    }
    if( i*i==N && N%i==0 ) 
	res += i ;
    return res ;
}

int main() {
    int tmp ;
    char fmt[500] ;

    while( scanf("%d", &tmp ) && tmp ) {
	arr[T++] = tmp ;
	maxLen = max( maxLen, taman(tmp) ) ;
    }

    sprintf( fmt, "%%%dd  %%s\n", 5 ) ;
    
    printf("PERFECTION OUTPUT\n" ) ;
    for( int i=0; i<T; i++ ) {
	tmp = arr[i] ;
	int d = numDiv(tmp) ;
	string S ;
	if( d>tmp )
	    S = "ABUNDANT" ;
	else if( d==tmp )
	    S = "PERFECT" ;
	else
	    S = "DEFICIENT" ;
	printf( fmt, tmp, S.c_str() ) ;
    }
    printf("END OF OUTPUT\n" ) ;

    return 0 ;
}
