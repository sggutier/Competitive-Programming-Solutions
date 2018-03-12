#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <queue>
#include <stack>
#include <list>
#include <vector>
#include <set>
#include <map>
#include <utility>
#include <string>
#include <cstring>
using namespace std ;

int main() {
    long long N ;

    while( scanf("%lld",&N)!=EOF ) {
	long long K = N*(N+1)/2LL ;
	printf("%lld\n", K*K ) ;
    }
    
    return 0 ;
}
