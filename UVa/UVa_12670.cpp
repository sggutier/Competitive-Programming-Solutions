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

long long unos( long long N, int pos ) {
    if( pos<0 )
	return 0LL ;
    long long res = 0LL ;
    if( (1LL<<pos) & N  )
	res += unos( N&((1LL<<pos)-1), pos-1 ) + N-(1LL<<pos)+1 ;
    else
	res += unos( N, pos-1 ) ;
    if( ((1LL<<pos) & N) and pos )
	res += (1LL<<(pos-1))*pos ;
    return res ;
}

int main() {
    long long A, B ;

    while( scanf("%lld%lld", &A, &B ) != EOF  ) {
	printf("%lld\n", unos(B,60)-unos(A-1,60)  ) ;
    }
    
    return 0 ;
}
