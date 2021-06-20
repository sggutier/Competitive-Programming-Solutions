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
using namespace std ;
const int lim = 1000005 ;

bool comp[lim] ;

void criba() {
    for( int i=2; i*i<lim; i++ )
	if( !comp[i] )
	    for( int j=i*i; j<lim; j+=i )
		comp[j] = 1 ;
    comp[0] = comp[1] = 1 ;
}

int revo( int N ) {
    int res = 0;
    while( N ) {
	res *= 10;
	res += N%10 ;
	N /= 10 ;
    }
    return res ;
}

int main() {
    criba() ;
    int N ;

    while( scanf("%d", &N) != EOF ) {
	printf("%d is ", N ) ;
	if( !comp[N] ) {
	    if( revo(N)!=N and  !comp[ revo(N) ] ) 
		printf("emirp.\n" ) ;
	    else
		printf("prime.\n" ) ;
	}
	else {
	    printf("not prime.\n" ) ;
	}
    }
    
    return 0 ;
}
