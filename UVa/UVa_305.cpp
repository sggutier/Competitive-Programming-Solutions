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
const int lim = 100005 ;

bool simula( int X, int mv ) {
    int Y = X/2 ;
    int pos = mv%X ;

    for( int i=0; i<Y; i++ ) {
	if( pos<Y )
	    return 0 ;
	X -- ;
	pos = (pos+mv)%X ;
    }
    return 1 ;
}

int main() {
    int N ;
    int res[15] ;

    res[1] = 2 ;
    res[2] = 7 ;
    res[3] = 5 ;
    res[4] = 30 ;
    res[5] = 169 ;
    res[6] = 441 ;
    res[7] = 1872 ;
    res[8] = 7632 ;
    res[9] = 1740 ;
    res[10] = 93313 ;
    res[11] = 459901 ;
    res[12] = 1358657 ;
    res[13] = 2504881 ;
    res[14] = 13482720 ;
    res[15] = 25779600 ;

    while( scanf("%d",&N)!=EOF and N  )
	printf("%d\n", res[N] ) ;

    return 0 ;

    cin >> N ;

    for( int i=1; i<=N; i++ ) {
	for( int k=2; ; k++ ) {
	    if( !simula( i*2, k-1 ) )
		continue ;
	    cout << i << " " << k << endl ;
	    break ;
	}
    }

    
    
    return 0 ;
}
