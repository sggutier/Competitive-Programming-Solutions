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
const int lim = 51 ;

long long fib[lim] ;

void precarga() {
    fib[0] = fib[1] = 1LL ;
    for( int i=2; i<lim; i++ )
	fib[i] = fib[i-1] + fib[i-2] ;
}

int main() {
    precarga() ;

    int N ;

    while( scanf("%d",&N)!=EOF and N!=0 ) {
	printf("%lld\n", fib[N] ) ;
    }
    
    return 0 ;
}
