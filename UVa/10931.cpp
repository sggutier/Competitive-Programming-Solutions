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
const int lim = 100005 ;

int printa( int N ) {
    bool fst = 1 ;
    int res = 0 ;
    for( int i=31; i>=0; i-- ) {
	if( i==0 )
	    fst = 0 ;
	if( (1<<i) & N ) {
	    fst = 0 ;
	    printf("1" ) ;
	    res ++ ;
	}
	else if( !fst ) {
	    printf("0" ) ;
	}
    }

    return res ;
}

int main() {
    int N ;

    while( scanf("%d",&N)!=EOF   and  N ) {
	printf("The parity of " ) ;
	int tmp = printa(N) ;
	printf(" is %d (mod 2).\n", tmp ) ;
    }
    
    return 0 ;
}
