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

void calc( long long mal, long long fem, int N ) {
    if( N==1 ) {
	printf("%lld %lld\n", mal, mal+fem ) ;
	return ;
    }
    calc( mal+fem, mal+1, N-1 ) ;
}

int main() {
    int N ;

    while( scanf("%d", &N)!=EOF and N!=-1 )
	calc( 0, 1, N+1 ) ;
    
    return 0 ;
}
