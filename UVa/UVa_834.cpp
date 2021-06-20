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

void imprime( char prv, int a, int b ) {
    if( b==1 ) {
	printf("%c%d", prv, a ) ;
	return ;
    }
    printf("%c%d", prv, a/b ) ;
    imprime( ',', b, a%b ) ;
}

void caso( int a, int b ) {
    printf("[%d", a/b ) ;
    if( a%b )
	imprime( ';', b, a%b ) ;
    printf("]\n" ) ;
}

int main() {
    int x, y ;

    while( scanf("%d%d",&x,&y)!=EOF )
	caso(x,y) ;
    
    return 0 ;
}
