#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cctype>
#include <string>
#include <vector>
#include <utility>
#include <map>
#include <set>
#include <stack>
#include <queue>
using namespace std ;
#define parI pair <int,int>
#define p1 first
#define p2 second
#define mkp make_pair
const int inf = 1e9 ;
const int lim = 1e5 + 5 ;

int N ;
priority_queue <int> res ;

int main() {
    while( scanf("%d",&N)!=EOF and N ) {
	int tot = 0 ;
	for( int i=0; i<N; i++ ) {
	    int tmp ;
	    scanf("%d", &tmp ) ;
	    res.push( -tmp ) ;
	}
	while( res.size()>1 ) {
	    int a = res.top(), b ;
	    res.pop() ;
	    b = res.top() ;
	    res.pop() ;
	    tot += -a-b ;
	    res.push( a + b ) ;
	}
	printf("%d\n", tot ) ;
	res.pop() ;
    }


    
    return 0 ;
}
