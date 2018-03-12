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
    int N ;

    scanf("%d", &N ) ;
    for( int i=0; i<N; i++ ) {
	int a, b, c ;
	scanf("%d%d%d", &a, &b, &c ) ;
	printf("Case %d: %d\n", i+1, (b+c-1)%a + 1 ) ;
    }
    
    return 0 ;
}
