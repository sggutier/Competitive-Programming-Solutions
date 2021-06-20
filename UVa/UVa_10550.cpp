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

int dif( int a, int b, int dir ) {
    return ( 40 + (b-a)*dir )%40 ;
}

void caso( int ini, int a, int b, int c ) {
    int res = 40*3 ;
    res += dif( ini, a, -1 ) + dif( a, b, 1 ) + dif( b, c, -1 )  ;
    printf("%d\n", res*9 ) ;
}

int main() {
    int n, a, b, c ;

    while( scanf("%d%d%d%d",&n,&a,&b,&c)!=EOF  and  (n or a or b or c)  )
	caso( n, a, b, c ) ;
    
    return 0 ;
}
