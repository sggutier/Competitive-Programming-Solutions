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

int main() {
    long long N ;

    while( scanf("%lld", &N) != EOF ) {
	N = (N+1)/2 ;
	long long pos = N*N ;
	pos = 2*pos - 1 ;
	printf("%lld\n", pos + pos-2 + pos-4 ) ;
    }
    
    return 0 ;
}
