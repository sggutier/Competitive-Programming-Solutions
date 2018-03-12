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

int main() {
    long long N ;

    while( scanf("%lld",&N)!=EOF and N>=0 )
	printf("%lld%%\n", N==1? 0LL : N*25 ) ;
    
    return 0 ;
}
