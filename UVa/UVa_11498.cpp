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

int pos( int a, int b ) {
    if( a<b )
	return 0 ;
    if( a>b )
	return 1 ;
    if( a==b )
	return 2 ;
}

char res[2][2][3] = { {"SO","NO"}, {"SE","NE"} } ;

void caso(int N) {

    int a, b ;

    // scanf("%d", &N ) ;
    scanf("%d%d", &a, &b ) ;
    for( int i=0; i<N; i++ ) {
	int x, y ;
	scanf("%d%d", &x, &y ) ;
	x = pos( x, a ) ;
	y = pos( y, b ) ;
	if( x==2 or y==2 ) 
	    printf("divisa\n" );
	else
	    printf("%s\n", res[x][y] ) ;
    }
}

int main() {
    int K ;

    while( scanf("%d",&K)!=EOF )
	caso(K) ;
    
    return 0 ;
}
